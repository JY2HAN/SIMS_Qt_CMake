#include <QtWidgets/QApplication>
#include "Menu.h"
#include "Logging.h"
#include "MainView.h"
int main(int argc, char *argv[])
{
    int a = 10;
    QApplication app(argc, argv);
    Logging login;
    //Logging login = new Logging();
    //login->setWindowTitle("登录");//设置窗体标题
    MainView* main = new MainView();
    main->setWindowTitle("学籍信息操作管理系统SIMS");//设置窗体标题
    if (login.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
    {
        main->show();
        return app.exec();
    }//先显示登录界面，确认账号密码之后进入菜单页面
    else return 0;
}

//#include <QApplication>
//
//#include "MainView.h"
//
//int main(int argc, char* argv[]) {
//    QApplication app(argc, argv);
//
//    MainView w;
//    w.show();
//
//    return app.exec();
//}


