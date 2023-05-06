#include "CourseInfoPage.h"
#include "ui_CourseInfoPage.h"

CourseInfoPage::CourseInfoPage(QWidget *parent, QMap<QString,Course>:: Iterator cIt) :
    QDialog(parent),
    ui(new Ui::CourseInfoPage)
{
    ui->setupUi(this);

    cors = cIt.value();

    ui->nameLabel->setText(cIt->getCourseName());
    ui->codeLabel->setText(cIt->getCode());
    ui->lecHallLabel->setText(cIt->getLecHall());
    ui->dayLabel->setText(cIt->getLecDay());
    ui->timeLabel->setText(cIt->getLecTime());

    studentsTableDisplay();
    professorTableDisplay();
}

CourseInfoPage::~CourseInfoPage()
{
    delete ui;
}

void CourseInfoPage::studentsTableDisplay()
{
    ui->studentsInCourseTable->setRowCount(0);
    ui->studentsInCourseTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"Name"<<"Grade";
    ui->studentsInCourseTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(QMap<QString,float>:: Iterator It = cors.studentsGrade.begin();
        It != cors.studentsGrade.end();
        It++)
    {
        ui->studentsInCourseTable->insertRow(rowcount);

        QTableWidgetItem *Name= new QTableWidgetItem;
        QTableWidgetItem *Grade= new QTableWidgetItem;

        Name->setText(Student::students.find(It.key())->getFullName());
        Grade->setText(QString::number(It.value()));

        ui->studentsInCourseTable->setItem(rowcount,0,Name);
        ui->studentsInCourseTable->setItem(rowcount,1,Grade);

        rowcount++;
    }
}


void CourseInfoPage::professorTableDisplay()
{
    ui->profInCourseTable->setColumnCount(2);

    QStringList hLables;
    hLables<<"ID"<<"Name";
    ui->profInCourseTable->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(auto p : cors.professorsForCourse){
        ui->profInCourseTable->insertRow(rowcount);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;

        ID->setText(Professor::professors.find(p)->getID());
        Name->setText(Professor::professors.find(p)->getFullName());

        ui->profInCourseTable->setItem(rowcount,0,ID);
        ui->profInCourseTable->setItem(rowcount,1,Name);

        rowcount++;
    }
}


void CourseInfoPage::on_editPushButton_clicked()
{
    QString thisId = ui->codeLabel->text();
    QMap<QString,Course>:: Iterator corsIt = Course::courses.find(thisId);
    corsEditPage = new CourseEditPage(this,corsIt);
    corsEditPage->show();
    this->close();
}
