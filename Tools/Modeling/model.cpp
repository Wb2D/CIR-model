#include "Tools/Modeling/model.h"

Model::Model(const Equation& eq, const uint &traj, const uint &ltime,
             const uint& rtime, const uint &amount) :
    _equation(eq), _amountTraj(traj), _leftTime(ltime), _rightTime(rtime) {
    _step = (rtime - ltime) / amount;
}

Trajectories Model::start(const double& rStart, const uint& method) const {
    std::mt19937 gen;
    uint seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);
    std::normal_distribution<double> dist(0., 1.);

    double dt = static_cast<double>(_step) / 1000;
    Trajectories result;

    for(uint i = 0; i  < _amountTraj; ++i) {
        result.push_back(QVector<double>());
        double r = rStart;
        double dr = 0.;
        for(uint j = _leftTime; j < _rightTime; j += _step) {
            double dW = dist(gen) * sqrt(dt);
            switch (method) {
            case 1: { // метод Эйлера
                r += _equation.F(r) * dt + _equation.G(r) * dW;
                break;
            }
            case 2: { // метод Мильштейна
                r += _equation.F(r) * dt + _equation.G(r) * dW + 0.25 *
                        pow(_equation.getSigma(), 2) * (pow(dW, 2) - dt);
                break;
            }
            case 3: { // разложение в ряд Тейлора второго порядка
                dr = _equation.F(r) * dt + _equation.G(r) * dW;
                r += dr + ((((-_equation.getK() * dr) +
                             (((_equation.getSigma() * dr) / (2 * sqrt(r) * dt)) * dW)) / 2) * pow(dt, 2));
                break;
            }
            case 4: { // Рунге-Кутты порядка 3
                double k1 = _equation.F(r) + _equation.G(r) * dW / dt;
                double k2 = _equation.F(r + (dt / 2) * k1) + _equation.G(r + (dt / 2) * k1) * dW / dt;
                double k3 = _equation.F(r - dt * k1 + 2 * dt * k2)
                        + _equation.G(r - dt * k1 + 2 * dt * k2) * dW / dt;
                r += (dt / 6) * (k1 + 4 * k2 + 2 * k3);
                break;
            }
            case 5: { // Рунге-Кутты порядка 4
                double k1 = _equation.F(r) + _equation.G(r) * dW / dt;
                double k2 = _equation.F(r + (dt / 2) * k1) + _equation.G(r + (dt / 2) * k1) * dW / dt;
                double k3 = _equation.F(r + (dt / 2) * k2) + _equation.G(r + (dt / 2) * k2) * dW / dt;
                double k4 = _equation.F(r + dt * k3) + _equation.G(r + dt * k3) * dW / dt;
                r += (dt / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
                break;
            }
            default: // выбран неверный метод
                break;
            }
            result[i].push_back(r);
        }
    }
    return result;
}
