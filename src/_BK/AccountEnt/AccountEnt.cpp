#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "AccountEnt.h"

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
