#ifndef STUDENTEDITPAGE_H
#define STUDENTEDITPAGE_H

#include <QDialog>
#include "student.h"

namespace Ui {
class StudentEditPage;
}

class StudentEditPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentEditPage(QWidget *parent = nullptr,QMap<QString,Student>:: Iterator stud = {});
    ~StudentEditPage();

    void studentCoursesDisplay();
    void allCoursesDisplay();
    void courseComboBoxDisplay();
    void setValidator();
private slots:
    void on_savePushButton_clicked();
    void on_allCoursesTable_cellDoubleClicked(int row, int column);
    void on_setPushButton_clicked();
    void on_studentCoursesTable_cellDoubleClicked(int row, int column);

private:
    Ui::StudentEditPage *ui;

    Student *studPtr;
     QString oldID;
int rowcount =0;
};

#endif // STUDENTEDITPAGE_H
