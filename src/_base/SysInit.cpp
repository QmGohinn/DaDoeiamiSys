#include "SysInit.h"
#include "../_base/DBSetup.h"
#include "../_base/UVGlobal.h"

#include "../_BK/AccountEnt/AccountEnt.h"
#include "../_BK/TotalShow/TotalShow.h"

void SysInit::Init()
{
    /// Connect PSQL
    DBSetup::DBConnect();

    /// Global param Ready
    UVGlobal::init();

    /// Add a default user
    DBSetup::AddDefaultUser();

    /// simulate totalshow table data into db
    DBSetup::DBInsertSimulate();
}
