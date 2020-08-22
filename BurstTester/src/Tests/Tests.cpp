#include "Tests.h"

#include "../TestComponents.h"

bool Emplace_View()
{
	START_TEST(Emplace_And_View);

	Burst::Registery<> registery;
	Burst::Entity entity = registery.NewEntity();

	registery.AddComponent<Transform>(entity);
	registery.AddComponent<Sprite>(entity);
	registery.AddComponent<PtrComponent>(entity);
	registery.AddComponent<Mesh>(entity);

	auto entityComponents = registery.View(entity);
	ASSERT(entityComponents.size() == 4)

	END_TEST(Emplace_And_View);
}


bool Emplace_Remove_View()
{
	START_TEST(Emplace_Remove_View);

	Burst::Registery<> registery;
	Burst::Entity entity = registery.NewEntity();

	registery.AddComponent<Transform>(entity);
	registery.AddComponent<Sprite>(entity);
	registery.AddComponent<PtrComponent>(entity);
	registery.AddComponent<Mesh>(entity);

	registery.RemoveComponent<Transform>(entity);
	registery.RemoveComponent<Sprite>(entity);

	auto entityComponents = registery.View(entity);
	ASSERT(entityComponents.size() == 2)

	END_TEST(Emplace_Remove_View);
}


bool Emplace_RemoveEntity_View()
{
	START_TEST(Emplace_Remove_View);

	Burst::Registery<> registery;
	Burst::Entity entity = registery.NewEntity();

	registery.AddComponent<Transform>(entity);
	registery.AddComponent<Sprite>(entity);
	registery.AddComponent<PtrComponent>(entity);
	registery.AddComponent<Mesh>(entity);

	registery.RemoveEntity(entity);

	auto entityComponents = registery.View(entity);
	ASSERT(entityComponents.size() == 0)

	END_TEST(Emplace_RemoveEntity_View);
}


bool ClearRegistery()
{
	START_TEST(ClearRegistery);

	Burst::Registery<> registery;
	Burst::Entity entity = registery.NewEntity();
	Burst::Entity player = registery.NewEntity();

	registery.AddComponent<Transform>(entity);
	registery.AddComponent<Sprite>(entity);
	registery.AddComponent<PtrComponent>(player);
	registery.AddComponent<Mesh>(player);

	registery.Clear();

	ASSERT(registery.ViewEntities().size() == 0)
	ASSERT(registery.View(entity).size() == 0)
	ASSERT(registery.View(player).size() == 0)

	END_TEST(ClearRegistery);
}


bool Perfos_AddComponent()
{
	START_TEST(Perfos_AddComponent);

	Burst::Registery<> registery;
	
	for ( int i = 0; i < 10000; i++ ) {
		Burst::Entity newEntity = registery.NewEntity();
		registery.AddComponent<PtrComponent>(newEntity);
	}

	ASSERT(registery.View<PtrComponent>().size() == 10000)

	END_TEST(Perfos_AddComponent);
}