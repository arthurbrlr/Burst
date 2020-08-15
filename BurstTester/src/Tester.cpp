// ECS lib tester

#include <iostream>
#include <chrono>

#include "Burst.h"
#include "Tests/Tests.h"

#include "Components.h"

BURST_COMPONENT(Transform)
BURST_COMPONENT(Sprite)
BURST_COMPONENT(Mesh)

int main()
{
    bool emplaceComponentResult = BurstTest_ComponentTest_Emplacing();
    bool removeComponentResult = BurstTest_ComponentTest_Removing();

    bool normalRegistery = BurstTest_CompleteTest_NormalRegistery();
    bool templatedRegistery = BurstTest_CompleteTest_TemplatedRegistery();


    std::cout << "****************" << std::endl;
    std::cout << "**** Recap: ****" << std::endl;
    std::cout << "****************" << std::endl;

    TEST_RESULT(BurstTest_ComponentTest_Emplacing, emplaceComponentResult);
    TEST_RESULT(BurstTest_ComponentTest_Removing, removeComponentResult);

    TEST_RESULT(BurstTest_CompleteTest_NormalRegistery, normalRegistery);
    TEST_RESULT(BurstTest_CompleteTest_TemplatedRegistery, templatedRegistery);
}