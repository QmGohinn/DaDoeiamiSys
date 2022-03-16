#ifndef DBTABLEREG_HPP
#define DBTABLEREG_HPP

#include "QxDao/QxSqlDatabase.h"

#include "../_BK/BaseEnt/BaseEnt.h"
#include "../_BK/AccountEnt/AccountEnt.h"

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
    }
};

#endif // DBTABLEREG_HPP
