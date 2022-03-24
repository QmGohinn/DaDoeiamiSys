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


}
} // namespace qx
