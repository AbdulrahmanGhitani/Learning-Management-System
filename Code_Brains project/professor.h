#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "User.h"
#include <QList>
#include<QMap>
//#include<vector>
#include <iostream>
#include <course.h>
class Professor: public User
{
protected:
    QString title;

public:
    //المفروض فى فانكشن جيت كورسز وتإنسرت فى الفيكتور ويبقا الفكتور برايفت
   QVector<Course>coursesForProfessor;

   // When I click add I will insert this opject in map with his id;
   static QMap<QString, Professor>professors;

    Professor();

    Professor(QString n, QString m,QString e , QString I,QString t);

    QString getFirstLastName() ;
    QString getFullName();
    QString getMobile();
    QString getMail();
    QString getID();
    QString getTitle();

    void setFullName(QString newfirstName);

    void setMobile(QString newMobile);
    void setMail(QString newEmail);
    void setID(QString newID);
    void setTitle(QString newTitle);




};



#endif // PROFESSOR_H
