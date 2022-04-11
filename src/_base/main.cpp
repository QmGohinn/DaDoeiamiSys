#include <QApplication>
#include <QThreadPool>

#include "../_base/SysInit.h"
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
    a.setWindowIcon(QIcon(":/res/logo/exelogo.ico"));
    /// 设置程序名字
    a.setApplicationName("UVision");
    /// 设置程序版本
    a.setApplicationVersion("1.0.1");

    if(DBScratch::_BuildTableFlg)
    {
        /// 生成表
        DBScratch::buildSqlite();
        return 0;
    }

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    qx::QxClassX::registerAllClasses(true);
    qx::QxCollection<QString, qx::IxClass *>*
            pAllClasses = qx::QxClassX::getSingleton()->getAll();
///                                                                             注册所有的类
///                                                                             设置最大线程数
    for (long k = 0; k < pAllClasses->count(); k++)
    {
        qx::IxClass * pClass = pAllClasses->getByIndex(k);
        if (! pClass)
        {
            continue;
        }
        /// This line should initialize the 'm_pClass' variable
        /// where your assertion is thrown
        pClass->getAllValidator();
    }
    /// set the max thread num is 100
    QThreadPool::globalInstance()->setMaxThreadCount(200);
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

    /// system do init
    SysInit::Init();

    /// 登录界面
    UserLoginForm* _userLoginForm = new UserLoginForm ;

    /// 登录失败 或 点击退出
    if(_userLoginForm->exec() != QDialog::Accepted)
    {
        return 0;
    }
    /// 销毁登录界面
    _userLoginForm->~UserLoginForm();

    /// 主界面
    EiamiSysWindows w;
    QThread::sleep(2);
    w.show();
    w.m_trayIcon->show();

    return a.exec();
}
