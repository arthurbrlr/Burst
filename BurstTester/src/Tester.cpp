// ECS lib tester

#include <iostream>
#include <chrono>

#include "Burst.h"
#include "Components.h"

int main()
{
    Burst::Registery registery;
    Burst::Entity& player = registery.NewEntity();
    Burst::Entity& enemy = registery.NewEntity();

#if 0
    auto start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i < 1000; i++ ) {
        registery.AddComponent<Transform>(ent);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>( end - start );

    std::cout << "1 000 AddComponent: " << elapsed.count() << " s" << std::endl;
#endif

    registery.AddComponent<Transform>(player);
    registery.AddComponent<Transform>(enemy);

    registery.RemoveComponent<Transform>(player);

    Transform* playerTransform = registery.GetComponent<Transform>(player);
    if ( playerTransform ) {
        playerTransform->Set(51, 20);
        playerTransform->Print();
    }

    registery.AddComponent<Sprite>(player);

    auto allTransforms = registery.View<Transform>();
    auto allSprites = registery.View<Sprite>();
    auto allMeshes = registery.View<Mesh>();

    //Transform::PrintID();
    //Sprite::PrintID();
    //Mesh::PrintID();
}