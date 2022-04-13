///*********************************
///
/// 高温锅炉总览表
///

#ifndef BOILERENT_H
#define BOILERENT_H

#include <src/_BK/BaseEnt/BaseEnt.h>
#include <src/_BK/InspectorEnt/InspectorEnt.h>

class BoilerEnt;

/// 锅炉
class QX_QM_EXPORT BoilerEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(BoilerEnt)
    QX_PERSISTABLE_HPP(BoilerEnt)

public:
    BoilerEnt() : BaseEnt() {}
    virtual ~BoilerEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param
    QString m_devSerial = "";
    /// baseinfo
    InspecorEnt m_baseInfo;

    static void Create(const QString&, const InspecorEnt&);
};

QX_REGISTER_HPP_QM(BoilerEnt, BaseEnt, 1)

typedef QSharedPointer<BoilerEnt> BoilerEntPtr;
typedef qx::QxCollection<long, BoilerEnt> List_BoilerEnt;

Q_DECLARE_METATYPE(BoilerEntPtr);

#endif // BOILERENT_H
