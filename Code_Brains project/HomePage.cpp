#include "HomePage.h"
#include "ui_HomePage.h"
#include "SignupPage.h"
#include "admin.h"
#include "professor.h"
#include "course.h"
#include "student.h"
#include "AddCoursePage.h"
#include "AddStudentPage.h"
#include "AddProfessorPage.h"
#include "LoginPage.h"

#include <QCompleter>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>

HomePage::HomePage(QString name, QString username ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    Admin *admin = new Admin();
    ui->helloLabel->setText("Hello " + name);
    HomePage::username = username;
    HomePage::name = name;

    studentTableDisblay();
    professorTableDisplay();
    courseTableDisplay();
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::studentTableDisblay()
{
    ui->studentTable->setRowCount(0);
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

void HomePage::professorTableDisplay()
{
    ui->professorTable->setRowCount(0);
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

void HomePage::courseTableDisplay()
{
    ui->courseTable->setRowCount(0);
    ui->courseTable->setColumnCount(2);

    QStringList firstTitle;
    firstTitle<<"Code"<<"Name";
    ui->courseTable->setHorizontalHeaderLabels(firstTitle);

//    QMap<QString, Student> :: Iterator It = Student::students.begin();

     int rowcount = 0;
     for(auto It : Course::courses)
     {
         ui->courseTable->insertRow(rowcount);

         QTableWidgetItem *Code= new QTableWidgetItem;
         QTableWidgetItem *Name= new QTableWidgetItem;

         Code->setText(It.getCode());
         Name->setText(It.getCourseName());

         ui->courseTable->setItem(rowcount,0,Code);
         ui->courseTable->setItem(rowcount,1,Name);

         rowcount++;
    }
}


void HomePage::on_studentTable_cellDoubleClicked(int row, int column)
{
    QString thisId = ui->studentTable->item(row,0)->text();
    QMap<QString,Student>:: Iterator stud = Student::students.find(thisId);
    sip = new StudentInfoPage(this,stud);
    sip->show();
}


void HomePage::on_professorTable_cellDoubleClicked(int row, int column)
{
    QString thisId = ui->professorTable->item(row,0)->text();
    QMap<QString,Professor>:: Iterator prof = Professor::professors.find(thisId);
    pip = new ProfessorInfoPage(this,prof);
    pip->show();
}


void HomePage::on_courseTable_cellDoubleClicked(int row, int column)
{
    QString thisCode = ui->courseTable->item(row,0)->text();
    QMap<QString,Course>:: Iterator cors = Course::courses.find(thisCode);
    cip = new CourseInfoPage(this,cors);
    cip->show();
}


void HomePage::on_logoutButton_clicked()
{
    LoginPage *loginPage = new LoginPage;
     this->close();
    loginPage->show();

}


void HomePage::on_infoButton_clicked()
{

    adminInfoPage = new AdminInfoPage(name, username, this);
    adminInfoPage->show();

}


void HomePage::on_refreshPButton_clicked()
{
    ui->professorTable->clear();
    professorTableDisplay();
}


void HomePage::on_RefreshCButton_clicked()
{
    ui->courseTable->clear();
    courseTableDisplay();
}


void HomePage::on_RefreshSButton_clicked()
{
    ui->studentTable->clear();
    studentTableDisblay();
}


void HomePage::on_addStudent_clicked()
{
    AddStudentPage *addStudent;
    addStudent = new AddStudentPage(this);
    addStudent->show();
    addStudent->exec();
}


void HomePage::on_addCourse_clicked()
{
    AddCoursePage *addCourse;
    addCourse = new AddCoursePage(this);
    addCourse->show();
    addCourse->exec();
}


void HomePage::on_addProfessor_clicked()
{
    AddProfessorPage *addproff;
    addproff = new AddProfessorPage(this);
    addproff->show();
    addproff->exec();
}

void HomePage::on_lineEdit_stud_textChanged(const QString &arg1)
{
    if(!ui->lineEdit_stud->text().isEmpty()){
        QStringList list;
        foreach (QTableWidgetItem *item, ui->studentTable->findItems(ui->lineEdit_stud->text(), Qt::MatchContains)) {
            list<< item->text();
        }

        QCompleter *complete = new QCompleter(list);
        complete->setCaseSensitivity(Qt::CaseInsensitive);
        complete->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->lineEdit_stud->setCompleter(complete);
    }


}


void HomePage::on_lineEdit_course_textChanged(const QString &arg1)
{
    if(!ui->lineEdit_course->text().isEmpty()){
        QStringList list;
        foreach (QTableWidgetItem *item, ui->courseTable->findItems(ui->lineEdit_course->text(), Qt::MatchContains)) {
            list<< item->text();
        }

        QCompleter *complete = new QCompleter(list);
        complete->setCaseSensitivity(Qt::CaseInsensitive);
        complete->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->lineEdit_course->setCompleter(complete);
    }

}


void HomePage::on_lineEdit_prof_textChanged(const QString &arg1)
{
    if(!ui->lineEdit_prof->text().isEmpty()){
        QStringList list;
        foreach (QTableWidgetItem *item, ui->professorTable->findItems(ui->lineEdit_prof->text(), Qt::MatchContains)) {
            list<< item->text();

        }

        QCompleter *complete = new QCompleter(list);
        complete->setCaseSensitivity(Qt::CaseInsensitive);
        complete->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->lineEdit_prof->setCompleter(complete);
    }

}




void HomePage::on_search_stud_clicked()
{
    if(!ui->lineEdit_stud->text().isEmpty()){
        QString name = ui->lineEdit_stud->text().toLower();
        int row ;
        QTableWidgetItem *item1;
        QTableWidgetItem *item2;
        for (row =0 ; row < ui->studentTable->rowCount(); row++){
          item1 =  ui->studentTable->item(row, 0);
          item2 =  ui->studentTable->item(row, 1);
          ui->studentTable->setRowHidden(row, name != item1->text().toLower() && name != item2->text().toLower());
        }

    }
    else
    QMessageBox::information(this, "warning", "please write something to search");
}


void HomePage::on_search_course_clicked()
{
    if(!ui->lineEdit_course->text().isEmpty()){
        QString name = ui->lineEdit_course->text().toLower();
        int row ;
        QTableWidgetItem *item1;
        QTableWidgetItem *item2;
        for (row =0 ; row < ui->courseTable->rowCount(); row++){
            item1 =  ui->courseTable->item(row, 0);
            item2 =  ui->courseTable->item(row, 1);
          ui->courseTable->setRowHidden(row, name != item1->text().toLower() && name != item2->text().toLower());
        }
    }
    else
    QMessageBox::information(this, "warning", "please write something to search");
}


void HomePage::on_search_prof_clicked()
{
    if(!ui->lineEdit_prof->text().isEmpty()){
        QString name = ui->lineEdit_prof->text().toLower();
        int row ;
        QTableWidgetItem *item1;
        QTableWidgetItem *item2;
        for (row =0 ; row < ui->professorTable->rowCount(); row++){
            item1 =  ui->professorTable->item(row, 0);
            item2 =  ui->professorTable->item(row, 1);
          ui->professorTable->setRowHidden(row, name != item1->text().toLower() && name != item2->text().toLower());
        }
    }
    else
    QMessageBox::information(this, "warning", "please write something to search");
}



void HomePage::on_delete_stud_clicked()
{

    QString deletedID =ui->studentTable->item(ui->studentTable->currentRow(),0)->text();
            Student::students.remove(deletedID);
            ui->studentTable->removeRow(ui->studentTable->currentRow());
}

void HomePage::on_delete_prof_clicked()
{
    QString deletedID =ui->professorTable->item(ui->professorTable->currentRow(),0)->text();
            Professor::professors.remove(deletedID);
            ui->professorTable->removeRow(ui->professorTable->currentRow());
}


void HomePage::on_delete_course_clicked()
{
    QString deletedID =ui->courseTable->item(ui->courseTable->currentRow(),0)->text();
    LecHall::lecHalls.find(Course::courses.find(deletedID)->getLecHall())->nonreserve(Course::courses.find(deletedID)->getLecDay(), Course::courses.find(deletedID)->getLecTime());
    Course::courses.remove(deletedID);
    ui->courseTable->removeRow(ui->courseTable->currentRow());

}

void HomePage::on_save_stud_clicked()
{
    QFile file(QCoreApplication::applicationDirPath() + "/csvStud.csv");
    if(file.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream out(&file);
//      QStringList listtext ;
        out << " ID " << "," << " Name " << "," << "Phone \t" << "," << "E-mail \t" <<
               "," << "TotalGrade \t" << "," << "CourseID" << "," << "Grade" << ","  ;
        out<< "\n";
            for(auto it : Student::students){
               out<< it.getID() << "," << it.getFullName() << "," << it.getMobile() << "," << it.getMail() << "," << it.getTotalGrade() << "," ;
                    for(QMap<QString, float>::Iterator c = it.grades.begin() ; c != it.grades.end() ; c++){
                        out << c.key() << "," << c.value()<< "," ;
                    }
               out<< "\n";
            }

//        for(int rcount = 0; rcount<ui->studentTable->rowCount(); rcount++){
//            listtext.clear();
//            for(int ccount = 0; ccount<ui->studentTable->columnCount(); ccount++){
//                listtext << "\" "+ui->studentTable->horizontalHeaderItem(ccount)->data(Qt::DisplayRole).toString() + "\" ";
//                listtext << "\" "+ui->studentTable->item(rcount,ccount)->text()+ "\" ";
//            }
//            out << listtext.join( "," )+"\n";
//        }
        file.flush();
        file.close();
        QMessageBox::information(this, "Saved", "File saved in " + QCoreApplication::applicationDirPath() + "/csvStud.csv");
    }
    else{
        QMessageBox::warning(this, "warning", "File is not open");
    }

}


void HomePage::on_save_course_clicked()
{
    QFile file(QCoreApplication::applicationDirPath() + "/csvCourse.csv");
    if(file.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream out(&file);
//      QStringList listtext ;
        out << " Code " << "," << " Name " << "," << "Hall \t" << "," << "Time \t" <<
               "," << "professors \t" << "," ;
        out<< "\n";
                for(auto it : Course::courses){
                    out << it.getCode() << "," << it.getCourseName() << "," << it.getLecHall() << "," << it.getLecTime() << "," ;
                        for(QVector<QString>::Iterator c = it.professorsForCourse.begin() ; c != it.professorsForCourse.end() ; c++ ){
                            out << *c << "," ;
                        }
                out<< "\n";
                }


//        for(int rcount = 0; rcount<ui->courseTable->rowCount(); rcount++){
//            listtext.clear();
//            for(int ccount = 0; ccount<ui->courseTable->columnCount(); ccount++){
//                listtext << "\" "+ui->courseTable->horizontalHeaderItem(ccount)->data(Qt::DisplayRole).toString() + "\" ";
//                listtext << "\" "+ui->courseTable->item(rcount,ccount)->text()+ "\" ";
//            }
//            out << listtext.join( "," )+"\n";
//        }
        file.flush();
        file.close();
        QMessageBox::information(this, "Saved", "File saved in " + QCoreApplication::applicationDirPath() + "/csvCourse.csv");
    }
    else{
        QMessageBox::warning(this, "warning", "File is not open");
    }
}


void HomePage::on_save_prof_clicked()
{
    QFile file(QCoreApplication::applicationDirPath() + "/csvProf.csv");
    if(file.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream out(&file);
//      QStringList listtext ;
        out << " ID " << "," << " Title " << "," << " Name " << "," << "Phone \t" << "," << "Email \t" <<
               "," << "Courses \t" << "," ;
        out<< "\n";
                for (auto it : Professor::professors){
                    out<< it.getID() << "," << it.getTitle() << "," << it.getFullName() << "," <<
                          it.getMobile() << "," << it.getMail() << "," ;
                        for(QVector<Course>::Iterator c  = it.coursesForProfessor.begin(); c != it.coursesForProfessor.end() ; c++ ){
                               out << c->getCode() << "," << c->getCourseName() << "," ;
                        }
                out<< "\n";
                }

//        for(int rcount = 0; rcount<ui->professorTable->rowCount(); rcount++){
//            listtext.clear();
//            for(int ccount = 0; ccount<ui->professorTable->columnCount(); ccount++){
//                listtext << "\" "+ui->professorTable->horizontalHeaderItem(ccount)->data(Qt::DisplayRole).toString() + "\" ";
//                listtext << "\" "+ui->professorTable->item(rcount,ccount)->text()+ "\" ";
//            }
//            out << listtext.join( "," )+"\n";
//        }
        file.flush();
        file.close();
        QMessageBox::information(this, "Saved", "File saved in " + QCoreApplication::applicationDirPath() + "/csvProf.csv");
    }
    else{
        QMessageBox::warning(this, "warning", "File is not open");
    }
}


void HomePage::on_addAdminButton_clicked()
{
    SignupPage *sign = new SignupPage(this);
    sign->show();
    hide();
}

