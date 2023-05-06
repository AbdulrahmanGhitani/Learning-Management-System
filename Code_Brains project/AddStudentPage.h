#ifndef ADDSTUDENTPAGE_H
#define ADDSTUDENTPAGE_H
#include"student.h"
#include <QDialog>

namespace Ui {
class AddStudentPage;
}

class AddStudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentPage(QWidget *parent = nullptr);
    void setValidator();
    ~AddStudentPage();

private slots:
    void on_buttomadd_clicked();

private:
    Ui::AddStudentPage *ui;
};

#endif // ADDSTUDENTPAGE_H
