#ifndef DBTABLEREG_HPP
#define DBTABLEREG_HPP

#include "QxDao/QxSqlDatabase.h"

#include "../_BK/BaseEnt/BaseEnt.h"
#include "../_BK/AccountEnt/AccountEnt.h"
#include "../_BK/TotalShow/TotalShow.h"

class DBScratch
{
public:
    inline static void buildSqlite()
    {
        const QString DB_URL("./uvision.db");
        qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
        qx::QxSqlDatabase::getSingleton()->setDatabaseName(DB_URL);
        qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
        qx::QxSqlDatabase::getSingleton()->setUserName("root");
        qx::QxSqlDatabase::getSingleton()->setPassword("");

        QSqlError daoError;

        daoError = qx::dao::create_table<UserEnt>();
        daoError = qx::dao::create_table<TotalShowEnt>();
    }

    /// 程序走向标志 0：正常执行 1：生成表文件
    static int _BuildTableFlg;
};

int DBScratch::_BuildTableFlg = 0;
//int DBScratch::_BuildTableFlg = 1;

#endif // DBTABLEREG_HPP
