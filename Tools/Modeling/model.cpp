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
    std::normal_distribution<double> dist(0., 1);

    double dt = static_cast<double>(_step) / 1000;
    Trajectories result;
    double r = rStart;

    for(uint i = 0; i  < _amountTraj; ++i) {
        result.push_back(QVector<double>());
        for(uint j = _leftTime; j < _rightTime; j += _step) {
            double dW = dist(gen) * sqrt(dt);
            switch (method) {
            case 1: // применение метода Эйлера
                r += _equation.F(r) * dt + _equation.G(r) * dW;
                break;
            default: // неверный метод
                break;
            }
            result[i].push_back(r);
        }
    }
    return result;
}
