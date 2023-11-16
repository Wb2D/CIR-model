#include "Tools/DataWorker/dataworker.h"
#include "Tools/Modeling/model.h"
#include "Model/equation.h"

// параметры уравнения
#define K 0.95
#define THETA 1.15
#define SIGMA 0.2

// параметры моделирования
#define AMOUNT_TRAJ 5
#define START 0
#define END 3000
#define AMOUNT_ITER 1000

// начальное значение для f(START) = R_ZERO
#define R_ZERO 0.5

int main()
{
    Equation equation(K, THETA, SIGMA);
    Model model(equation, AMOUNT_TRAJ, START, END, AMOUNT_ITER);

    DataWorker::save("test1.json", model.start(R_ZERO, 2));

    return 0;
}
