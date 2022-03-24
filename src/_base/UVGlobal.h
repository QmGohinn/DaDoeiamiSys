#ifndef UVGLOBAL_H
#define UVGLOBAL_H

#include <QMap>
#include <QString>
#include <QTime>

#define DEV1TYPE "高温锅炉"
#define DEV2TYPE "汽机"
#define DEV3TYPE "输煤皮带"
#define DEV4TYPE "高压管道"
#define DEV5TYPE "变压器"

class UVGlobal
{
public:
    UVGlobal();
    ~UVGlobal();

public:
    static void init();
    /// 介绍标语
    static QMap<int, QString> g_mapIntQStr;
    /// 巡检设备类型数量
    static int g_devKindNum;
    /// 设备类型数组
    static QMap<int, QString> g_devType;
    /// 运行日期
    static QDateTime g_DATETIME;

    static int g_transformsNum ;
    static int g_pipelineNum;
    static int g_beltNum;
    static int g_motorNum;
    static int g_boilerNum;
};

enum PATROLRES{
    NRM = 1,
    ERROE = 0,
    QUESTION_1_LEVEL = -1,
    QUESTION_2_LEVEL = -2,
    QUESTION_3_LEVEL = -3
};

#endif // UVGLOBAL_H
