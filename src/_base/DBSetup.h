#ifndef DBSETUP_H
#define DBSETUP_H

class DBSetup
{
public:
    DBSetup();
    /// 数据库连接
    static void DBConnect();
    /// 插入模拟数据
    static void DBInsertSimulate();
    /// add a default user named 'qm' passworded 'qm'
    /// when user num == 0
    static void AddDefaultUser();
    /// 插入输煤皮带数据
    static void DB_Belt_Simulate();
    /// 插入高温锅炉数据
    static void DB_Boiler_Simulate();
    /// 插入汽机数据
    static void DB_Motor_Simulate();
    /// 插入高压管道数据
    static void DB_Pipeline_Simulate();
    /// 插入变压器数据
    static void DB_Transformer_Simulate();
private:
    /// 总数表模拟
    static void DB_TotalShow_Simulate();
};

#endif // DBSETUP_H
