#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "TotalShow.h"

QX_REGISTER_CPP_QM(TotalShowEnt)
QX_PERSISTABLE_CPP(TotalShowEnt)

namespace qx {
template<>
void register_class(QxClass<TotalShowEnt> &t)
{
    t.id(&TotalShowEnt::id, "id");

    t.setName("totalshow");

    t.data(&TotalShowEnt::devType, "devtype", 1);
    t.data(&TotalShowEnt::totalDevNum, "totaldevnum", 1);
    t.data(&TotalShowEnt::realDevNum, "realdevnum", 1);
    t.data(&TotalShowEnt::questionDevNum, "questiondevnum", 1);
    t.data(&TotalShowEnt::errorDevNum, "errordevnum", 1);
}
} // namespace qx
