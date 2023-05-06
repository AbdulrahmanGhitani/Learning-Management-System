#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "./HomePage.h"
#include "SignupPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_loginButton_clicked();



private:
    Ui::LoginPage *ui;
    HomePage *homePage;
    SignupPage *signupPage;
};
#endif // LOGINPAGE_H
