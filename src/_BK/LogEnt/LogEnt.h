///****************************************
///
/// 日志维护表
///

#ifndef LOGENT_H
#define LOGENT_H

#include "../../_BK/BaseEnt/BaseEnt.h"

class LogEnt;

enum LogType
{
    SysLog = 0
};

/// 用户管理
class QX_QM_EXPORT LogEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(LogEnt)
    QX_PERSISTABLE_HPP(LogEnt)

public:
    LogEnt() : BaseEnt() {}
    virtual ~LogEnt() {}
    virtual void makeAbstractClass() { ; }

    static void DBLogCreate(const LogType&, const QString&, const QString& _mmsg = "");

    /// 日志类型
    LogType m_type = SysLog;
    /// 简略日志
    QString m_msg = "";
    /// 详细日志
    QString m_mmsg = "";
    /// 操作员名字
    QString m_name = "";
};

QX_REGISTER_HPP_QM(LogEnt, BaseEnt, 1)

typedef QSharedPointer<LogEnt> LogEntPtr;
typedef qx::QxCollection<long, LogEntPtr> List_LogEnt;

Q_DECLARE_METATYPE(LogEntPtr);

#endif
/// LOGENT_H
