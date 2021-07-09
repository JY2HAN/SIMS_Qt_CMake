#ifndef SearchStuWidget_H
#define SearchStuWidget_H

#include <QWidget>
#include <QtDebug>
#include <QFile>
#include <QVector>
#include <QMessageBox>

#include "studentinfo.h"
namespace Ui {
    class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget* parent = nullptr);
    ~Search();

private:
    Ui::Search* ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();
    void on_searchButton_clicked();
};

#endif // SearchStuWidget_H
