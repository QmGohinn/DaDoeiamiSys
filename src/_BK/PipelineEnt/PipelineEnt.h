///*********************************
///
/// 高压管道总览表
///

#ifndef PIPELINEENT_H
#define PIPELINEENT_H

#include "../../_BK/BaseEnt/BaseEnt.h"
#include "../../_BK/InspectorEnt/InspectorEnt.h"

class PipelineEnt;

/// 用户管理
class QX_QM_EXPORT PipelineEnt : public BaseEnt
{
    QX_REGISTER_FRIEND_CLASS(PipelineEnt)
    QX_PERSISTABLE_HPP(PipelineEnt)

public:
    PipelineEnt() : BaseEnt() {}
    virtual ~PipelineEnt() {}
    virtual void makeAbstractClass() { ; }

    /// DIY Param
    QString m_devSerial = "";
    /// baseinfo
    InspecorEnt m_baseInfo;
};

QX_REGISTER_HPP_QM(PipelineEnt, BaseEnt, 1)

typedef QSharedPointer<PipelineEnt> PipelineEntPtr;
typedef qx::QxCollection<long, PipelineEnt> List_PipelineEnt;

Q_DECLARE_METATYPE(PipelineEntPtr);

#endif // PIPELINEENT_H
