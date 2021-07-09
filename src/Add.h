#ifndef AddStuWidget_H
#define AddStuWidget_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
    class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget* parent = nullptr);
    ~Add();

private:
    Ui::Add* ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //点击主菜单按钮
    void on_addButton_clicked();    //点击添加按钮
};

#endif // AddStuWidget_H
