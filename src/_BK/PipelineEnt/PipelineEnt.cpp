#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "PipelineEnt.h"

QX_REGISTER_CPP_QM(PipelineEnt)
QX_PERSISTABLE_CPP(PipelineEnt)

namespace qx {
template<>
void register_class(QxClass<PipelineEnt> &t)
{
    t.id(&PipelineEnt::id, "id");

    t.setName("pipeline");


}
} // namespace qx
