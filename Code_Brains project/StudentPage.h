#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QDialog>
#include "StudentInfoPagee.h"

namespace Ui {
class StudentPage;
}

class StudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr);
    ~StudentPage();

    void studentTableDisblay();


private slots:

    void on_studentTable_cellDoubleClicked(int row, int column);

private:
    Ui::StudentPage *ui;
    StudentInfoPage *sip;
};

#endif // STUDENTPAGE_H
