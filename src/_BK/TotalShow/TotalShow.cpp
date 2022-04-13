#include <src/_base/precompiled.h>
#include <QxOrm_Impl.h>

#include "TotalShow.h"
#include <src/_BK/LogEnt/LogEnt.h>

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

void TotalShowEnt::Create(const QString & _devType, const int & _totalDevNum, const int & _realDevNum, const int & _questionDevNum, const int & _errorDevNum)
{
    TotalShowEntPtr p;
    p.reset(new TotalShowEnt());

    p->devType = _devType;
    p->totalDevNum = _totalDevNum;
    p->realDevNum = _realDevNum;
    p->questionDevNum = _questionDevNum;
    p->errorDevNum = _errorDevNum;

    qx::dao::save(p);

    LogEnt::Create(SysLog, QString("新加 / 更新%1设备总数").arg(_devType));
}
