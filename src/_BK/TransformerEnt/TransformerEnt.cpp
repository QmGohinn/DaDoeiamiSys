#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "TransformerEnt.h"

QX_REGISTER_CPP_QM(TransformerEnt)
QX_PERSISTABLE_CPP(TransformerEnt)

namespace qx {
template<>
void register_class(QxClass<TransformerEnt> &t)
{
    t.id(&TransformerEnt::id, "id");

    t.setName("transformer");


}
} // namespace qx