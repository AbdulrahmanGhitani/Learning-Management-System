#include "AddStudentPage.h"
#include "qregularexpression.h"
#include "qvalidator.h"
#include "ui_AddStudentPage.h"
#include <QMessageBox>

AddStudentPage::AddStudentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setValidator();
}

AddStudentPage::~AddStudentPage()
{
    delete ui;
}

void AddStudentPage::setValidator(){
    QRegularExpression name("[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+" );
    QRegularExpressionValidator *v = new QRegularExpressionValidator(name, this) ;
    ui->line_name->setValidator(v);
    QRegularExpression age("[1-9]\\d{0-1}");
    QRegularExpressionValidator *v2 = new QRegularExpressionValidator(age, this);
    ui->line_Age->setValidator(v2);
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

void AddStudentPage::on_buttomadd_clicked()
{
    QString name=ui->line_name->text(),
            id=ui->line_ID->text(),
            age=ui->line_Age->text(),
            mail=ui->line_mail->text(),
            phone=ui->line_phone->text();
    if(phone.size()!=11)
    {
        QMessageBox::critical(this,"ERROR","This number isn't valid");
        return;
    }

    if(!mail.contains('@',Qt::CaseInsensitive) || !mail.contains('.',Qt::CaseInsensitive))
    {
        QMessageBox::critical(this,"ERROR","This mail isn't valid");
        return;
    }

    if(id.isEmpty(),mail.isEmpty(),phone.isEmpty(),name.isEmpty(),age.isEmpty())
    {
        QMessageBox::critical(this,"Erorr","Empty field");
        return;
    }

    if(Student::students.find(ui->line_ID->text()) !=Student::students.end())
    {
        QMessageBox::critical(this,"ERROR","This ID is already used ");
        return;
    }



    Student *student=new Student(name,phone,mail,ui->line_ID->text(),age);
    Student::students.insert(ui->line_ID->text(),*student);
    this->close();
}
