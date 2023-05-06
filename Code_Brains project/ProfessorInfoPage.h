#ifndef PROFESSORINFOPAGE_H
#define PROFESSORINFOPAGE_H

#include "professor.h"
#include "ProfessorEditPage.h"

#include <QDialog>

namespace Ui {
class ProfessorInfoPage;
}

class ProfessorInfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessorInfoPage(QWidget *parent = nullptr,QMap<QString,Professor>:: Iterator profIt = {});
    ~ProfessorInfoPage();

    void professorInfoTableDisplay();
    Professor prof;

private slots:

    void on_editPushButton_clicked();

    void refreshTable();

private:
    Ui::ProfessorInfoPage *ui;
    ProfessorEditPage *profEditPage;
};

#endif // PROFESSORINFOPAGE_H
