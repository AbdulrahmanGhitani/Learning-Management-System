#include "course.h"

Course::Course()
{}

Course::Course(QString n, QString c)
{
    name = n;
    code = c;
}

QString Course::getCourseName(){
    return name;
}

QString Course::getCode(){
    return code;
}

QString Course::getLecHall(){
    return lecHall;
}

QString Course::getLecTime(){
    return time;
}

QString Course::getLecDay()
{
    return day;
}

void Course::setCode(QString c){
    code = c;
}

void Course::setCourseName(QString n){
    name = n;
}

void Course::setLecHall(QString hall){
    lecHall = hall;
}

void Course::setLecTime(QString t)
{
    time = t;
}

void Course::setLecDay(QString d)
{
    day = d;
}

QMap<QString, Course> Course::courses = {};
