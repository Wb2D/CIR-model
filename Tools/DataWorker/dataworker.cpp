#include "dataworker.h"

void DataWorker::save(const QString &path, const QVector<QVector<double>> &data) {
    QJsonArray result;
    int counter = 0;
    for(const auto &traj : data) {
        QJsonArray tmp;
        for(const auto &value : traj) {
            tmp.append(value);
        }
        QJsonObject trajObj;
        trajObj["trajectory_id"] = counter++;
        trajObj["data"] = tmp;
        result.append(trajObj);
    }
    QJsonObject resultObj;
    resultObj["trajectories"] = result;
    QJsonDocument doc(resultObj);
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << doc.toJson();
        file.close();
    }
    else {
        qDebug() << "Cant save file";
    }
    qDebug() << "Results have been recorded successfully";
}
