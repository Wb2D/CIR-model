#include "Tools/DataWorker/dataworker.h"
#include "Tools/Modeling/model.h"
#include "Model/equation.h"

#include <cstdlib>
#include <QElapsedTimer>
#include <QDebug>

// параметры уравнения
#define K 0.95
#define THETA 1.15
#define SIGMA 0.2

// параметры моделирования
#define AMOUNT_TRAJ 50
#define START 0
#define END 3000
#define AMOUNT_ITER 1000

// начальное значение для f(START) = R_ZERO
#define R_ZERO 1.5

int main() {
    Equation equation(K, THETA, SIGMA);

    // подсчет затраченного времени для опр зависимости от числа траекторий
    /*
    uint counter = 0;
    Model model(equation, counter, START, END, AMOUNT_ITER);

    QString path = "time.json";
    QFile file(path);
    QElapsedTimer timer;

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QJsonArray resultArray;

        while(counter < 1000) {
            model.setTraj(counter);
            timer.start();
            model.start(R_ZERO, 5);
            qint64 elapsedTime = timer.elapsed();
            counter += 10;

            QJsonObject object;
            object["elapsedTime"] = static_cast<int>(elapsedTime);
            object["numberOfIterations"] = static_cast<int>(counter);

            resultArray.append(object);
        }
        QJsonObject result;
        result["results"] = resultArray;
        QJsonDocument resultDoc(result);
        stream << resultDoc.toJson(QJsonDocument::Indented);
        file.close();
    } else {
        qDebug() << "Error";
    }
    */

    // создание различных моделей для дальнейшего анализа
    /*
    DataWorker::save("test1.json", model.start(R_ZERO, 1));
    system("python C:/Qt/Projects/CIR/Plot/main.py");
    system("python C:/Qt/Projects/CIR/Statistical/main.py");
    */

    return 0;
}
