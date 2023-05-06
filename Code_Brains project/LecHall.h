#ifndef LECHALL_H
#define LECHALL_H

#include <QMap>
#include <QHash>
#include <QVector>

class LecHall
{

private:

    QString name;

public:

    static QMap<QString,LecHall> lecHalls;

    bool avaliable[6][5];

    LecHall(QString n);

    QString getName();

    bool isAvaliable(QString day, QString time);

    QStringList timesAval(QString d);

    void reserve(QString day, QString time);
    void nonreserve(QString day, QString time);

    static QHash <QString,int> days;
    static QHash <QString,int> times;

};

#endif // LECHALL_H
