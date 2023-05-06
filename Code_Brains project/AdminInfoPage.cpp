#include "./AdminInfoPage.h"
#include "./ui_AdminInfoPage.h"

AdminInfoPage::AdminInfoPage(QString name, QString username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminInfoPage)
{
    ui->setupUi(this);
    ui->nameLabel->setText(name);
    ui->usernameLabel->setText(username);
    AdminInfoPage::name = name;
    AdminInfoPage::username = username;
    AdminInfoPage::parent = parent;
}

AdminInfoPage::~AdminInfoPage()
{
    delete ui;
}

void AdminInfoPage::on_editButton_clicked()
{
    adminEditPage = new AdminEditPage(name, username,parent);
    close();
    adminEditPage->show();

}

