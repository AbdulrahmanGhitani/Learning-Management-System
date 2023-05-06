#ifndef PROFESSORPAGE_H
#define PROFESSORPAGE_H

#include "ProfessorInfoPage.h"

#include <QDialog>

namespace Ui {
class ProfessorPage;
}

class ProfessorPage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessorPage(QWidget *parent = nullptr);
    ~ProfessorPage();

    void professorTableDisplay();

private slots:
    void on_professorTable_cellDoubleClicked(int row, int column);

private:
    Ui::ProfessorPage *ui;
    ProfessorInfoPage *pip;
};

#endif // PROFESSORPAGE_H
