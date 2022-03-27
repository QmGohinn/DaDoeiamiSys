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
        UserEntPtr u;
        u.reset(new UserEnt());
        u->userName = "qm";
        u->password = "qm";
        u->role = 1;
        qx::dao::save(u);
    }
}

void DBSetup::DB_Belt_Simulate()
{
    if(qx::dao::count<BeltEnt>() != 0){
        return;
    }

    BeltEntPtr p_belt;
    InspecorEntPtr p_Info;

    for(int _size = 1; _size <= UVGlobal::g_beltNum; _size++)
    {
        QString _devName = QString("PD%1").arg(_size);

        p_Info.reset(new InspecorEnt());

        p_Info->m_res = NRM;
        p_Info->m_name = "wu.b";
        p_Info->m_phone = "4381108820";
        p_Info->m_patrolTime = QDateTime::currentDateTime();
        p_Info->m_devSerial = _devName;
        qx::dao::save(p_Info);

        p_belt.reset(new BeltEnt());

        p_belt->m_devSerial = _devName;
        p_belt->m_baseInfo = *p_Info;
        qx::dao::save(p_belt);
    }
}

void DBSetup::DB_Boiler_Simulate()
{
    if(qx::dao::count<BoilerEnt>() != 0){
        return;
    }

    BoilerEntPtr p_boiler;
    InspecorEntPtr p_Info;

    for(int _size = 1; _size <= UVGlobal::g_boilerNum; _size++)
    {
        QString _devName = QString("GL%1").arg(_size);

        p_Info.reset(new InspecorEnt());

        p_Info->m_res = NRM;
        p_Info->m_name = "wu.b";
        p_Info->m_phone = "4381108820";
        p_Info->m_patrolTime = QDateTime::currentDateTime();
        p_Info->m_devSerial = _devName;
        qx::dao::save(p_Info);

        p_boiler.reset(new BoilerEnt());

        p_boiler->m_devSerial = _devName;
        p_boiler->m_baseInfo = *p_Info;
        qx::dao::save(p_boiler);
    }
}

void DBSetup::DB_Motor_Simulate()
{
    if(qx::dao::count<MotorEnt>() != 0){
        return;
    }

    MotorEntPtr p_motor;
    InspecorEntPtr p_Info;

    for(int _size = 1; _size <= UVGlobal::g_motorNum; _size++)
    {
        QString _devName = QString("QJ%1").arg(_size);

        p_Info.reset(new InspecorEnt());

        p_Info->m_res = NRM;
        p_Info->m_name = "wu.b";
        p_Info->m_phone = "4381108820";
        p_Info->m_patrolTime = QDateTime::currentDateTime();
        p_Info->m_devSerial = _devName;
        qx::dao::save(p_Info);

        p_motor.reset(new MotorEnt());

        p_motor->m_devSerial = _devName;
        p_motor->m_baseInfo = *p_Info;
        qx::dao::save(p_motor);
    }
}

void DBSetup::DB_Pipeline_Simulate()
{
    if(qx::dao::count<PipelineEnt>() != 0){
        return;
    }

    PipelineEntPtr p_pipeline;
    InspecorEntPtr p_Info;

    for(int _size = 1; _size <= UVGlobal::g_motorNum; _size++)
    {
        QString _devName = QString("GD%1").arg(_size);

        p_Info.reset(new InspecorEnt());

        p_Info->m_res = NRM;
        p_Info->m_name = "wu.b";
        p_Info->m_phone = "4381108820";
        p_Info->m_patrolTime = QDateTime::currentDateTime();
        p_Info->m_devSerial = _devName;
        qx::dao::save(p_Info);

        p_pipeline.reset(new PipelineEnt());

        p_pipeline->m_devSerial = _devName;
        p_pipeline->m_baseInfo = *p_Info;
        qx::dao::save(p_pipeline);
    }
}

void DBSetup::DB_Transformer_Simulate()
{
    if(qx::dao::count<TransformerEnt>() != 0){
        return;
    }

    TransformerEntPtr p_transformer;
    InspecorEntPtr p_Info;

    for(int _size = 1; _size <= UVGlobal::g_motorNum; _size++)
    {
        QString _devName = QString("BY%1").arg(_size);

        p_Info.reset(new InspecorEnt());

        p_Info->m_res = NRM;
        p_Info->m_name = "wu.b";
        p_Info->m_phone = "4381108820";
        p_Info->m_patrolTime = QDateTime::currentDateTime();
        p_Info->m_devSerial = _devName;
        qx::dao::save(p_Info);

        p_transformer.reset(new TransformerEnt());

        p_transformer->m_devSerial = _devName;
        p_transformer->m_baseInfo = *p_Info;
        qx::dao::save(p_transformer);
    }
}
