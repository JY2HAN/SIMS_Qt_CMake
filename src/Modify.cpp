#include "Modify.h"
#include "ui_Modify.h"
//#include "Modify.ui"

Modify::Modify(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_returnButton_clicked() {
    emit display(0);
}
void Modify::on_deleteButton_clicked() {
    QVector<StudentInfo> allStudentInfo;    //数据类型为StudentInfo的QVector容器
    if (ui->idLineEdit->text() == "") {   //如果id输入栏为空则输出错误提示并返回
        QMessageBox::about(NULL, "反馈", "id不得为空!");
        return;
    }
    QFile file("student.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //以只读 的方式打开文本文件
    if (!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return;
    }
    //QIODevice::Truncate在写入时会从文件开始处写入，覆盖原有内容
    QTextStream inp(&file);
    //以file建立一个QT的文本流
    while (!inp.atEnd()) {
        QString name, grade;
        int id, A, B, C;
        inp >> id>> name >> grade >> A >> B >> C;
        //读入学号 姓名 科目A 科目B  科目C
        allStudentInfo.push_back(StudentInfo(id, name, grade, A, B, C));
        //调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    allStudentInfo.pop_back();  //文件最后会多读一个无用数据，将其拿出
    file.close();
    int id = ui->idLineEdit->text().toInt();
    //获取用户输入的id
    bool flag = false;
    //记录是否进行过删除
    for (QVector<StudentInfo>::iterator it = allStudentInfo.begin(); it != allStudentInfo.end(); it++) {
        //用迭代器遍历allStudentInfo
        if (it->getId() == id) {  //如果找到有id与该id相同的学生，就进行删除
            allStudentInfo.erase(it);
            flag = true;
            break;
        }
    }
    if (flag) {   //如果进行过删除，弹出对话框并更新文件
        QMessageBox::about(NULL, "反馈", "删除成功");
        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
        //以只写覆盖的方式打开文本文件
        if (!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
            QMessageBox::about(NULL, "反馈", "数据文件打开失败");
            return;
        }
        QTextStream out(&file);
        for (auto i : allStudentInfo) {
            out << i.getId() << " " <<i.getName() << " " << i.getGrade() << " " << i.getA() << " " << i.getB() << " " << i.getC() << endl;
        }
        file.close();
    }
    else {
        //如果没有进行删除，弹出不存在对话框
        QMessageBox::about(NULL, "反馈", "id不存在！");
    }
    //关闭文件
    ui->idLineEdit->clear();
    //清空id输入框
}

void Modify::on_modifyButton_clicked() {
    if (ui->idLineEdit->text() == "" || ui->nameLineEdit->text() == "" || ui->gradeLineEdit->text() == "" || ui->ALineEdit->text() == "" || ui->BLineEdit->text() == "" || ui->CLineEdit->text() == "") {
        QMessageBox::about(NULL, "反馈", "存在空项");
        return;
    }
    QVector<StudentInfo> allStudentInfo;    //数据类型为StudentInfo的QVector容器
    QFile file("student.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //以只读 的方式打开文本文件
    if (!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return;
    }
    //QIODevice::Truncate在写入时会从文件开始处写入，覆盖原有内容
    QTextStream inp(&file);
    //以file建立一个QT的文本流
    while (!inp.atEnd()) {
        QString name,grade;
        int id, A, B, C;
        inp >> id >>name >>grade >> A >> B >> C;
        //读入学号 姓名 科目A 科目B  科目C
        allStudentInfo.push_back(StudentInfo(id, name, grade, A, B, C));
        //调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    allStudentInfo.pop_back();  //文件最后会多读一个无用数据，将其拿出
    file.close();
    int id = ui->idLineEdit->text().toInt();
    QString name = ui->nameLineEdit->text();
    QString grade = ui->gradeLineEdit->text();
    int A = ui->ALineEdit->text().toInt();
    int B = ui->BLineEdit->text().toInt();
    int C = ui->CLineEdit->text().toInt();
    bool flag = false;
    for (QVector<StudentInfo>::iterator it = allStudentInfo.begin(); it != allStudentInfo.end(); it++) {
        if (it->getId() == id) {
            it->setName(name);
            it->setGrade(grade);
            it->setA(A);
            it->setB(B);
            it->setC(C);
            flag = true;
        }
    }
    if (flag) {   //如果进行过修改，弹出对话框并更新文件
        QMessageBox::about(NULL, "反馈", "修改成功");
        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
        //以只写覆盖的方式打开文本文件
        if (!file.isOpen()) { //如果数据文件没有打开，弹出对话框提示用户
            QMessageBox::about(NULL, "反馈", "数据文件打开失败");
            return;
        }
        QTextStream out(&file);
        for (auto i : allStudentInfo) {
            out << i.getId() << " " <<i.getName() << " " << i.getGrade() << " " << i.getA() << " " << i.getB() << " " << i.getC() << endl;
        }
        file.close();
    }
    else {
        //如果没有进行修改，弹出不存在对话框
        QMessageBox::about(NULL, "反馈", "id不存在！");
    }
    //关闭文件
    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->gradeLineEdit->clear();
    ui->ALineEdit->clear();
    ui->BLineEdit->clear();
    ui->CLineEdit->clear();
    //清空所有输入框
}
