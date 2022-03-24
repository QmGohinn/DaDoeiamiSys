///*********************************
///
/// 巡检信息总览表
///

#ifndef TOTALSHOW_H
#define TOTALSHOW_H

#include "../../_BK/BaseEnt/BaseEnt.h"

class TotalShowEnt;

/// 用户管理
class QX_QM_EXPORT TotalShowEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(TotalShowEnt)
    QX_PERSISTABLE_HPP(TotalShowEnt)

public:
    TotalShowEnt() : BaseEnt() {}
    virtual ~TotalShowEnt() {}
    virtual void makeAbstractClass() { ; }

    long id;
    /// 设备类型
    QString devType = "";
    /// 应检数额
    int totalDevNum = 0;
    /// 实检数额
    int realDevNum = 0;
    /// 问题设备
    int questionDevNum = 0;
    /// 故障设备
    int errorDevNum = 0;
};

QX_REGISTER_HPP_QM(TotalShowEnt, BaseEnt, 1)

typedef QSharedPointer<TotalShowEnt> TotalShowEntPtr;
typedef qx::QxCollection<long, TotalShowEnt> List_TotalShowEntPtr;

Q_DECLARE_METATYPE(TotalShowEntPtr);

#endif // TOTALSHOW_H
