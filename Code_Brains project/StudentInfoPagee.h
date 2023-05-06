#ifndef STUDENTINFOPAGEE_H
#define STUDENTINFOPAGEE_H

#include <QDialog>
#include "student.h"
#include "StudentEditPage.h"

namespace Ui {
class StudentInfoPage;
}

class StudentInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfoPage(QWidget *parent = nullptr,QMap<QString,Student>:: Iterator stud = {});
    ~StudentInfoPage();

    void studentInfoTableDisplay();

    Student sit;

private slots:

    void on_editPushButton_clicked();

private:
    Ui::StudentInfoPage *ui;
    StudentEditPage *studEditPage;

};

#endif // STUDENTINFOPAGEE_H
