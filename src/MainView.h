#ifndef MAINVIEWWIDGET_H
#define MAINVIEWWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "Menu.h"
#include "Add.h"
#include "Search.h"
#include "Modify.h"
#include "Sort.h"
//#include "SortStuWidget.h"

namespace Ui {
    class MainView;
}

class MainView : public QWidget
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr);
    ~MainView();

private:
    Ui::MainView* ui;

    Menu* MenuWidget;	        //菜单窗口
    Add* AddStuWidget;	        //添加窗口
    Search* SearchStuWidget;	//查询窗口
    Modify* ModifyStuWidget;	//修改窗口
    Sort* SortStuWidget;	    //排序窗口
    QStackedLayout* stackLayout;//QStackedLayout布局


};

#endif // MAINVIEWWIDGET_H
