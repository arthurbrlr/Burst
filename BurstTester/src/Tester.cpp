// ECS lib tester

#include <iostream>
#include <chrono>

#include "Burst.h"
#include "Tests/Tests.h"

#include "TestComponents.h"


int main()
{
    bool emplaceView = Emplace_View();
    bool emplaceRemoveView = Emplace_Remove_View();
    bool emplaceRemoveEntityView = Emplace_RemoveEntity_View();
    bool clearRegistery = ClearRegistery();

    bool templated_emplaceRemoveView = Templated_Emplace_Remove_View();
    bool templated_emplaceRemoveEntityView = Templated_Emplace_RemoveEntity_View();

#ifndef _DEBUG
    bool perfAddComponent = Perfos_AddComponent();
#endif
}