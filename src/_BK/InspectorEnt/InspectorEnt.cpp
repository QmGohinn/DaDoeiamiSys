#include <src/_base/precompiled.h>
#include <QxOrm_Impl.h>

#include "InspectorEnt.h"
#include <src/_BK/LogEnt/LogEnt.h>

#include <src/_base/UVGlobal.h>

QX_REGISTER_CPP_QM(InspecorEnt)
QX_PERSISTABLE_CPP(InspecorEnt)

namespace qx {
template<>
void register_class(QxClass<InspecorEnt> &t)
{
    t.id(&InspecorEnt::id, "id");

    t.setName("inspecorbaseinfo");

    t.data(&InspecorEnt::m_res, "res", 1);
    t.data(&InspecorEnt::m_name, "name", 1);
    t.data(&InspecorEnt::m_phone, "phone", 1);
    t.data(&InspecorEnt::m_patrolTime, "patroltime", 1);
    t.data(&InspecorEnt::m_devSerial, "devserial", 1);
}
} // namespace qx

InspecorEnt InspecorEnt::Create(const PATROLRES & _res, const QDateTime & _patroltime, const QString & _phone, const QString & _name, const QString & _devSerial)
{
    InspecorEntPtr p;
    p.reset(new InspecorEnt());

    p->m_res = _res;
    p->m_name = _name;
    p->m_phone = _phone;
    p->m_devSerial= _devSerial;
    p->m_patrolTime = _patroltime;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("%1 新提交一条巡检信息!").arg(_name),
                   QString("设备:%1 结果为:%2 联系方式为:%3")
                   .arg(_devSerial)
                   .arg(UVGlobal::gFunc_PatrolRes2Str(_res))
                   .arg(_phone));

    return *p;
}
