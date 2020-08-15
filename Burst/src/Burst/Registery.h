#pragma once

#include "Types.h"
#include "ComponentPool.h"

namespace Burst {

	class Component;

	static Entity nextEntity = 0;

	template<typename TExternalEntityIdentifier = Entity>
	class Registery {

		public:

				/* ENTITIES */

			Entity NewEntity(const TExternalEntityIdentifier& id = nextEntity)
			{
				_entities[id] = nextEntity;
				return (Entity)nextEntity++;
			}


			void DeleteEntity(Entity& entity)
			{
				/*
				for (auto& componentPair : _componentPools)
				{
					componentPair.second.At(entity);
				}

				_entities.erase(entity._guid);
				*/
			}


				/* COMPONENTS */

			template<typename T, typename... Args>
			T* AddComponent(Entity& entity, Args... args)
			{
				ComponentID compID = GetComponentID<T>();
#ifdef _DEBUG
				std::cout << std::endl;
				std::cout << "Emplacing component of id : " << compID << " into entity " << entity << std::endl;
#endif
				if ( !_componentPools[compID].Initialised() ) {
					_componentPools[compID].InitialisePool<T>(10000);
				}
				return _componentPools[compID].CreateComponent<T>(entity, args...);
			}

			template<typename T>
			void RemoveComponent(Entity& entity)
			{
				ComponentID compID = GetComponentID<T>();
				if ( _componentPools.size() <= compID ) {
					return;
				}
				_componentPools[compID].RemoveComponent<T>(entity);
#ifdef _DEBUG
				std::cout << "Removing component of id : " << compID << " of entity " << entity << std::endl;
#endif
				return;
			}

			template<typename T>
			T* GetComponent(Entity& entity)
			{
				ComponentID compID = GetComponentID<T>();
				if ( _componentPools.size() <= compID ) return nullptr;
				return (T*)_componentPools[compID].At(entity);
			}

			template<typename T>
			bool HasComponent(Entity& entity)
			{
				ComponentID compID = GetComponentID<T>();
				if ( _componentPools[compID].At(entity) ) {
#ifdef _DEBUG
					std::cout << "Entity " << entity << " has component of id : " << compID << std::endl;
#endif
					return true;
				}
#ifdef _DEBUG
				std::cout << "Entity " << entity << " has no component of id : " << compID << std::endl;
#endif
				return false;
			}


				/* COMPONENT VIEWS */

			template<typename T>
			std::unordered_map<Entity, Component*>& View()
			{
				ComponentID compID = GetComponentID<T>();
				return _componentPools[compID].View();
			}

			std::vector<Component*> View(Entity entity)
			{
				std::vector<Component*> view;
				for ( auto& pool : _componentPools ) {
					if ( pool.second.At(entity) ) {
#ifdef _DEBUG
						std::cout << "Component " << typeid( pool.second.At(entity) ).name() << " found for entity " << entity << std::endl;
#endif
						view.push_back(pool.second.At(entity));
					}
				}
				return view;
			}


				/* ENTITIES VIEWS */

			const std::unordered_map<TExternalEntityIdentifier, Entity>& ViewEntities()
			{
				return _entities;
			}

			Entity GetEntityFromEntityID(const TExternalEntityIdentifier& id)
			{
				return _entities[id];
			}

		private:
			using Entities = std::unordered_map<TExternalEntityIdentifier, Entity>;
			using Components = std::unordered_map<ComponentID, ComponentPool>;

			Entities _entities;
			Components _componentPools;

	};
}

