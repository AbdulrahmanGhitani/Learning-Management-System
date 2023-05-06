#include "SignupPage.h"
#include "ui_SignupPage.h"
#include "admin.h"
#include <QMessageBox>
#include <QMap>

SignupPage::SignupPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignupPage)
{
    ui->setupUi(this);
}

SignupPage::~SignupPage()
{
    delete ui;
}

void SignupPage::on_registerButton_clicked()
{
    if(ui->fullNameLineEdit->text().isEmpty() || ui->usernameLineEdit->text().isEmpty() || ui->passwordLineEdit->text().isEmpty() || ui->confirmPassswordLineEdit->text().isEmpty()){
        QMessageBox::warning(this,"Error", "Please fill all the data");
    }
    else if(ui->passwordLineEdit->text() != ui->confirmPassswordLineEdit->text()){
        QMessageBox::warning(this,"Error", "Passwords doesn't match");
    }
    else{
        Admin *admin = new Admin();
        if(!admin->checkUsername(ui->usernameLineEdit->text())){
            QMessageBox::warning(this,"Error", "Username is already taken");
        }else if(!admin->checkPassword(ui->passwordLineEdit->text())){
            QMessageBox::warning(this,"Error", "Password should be longer than 8 characters");
        }
        else{
           hide();
            homePage = new HomePage(ui->fullNameLineEdit->text(), ui->usernameLineEdit->text(),this);
            homePage->show();
            admin->registerNew(ui->usernameLineEdit->text(), ui->passwordLineEdit->text(), ui->fullNameLineEdit->text());

        }
    }
}

