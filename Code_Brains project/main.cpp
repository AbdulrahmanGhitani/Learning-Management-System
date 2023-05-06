#include "LoginPage.h"
#include "admin.h"
#include "professor.h"
#include "student.h"
#include "course.h"
#include "LecHall.h"

#include <QApplication>
#include<QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile ssfile("C:/x/Toolery.qss");

//    ssfile.open(QFile::ReadOnly);

//    QString ssstring = QLatin1String(ssfile.readAll());

//    a.setStyleSheet(ssstring);

    Admin admin;
    admin.check = {{"omar", admin.hashing("01234567")}};
    admin.usernameFullName = {{"omar", "Omar Abdulnasser :) "}};
    LoginPage l;
    l.show();


    LecHall l3100("3100");

    LecHall l3200("3200");

    LecHall l3300("3300");

    LecHall::lecHalls ={
        {l3100.getName(),l3100},
        {l3200.getName(),l3200},
        {l3300.getName(),l3300}};



    return a.exec();
}
