#include "LecHall.h"

LecHall::LecHall(QString n) : name(n){
    for(int i = 0; i < 6; i++)
            for(int j = 0; j < 5; j++)
                this->avaliable[i][j] = true;
}

QString LecHall::getName()
{
    return name;
}

bool LecHall::isAvaliable(QString day, QString time)
{
    int dayn = LecHall::days.find(day).value();
    int timen = LecHall::times.find(time).value();

    return this->avaliable[dayn][timen];
}

QStringList LecHall::timesAval(QString d)
{
    QStringList timesAval;

    for(QHash <QString,int> :: Iterator t = LecHall::times.begin();
        t != LecHall::times.end();
        t++){
        if(this->isAvaliable(d,t.key()))
            timesAval.push_front(t.key());
    }
    return timesAval;
}

void LecHall::reserve(QString day, QString time)
{
    int dayn = LecHall::days.find(day).value();
    int timen = LecHall::times.find(time).value();

    this->avaliable[dayn][timen] = false;
}

void LecHall::nonreserve(QString day, QString time)
{
    int dayn = LecHall::days.find(day).value();
    int timen = LecHall::times.find(time).value();

    this->avaliable[dayn][timen] = true;
}
    QMap<QString,LecHall> LecHall::lecHalls = {};

    QHash <QString,int> LecHall::days = {
        {"Saturday",0},
        {"Sunday",1},
        {"Monday",2},
        {"Tuesday",3},
        {"Wednesday",4},
        {"Thursday",5}
    };

    QHash <QString,int> LecHall::times = {
        {"8 : 30 - 10 : 00",0},
        {"10 : 15 - 11 : 45",1},
        {"12 : 15 - 1 : 45",2},
        {"2 : 00 - 3 : 30",3},
        {"3 : 45 - 5 : 15",4}
    };
