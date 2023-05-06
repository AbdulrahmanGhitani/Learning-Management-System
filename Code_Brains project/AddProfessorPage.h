#ifndef ADDPROFESSORPAGE_H
#define ADDPROFESSORPAGE_H
#include"professor.h"
#include <QDialog>

namespace Ui {
class AddProfessorPage;
}

class AddProfessorPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddProfessorPage(QWidget *parent = nullptr);
    void setValidator();
    ~AddProfessorPage();

private slots:
    void on_bottum_add_clicked();

private:
    Ui::AddProfessorPage *ui;
};

#endif // ADDPROFESSORPAGE_H
