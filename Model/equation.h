#ifndef EQUATION_H
#define EQUATION_H

#include "QtMath"

/*
 * 2ab >= sigma^2
*/

class Equation
{
public:
    // конструктор
    Equation(const double &k, const double &theta, const double &sigma) :
        _k(k), _theta(theta), _sigma(sigma) {}

    // детерминированная часть
    double F(const double &r) const { return _k * (_theta - r); }
    // стохастическая часть
    double G(const double &r) const { return _sigma * sqrt(r); }

private:
    double _k;
    double _theta;
    double _sigma;
};

#endif //  EQUATION_H
