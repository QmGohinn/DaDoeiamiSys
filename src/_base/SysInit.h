#ifndef SYSINIT_H
#define SYSINIT_H

class SysInit
{
public:
    SysInit();
    ~SysInit();

public:
    /// Include DBSetup::DBConnect Func
    static void Init();
    /// add a default user named 'qm' passworded 'qm'
    /// when user num == 0
    static void AddDefaultUser();
};

#endif // SYSINIT_H
