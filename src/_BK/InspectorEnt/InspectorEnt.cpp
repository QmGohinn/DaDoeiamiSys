#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "InspectorEnt.h"

QX_REGISTER_CPP_QM(InspecorEnt)
QX_PERSISTABLE_CPP(InspecorEnt)

namespace qx {
template<>
void register_class(QxClass<InspecorEnt> &t)
{
    t.id(&InspecorEnt::id, "id");

    t.setName("inspecorbaseinfo");

    t.data(&InspecorEnt::m_res, "res", 1);
    t.data(&InspecorEnt::m_name, "name", 1);
    t.data(&InspecorEnt::m_phone, "phone", 1);
    t.data(&InspecorEnt::m_patrolTime, "patroltime", 1);
    t.data(&InspecorEnt::m_devSerial, "devserial", 1);
}
} // namespace qx
