#include "DBSetup.h"

DBSetup::DBSetup(){ ; };

void DBSetup::DBInit()
{
    qx::QxSqlDatabase::clearAllDatabases();

    qx::QxSqlDatabase::getSingleton()->setDriverName("QPSQL");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("uvisiondb");

    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("uvision");
    qx::QxSqlDatabase::getSingleton()->setPassword("uvision");
    qx::QxSqlDatabase::getSingleton()->setPort(5432);
};
