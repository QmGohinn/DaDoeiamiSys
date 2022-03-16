#include <QApplication>

/// 主界面
#include "../_APL/main/eiamisyswindows.h"
/// 登录界面
#include "../_APL/userlogin/userloginform.h"
/// 数据库表注册头文件
#include "../_base/dbTableReg.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /// 设置Logo图片
    a.setWindowIcon(QIcon("../../../res/exelogo.ico"));
    /// 设置程序名字
    a.setApplicationName("UVision");
    /// 设置程序版本
    a.setApplicationVersion("1.0.1");

    /// 生成表
//    DBScratch::buildSqlite();
//    return 0;

    /// 主界面
    EiamiSysWindows w;

    /// 登录界面
    UserLoginForm _userLoginForm(&w);
    /// 显示
    _userLoginForm.show();

    /// 登录失败 或 点击退出
    if(_userLoginForm.exec() != QDialog::Accepted)
    {
        return 0;
    }

    /// 主界面显示
    w.show(); w.m_trayIcon->show();

    return a.exec();
}
