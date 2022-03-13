/// 主界面
#include "../_APL/main/eiamisyswindows.h"
/// 登录界面
#include "../_APL/userlogin/userloginform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //主界面
    EiamiSysWindows w;

    //登录界面
    UserLoginForm _userLoginForm(&w);
    _userLoginForm.show();

    /// 登录失败 或 点击退出
    if(_userLoginForm.exec() != QDialog::Accepted)
    {
        return 0;
    }

    w.show();
    return a.exec();
}