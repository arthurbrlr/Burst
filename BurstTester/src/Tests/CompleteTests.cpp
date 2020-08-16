#include "Tests.h"
#include "../TestComponents.h"

#include <random>
#include <sstream>

bool BurstTest_CompleteTest_NormalRegistery()
{
    START_TEST(BurstTest_CompleteTest_NormalRegistery);

    try {
        Burst::Registery<> registery;
        Burst::Entity player = registery.NewEntity();
        Burst::Entity enemy = registery.NewEntity();
        Burst::Entity enemy2 = registery.NewEntity();
        Burst::Entity enemy3 = registery.NewEntity();
        Burst::Entity god = registery.NewEntity();
        Burst::Entity devil = registery.NewEntity();
        Burst::Entity dice = registery.NewEntity();

        Transform* playerTransform = registery.AddComponent<Transform>(player);
        registery.HasComponent<Transform>(player);
        registery.HasComponent<Sprite>(player);
        playerTransform->Print();

        Transform* enemyTransform = registery.AddComponent<Transform>(enemy, 4096.f);
        registery.AddComponent<Transform>(enemy2, 4096.f, 16024.f);
        registery.AddComponent<Transform>(enemy3, 4096.4096f, 16024.f, 16024.f);

        registery.RemoveComponent<Transform>(player);
        playerTransform = registery.AddComponent<Transform>(player, 1.f, 1.f, 1.f);
        playerTransform->Print();

        registery.AddComponent<Transform>(god);
        registery.RemoveComponent<Transform>(enemy3);
        registery.AddComponent<Transform>(devil);
        registery.AddComponent<Transform>(dice);
        registery.RemoveComponent<Transform>(player);
        registery.AddComponent<Transform>(enemy3);
        registery.AddComponent<Transform>(player);

        playerTransform = registery.GetComponent<Transform>(player);
        if ( playerTransform ) {
            playerTransform->Set(51, 20);
            playerTransform->Print();
        }

        if ( enemyTransform ) {
            enemyTransform->Print();
        }

        registery.AddComponent<Sprite>(player);

        auto playerComponents = registery.View(player);

        auto allEntities = registery.ViewEntities();

        auto allTransforms = registery.View<Transform>();
        auto allSprites = registery.View<Sprite>();
        auto allMeshes = registery.View<Mesh>();
    } catch ( std::exception e ) {
        std::cout << e.what() << std::endl;
        success = false;
    }

    END_TEST(BurstTest_CompleteTest_NormalRegistery);
    return success;
}


bool BurstTest_CompleteTest_TemplatedRegistery()
{
    typedef std::string UUID;
    auto NewUUID = []() {
        static std::random_device              rd;
        static std::mt19937                    gen(rd());
        static std::uniform_int_distribution<> dis(0, 15);
        static std::uniform_int_distribution<> dis2(8, 11);

        // TODO : keep track of existing UUIDs

        std::stringstream ss;
        int i;
        ss << std::hex;
        for ( i = 0; i < 8; i++ ) {
            ss << dis(gen);
        }
        //ss << "-";
        for ( i = 0; i < 4; i++ ) {
            ss << dis(gen);
        }
        //ss << "-";
        for ( i = 0; i < 4; i++ ) {
            ss << dis(gen);
        }
        //ss << "-";
        ss << dis2(gen);
        for ( i = 0; i < 3; i++ ) {
            ss << dis(gen);
        }
        //ss << "-";
        for ( i = 0; i < 12; i++ ) {
            ss << dis(gen);
        };
        return (UUID)ss.str();
    };

    START_TEST(BurstTest_CompleteTest_TemplatedRegistery);

    try {
        Burst::Registery<UUID> registery;
        Burst::Entity player = registery.NewEntity(NewUUID());
        Burst::Entity enemy = registery.NewEntity(NewUUID());
        Burst::Entity enemy2 = registery.NewEntity(NewUUID());
        Burst::Entity enemy3 = registery.NewEntity(NewUUID());
        Burst::Entity god = registery.NewEntity(NewUUID());
        Burst::Entity devil = registery.NewEntity(NewUUID());
        Burst::Entity dice = registery.NewEntity(NewUUID());

        Transform* playerTransform = registery.AddComponent<Transform>(player);
        registery.HasComponent<Transform>(player);
        registery.HasComponent<Sprite>(player);
        playerTransform->Print();

        Transform* enemyTransform = registery.AddComponent<Transform>(enemy, 4096.f);
        registery.AddComponent<Transform>(enemy2, 4096.f, 16024.f);
        registery.AddComponent<Transform>(enemy3, 4096.4096f, 16024.f, 16024.f);

        registery.RemoveComponent<Transform>(player);
        playerTransform = registery.AddComponent<Transform>(player, 1.f, 1.f, 1.f);
        playerTransform->Print();

        registery.AddComponent<Transform>(god);
        registery.RemoveComponent<Transform>(enemy3);
        registery.AddComponent<Transform>(devil);
        registery.AddComponent<Transform>(dice);
        registery.RemoveComponent<Transform>(player);
        registery.AddComponent<Transform>(enemy3);
        registery.AddComponent<Transform>(player);

        playerTransform = registery.GetComponent<Transform>(player);
        if ( playerTransform ) {
            playerTransform->Set(51, 20);
            playerTransform->Print();
        }

        if ( enemyTransform ) {
            enemyTransform->Print();
        }

        registery.AddComponent<Sprite>(player);

        auto playerComponents = registery.View(player);

        auto allEntities = registery.ViewEntities();

        auto allTransforms = registery.View<Transform>();
        auto allSprites = registery.View<Sprite>();
        auto allMeshes = registery.View<Mesh>();

        registery.AddComponent<Mesh>(player);
    } catch ( std::exception e ) {
        std::cout << e.what() << std::endl;
        success = false;
    }

    END_TEST(BurstTest_CompleteTest_TemplatedRegistery);
    return success;
}