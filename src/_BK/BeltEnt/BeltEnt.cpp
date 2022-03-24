#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "BeltEnt.h"

QX_REGISTER_CPP_QM(BeltEnt)
QX_PERSISTABLE_CPP(BeltEnt)

namespace qx {
template<>
void register_class(QxClass<BeltEnt> &t)
{
    t.id(&BeltEnt::id, "id");

    t.setName("belt");

    t.data(&BeltEnt::m_devSerial, "devserial", 1);
    t.data(&BeltEnt::m_baseInfo, "baseinfo", 1);
}
} // namespace qx
