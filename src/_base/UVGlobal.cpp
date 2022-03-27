#include "UVGlobal.h"
#include "../_BK/TotalShow/TotalShow.h"

/// * * * * * * * * * * * * * * * * * * *
/// the global param define start

QMap<int, QString> UVGlobal::g_mapIntQStr;

QMap<int, QString> UVGlobal::g_devType;

QDateTime UVGlobal::g_DATETIME;

int UVGlobal::g_boilerNum = 0;
int UVGlobal::g_motorNum = 0;
int UVGlobal::g_beltNum = 0;
int UVGlobal::g_pipelineNum = 0;
int UVGlobal::g_transformsNum = 0;

int UVGlobal::g_currentRole = -1;
QString UVGlobal::g_userName = "";
QString UVGlobal::g_passWord = "";

int UVGlobal::g_logNum = 0;

/// the global param define end
/// * * * * * * * * * * * * * * * * * * *

UVGlobal::UVGlobal(){
    ;;
}

void UVGlobal::init()
{
    /// 介绍文本初始化
    UVGlobal::g_mapIntQStr.insert(1, "欢迎使用优视（UVision）巡检!");
    UVGlobal::g_mapIntQStr.insert(2, "您的意见是我前进的动力!");
    UVGlobal::g_mapIntQStr.insert(3, "愿安全每一天!");
    UVGlobal::g_mapIntQStr.insert(4, "安全来于警惕，事故出于麻痹!");
    UVGlobal::g_mapIntQStr.insert(5, "巡检记录要可靠，故障分析才有效!");

    /// 设备类型初始化
    UVGlobal::g_devType[0] = DEV1TYPE;
    UVGlobal::g_devType[1] = DEV2TYPE;
    UVGlobal::g_devType[2] = DEV3TYPE;
    UVGlobal::g_devType[3] = DEV4TYPE;
    UVGlobal::g_devType[4] = DEV5TYPE;
}

int UVGlobal::g_devKindNum = 5;

QString UVGlobal::gFunc_PatrolRes2Str(const PATROLRES& _tmpRes)
{
    QString _tmpStrRes = "";
    switch (_tmpRes) {
    case NRM:
        _tmpStrRes = "正常";
        break;
    case ERROE:
        _tmpStrRes = "故障";
        break;
    case QUESTION_1_LEVEL:
        _tmpStrRes = "一级风险";
        break;
    case QUESTION_2_LEVEL:
        _tmpStrRes = "二级风险";
        break;
    case QUESTION_3_LEVEL:
        _tmpStrRes = "三级风险";
        break;
    }
    return _tmpStrRes;
}
