#include "ProfessorPage.h"
#include "ui_ProfessorPage.h"
#include "professor.h"

ProfessorPage::ProfessorPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfessorPage)
{
    ui->setupUi(this);
    professorTableDisplay();
}

ProfessorPage::~ProfessorPage()
{
    delete ui;
}

void ProfessorPage::professorTableDisplay()
{
    ui->professorTable->setRowCount(Professor::professors.size());
    ui->professorTable->setColumnCount(2);

    QStringList firstTitle;
    firstTitle<<"ID"<<"Name";
    ui->professorTable->setHorizontalHeaderLabels(firstTitle);

//    QMap<QString, Student> :: Iterator It = Student::students.begin();

     int rowcount = 0;
     for(auto It : Professor::professors)
     {
         ui->professorTable->insertRow(rowcount);

         QTableWidgetItem *ID= new QTableWidgetItem;
         QTableWidgetItem *Name= new QTableWidgetItem;

         ID->setText(It.getID());
         Name->setText(It.getFullName());

         ui->professorTable->setItem(rowcount,0,ID);
         ui->professorTable->setItem(rowcount,1,Name);

         rowcount++;
     }
 }

void ProfessorPage::on_professorTable_cellDoubleClicked(int row, int column)
{
    QString thisId = ui->professorTable->item(row,0)->text();
    QMap<QString,Professor>:: Iterator prof = Professor::professors.find(thisId);
    pip = new ProfessorInfoPage(this,prof);
    pip->exec();
}

