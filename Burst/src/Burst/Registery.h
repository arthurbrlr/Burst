#pragma once

#include "Types.h"
#include "ComponentPool.h"

#include <assert.h>
#include <vector>

namespace Burst {

	class Component;

	template<typename TExternalEntityIdentifier = Entity>
	class Registery {

		public:

				/* ENTITIES */
			
			Entity NewEntity()
			{
				_entities[nextEntity] = nextEntity;
				return (Entity)nextEntity++;
			}


			Entity NewEntity(const TExternalEntityIdentifier& id)
			{
#ifdef _BURST_DEBUG
				std::cout << "Key is " << id << std::endl;
#endif
				_entities[id] = nextEntity;
				return (Entity)nextEntity++;
			}


			void RemoveEntity(Entity& entity)
			{
				for (auto& componentPair : _componentPools) {
					if ( componentPair.second.At(entity) )
						componentPair.second.RemoveComponent(entity);
				}
				_entities.erase(entity);
			}


			void RemoveEntity(const TExternalEntityIdentifier& id)
			{
				Entity entity = _entities[id];
				for ( auto& componentPair : _componentPools ) {
					if ( componentPair.second.At(entity) )
						componentPair.second.RemoveComponent(entity);
				}
				_entities.erase(id);
			}


			void Clear()
			{
				_componentPools.clear();
				_entities.clear();
				nextEntity = 0;
			}


				/* COMPONENTS */

			template<typename T, typename... Args>
			T* AddComponent(Entity& entity, Args... args)
			{
				ComponentID compID = T::GetStaticComponentID();
				assert(!HasComponent<T>(entity)); // Entity has already a component of type T !

#ifdef _BURST_DEBUG
				std::cout << std::endl;
				std::cout << "Emplacing component of id : " << compID << " into entity " << entity << std::endl;
#endif
				if ( !_componentPools[compID].Initialised() ) {
					_componentPools[compID].template InitialisePool<T>(10000);
				}
				return _componentPools[compID].template CreateComponent<T>(entity, args...);
			}

			template<typename T>
			void RemoveComponent(Entity& entity)
			{
				ComponentID compID = T::GetStaticComponentID();
				if ( _componentPools[compID].At(entity) ) {
					_componentPools[compID].RemoveComponent(entity);
#ifdef _BURST_DEBUG
					std::cout << "Removing component of id : " << compID << " of entity " << entity << std::endl;
#endif
				}
			}


			void RemoveComponent(Entity& entity, Component* component)
			{
				ComponentID compID = component->GetComponentID();
				if ( _componentPools[compID].At(entity) ) {
					_componentPools[compID].RemoveComponent(entity);
#ifdef _BURST_DEBUG
					std::cout << "Removing component of id : " << compID << " of entity " << entity << std::endl;
#endif
				}
			}

			template<typename T>
			T* GetComponent(Entity& entity)
			{
				ComponentID compID = T::GetStaticComponentID();
				assert(HasComponent<T>(entity)); // Entity has no component of type T !
				if ( _componentPools[compID].At(entity) ) return (T*)_componentPools[compID].At(entity);
				return nullptr;
			}

			template<typename T>
			bool HasComponent(Entity& entity)
			{
				ComponentID compID = T::GetStaticComponentID();
				if ( _componentPools[compID].At(entity) ) {
#ifdef _BURST_DEBUG
					std::cout << "Entity " << entity << " has component of id : " << compID << std::endl;
#endif
					return true;
				}
#ifdef _BURST_DEBUG
				std::cout << "Entity " << entity << " has no component of id : " << compID << std::endl;
#endif
				return false;
			}


				/* COMPONENT VIEWS */

			template<typename T>
			std::unordered_map<Entity, Component*>& View()
			{
				ComponentID compID = T::GetStaticComponentID();
				return _componentPools[compID].View();
			}

			std::vector<Component*> View(Entity entity)
			{
				std::vector<Component*> view;
				for ( auto& pool : _componentPools ) {
					if ( pool.second.At(entity) ) {
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

			Entity GetEntityFromExternID(const TExternalEntityIdentifier& id)
			{
				if ( _entities.find(id) != _entities.end() )
					return _entities[id];
				return -1;
			}

		private:
			using Entities = std::unordered_map<TExternalEntityIdentifier, Entity>;
			using Components = std::unordered_map<ComponentID, ComponentPool>;

			Entities _entities;
			Components _componentPools;
			Entity nextEntity = 0;
	};
}

