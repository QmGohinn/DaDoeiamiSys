#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "BoilerEnt.h"

QX_REGISTER_CPP_QM(BoilerEnt)
QX_PERSISTABLE_CPP(BoilerEnt)

namespace qx {
template<>
void register_class(QxClass<BoilerEnt> &t)
{
    t.id(&BoilerEnt::id, "id");

    t.setName("boiler");

    t.data(&BoilerEnt::m_devSerial, "devserial", 1);
    t.data(&BoilerEnt::m_baseInfo, "baseinfo", 1);
}
} // namespace qx
