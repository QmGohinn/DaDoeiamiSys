#include "SysInit.h"
#include <src/_base/DBSetup.h>
#include <src/_base/UVGlobal.h>
#include <src/_BK/AccountEnt/AccountEnt.h>
#include <src/_BK/TotalShow/TotalShow.h>

void SysInit::Init()
{
    /// Global param Ready
    UVGlobal::init();

    /// Connect PSQL
    DBSetup::DBConnect();

    /// Add a default user
    DBSetup::AddDefaultUser();

    /// simulate totalshow table data into db
    DBSetup::DBInsertSimulate();
}
