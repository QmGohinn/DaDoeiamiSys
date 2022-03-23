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
};

#endif // SYSINIT_H
