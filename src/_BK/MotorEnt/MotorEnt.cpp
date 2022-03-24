#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "MotorEnt.h"

QX_REGISTER_CPP_QM(MotorEnt)
QX_PERSISTABLE_CPP(MotorEnt)

namespace qx {
template<>
void register_class(QxClass<MotorEnt> &t)
{
    t.id(&MotorEnt::id, "id");

    t.setName("motor");


}
} // namespace qx
