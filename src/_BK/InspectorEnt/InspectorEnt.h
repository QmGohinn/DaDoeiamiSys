///*********************************
///
/// 巡检信息总览表
///

#ifndef INSPECTORENT_H
#define INSPECTORENT_H

#include <src/_BK/BaseEnt/BaseEnt.h>
#include <src/_base/UVGlobal.h>

class InspecorEnt;

typedef QSharedPointer<InspecorEnt> InspecorEntPtr;
typedef qx::QxCollection<long, InspecorEnt> List_InspecorEnt;

/// 用户管理
class QX_QM_EXPORT InspecorEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(InspecorEnt)
    QX_PERSISTABLE_HPP(InspecorEnt)

public:
    InspecorEnt() : BaseEnt() {}
    virtual ~InspecorEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param
    /// Result
    PATROLRES m_res = NRM;
    /// time
    QDateTime m_patrolTime = QDateTime::currentDateTime();
    /// 巡检员名字
    QString m_name = "";
    /// 巡检员电话
    QString m_phone = "";
    /// 巡检设备编号
    QString m_devSerial = "";

    static InspecorEnt Create(const PATROLRES&, const QDateTime&, const QString&, const QString&, const QString&);
};

QX_REGISTER_HPP_QM(InspecorEnt, BaseEnt, 1)

Q_DECLARE_METATYPE(InspecorEntPtr);

#endif // INSPECTORENT_H
