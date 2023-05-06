#include "AddProfessorPage.h"
#include "ui_AddProfessorPage.h"
#include "qregularexpression.h"
#include "qvalidator.h"
#include<QMessageBox>

AddProfessorPage::AddProfessorPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProfessorPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setValidator();
}

void AddProfessorPage::setValidator(){
    QRegularExpression name("[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+" );
    QRegularExpressionValidator *v = new QRegularExpressionValidator(name, this) ;
    ui->line_name->setValidator(v);
    QRegularExpression title("[a-z-A-Z]+\\s+[a-z-A-Z]+");
    QRegularExpressionValidator *v2 = new QRegularExpressionValidator(title, this);
    ui->line_title->setValidator(v2);
    QRegularExpression ID("[0-9]\\d{6}");
    QRegularExpressionValidator *v3 = new QRegularExpressionValidator(ID, this);
    ui->line_ID->setValidator(v3);
    QRegularExpression phone("01\\d{8}[0-9]");
    QRegularExpressionValidator *v4 = new QRegularExpressionValidator(phone, this);
    ui->line_phone->setValidator(v4);
    QRegularExpression mail("\\w+@\\w+.\\w+\\S");
    QRegularExpressionValidator *v5 = new QRegularExpressionValidator(mail, this);
    ui->line_mail->setValidator(v5);
}

AddProfessorPage::~AddProfessorPage()
{
    delete ui;
}

void AddProfessorPage::on_bottum_add_clicked()
{
    if(ui->line_phone->text().size()!=11)
    {
        QMessageBox::critical(this,"ERROR","This number isn't valid");
        return;
    }

    if(!ui->line_mail->text().contains('@',Qt::CaseInsensitive) || !ui->line_mail->text().contains('.',Qt::CaseInsensitive))
    {
        QMessageBox::critical(this,"ERROR","This mail isn't valid");
        return;
    }

    if(ui->line_ID->text().isEmpty(),ui->line_mail->text().isEmpty(),ui->line_name->text().isEmpty(),ui->line_phone->text().isEmpty(),ui->line_title->text().isEmpty())
    {
        QMessageBox::critical(this,"Erorr","Empty field");
        return;
    }

    if(Professor::professors.find(ui->line_ID->text()) !=Professor::professors.end())
    {
        QMessageBox::critical(this,"ERROR","This ID is already used ");
        return;
    }

    QString name=ui->line_name->text(),id=ui->line_ID->text(),phone=ui->line_phone->text(),
            mail=ui->line_mail->text(),title=ui->line_title->text();
    Professor *prof=new Professor(name,phone,mail,id,title);
    Professor::professors.insert(id,*prof);



    this->close();
}
