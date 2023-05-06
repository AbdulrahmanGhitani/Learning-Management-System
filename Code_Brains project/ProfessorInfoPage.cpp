#include "ProfessorInfoPage.h"
#include "ui_ProfessorInfoPage.h"

ProfessorInfoPage::ProfessorInfoPage(QWidget *parent,QMap<QString,Professor>:: Iterator profIt) :
    QDialog(parent),
    ui(new Ui::ProfessorInfoPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    prof = profIt.value();

    ui->FLNameLabel->setText(prof.getFirstLastName());
    ui->nameLabel->setText(prof.getFullName());
    ui->idLabel->setText(prof.getID());
    ui->phoneLabel->setText(prof.getMobile());
    ui->emailLabel->setText(prof.getMail());
    ui->titleLabel->setText(prof.getTitle());

    professorInfoTableDisplay();
}

ProfessorInfoPage::~ProfessorInfoPage()
{
    delete ui;
}

void ProfessorInfoPage::professorInfoTableDisplay()
{
    ui->professorTableInfo->setColumnCount(2);

    QStringList hLables;
    hLables<<"Code"<<"Name";
    ui->professorTableInfo->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(auto v : prof.coursesForProfessor)
    {
        ui->professorTableInfo->insertRow(rowcount);

        QTableWidgetItem *Code= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;

        Code->setText(v.getCode());
        Name->setText(v.getCourseName());

        ui->professorTableInfo->setItem(rowcount,0,Code);
        ui->professorTableInfo->setItem(rowcount,1,Name);

        rowcount++;
    }
}

void ProfessorInfoPage::on_editPushButton_clicked()
{
    QString thisId = ui->idLabel->text();
    QMap<QString,Professor>:: Iterator profIt = Professor::professors.find(thisId);
    profEditPage = new ProfessorEditPage(this,profIt);
    profEditPage->exec();
    this->close();
}

void ProfessorInfoPage::refreshTable()
{
    ui->professorTableInfo->clear();
    professorInfoTableDisplay();
}
