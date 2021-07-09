#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
    class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget* parent = nullptr);
    ~Menu();

private:
    Ui::Menu* ui;

signals:
    void display(int number);

private slots:
    void on_addButton_clicked();
    void on_searchButton_clicked();
    void on_modifyButton_clicked();
    void on_sortButton_clicked();
    void on_exitButton_clicked();

};

#endif // MENU_H
