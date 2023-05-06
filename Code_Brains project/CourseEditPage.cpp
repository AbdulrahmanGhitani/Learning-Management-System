#include "CourseEditPage.h"
#include "ui_CourseEditPage.h"
#include "qregularexpression.h"
#include "qvalidator.h"
#include<QMessageBox>
CourseEditPage::CourseEditPage(QWidget *parent,QMap<QString,Course>:: Iterator corsIt) :
    QDialog(parent),
    ui(new Ui::CourseEditPage)
{
    ui->setupUi(this);

    oldCode=corsIt->getCode();

//    ui->FLNameLabel->setText(corsIt->getCourseName());
    ui->name_LineEdit->setText(corsIt->getCourseName());
    ui->ID_LineEdit->setText(corsIt->getCode());

    LecHall::lecHalls.find(corsIt->getLecHall())->nonreserve(corsIt->getLecDay(),corsIt->getLecTime());

    corsPtr =& corsIt.value();

    lecHallComboboxdisplay();
    dayComboboxdisplay();
    timeComboboxdisplay();

    allStdTableDisplay();
    allPrfTableDisplay();

    addedStdTableDisplay();
    addedPrfTableDisplay();
    setValidator();
}

void CourseEditPage::setValidator(){
    QRegularExpression name("[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+\\s+[a-z-A-Z]+" );
    QRegularExpressionValidator *v = new QRegularExpressionValidator(name, this) ;
    ui->name_LineEdit->setValidator(v);
    QRegularExpression code("[A-Z]+[0-9]\\d{2}+\\S" );
    QRegularExpressionValidator *v2 = new QRegularExpressionValidator(code, this) ;
    ui->ID_LineEdit->setValidator(v2);
}


CourseEditPage::~CourseEditPage()
{
    delete ui;
}

void CourseEditPage::lecHallComboboxdisplay()
{
    QStringList lecHallsList;

    for(auto v : LecHall::lecHalls)
        lecHallsList.push_front(v.getName());

    for(int lh = 0; lh < lecHallsList.size(); lh++)
        ui->lecHallCBox->addItem(lecHallsList[lh]);
}

void CourseEditPage::dayComboboxdisplay()
{
    QStringList days;

    days.push_front("Thursday");
    days.push_front("Wednesday");
    days.push_front("Tuesday");
    days.push_front("Monday");
    days.push_front("Sunday");
    days.push_front("Saturday");

    for(int d = 0; d < days.size(); d++)
        ui->dayComboBox->addItem(days[d]);
}

void CourseEditPage::timeComboboxdisplay()
{
    QStringList timeAvalList;

    QString lecHallSelected = ui->lecHallCBox->currentText();

    QMap<QString,LecHall> :: Iterator lhIt = LecHall::lecHalls.find(lecHallSelected);

    QString daySelected =ui->dayComboBox->currentText();


    timeAvalList = lhIt->timesAval(daySelected);

    for(int lh = 0; lh < timeAvalList.size(); lh++)
        ui->timeComboBox->addItem(timeAvalList[lh]);
    if(ui->timeComboBox->count() == 0)
        ui->timeComboBox->addItem("The Hall is reserved all the day");
}

void CourseEditPage::allStdTableDisplay()
{
    ui->allStudentsTable->setRowCount(0);
    ui->allStudentsTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"Name"<<"Grade";
    ui->allStudentsTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(QMap<QString,Student>:: Iterator It = Student::students.begin();
        It!= Student::students.end();
        It++)
    {
        ui->allStudentsTable->insertRow(rowcount);

            QTableWidgetItem *ID= new QTableWidgetItem;
            QTableWidgetItem *Name= new QTableWidgetItem;

            ID->setText(It->getID());
            Name->setText(It->getFullName());

            ui->allStudentsTable->setItem(rowcount,0,ID);
            ui->allStudentsTable->setItem(rowcount,1,Name);

            rowcount++;
    }
}

void CourseEditPage::allPrfTableDisplay()
{
    ui->allProfessorsTable->setRowCount(0);
    ui->allProfessorsTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"ID"<<"Name";
    ui->allProfessorsTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(QMap<QString,Professor>:: Iterator It = Professor::professors.begin();
        It != Professor::professors.end();
        It++)
    {
        ui->allProfessorsTable->insertRow(rowcount);

            QTableWidgetItem *ID= new QTableWidgetItem;
            QTableWidgetItem *Name= new QTableWidgetItem;

            ID->setText(It.key());
            Name->setText(It->getFullName());

            ui->allProfessorsTable->setItem(rowcount,0,ID);
            ui->allProfessorsTable->setItem(rowcount,1,Name);

            rowcount++;
    }
}

void CourseEditPage::addedStdTableDisplay()
{
    ui->addedStudentsTable->setRowCount(0);
    ui->addedStudentsTable->setColumnCount(3);

    QStringList hLables;
    hLables<<"Name"<<"Grade";
    ui->addedStudentsTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(QMap<QString,float>:: Iterator It = corsPtr->studentsGrade.begin();
        It != corsPtr->studentsGrade.end();
        It++)
    {
        ui->addedStudentsTable->insertRow(rowcount);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;
        QTableWidgetItem *Grade= new QTableWidgetItem;

        ID->setText(It.key());
        Name->setText(Student::students.find(It.key())->getFullName());
        Grade->setText(QString::number(It.value()));

        ui->addedStudentsTable->setItem(rowcount,0,ID);
        ui->addedStudentsTable->setItem(rowcount,1,Name);
        ui->addedStudentsTable->setItem(rowcount,2,Grade);

        rowcount++;
    }
}

void CourseEditPage::addedPrfTableDisplay()
{
    ui->addedProfessorsTable->setRowCount(0);
    ui->addedProfessorsTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"ID"<<"Name";
    ui->addedProfessorsTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;

    for(auto p : corsPtr->professorsForCourse){
            ui->addedProfessorsTable->insertRow(rowcount);

            QTableWidgetItem *ID= new QTableWidgetItem;
            QTableWidgetItem *Name= new QTableWidgetItem;

            ID->setText(p);
            Name->setText(Professor::professors.find(p)->getFullName());

            ui->addedProfessorsTable->setItem(rowcount,0,ID);
            ui->addedProfessorsTable->setItem(rowcount,1,Name);

            rowcount++;
    }
}


void CourseEditPage::on_SavePushButton_clicked()
{
    if(ui->ID_LineEdit->text().isEmpty(),ui->ID_LineEdit->text().isEmpty())
    {
        QMessageBox::critical(this,"Erorr","Empty line");
        return;
    }

    corsPtr->setCourseName(ui->name_LineEdit->text());
    corsPtr->setLecHall(ui->lecHallCBox->currentText());
    corsPtr->setLecDay(ui->dayComboBox->currentText());
    corsPtr->setLecTime(ui->timeComboBox->currentText());

    int studNum = ui->addedStudentsTable->rowCount();
    int profNum = ui->addedProfessorsTable->rowCount();

        for(int s = 0; s < studNum; s++){
            QString studId = ui->addedStudentsTable->item(s,0)->text();
            corsPtr->studentsGrade.insert(studId,0);
        }

        for(int p = 0; p < profNum; p++){
            QString profId = ui->addedProfessorsTable->item(p,0)->text();
            corsPtr->professorsForCourse.push_front(profId);
        }

        corsPtr->setCode(ui->ID_LineEdit->text());

        if(ui->ID_LineEdit->text() != oldCode)
        {
            if(Course::courses.find(ui->ID_LineEdit->text()) != Course::courses.end())
            {
                QMessageBox::critical(this,"ERROR","This code is already used ");
                return;
            }
            Course::courses.insert(corsPtr->getCode(),*corsPtr);
            Course::courses.remove(oldCode);
        }


    LecHall::lecHalls.find(corsPtr->getLecHall())->reserve(corsPtr->getLecDay(),corsPtr->getLecTime());

    this->close();
}



void CourseEditPage::on_allStudentsTable_cellDoubleClicked(int row, int column)
{
    QString addThisStud = ui->allStudentsTable->item(row,0)->text();
    QList<QTableWidgetItem*> l = ui->addedStudentsTable->findItems(addThisStud,Qt::MatchFlag());

if(l.count()==0)
{

    int rowcount = ui->addedStudentsTable->rowCount();

    ui->addedStudentsTable->insertRow(rowcount);

    QString thisId = ui->allStudentsTable->item(row,0)->text();
    QMap<QString,Student>:: Iterator stud = Student::students.find(thisId);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;
        QTableWidgetItem *Grade= new QTableWidgetItem;

        ID->setText(stud->getID());
        Name->setText(stud->getFullName());
        Grade->setText(QString::number(stud->grades.find(corsPtr->getCode()).value()));

        ui->addedStudentsTable->setItem(rowcount,0,ID);
        ui->addedStudentsTable->setItem(rowcount,1,Name);
        ui->addedStudentsTable->setItem(rowcount,2,Grade);
}

else
{
   QMessageBox::critical(this,"ERROR","This student already exists");
}

}


void CourseEditPage::on_allProfessorsTable_cellDoubleClicked(int row, int column)
{
     QString addThisProf = ui->allProfessorsTable->item(row,0)->text();
     QList<QTableWidgetItem*> l = ui->addedProfessorsTable->findItems(addThisProf,Qt::MatchFlag());

 if(l.count()==0)
 {

    int rowcount = ui->addedProfessorsTable->rowCount();

    ui->addedProfessorsTable->insertRow(rowcount);

    QString thisId = ui->allProfessorsTable->item(row,0)->text();
    QMap<QString,Professor>:: Iterator prof = Professor::professors.find(thisId);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;

        ID->setText(prof->getID());
        Name->setText(prof->getFullName());

        ui->addedProfessorsTable->setItem(rowcount,0,ID);
        ui->addedProfessorsTable->setItem(rowcount,1,Name);
}
 else
 {
    QMessageBox::critical(this,"ERROR","This professor already exists");
 }
 }




void CourseEditPage::on_lecHallCBox_textActivated(const QString &arg1)
{
    ui->timeComboBox->clear();
    timeComboboxdisplay();
}


void CourseEditPage::on_dayComboBox_textActivated(const QString &arg1)
{
    ui->timeComboBox->clear();
    timeComboboxdisplay();
}


void CourseEditPage::on_addedStudentsTable_cellDoubleClicked(int row, int column)
{

    ui->addedStudentsTable->removeRow(ui->addedStudentsTable->currentRow());
}


void CourseEditPage::on_addedProfessorsTable_cellDoubleClicked(int row, int column)
{
        ui->addedProfessorsTable->removeRow(ui->addedProfessorsTable->currentRow());
}

