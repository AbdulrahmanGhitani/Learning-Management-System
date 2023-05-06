#include "LoginPage.h"
#include "./ui_LoginPage.h"
#include "admin.h"
#include <QPixmap>
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);




}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_loginButton_clicked()
{
    Admin *admin = new Admin();

    if(!admin->loginCheck(ui->usernamLlineEdit->text(),ui->passworLlineEdit->text()) || ui->usernamLlineEdit->text().isEmpty() || ui->passworLlineEdit->text().isEmpty()){
        QMessageBox::critical(this,"Error","Incorrect Username or Password");
    }
    else{

        homePage = new HomePage(admin->getFullName(ui->usernamLlineEdit->text()),ui->usernamLlineEdit->text() , this);
        homePage->show();
        hide();
    }
}



