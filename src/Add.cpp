#include "Add.h"
#include "ui_Add.h"
Add::Add(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}
Add::~Add()
{
    delete ui;
}
void Add::on_returnButton_clicked() {   //"主菜单"按钮点击
    emit display(0);
}

void Add::on_addButton_clicked() {  //"添加"按钮点击
    int id = ui->idLineEdit->text().toInt();
    //将用户输入的学号由idLineEdit取出，并转换为整型
    QString name = ui->nameLineEdit->text();
    //将用户输入的姓名由nameLineEdit取出
    QString grade = ui->gradeLineEdit->text();
    //将用户输入的姓名由nameLineEdit取出
    int A = ui->ALineEdit->text().toInt();
    //将用户输入的学号由ALineEdit取出，并转换为整型
    int B = ui->BLineEdit->text().toInt();
    //将用户输入的学号由BLineEdit取出，并转化为整型
    int C = ui->CLineEdit->text().toInt();
    //将用户输入的学号由CLineEdit取出，并转化为整型
    if (ui->nameLineEdit->text() == "" || ui->idLineEdit->text() == "" || ui->ALineEdit->text() == "" || ui->BLineEdit->text() == "" || ui->CLineEdit->text() == "") {
        //插入的五项数据都不能为空，否则在读取文件时会出现问题。
        QMessageBox::about(NULL, "反馈", "存在空项");
    }
    QFile file("student.txt");
    //实例化一个QFile file为我们的数据文件student.txt
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    //open()可以用来打开文件这里QIODevice::WriteOnly代表将文件以只写的方式打开
    //QIODevice::Text代表我们打开的是文本文件，QIODevice::Text会对end-of-line结束符进行转译
    //QIODevice::Append以追加的方式打开，新增加的内容将被追加到文件末尾
    if (!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return;
    }
    QTextStream out(&file);
    //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
    out << id << " " << name << " " << grade << " " << A << " " << B << " " << C << endl;
    //将我们刚刚获取的数据写入文件
    file.close();
    QMessageBox::about(NULL, "反馈", "插入成功");
    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->gradeLineEdit->clear();
    ui->ALineEdit->clear();
    ui->BLineEdit->clear();
    ui->CLineEdit->clear();
    //将用户输入的数据清空
}
