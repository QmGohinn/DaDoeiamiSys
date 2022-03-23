#include "SysInit.h"
#include "../_base/DBSetup.h"
#include "../_base/UVGlobal.h"

#include "../_BK/AccountEnt/AccountEnt.h"
#include "../_BK/TotalShow/TotalShow.h"

void SysInit::Init()
{
    /// Connect PSQL
    DBSetup::DBConnect();
    /// Add a default user
    DBSetup::AddDefaultUser();
    /// Global param Ready
    UVGlobal::init();
    /// simulate totalshow table data into db
    DBSetup::DBInsertSimulate();
}
