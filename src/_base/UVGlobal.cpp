#include "UVGlobal.h"

/// * * * * * * * * * * * * * * * * * * *
/// the global param define start

QMap<int, QString> UVGlobal::g_mapIntQStr;

QMap<int, QString> UVGlobal::g_devType;

QDateTime UVGlobal::g_DATETIME;

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
