#include <src/_base/precompiled.h>
#include <QxOrm_Impl.h>

#include "PipelineEnt.h"
#include <src/_BK/LogEnt/LogEnt.h>

QX_REGISTER_CPP_QM(PipelineEnt)
QX_PERSISTABLE_CPP(PipelineEnt)

namespace qx {
template<>
void register_class(QxClass<PipelineEnt> &t)
{
    t.id(&PipelineEnt::id, "id");

    t.setName("pipeline");

    t.data(&PipelineEnt::m_devSerial, "devserial", 1);
    t.data(&PipelineEnt::m_baseInfo, "baseinfo", 1);
}
} // namespace qx

void PipelineEnt::Create(const QString & _devserial, const InspecorEnt & _info)
{
    PipelineEntPtr p;
    p.reset(new PipelineEnt());

    p->m_devSerial = _devserial;
    p->m_baseInfo = _info;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("%1 新增一条巡检信息!").arg(_devserial),
                   QString("巡检结果为%1").arg(UVGlobal::gFunc_PatrolRes2Str(_info.m_res)));
}
