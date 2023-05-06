
#include <iostream>
#include <QMap>
#include<QObject>
#include <QDebug>


#include "admin.h"

using namespace std;



Admin::Admin(){}

int Admin::hashing(QString password){
        hash<QString> h;
        return h(password);
    }

QMap<QString, int> Admin::check = {};
QMap<QString, QString> Admin::usernameFullName = {};

bool Admin::checkUsername(QString username){
        if(check[username]) return false;
        else return true;

    }

bool Admin::checkPassword(QString password){
    if(password.size() < 8) return false;
    else return true;
}

void Admin::registerNew(QString username, QString password, QString fullName)
{


        this->fullName = fullName;
         usernameFullName.insert(username, fullName);
      this-> password = password;
       this->username = username;
        check.insert(username, hashing(password));

}

    bool Admin::loginCheck(QString username, QString password)
    {
        if(check[username] == hashing(password)) return true;

        else  return false;

    }
 void Admin::deleteUser(QString username){
 check.remove(username);
 usernameFullName.remove(username);
 }




    void Admin::setFullName(QString newFullName)
    {
        fullName = newFullName;
    }

    void Admin::setPassword(QString newPassword)
    {
        if(checkPassword(newPassword)) password = newPassword;
        else qDebug()<< "Passord should be longer than 8 characters";
    }

    void Admin::setUsername(QString newUsername)
    {
        if(checkUsername(newUsername)) username = newUsername;
        else qDebug()<< "Username is already taken";
    }



    QString Admin::getFullName(QString username)
    {
        return usernameFullName[username];
    }



    Admin::~Admin(){}
