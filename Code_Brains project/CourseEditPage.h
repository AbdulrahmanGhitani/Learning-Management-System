#ifndef COURSEEDITPAGE_H
#define COURSEEDITPAGE_H

#include <QDialog>

#include "course.h"
#include "LecHall.h"
#include "student.h"
#include "professor.h"

namespace Ui {
class CourseEditPage;
}

class CourseEditPage : public QDialog
{
    Q_OBJECT

public:
    explicit CourseEditPage(QWidget *parent = nullptr,QMap<QString,Course>:: Iterator corsIt = {});
    ~CourseEditPage();

    void lecHallComboboxdisplay();
    void dayComboboxdisplay();
    void timeComboboxdisplay();

    void allStdTableDisplay();
    void allPrfTableDisplay();

    void addedStdTableDisplay();
    void addedPrfTableDisplay();
    void setValidator();

private slots:
    void on_SavePushButton_clicked();

    void on_allStudentsTable_cellDoubleClicked(int row, int column);

    void on_allProfessorsTable_cellDoubleClicked(int row, int column);

    void on_lecHallCBox_textActivated(const QString &arg1);

    void on_dayComboBox_textActivated(const QString &arg1);

    void on_addedStudentsTable_cellDoubleClicked(int row, int column);

    void on_addedProfessorsTable_cellDoubleClicked(int row, int column);

private:
    Ui::CourseEditPage *ui;
QString oldCode;
    Course *corsPtr;
};

#endif // COURSEEDITPAGE_H
