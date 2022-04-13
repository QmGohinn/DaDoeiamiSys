/**
 *  模板头文件(HPP File)
 *  主要功能为根据实体类自动生成.db文件
 *  然后去Psql建表
*/

#ifndef DBTABLEREG_HPP
#define DBTABLEREG_HPP

#include "QxDao/QxSqlDatabase.h"

#include <src/_BK/BaseEnt/BaseEnt.h>
#include <src/_BK/AccountEnt/AccountEnt.h>
#include <src/_BK/TotalShow/TotalShow.h>

#include <src/_BK/InspectorEnt/InspectorEnt.h>

#include <src/_BK/BeltEnt/BeltEnt.h>
#include <src/_BK/BoilerEnt/BoilerEnt.h>
#include <src/_BK/MotorEnt/MotorEnt.h>
#include <src/_BK/PipelineEnt/PipelineEnt.h>
#include <src/_BK/TransformerEnt/TransformerEnt.h>

#include <src/_BK/LogEnt/LogEnt.h>

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
        daoError = qx::dao::create_table<InspecorEnt>();

        daoError = qx::dao::create_table<BeltEnt>();
        daoError = qx::dao::create_table<BoilerEnt>();
        daoError = qx::dao::create_table<MotorEnt>();
        daoError = qx::dao::create_table<PipelineEnt>();
        daoError = qx::dao::create_table<TransformerEnt>();
        daoError = qx::dao::create_table<LogEnt>();
    }

    /// 程序走向标志 0：正常执行 1：生成表文件
    static int _BuildTableFlg;
};

int DBScratch::_BuildTableFlg = 0;
//int DBScratch::_BuildTableFlg = 1;

#endif // DBTABLEREG_HPP
