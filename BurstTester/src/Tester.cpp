// ECS lib tester

#include <iostream>
#include <chrono>

#include "Burst.h"
#include "Components.h"

int main()
{
    Burst::Registery registery;
    Burst::Entity player = registery.NewEntity();
    Burst::Entity enemy = registery.NewEntity();
    Burst::Entity enemy2 = registery.NewEntity();
    Burst::Entity enemy3 = registery.NewEntity();
    Burst::Entity god = registery.NewEntity();
    Burst::Entity devil = registery.NewEntity();
    Burst::Entity dice = registery.NewEntity();

#if 0
    auto start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i < 1000; i++ ) {
        registery.AddComponent<Transform>(ent);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>( end - start );

    std::cout << "1 000 AddComponent: " << elapsed.count() << " s" << std::endl;
#endif

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

    auto allTransforms = registery.View<Transform>();
    auto allSprites = registery.View<Sprite>();
    auto allMeshes = registery.View<Mesh>();

}