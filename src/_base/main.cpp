#include <QApplication>
#include <QThreadPool>

#include "../_base/SysInit.h"

/// 主界面
#include "../_APL/main/eiamisyswindows.h"
/// 登录界面
#include "../_APL/userlogin/userloginform.h"
/// 数据库表注册头文件
#include "../_base/dbTableReg.hpp"

#include "../_BK/AccountEnt/AccountEnt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /// 设置Logo图片
    a.setWindowIcon(QIcon("../../../res/logo.png"));
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

    /// 初始化数据库 -- Connect PSql DB
    /// system do init
    SysInit::Init();
    /// Add a Default user named qm if user num == 0
    SysInit::AddDefaultUser();

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
    w.show();
    w.m_trayIcon->show();

    return a.exec();
}
