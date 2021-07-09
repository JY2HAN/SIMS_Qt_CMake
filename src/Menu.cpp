#include "Menu.h"
#include "ui_Menu.h"
Menu::Menu(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_addButton_clicked() {
    emit display(1);    //id为1的是AddStuWidget
}

void Menu::on_searchButton_clicked() {
    emit display(2);    //id为2的是SearchStuWidget
}

void Menu::on_modifyButton_clicked() {
    emit display(3);    //id为3的是ModifyStuWidget
}

void Menu::on_sortButton_clicked() {
    emit display(4);    //id为4的是SortStuWidget
}

void Menu::on_exitButton_clicked() {
    QApplication::exit();   //退出
}
