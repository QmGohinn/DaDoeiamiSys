#include "DBSetup.h"

#include "../_BK/TotalShow/TotalShow.h"
#include "../_BK/AccountEnt/AccountEnt.h"
#include "../_BK/BeltEnt/BeltEnt.h"
#include "../_BK/BoilerEnt/BoilerEnt.h"
#include "../_BK/MotorEnt/MotorEnt.h"
#include "../_BK/PipelineEnt/PipelineEnt.h"
#include "../_BK/TransformerEnt/TransformerEnt.h"

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
    DBSetup::DB_Belt_Simulate();
    DBSetup::DB_Boiler_Simulate();
    DBSetup::DB_Motor_Simulate();
    DBSetup::DB_Pipeline_Simulate();
    DBSetup::DB_Transformer_Simulate();
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
}

void DBSetup::DB_TotalShow_Simulate()
{
    if(qx::dao::count<TotalShowEnt>() != 0){
    }
    else
    {
        for(int i = 0; i < UVGlobal::g_devKindNum; ++i)
        {
            switch (i)
            {
            case 0:
                TotalShowEnt::Create(UVGlobal::g_devType[i], 50, 42, 5, 2);
                break;
            case 1:
                TotalShowEnt::Create(UVGlobal::g_devType[i], 31, 25, 3, 1);
                break;
            case 2:
                TotalShowEnt::Create(UVGlobal::g_devType[i], 152, 87, 10, 5);
                break;
            case 3:
                TotalShowEnt::Create(UVGlobal::g_devType[i], 73, 65, 5, 1);
                break;
            case 4:
                TotalShowEnt::Create(UVGlobal::g_devType[i], 268, 255, 8, 2);
                break;
            }
        }
    }

    List_TotalShowEntPtr lst;
    qx::dao::fetch_all(lst);

    for(const auto& loop_TotalInfo : lst)
    {
        if(loop_TotalInfo.second.devType == DEV1TYPE){
            UVGlobal::g_boilerNum = loop_TotalInfo.second.totalDevNum;
        }else if(loop_TotalInfo.second.devType == DEV2TYPE){
            UVGlobal::g_motorNum = loop_TotalInfo.second.totalDevNum;
        }else if(loop_TotalInfo.second.devType == DEV3TYPE){
            UVGlobal::g_beltNum = loop_TotalInfo.second.totalDevNum;
        }else if(loop_TotalInfo.second.devType == DEV4TYPE){
            UVGlobal::g_pipelineNum = loop_TotalInfo.second.totalDevNum;
        }else if(loop_TotalInfo.second.devType == DEV5TYPE){
            UVGlobal::g_transformsNum = loop_TotalInfo.second.totalDevNum;
        }
    }
}

void DBSetup::AddDefaultUser()
{
    if (qx::dao::count<UserEnt>() == 0)
    {
        UserEnt::Create("wubin", "221376", 1);
    }
}

void DBSetup::DB_Belt_Simulate()
{
    if(qx::dao::count<BeltEnt>() != 0){
        return;
    }

    for(int _size = 1; _size <= UVGlobal::g_beltNum; _size++)
    {
        QString _devName = QString("PD%1").arg(_size);

        BeltEnt::Create(_devName,
                        InspecorEnt::Create(NRM, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devName));
    }
}

void DBSetup::DB_Boiler_Simulate()
{
    if(qx::dao::count<BoilerEnt>() != 0){
        return;
    }

    for(int _size = 1; _size <= UVGlobal::g_boilerNum; _size++)
    {
        QString _devName = QString("GL%1").arg(_size);

        BoilerEnt::Create(_devName,
                        InspecorEnt::Create(NRM, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devName));
    }
}

void DBSetup::DB_Motor_Simulate()
{
    if(qx::dao::count<MotorEnt>() != 0){
        return;
    }

    for(int _size = 1; _size <= UVGlobal::g_motorNum; _size++)
    {
        QString _devName = QString("QJ%1").arg(_size);

        MotorEnt::Create(_devName,
                        InspecorEnt::Create(NRM, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devName));
    }
}

void DBSetup::DB_Pipeline_Simulate()
{
    if(qx::dao::count<PipelineEnt>() != 0){
        return;
    }

    for(int _size = 1; _size <= UVGlobal::g_motorNum; _size++)
    {
        QString _devName = QString("GD%1").arg(_size);

        PipelineEnt::Create(_devName,
                        InspecorEnt::Create(NRM, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devName));
    }
}

void DBSetup::DB_Transformer_Simulate()
{
    if(qx::dao::count<TransformerEnt>() != 0){
        return;
    }

    for(int _size = 1; _size <= UVGlobal::g_motorNum; _size++)
    {
        QString _devName = QString("BY%1").arg(_size);

        TransformerEnt::Create(_devName,
                        InspecorEnt::Create(NRM, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devName));
    }
}
