#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "AccountEnt.h"
#include "../LogEnt/LogEnt.h"

QX_REGISTER_CPP_QM(UserEnt)
QX_PERSISTABLE_CPP(UserEnt)

namespace qx {
template<>
void register_class(QxClass<UserEnt> &t)
{
    t.id(&UserEnt::id, "user_ent_id");

    t.setName("userlist");

    t.data(&UserEnt::userName, "username", 1);
    t.data(&UserEnt::password, "password", 1);
    t.data(&UserEnt::role, "role", 1);
}
} // namespace qx

void UserEnt::Create(const QString & _username, const QString & _password, const int & _role)
{
    UserEntPtr p;
    p.reset(new UserEnt());

    p->userName = _username;
    p->password = _password;
    p->role = _role;

    qx::dao::save(p);

//    LogEnt::Create(SysLog, QString("新建用户").arg(_username));
}
