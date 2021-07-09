#include "Sort.h"
#include "ui_Sort.h"
#include <algorithm>
Sort::Sort(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Sort)
{
    ui->setupUi(this);
    sortButtonGroup = new QButtonGroup();
    //实例化sortButtonGroup
    sortButtonGroup->addButton(ui->ARadioButton, 0);
    //将代表科目A的单选框加入sortButtonGroup并将其id设为0
    //不建议使用默认id，默认id是由-2开始依次递减的
    sortButtonGroup->addButton(ui->BRadioButton, 1);
    //将代表科目B的单选框加入sortButtonGroup并将其id设为1
    sortButtonGroup->addButton(ui->CRadioButton, 2);
    //将代表科目C的单选框加入sortButtonGroup并将其id设为2
    sortButtonGroup->addButton(ui->avgRadioButton, 3);
    //将代表平均分的单选框加入sortButtonGroup并将其id设为3
    ui->avgRadioButton->setChecked(true);
    //平均成绩默认选中
    ui->tableWidget->setColumnCount(6);
    QStringList headerLabels;
    //QStringList headerLabels用来记录表格表头数据
    headerLabels << tr("学号") << tr("姓名") << tr("班级") << tr("科目A") << tr("科目B") << tr("科目C") << tr("平均");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    // void setHorizontalHeaderLabels(const QStringList &labels);设置水平表头标签
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置根据总宽度调整列宽
    ui->tableWidget->setRowCount(1);
    //初始行数设为一行

}

Sort::~Sort()
{
    delete ui;
}

void Sort::on_returnButton_clicked() {
    emit display(0);
}

bool getStudentInfo(QVector<StudentInfo>& allStudentInfo) {  //读取信息成功返回true 否则返回false
    QFile file("student.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //以只读方式打开文本文件student.txt
    QTextStream inp(&file);
    if (!file.isOpen()) { //文件打开失败
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return false;
    }
    while (!inp.atEnd()) {    //读到文件结尾
        QString name, grade;
        int id, A, B, C;
        inp >> id >> name >> grade >> A >> B >> C;
        allStudentInfo.push_back(StudentInfo(id, name ,grade, A, B, C));
        //调用之前声明的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    allStudentInfo.pop_back();
    //扔掉最后的无用数据
    file.close();
    //关闭文件
    return true;
}

bool cmp_A(StudentInfo a, StudentInfo b) {    //科目A排序
    return a.getA() > b.getA();
}

bool cmp_B(StudentInfo a, StudentInfo b) { //科目B排序
    return a.getB() > b.getB();
}

bool cmp_C(StudentInfo a, StudentInfo b) {   //科目C排序
    return a.getC() > b.getC();
}

bool cmp_avg(StudentInfo a, StudentInfo b) { //平均成绩排序
    return a.getAvg() > b.getAvg();
}

void Sort::on_sortButton_clicked() {
    ui->tableWidget->clearContents();
    //清空除表头外的所有数据
    //若想清除表头可使用clear()
    int sortTag = sortButtonGroup->checkedId();
    //取得当前选中的单选框的id
    QVector<StudentInfo> allStudentInfo;
    //数据类型为StudentInfo的QVector容器
    if (!getStudentInfo(allStudentInfo)) //从文件读取数据到allStudentInfo
        return; //读取失败直接返回
    if (allStudentInfo.empty()) { //allStudentInfo中没有数据
        QMessageBox::about(NULL, "反馈", "没有学生信息");
        return;
    }
    switch (sortTag) {
    case 0: //sortTag==0根据数学进行排序
        std::sort(allStudentInfo.begin(), allStudentInfo.end(), cmp_A);
        break;
    case 1: //sortTag==1根据英语进行排序
        std::sort(allStudentInfo.begin(), allStudentInfo.end(), cmp_B);
        break;
    case 2: //sortTag==2根据C语言进行排序
        std::sort(allStudentInfo.begin(), allStudentInfo.end(), cmp_C);
        break;
    case 3: //sortTag==3根据平均成绩进行排序
        std::sort(allStudentInfo.begin(), allStudentInfo.end(), cmp_avg);
        break;
    }
    ui->tableWidget->setRowCount(allStudentInfo.size());
    //将表格的行数设为与学生数量相同
    //否则setItem添加单元格不会生效
    for (int i = 0; i < allStudentInfo.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(allStudentInfo[i].getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(allStudentInfo[i].getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(allStudentInfo[i].getGrade()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(allStudentInfo[i].getA())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(allStudentInfo[i].getB())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(allStudentInfo[i].getC())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(allStudentInfo[i].getAvg())));
        //设置各单元格的数据，非QString类型的数据需要转换为QString
    }
}


