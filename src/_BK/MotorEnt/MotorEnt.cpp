#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "MotorEnt.h"
#include "../LogEnt/LogEnt.h"

QX_REGISTER_CPP_QM(MotorEnt)
QX_PERSISTABLE_CPP(MotorEnt)

namespace qx {
template<>
void register_class(QxClass<MotorEnt> &t)
{
    t.id(&MotorEnt::id, "id");

    t.setName("motor");

    t.data(&MotorEnt::m_devSerial, "devserial", 1);
    t.data(&MotorEnt::m_baseInfo, "baseinfo", 1);
}
} // namespace qx

void MotorEnt::Create(const QString & _devserial, const InspecorEnt & _info)
{
    MotorEntPtr p;
    p.reset(new MotorEnt());

    p->m_devSerial = _devserial;
    p->m_baseInfo = _info;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("%1 新增一条巡检信息!").arg(_devserial),
                   QString("巡检结果为%1").arg(UVGlobal::gFunc_PatrolRes2Str(_info.m_res)));
}
