#include <src/_base/precompiled.h>
#include <QxOrm_Impl.h>

#include "UserLogEnt.h"

QX_REGISTER_CPP_QM(UserLogEnt)
QX_PERSISTABLE_CPP(UserLogEnt)

namespace qx {
template<>
void register_class(QxClass<UserLogEnt> &t)
{
    t.id(&UserLogEnt::id, "id");

    t.setName("userlog");

    t.data(&UserLogEnt::m_name, "name", 1);
    t.data(&UserLogEnt::m_msg, "msg", 1);
}
} // namespace qx

void UserLogEnt::Create(const QString & _name, const QString & _msg)
{
    UserLogEntPtr p;
    p.reset(new UserLogEnt());

    p->m_name = _name;
    p->m_msg = _msg;

    qx::dao::save(p);
}
