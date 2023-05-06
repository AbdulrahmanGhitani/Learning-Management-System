#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
//#include "CoursePage.h"
//#include "ProfessorPage.h"
//#include "StudentPage.h"
#include "StudentInfoPagee.h"
#include "ProfessorInfoPage.h"
#include "CourseInfoPage.h"

#include "AdminInfoPage.h"



namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QString name,QString username,QWidget *parent = nullptr);
    ~HomePage();

    void studentTableDisblay();

    void professorTableDisplay();

    void courseTableDisplay();


private slots:


    void on_logoutButton_clicked();

    void on_infoButton_clicked();

    void on_studentTable_cellDoubleClicked(int row, int column);

    void on_professorTable_cellDoubleClicked(int row, int column);

    void on_courseTable_cellDoubleClicked(int row, int column);

    void on_refreshPButton_clicked();

    void on_RefreshCButton_clicked();

    void on_RefreshSButton_clicked();

    void on_addStudent_clicked();

    void on_addCourse_clicked();

    void on_addProfessor_clicked();

    void on_lineEdit_stud_textChanged(const QString &arg1);

    void on_lineEdit_course_textChanged(const QString &arg1);

    void on_lineEdit_prof_textChanged(const QString &arg1);

    void on_search_stud_clicked();

    void on_search_prof_clicked();

    void on_delete_prof_clicked();

    void on_search_course_clicked();

    void on_delete_stud_clicked();

    void on_delete_course_clicked();

    void on_save_stud_clicked();

    void on_save_course_clicked();

    void on_save_prof_clicked();

    void on_addAdminButton_clicked();

private:
    Ui::HomePage *ui;
//    CoursePage *coursePage;
//    ProfessorPage *professorPage;
//    StudentPage *studentPage;
    AdminInfoPage *adminInfoPage;

    StudentInfoPage *sip;
    ProfessorInfoPage *pip;
    CourseInfoPage *cip;

    QString username;
    QString name;

};

#endif // HOMEPAGE_H
