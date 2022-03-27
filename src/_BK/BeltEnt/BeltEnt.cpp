#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "BeltEnt.h"
#include "../LogEnt/LogEnt.h"

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

void BeltEnt::Create(const QString & _devserial, const InspecorEnt & _info)
{
    BeltEntPtr p;
    p.reset(new BeltEnt());

    p->m_devSerial = _devserial;
    p->m_baseInfo = _info;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("%1 新增一条巡检信息!").arg(_devserial),
                   QString("巡检结果为%1").arg(UVGlobal::gFunc_PatrolRes2Str(_info.m_res)));
}
