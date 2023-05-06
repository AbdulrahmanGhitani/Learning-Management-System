#ifndef COURSEINFOPAGE_H
#define COURSEINFOPAGE_H
#include "course.h"
#include "CourseEditPage.h"

#include <QDialog>

namespace Ui {
class CourseInfoPage;
}

class CourseInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit CourseInfoPage(QWidget *parent = nullptr, QMap<QString,Course>:: Iterator cIt = {});
    ~CourseInfoPage();

    void studentsTableDisplay();
    void professorTableDisplay();

    Course cors;

private slots:
    void on_editPushButton_clicked();

private:
    Ui::CourseInfoPage *ui;
    CourseEditPage *corsEditPage;
};

#endif // COURSEINFOPAGE_H
