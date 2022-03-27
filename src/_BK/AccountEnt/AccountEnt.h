///****************************************
///
/// 用户账号信息维护表
///

#ifndef ACCOUNTENT_H
#define ACCOUNTENT_H

#include "../../_BK/BaseEnt/BaseEnt.h"

class UserEnt;

/// 用户管理
class QX_QM_EXPORT UserEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(UserEnt)
    QX_PERSISTABLE_HPP(UserEnt)

public:
    UserEnt() : BaseEnt() {}
    virtual ~UserEnt() {}
    virtual void makeAbstractClass() { ; }

    long id;
    /// 账号
    QString userName;
    /// 密码
    QString password;
    /// 权限
    /// 1:admin  0:operator
    int role;

    static void Create(const QString&, const QString&, const int& _role = 0);
};

QX_REGISTER_HPP_QM(UserEnt, BaseEnt, 1)

typedef QSharedPointer<UserEnt> UserEntPtr;
typedef qx::QxCollection<long, UserEntPtr> List_UserEnt;

Q_DECLARE_METATYPE(UserEntPtr);

#endif
/// ACCOUNTENT_H
