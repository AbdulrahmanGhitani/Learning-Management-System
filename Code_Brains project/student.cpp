
#include "student.h"
#include <QList>


QMap <QString,Student> Student::students = {};

Student::Student(){

   //firstName = lastName = mobile = email = ID = "";
   totalGrade = 0;

}

Student::Student(QString n, QString m, QString e, QString i, QString a)
    : User(n, m, e,i), age(a)
{}

//QChar Student::getGpa()
//{
//    return gpa;
//}

//void Student::calcGpa(QChar g_pa)
//{

//}

float Student::getTotalGrade()
{
    return totalGrade;
}

float Student::calcTotalGrade()
{
    totalGrade = 0;

    for(auto g : this->grades)
        totalGrade += g;

    return totalGrade;
}

QString Student::getFirstLastName()
{
    QStringList list_str = fullName.split(" ");
   // QString first = list_str.first();
   // QString last = list_str.back();
    return list_str.first()+" "+list_str.back();
}


QString Student::getFullName()
{
    return fullName;
}

 void Student::setFullName(QString newfullName)
 {
     fullName=newfullName;
 }

QString Student::getAge()
{
    return age;
}

void Student::setAge(QString a_ge)
{
    age = a_ge;
}

QString Student::getMobile()
{
    return mobile;
}

void Student::setMobile(QString m_obile)
{
    mobile = m_obile;
}

QString Student::getMail()
{
    return email;
}

void Student::setMail(QString e_mail)
{
    email = e_mail;
}

QString Student::getID(){
    return ID;
}
void Student::setID(QString newID){
    ID = newID;
}
