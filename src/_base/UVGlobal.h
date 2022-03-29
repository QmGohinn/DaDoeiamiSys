/*
 *  全局变量头文件
*/

#ifndef UVGLOBAL_H
#define UVGLOBAL_H

#include <QMap>
#include <QString>
#include <QTime>

#include "3rd/QsLog/include/QsLog.h"
#include "3rd/QsLog/include/QsLogDest.h"
#include "3rd/QsLog/include/QsLogLevel.h"

#include <QCoreApplication>
#include <QDir>
#include <iostream>

#define DEV1TYPE "高温锅炉"
#define DEV2TYPE "汽机"
#define DEV3TYPE "输煤皮带"
#define DEV4TYPE "高压管道"
#define DEV5TYPE "变压器"

enum PATROLRES{
    NRM = 1,
    ERROE = 0,
    QUESTION_1_LEVEL = -1,
    QUESTION_2_LEVEL = -2,
    QUESTION_3_LEVEL = -3
};

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
    /// 五种巡检设备的总数
    static int g_transformsNum ;
    static int g_pipelineNum;
    static int g_beltNum;
    static int g_motorNum;
    static int g_boilerNum;
    /// 当前用户权限 账号名 密码
    static int g_currentRole;
    static QString g_userName;
    static QString g_passWord;

    static int g_logNum;

    static QString gFunc_PatrolRes2Str(const PATROLRES&);
};

#endif // UVGLOBAL_H
