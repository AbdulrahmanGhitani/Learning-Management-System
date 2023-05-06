#ifndef USER_H
#define USER_H
#include <iostream>
#include <QString>


using namespace std;

class User{

protected:

    QString fullName, mobile, email;
    QString ID;

public:

    User()
    {
        fullName = mobile = email = ID = "";
    }

   User(QString n ,QString m,QString e , QString i):
       fullName(n),mobile(m),email(e),ID(i) {}

   virtual QString getFirstLastName()=0;
   virtual QString getFullName() = 0;
   virtual QString getMobile()=0;
   virtual QString getMail()=0;
   virtual QString getID() = 0;
   virtual void setFullName(QString newfullName)=0;
   virtual void setID(QString newID)=0;
   virtual void setMail(QString e_mail)=0;
   virtual void setMobile(QString m_obile)=0;


};
#endif // USER_H
