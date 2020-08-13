#pragma once

#include "Types.h"
#include "ComponentPool.h"

namespace Burst {

	class Component;

	class Registery {

		public:

				/* ENTITIES */

			Entity NewEntity()
			{
				static Entity next = 0;
				return (Entity)next++;
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
				if ( _componentPools.size() <= compID ) {
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

			template<typename T>
			std::unordered_map<Entity, Component*>& View()
			{
				ComponentID compID = GetComponentID<T>();
				return _componentPools[compID].View();
			}


		private:
			using Components = std::unordered_map<ComponentID, ComponentPool>;

			Components _componentPools;

	};
}

