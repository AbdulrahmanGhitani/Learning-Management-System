#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QMainWindow>
#include "HomePage.h"

namespace Ui {
class SignupPage;
}

class SignupPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignupPage(QWidget *parent = nullptr);
    ~SignupPage();

private slots:
    void on_registerButton_clicked();

private:
    Ui::SignupPage *ui;
    HomePage *homePage;
};

#endif // SIGNUPPAGE_H
