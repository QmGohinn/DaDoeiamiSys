///*********************************
///
/// 汽机总览表
///

#ifndef MOTOR_H
#define MOTOR_H

#include <src/_BK/BaseEnt/BaseEnt.h>
#include <src/_BK/InspectorEnt/InspectorEnt.h>

class MotorEnt;

/// 用户管理
class QX_QM_EXPORT MotorEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(MotorEnt)
    QX_PERSISTABLE_HPP(MotorEnt)

public:
    MotorEnt() : BaseEnt() {}
    virtual ~MotorEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param
    QString m_devSerial = "";
    /// baseinfo
    InspecorEnt m_baseInfo;

    static void Create(const QString&, const InspecorEnt&);
};

QX_REGISTER_HPP_QM(MotorEnt, BaseEnt, 1)

typedef QSharedPointer<MotorEnt> MotorEntPtr;
typedef qx::QxCollection<long, MotorEnt> List_MotorEnt;

Q_DECLARE_METATYPE(MotorEntPtr);

#endif // MOTOR_H
