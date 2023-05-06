#include "AdminEditPage.h"
#include "ui_AdminEditPage.h"
#include "admin.h"
#include "LoginPage.h"
#include "HomePage.h"
#include <QMessageBox>
#include <QProcess>

AdminEditPage::AdminEditPage(QString name, QString username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminEditPage)
{
    ui->setupUi(this);
    AdminEditPage::name = name;
    AdminEditPage::username = username;
    AdminEditPage::parent = parent;
    ui->nameLineEdit->setText(name);
    ui->usernameLineEdit->setText(username);
}

AdminEditPage::~AdminEditPage()
{
    delete ui;
}

void AdminEditPage::on_pushButton_clicked()
{
    Admin *admin = new Admin();
    if(!admin->loginCheck(username,ui->oldPassLineEdit->text())){
        QMessageBox::critical(this,"Error","Incorrect Old Password");
    }
    else if(ui->usernameLineEdit->isModified() && !admin->checkUsername(ui->usernameLineEdit->text())){
         QMessageBox::warning(this,"Error","Username is already taken");
    }
    else if(ui->newPassLineEdit->text() != ui->confirmPassLineEdit->text()){
        QMessageBox::warning(this, "Error", "Passwords doesn't match");
    }
    else if(!admin->checkPassword(ui->newPassLineEdit->text())){
         QMessageBox::warning(this,"Error","Password should be longer than 8 characters");
    }
    else{
        admin->deleteUser(username);
        admin->registerNew(ui->usernameLineEdit->text(), ui->newPassLineEdit->text(), ui->nameLineEdit->text());
        LoginPage *loginPage;
        loginPage = new LoginPage(this);
        this->close();
        parent->close();
        loginPage->show();


    }
}

