#ifndef PROFESSOREDITPAGE_H
#define PROFESSOREDITPAGE_H

#include <QDialog>

#include "professor.h"

namespace Ui {
class ProfessorEditPage;
}

class ProfessorEditPage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfessorEditPage(QWidget *parent = nullptr,QMap<QString,Professor>:: Iterator profIt = {});
//    explicit ProfessorEditPage(QWidget *parent = nullptr,Professor &passedProf() = nullptr);
    ~ProfessorEditPage();

  //  void courseComboBoxDisplay();
      void allCoursesTableDisplay();
      void professorCourseTableDisplay();
      void setValidator();

private slots:

    void on_allCoursesTable_cellDoubleClicked(int row, int column);

    void on_savePushButton_clicked();

    void on_professorCourseTable_cellDoubleClicked(int row, int column);

private:
    Ui::ProfessorEditPage *ui;
    Professor *profPtr;
     QString oldID;
     int rowcount=0;
};

#endif // PROFESSOREDITPAGE_H
