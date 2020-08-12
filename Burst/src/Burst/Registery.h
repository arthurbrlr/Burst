#pragma once

#include "Types.h"
#include "Entity.h"
#include "ComponentPool.h"

namespace Burst {

	class Component;

	class Registery {

		public:
			Entity NewEntity()
			{
				static GUID nextGuid = 0;
				_entities[nextGuid]._guid = nextGuid;
				return _entities[nextGuid++];
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

			template<typename T, typename... Args>
			T* AddComponent(Entity& entity, Args... args)
			{
				ComponentID compID = GetComponentID<T>();
#ifdef _DEBUG
				std::cout << std::endl;
				std::cout << "Emplacing component of id : " << compID << " into entity " << entity._guid << std::endl;
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
				return;
			}

			template<typename T>
			std::unordered_map<GUID, Component*>& View()
			{
				ComponentID compID = GetComponentID<T>();
				return _componentPools[compID].View();
			}


			template<typename T>
			T* GetComponent(Entity& entity)
			{
				ComponentID compID = GetComponentID<T>();
				if ( _componentPools.size() <= compID ) return nullptr;
				return (T*)_componentPools[compID].At(entity);
			}

		private:
			using Entities = std::unordered_map<GUID, Entity>;
			using Components = std::unordered_map<ComponentID, ComponentPool>;

			Entities _entities;
			Components _componentPools;

	};
}

