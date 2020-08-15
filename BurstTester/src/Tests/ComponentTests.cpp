#include "Tests.h"
#include "../Components.h"


bool BurstTest_ComponentTest_Emplacing()
{
    Burst::Registery<> registery;

    START_TEST(BurstTest_ComponentTest_Emplacing);

    try {
        for ( int i = 0; i < 1000; i++ ) {
            Burst::Entity newEntity;
            registery.AddComponent<Transform>(newEntity);
        }
    } catch ( std::exception e ) {
        std::cout << e.what() << std::endl;
        success = false;
    }
    
    END_TEST(BurstTest_ComponentTest_Emplacing);
    return success;
}

bool BurstTest_ComponentTest_Removing()
{
    Burst::Registery<> registery;
    for ( int i = 0; i < 1000; i++ ) {
        Burst::Entity newEntity;
        registery.AddComponent<Transform>(newEntity);
    }

    START_TEST(BurstTest_ComponentTest_Emplacing);

    try {
        for ( auto entity : registery.ViewEntities() ) {
            registery.RemoveComponent<Transform>(entity.second);
        }
    } catch ( std::exception e ) {
        std::cout << e.what() << std::endl;
        success = false;
    }

    END_TEST(BurstTest_ComponentTest_Removing);
    return success;
}