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

#ifdef NDEBUG
    bool perfAddComponent = Perfos_AddComponent();
#endif
}