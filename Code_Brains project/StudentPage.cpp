#include "StudentPage.h"
#include "ui_StudentPage.h"
#include "Student.h"
#include <QMap>

StudentPage::StudentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentPage)
{
    ui->setupUi(this);
    studentTableDisblay();
}

StudentPage::~StudentPage()
{
    delete ui;
}

void StudentPage::studentTableDisblay()
{
    ui->studentTable->setRowCount(Student::students.size());
    ui->studentTable->setColumnCount(2);

    QStringList firstTitle;
    firstTitle<<"ID"<<"Name";
    ui->studentTable->setHorizontalHeaderLabels(firstTitle);

//    QMap<QString, Student> :: Iterator It = Student::students.begin();

     int rowcount = 0;
     for(auto It : Student::students)
     {
         ui->studentTable->insertRow(rowcount);

         QTableWidgetItem *ID= new QTableWidgetItem;
         QTableWidgetItem *Name= new QTableWidgetItem;

         ID->setText(It.getID());
         Name->setText(It.getFullName());

         ui->studentTable->setItem(rowcount,0,ID);
         ui->studentTable->setItem(rowcount,1,Name);

         rowcount++;
     }
 }


    /* QMapIterator<QString, Student> It = Student::students;

    int rowcount = 0;
    while(It.hasNext())
    {
        It.next();
        ui->studentTable->insertRow(rowcount);

        QTableWidgetItem *ID= new QTableWidgetItem;
        QTableWidgetItem *Name= new QTableWidgetItem;
        ID->setText(It.key());

        Name->setText(It.value.getFullxName());

        ui->studentTable->setItem(rowcount,0,ID);
        ui->studentTable->setItem(rowcount,1,Name);

        rowcount++;

    }

}*/


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


void StudentPage::on_studentTable_cellDoubleClicked(int row, int column)
{
    QString thisId = ui->studentTable->item(row,0)->text();
    QMap<QString,Student>:: Iterator stud = Student::students.find(thisId);
    sip = new StudentInfoPage(this,stud);
    sip->exec();
}

