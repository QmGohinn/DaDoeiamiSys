#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "TransformerEnt.h"
#include "../LogEnt/LogEnt.h"

QX_REGISTER_CPP_QM(TransformerEnt)
QX_PERSISTABLE_CPP(TransformerEnt)

namespace qx {
template<>
void register_class(QxClass<TransformerEnt> &t)
{
    t.id(&TransformerEnt::id, "id");

    t.setName("transformer");

    t.data(&TransformerEnt::m_devSerial, "devserial", 1);
    t.data(&TransformerEnt::m_baseInfo, "baseinfo", 1);
}
} // namespace qx

void TransformerEnt::Create(const QString & _devserial, const InspecorEnt & _info)
{
    TransformerEntPtr p;
    p.reset(new TransformerEnt());

    p->m_devSerial = _devserial;
    p->m_baseInfo = _info;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("%1 新增一条巡检信息!").arg(_devserial),
                   QString("巡检结果为%1").arg(UVGlobal::gFunc_PatrolRes2Str(_info.m_res)));
}
