#ifndef COURSEPAGE_H
#define COURSEPAGE_H

#include <QDialog>

namespace Ui {
class CoursePage;
}

class CoursePage : public QDialog
{
    Q_OBJECT

public:
    explicit CoursePage(QWidget *parent = nullptr);
    ~CoursePage();

private:
    Ui::CoursePage *ui;
};

#endif // COURSEPAGE_H
