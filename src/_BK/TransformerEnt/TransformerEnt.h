///*********************************
///
/// 变压器总览表
///

#ifndef TRANSFORMERENT_H
#define TRANSFORMERENT_H

#include "../../_BK/BaseEnt/BaseEnt.h"
#include "../../_BK/InspectorEnt/InspectorEnt.h"

class TransformerEnt;

/// 用户管理
class QX_QM_EXPORT TransformerEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(TransformerEnt)
    QX_PERSISTABLE_HPP(TransformerEnt)

public:
    TransformerEnt() : BaseEnt() {}
    virtual ~TransformerEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param
    QString m_devSerial = "";
    /// baseinfo
    InspecorEnt m_baseInfo;
};

QX_REGISTER_HPP_QM(TransformerEnt, BaseEnt, 1)

typedef QSharedPointer<TransformerEnt> TransformerEntPtr;
typedef qx::QxCollection<long, TransformerEnt> List_TransformerEnt;

Q_DECLARE_METATYPE(TransformerEntPtr);

#endif // TRANSFORMERENT_H
