///*********************************
///
/// 输煤皮带总览表
///

#ifndef BELTENT_H
#define BELTENT_H

#include "../../_BK/InspectorEnt/InspectorEnt.h"
#include "../../_BK/BaseEnt/BaseEnt.h"

class BeltEnt;

class QX_QM_EXPORT BeltEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(BeltEnt)
    QX_PERSISTABLE_HPP(BeltEnt)

public:
    BeltEnt() : BaseEnt() {}
    virtual ~BeltEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param
    QString m_devSerial = "";
    /// baseinfo
    InspecorEnt m_baseInfo;

    static void Create(const QString&, const InspecorEnt&);
};

QX_REGISTER_HPP_QM(BeltEnt, BaseEnt, 1)

typedef QSharedPointer<BeltEnt> BeltEntPtr;
typedef qx::QxCollection<long, BeltEnt> List_BeltEnt;

Q_DECLARE_METATYPE(BeltEntPtr);

#endif // BELTENT_H
