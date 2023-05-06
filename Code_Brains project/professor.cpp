#include "professor.h"

Professor::Professor(){
    fullName ="";
    ID ="";
    email = "";
    mobile = "";
    title = "";
}

Professor::Professor(QString n,QString m,QString e , QString I,QString t)
 :User(n,m,e,I),title(t)
{}

QMap<QString, Professor>Professor::professors = {};

QString Professor::getFirstLastName()
{
    QStringList list_str = fullName.split(" ");
   // QString first = list_str.first();
   // QString last = list_str.back();
    return list_str.first()+" "+list_str.back();
}



QString Professor::getFullName()
{
    return fullName;
}

QString Professor::getMobile()
{
    return mobile;
}

QString Professor::getMail()
{
    return email;
}

QString Professor::getID()
{
    return ID;
}

QString Professor::getTitle()
{
    return title;
}

void Professor::setFullName(QString newfullName)
{
    fullName = newfullName;
}

void Professor::setMobile(QString newMobile)
{
    mobile = newMobile;
}
void Professor::setMail(QString newEmail)
{
    email = newEmail;
}
void Professor::setID(QString newID)
{
    ID = newID;
}
void Professor::setTitle(QString newTitle)
{
    title = newTitle;
}
