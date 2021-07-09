#ifndef ModifyStuWidget_H
#define ModifyStuWidget_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QVector>
#include "StudentInfo.h"

namespace Ui {
    class Modify;
}

class Modify : public QWidget
{
    Q_OBJECT

public:
    explicit Modify(QWidget* parent = nullptr);
    ~Modify();

private:
    Ui::Modify* ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //点击主菜单按钮
    void on_deleteButton_clicked(); //点击删除按钮
    void on_modifyButton_clicked(); //点击修改按钮
};

#endif // ModifyStuWidget_H
