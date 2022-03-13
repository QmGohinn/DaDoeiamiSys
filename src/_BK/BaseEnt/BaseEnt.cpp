#include "src/_base/precompiled.h"
#include "BaseEnt.h"

#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QM(BaseEnt)

namespace qx {
template <> void register_class(QxClass<BaseEnt>& t)
{
   IxDataMember * pData = NULL;
   Q_UNUSED(pData)
   pData = t.data(& BaseEnt::createdAt, "created_at");
   pData = t.data(& BaseEnt::updatedAt, "updated_at");
   pData = t.data(& BaseEnt::deleted, "deleted");
   pData = t.data(& BaseEnt::userModification, "user_id");
}}


void BaseEnt::onBeforeInsert(qx::dao::detail::IxDao_Helper* dao)
{
   Q_UNUSED(dao);
   if(createdAt.isValid() || createdAt.isNull())
   {
       createdAt = QDateTime::currentDateTime();
       updatedAt = QDateTime::currentDateTime();
   }
}

void BaseEnt::onBeforeUpdate(qx::dao::detail::IxDao_Helper* dao)
{
   Q_UNUSED(dao);
//    if(createdAt.isValid() || createdAt.isNull())
//        createdAt = QDateTime::currentDateTime();

   updatedAt = QDateTime::currentDateTime();
   userModification = "1";
}
