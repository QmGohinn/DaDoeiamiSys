#include "UVGlobal.h"

QMap<int, QString> UVGlobal::g_mapIntQStr;

UVGlobal::UVGlobal(){
    ;;
}

void UVGlobal::init(){

    /// 介绍文本初始化
    UVGlobal::g_mapIntQStr.insert(1, "欢迎使用优视（UVision）巡检!");
    UVGlobal::g_mapIntQStr.insert(2, "您的意见是我前进的动力!");
    UVGlobal::g_mapIntQStr.insert(3, "愿安全每一天!");
    UVGlobal::g_mapIntQStr.insert(4, "安全来于警惕，事故出于麻痹!");
    UVGlobal::g_mapIntQStr.insert(5, "巡检记录要可靠，故障分析才有效!");
}
