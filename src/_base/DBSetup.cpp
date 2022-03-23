#include "DBSetup.h"

#include "../_BK/TotalShow/TotalShow.h"
#include "../_BK/AccountEnt/AccountEnt.h"

#include "../_base/UVGlobal.h"

DBSetup::DBSetup(){ ;; };

void DBSetup::DBConnect()
{
    /// Clear all db before init
    qx::QxSqlDatabase::clearAllDatabases();
    /// create psql connect
    /// Set needed pramas
    qx::QxSqlDatabase::getSingleton()->setDriverName("QPSQL");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("uvisiondb");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("uvision");
    qx::QxSqlDatabase::getSingleton()->setPassword("uvision");
    qx::QxSqlDatabase::getSingleton()->setPort(5432);
};

void DBSetup::DBInsertSimulate()
{
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    DBSetup::DB_TotalShow_Simulate();
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
}

void DBSetup::DB_TotalShow_Simulate()
{
    if(qx::dao::count<TotalShowEnt>() != 0){
        return;
    }

    TotalShowEntPtr p;

    for(int i = 0; i < UVGlobal::g_devKindNum; ++i)
    {
        p.reset(new TotalShowEnt());
        p->devType = UVGlobal::g_devType[i];
        switch (i)
        {
        case 0:
            p->totalDevNum = 50;
            p->realDevNum = 42;
            p->questionDevNum = 1;
            p->errorDevNum = 0;
            break;
        case 1:
            p->totalDevNum = 31;
            p->realDevNum = 25;
            p->questionDevNum = 2;
            p->errorDevNum = 1;
            break;
        case 2:
            p->totalDevNum = 152;
            p->realDevNum = 87;
            p->questionDevNum = 2;
            p->errorDevNum = 0;
            break;
        case 3:
            p->totalDevNum = 73;
            p->realDevNum = 65;
            p->questionDevNum = 0;
            p->errorDevNum = 0;
            break;
        case 4:
            p->totalDevNum = 268;
            p->realDevNum = 255;
            p->questionDevNum = 1;
            p->errorDevNum = 0;
            break;
        }
        /// into db
        qx::dao::save(p);
    }
}

void DBSetup::AddDefaultUser()
{
    if (qx::dao::count<UserEnt>() == 0)
    {
        UserEntPtr u;
        u.reset(new UserEnt());
        u->userName = "qm";
        u->password = "qm";
        u->role = 1;
        qx::dao::save(u);
    }
}
