#ifndef DATAWORKER_H
#define DATAWORKER_H

#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDebug>

class DataWorker
{
public:
    static void save(const QString&, const QVector<QVector<double>>&);
};

#endif // DATAWORKER_H
