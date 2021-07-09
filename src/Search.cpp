#include "Search.h"
#include "ui_Search.h"
Search::Search(QWidget *parent)
	: QWidget(parent),
    ui(new Ui::Search)
{
	//ui.setupUi(this);
    ui->setupUi(this);
}
Search::~Search()
{
    delete ui;
}

void Search::on_returnButton_clicked() {
    emit display(0);
}

void Search::on_searchButton_clicked() {
    if (ui->idLineEdit->text() == "") {
        QMessageBox::about(NULL, "反馈", "id不能为空");
        return;
    }
    QFile file("student.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //以只读的方式打开文本文件
    if (!file.isOpen()) { //文件打开失败
        QMessageBox::about(NULL, "反馈", "文件打开失败");
        return;
    }
    QTextStream inp(&file);
    //以file作为Qt文本流
    QVector<StudentInfo> allStudentInfo;
    //数据类型为StudentInfo的QVector容器
    while (!inp.atEnd()) { //读到文件结尾
        QString name;
        QString grade;
        int id, A, B, C;
        inp >> id >> name >> grade >> A >> B >> C;
        allStudentInfo.push_back(StudentInfo(id, name, grade, A, B, C));
        //调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    allStudentInfo.pop_back();
    //扔掉最后的无用数据
    file.close();
    //关闭文件
    int id = ui->idLineEdit->text().toInt();
    bool flag = false;
    for (auto i : allStudentInfo) {
        if (i.getId() == id) {
            ui->showNameLabel->setText(i.getName());
            ui->showGradeLabel->setText(i.getGrade());
            ui->showALabel->setText(QString::number(i.getA()));
            ui->showBLabel->setText(QString::number(i.getB()));
            ui->showCLabel->setText(QString::number(i.getC()));
            ui->showAvgLabel->setText(QString::number(i.getAvg()));
            flag = true;
            break;
        }
    }
    if (!flag) {
        QMessageBox::about(NULL, "反馈", "id不存在！");
    }
    ui->idLineEdit->clear();
}
