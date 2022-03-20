#include "SysInit.h"
#include "../_base/DBSetup.h"
#include "../_base/UVGlobal.h"

#include "../_BK/AccountEnt/AccountEnt.h"
#include "../_BK/TotalShow/TotalShow.h"

void SysInit::Init()
{
    DBSetup::DBConnect();
    SysInit::AddDefaultUser();
    UVGlobal::init();
}

void SysInit::AddDefaultUser()
{
    if (qx::dao::count<UserEnt>() == 0)
    {
        UserEntPtr u;
        u.reset(new UserEnt());
        u->userName = "qm";
        u->password = "qm";
        u->role = 1;
        qx::dao::save(u);
    }
}
