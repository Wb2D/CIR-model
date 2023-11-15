#ifndef MODEL_H
#define MODEL_H

#include <QVector>

#include <chrono>
#include <ctime>
#include <random>
#include <QRandomGenerator>

#include "Model/equation.h"

typedef  QVector<QVector<double>> Trajectories;

class Model
{
public:
    Model(const Equation&, const uint&, const uint&, const uint&, const uint&);

    Trajectories start(const double&, const uint&) const;

private:
    Equation _equation;
    uint _amountTraj;
    uint _leftTime;
    uint _rightTime;
    uint _step;
};

#endif //  MODEL_H
