///*********************************
///
/// 高温锅炉总览表
///

#ifndef BOILERENT_H
#define BOILERENT_H

#include "../../_BK/BaseEnt/BaseEnt.h"

class BoilerEnt;

/// 用户管理
class QX_QM_EXPORT BoilerEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(BoilerEnt)
    QX_PERSISTABLE_HPP(BoilerEnt)

public:
    BoilerEnt() : BaseEnt() {}
    virtual ~BoilerEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param

};

QX_REGISTER_HPP_QM(BoilerEnt, BaseEnt, 1)

typedef QSharedPointer<BoilerEnt> BoilerEntPtr;
typedef qx::QxCollection<long, BoilerEnt> List_BoilerEnt;

Q_DECLARE_METATYPE(BoilerEntPtr);

#endif // BOILERENT_H
