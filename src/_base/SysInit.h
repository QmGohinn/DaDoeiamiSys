/*
 *  系统初始化头文件
 *  可能包括一些数据库操作
 *  和全局变量初始化操作
*/

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
