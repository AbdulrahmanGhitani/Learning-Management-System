//#ifndef ADMIN_H
//#define ADMIN_H

#pragma once

#include <iostream>
#include <QMap>
#include<QObject>
using namespace std;

class Admin
{

private:

    QString username;
    QString password;
    QString fullName;




public:
    static QMap<QString, int> check;
    static QMap<QString, QString> usernameFullName;

    Admin();


    int hashing(QString password);


    bool checkUsername(QString username);

    bool checkPassword(QString password);

    void registerNew(QString username, QString password, QString fullName);

    void deleteUser(QString username);

    bool loginCheck(QString username, QString password);

    void setUsername(QString username);

    void setPassword(QString password);

    void setFullName(QString fullName);



    QString getFullName(QString username);



    ~Admin();
};
//#endif
