#ifndef SortStuWidget_H
#define SortStuWidget_H

#include <QWidget>
#include <QButtonGroup>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "StudentInfo.h"

namespace Ui {
    class Sort;
}

class Sort : public QWidget
{
    Q_OBJECT

public:
    explicit Sort(QWidget* parent = nullptr);
    ~Sort();

private:
    Ui::Sort* ui;
    QButtonGroup* sortButtonGroup;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //返回菜单
    void on_sortButton_clicked();   //排序
};

#endif // SortStuWidget_H
