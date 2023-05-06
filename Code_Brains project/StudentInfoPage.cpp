#include "StudentInfoPagee.h"
#include "ui_StudentInfoPage.h"
#include "student.h"
#include "course.h"


StudentInfoPage::StudentInfoPage(QWidget *parent, QMap<QString,Student> :: Iterator stud) :
    QDialog(parent),
    ui(new Ui::StudentInfoPage)
{
    ui->setupUi(this);

    sit = stud.value();

    ui->FLNameLabel->setText(stud->getFirstLastName());
    ui->nameLabel->setText(stud->getFullName());
    ui->idLabel->setText(stud->getID());
    ui->phoneLabel->setText(stud->getMobile());
    ui->emailLabel->setText(stud->getMail());
    ui->tGradeLabel->setText(QString::number(stud->calcTotalGrade()));

    studentInfoTableDisplay();

}

StudentInfoPage::~StudentInfoPage()
{
    delete ui;
}


void StudentInfoPage::studentInfoTableDisplay()
{

    ui->studentTableInfo->setColumnCount(2);

    QStringList hLables;
    hLables<<"Name"<<"Grade";
    ui->studentTableInfo->setHorizontalHeaderLabels(hLables);

    int rowcount = 0;
    for(QMap<QString,float>:: Iterator It = sit.grades.begin();
        It!= sit.grades.end();
        It++)
    {
        ui->studentTableInfo->insertRow(rowcount);

        QTableWidgetItem *Name= new QTableWidgetItem;
        QTableWidgetItem *Grade= new QTableWidgetItem;

        Name->setText(Course::courses.find(It.key())->getCourseName());
        Grade->setText(QString::number(It.value()));

        ui->studentTableInfo->setItem(rowcount,0,Name);
        ui->studentTableInfo->setItem(rowcount,1,Grade);

        rowcount++;
    }
}

void StudentInfoPage::on_editPushButton_clicked(){

    QString thisId = ui->idLabel->text();
    QMap<QString,Student>:: Iterator stud = Student::students.find(thisId);
    studEditPage = new StudentEditPage(this,stud);
    studEditPage->exec();
}


/*void StudentInfoPage::studentInfoTableDisplay()
{

 //  ui->studentTableInfo->setRowCount(Student::students.);



    {
        ui->tableWidget->setRowCount(m.size());
        ui->tableWidget->setColumnCount(2);
        QStringList hLables;
        hLables<<"ID"<<"Name";
        ui->tableWidget->setHorizontalHeaderLabels(hLables);

       QMapIterator<int,QString> It(m);

    int rowcount=0;
    while(It.hasNext())
    {
        It.next();
        ui->tableWidget->insertRow(rowcount);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;
    ID->setText(QString::number(It.key()));
    Name->setText(It.value());

        ui->tableWidget->setItem(rowcount,0,ID);
        ui->tableWidget->setItem(rowcount,1,Name);

        rowcount++;
    }




//    for(int i=0;i<ui->tableWidget->rowCount();i++)
//    {
//        It.next();
//        item = new QTableWidgetItem;
//            item->setText(It.key());
//            ui->tableWidget->setItem(i,0,item);
//    }
//    It.toFront();
//    for(int i=0;i<ui->tableWidget->rowCount();i++)
//    {
//            It.next();
//            item = new QTableWidgetItem;
//            item->setText(It.value());
//            ui->tableWidget->setItem(i,1,item);
//    }


    }

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

                        ui->label_2->setText("ID: "+ ui->tableWidget->item(row,0)->text() +"<br>"+
                         "Name: "+*m2.find(ui->tableWidget->item(row,0)->text())+"<br>"+""
                         );
}


                   void MainWindow::on_pushButton_clicked()
                   {
                   //secDialog second;
                   //second.setModal(true);
                   //second.exec();

                   //hide();
                   second =new secDialog(this);
                       second->show();
                     }



}*/
