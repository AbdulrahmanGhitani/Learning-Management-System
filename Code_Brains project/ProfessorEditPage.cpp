#include "ProfessorEditPage.h"
#include "ui_ProfessorEditPage.h"
#include <QMessageBox>
#include <QAction>
#include "course.h"
#include "qregularexpression.h"
#include "qvalidator.h"

ProfessorEditPage::ProfessorEditPage(QWidget *parent,QMap<QString,Professor>:: Iterator profIt) :
    QDialog(parent),
    ui(new Ui::ProfessorEditPage)
{
    ui->setupUi(this);

    oldID=profIt->getID();


    ui->FLNameLabel->setText(profIt->getFirstLastName());
    ui->nameLineEdit->setText(profIt->getFullName());
    ui->idLineEdit->setText(profIt->getID());
    ui->titleLineEdit->setText(profIt->getTitle());
    ui->emailLineEdit->setText(profIt->getMail());
    ui->phoneLineEdit->setText(profIt->getMobile());

    profPtr = &profIt.value();

   professorCourseTableDisplay();
    allCoursesTableDisplay();
    setValidator();
}

void ProfessorEditPage::setValidator(){
    QRegularExpression name("[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+" );
    QRegularExpressionValidator *v = new QRegularExpressionValidator(name, this) ;
    ui->nameLineEdit->setValidator(v);
    QRegularExpression title("[a-z-A-Z]+\\s+[a-z-A-Z]+");
    QRegularExpressionValidator *v2 = new QRegularExpressionValidator(title, this);
    ui->titleLineEdit->setValidator(v2);
    QRegularExpression ID("[0-9]\\d{6}");
    QRegularExpressionValidator *v3 = new QRegularExpressionValidator(ID, this);
    ui->idLineEdit->setValidator(v3);
    QRegularExpression phone("01\\d{8}[0-9]");
    QRegularExpressionValidator *v4 = new QRegularExpressionValidator(phone, this);
    ui->phoneLineEdit->setValidator(v4);
    QRegularExpression mail("\\w+@\\w+.\\w+\\S");
    QRegularExpressionValidator *v5 = new QRegularExpressionValidator(mail, this);
    ui->emailLineEdit->setValidator(v5);
}

ProfessorEditPage::~ProfessorEditPage()
{
    delete ui;
}



void ProfessorEditPage::allCoursesTableDisplay()
{
    ui->allCoursesTable->setRowCount(0);
    ui->allCoursesTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"ID"<<"Name";
    ui->allCoursesTable->setHorizontalHeaderLabels(hLables);

    rowcount = 0;
    for(QMap<QString,Course>:: Iterator it = Course::courses.begin();
        it!= Course::courses.end();
        it++)
    {
        ui->allCoursesTable->insertRow(rowcount);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;

        ID->setText(it.key());
        Name->setText(it->getCourseName());

        ui->allCoursesTable->setItem(rowcount,0,ID);
        ui->allCoursesTable->setItem(rowcount,1,Name);

        rowcount++;
    }
}


void ProfessorEditPage::on_allCoursesTable_cellDoubleClicked(int row, int column)
{
    QString addThisCourse = ui->allCoursesTable->item(row,0)->text();
    QList<QTableWidgetItem*> l = ui->professorCourseTable->findItems(addThisCourse,Qt::MatchFlag());

if(l.count()==0)
{
        rowcount=ui->professorCourseTable->rowCount();

        QMap<QString,Course>::Iterator It= Course::courses.find(addThisCourse);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;

        ID->setText(It.key());
        Name->setText(It->getCourseName());

      ui->professorCourseTable->insertRow(rowcount);

        ui->professorCourseTable->setItem(rowcount,0,ID);
        ui->professorCourseTable->setItem(rowcount,1,Name);
}

else
{
   QMessageBox::critical(this,"ERROR","This course already exists");
}
}


void ProfessorEditPage::professorCourseTableDisplay()
{
    ui->professorCourseTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"Code"<<"Name";
    ui->professorCourseTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(auto v : profPtr->coursesForProfessor)
    {
        ui->professorCourseTable->insertRow(rowcount);

        QTableWidgetItem *Code= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;

        Code->setText(v.getCode());
        Name->setText(v.getCourseName());

        ui->professorCourseTable->setItem(rowcount,0,Code);
        ui->professorCourseTable->setItem(rowcount,1,Name);

        rowcount++;
    }
}

void ProfessorEditPage::on_professorCourseTable_cellDoubleClicked(int row, int column)
{
    QString deleteThisCourse = ui->allCoursesTable->item(row,0)->text();
    ui->professorCourseTable->removeRow(row);

}

void ProfessorEditPage::on_savePushButton_clicked()
{
    if(ui->phoneLineEdit->text().size()!=11)
    {
        QMessageBox::critical(this,"ERROR","This number isn't valid");
        return;
    }

    if(!ui->emailLineEdit->text().contains('@',Qt::CaseInsensitive) || !ui->emailLineEdit->text().contains('.',Qt::CaseInsensitive))
    {
        QMessageBox::critical(this,"ERROR","This mail isn't valid");
        return;
    }

    if(ui->nameLineEdit->text().isEmpty()||ui->emailLineEdit->text().isEmpty()||ui->phoneLineEdit->text().isEmpty()||ui->idLineEdit->text().isEmpty()||ui->titleLineEdit->text().isEmpty())
    {
        QMessageBox::critical(this,"Error","Empty filed");
        return;
    }

    profPtr->setFullName(ui->nameLineEdit->text());
    profPtr->setMail(ui->emailLineEdit->text());
    profPtr->setMobile(ui->phoneLineEdit->text());
    profPtr->setTitle(ui->titleLineEdit->text());

    int coursesNum = ui->professorCourseTable->rowCount();
    profPtr->coursesForProfessor.clear();
   for(int i = 0; i < coursesNum; i++)
    {
       profPtr->coursesForProfessor.push_back(Course::courses.find(ui->professorCourseTable->takeItem(i,0)->text()).value());
   }

    profPtr->setID(ui->idLineEdit->text());
    if(ui->idLineEdit->text()!=oldID)
    {
        if(Professor::professors.find(ui->idLineEdit->text()) != Professor::professors.end())
        {
            QMessageBox::critical(this,"ERROR","This ID is already used ");
            return;
        }
        Professor::professors.insert(profPtr->getID(),*profPtr);
        Professor::professors.remove(oldID);
    }


    this->close();
}


