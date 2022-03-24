#ifndef BASEENT_H
#define BASEENT_H

/// 数据库关系映射基础类
class QX_QM_EXPORT BaseEnt : public qx::IxPersistable
{
    QX_REGISTER_FRIEND_CLASS(BaseEnt)
protected:
public:
    BaseEnt() : id(0)  { ; }
    virtual ~BaseEnt()   { ; }
    virtual void makeAbstractClass() = 0;

    long id;
    QDateTime createdAt;
    QDateTime updatedAt;
    int deleted = 0;
    QString userModification;

    void onBeforeInsert(qx::dao::detail::IxDao_Helper* dao);
    void onBeforeUpdate(qx::dao::detail::IxDao_Helper* dao);
};

QX_REGISTER_ABSTRACT_CLASS(BaseEnt)
QX_REGISTER_HPP_QM(BaseEnt, qx::trait::no_base_class_defined, 0)

namespace qx {
namespace dao {
namespace detail {

template <>
struct QxDao_Trigger<BaseEnt>
{
   static inline void onBeforeInsert(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao) { if (t) { t->onBeforeInsert(dao); } }
   static inline void onBeforeUpdate(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao) { if (t) { t->onBeforeUpdate(dao); } }
   static inline void onBeforeDelete(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao) { Q_UNUSED(t); Q_UNUSED(dao); }
   static inline void onBeforeFetch(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao)  { Q_UNUSED(t); Q_UNUSED(dao); }
   static inline void onAfterInsert(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao)  { Q_UNUSED(t); Q_UNUSED(dao); }
   static inline void onAfterUpdate(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao)  { Q_UNUSED(t); Q_UNUSED(dao); }
   static inline void onAfterDelete(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao)  { Q_UNUSED(t); Q_UNUSED(dao); }
   static inline void onAfterFetch(BaseEnt* t, qx::dao::detail::IxDao_Helper* dao)   { Q_UNUSED(t); Q_UNUSED(dao); }
};

} // namespace detail
} // namespace dao
} // namespace qx

#endif // BASEENT_H
