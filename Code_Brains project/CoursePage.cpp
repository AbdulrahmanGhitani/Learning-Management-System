#include "CoursePage.h"
#include "ui_CoursePage.h"

CoursePage::CoursePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoursePage)
{
    ui->setupUi(this);
}

CoursePage::~CoursePage()
{
    delete ui;
}
