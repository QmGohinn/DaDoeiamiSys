#include "../../_base/precompiled.h"
#include <QxOrm_Impl.h>

#include "LogEnt.h"
#include "../../_base/UVGlobal.h"

QX_REGISTER_CPP_QM(LogEnt)
QX_PERSISTABLE_CPP(LogEnt)

namespace qx {
template<>
void register_class(QxClass<LogEnt> &t)
{
    t.id(&LogEnt::id, "id");

    t.setName("dblog");

    t.data(&LogEnt::m_type, "type", 1);
    t.data(&LogEnt::m_msg, "msg", 1);
    t.data(&LogEnt::m_mmsg, "mmsg", 1);
    t.data(&LogEnt::m_name, "username", 1);
}
} // namespace qx

void LogEnt::Create(const LogType& _type, const QString& _msg, const QString& _mmsg)
{
    LogEntPtr _tmpLog;
    _tmpLog.reset(new LogEnt());

    _tmpLog->m_type = _type;
    _tmpLog->m_msg = _msg;
    _tmpLog->m_mmsg = _mmsg;

    _tmpLog->m_name = UVGlobal::g_userName;

    qx::dao::save(_tmpLog);
}
