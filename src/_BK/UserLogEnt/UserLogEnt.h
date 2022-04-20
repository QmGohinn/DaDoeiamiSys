///*********************************
///
/// 用户登录日志表
///

#ifndef USERLOGENT_H
#define USERLOGENT_H

#include <src/_BK/BaseEnt/BaseEnt.h>

class TransformerEnt;

/// 用户管理
class QX_QM_EXPORT UserLogEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(UserLogEnt)
    QX_PERSISTABLE_HPP(UserLogEnt)

public:
    UserLogEnt() : BaseEnt() {}
    virtual ~UserLogEnt() {}
    virtual void makeAbstractClass() { ; }

    QString m_msg = "";
    QString m_name = "";

    static void Create(const QString&, const QString&);
};

QX_REGISTER_HPP_QM(UserLogEnt, BaseEnt, 1)

typedef QSharedPointer<UserLogEnt> UserLogEntPtr;
typedef qx::QxCollection<long, UserLogEntPtr> List_UserLogEnt;

Q_DECLARE_METATYPE(UserLogEntPtr);

#endif // USERLOGENT_H
