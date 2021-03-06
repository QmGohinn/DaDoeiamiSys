#include <src/_base/precompiled.h>
#include <QxOrm_Impl.h>

#include "BoilerEnt.h"
#include <src/_BK/LogEnt/LogEnt.h>

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

void BoilerEnt::Create(const QString & _devserial, const InspecorEnt & _info)
{
    BoilerEntPtr p;
    p.reset(new BoilerEnt());

    p->m_devSerial = _devserial;
    p->m_baseInfo = _info;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("%1 新增一条巡检信息!").arg(_devserial),
                   QString("巡检结果为%1").arg(UVGlobal::gFunc_PatrolRes2Str(_info.m_res)));
}
