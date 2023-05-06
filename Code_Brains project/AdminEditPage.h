#ifndef ADMINEDITPAGE_H
#define ADMINEDITPAGE_H

#include <QDialog>
namespace Ui {
class AdminEditPage;
}

class AdminEditPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEditPage(QString name, QString username,QWidget *parent = nullptr);
    ~AdminEditPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminEditPage *ui;
    QWidget *parent = nullptr;
    QString username;
    QString name;
};

#endif // ADMINEDITPAGE_H
