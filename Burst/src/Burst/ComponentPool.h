#pragma once

#include "Types.h"
#include "Component.h"

#include <unordered_map>
#include <stdexcept>

#ifdef _BURST_DEBUG
	#include <iostream>
#endif

namespace Burst {

	class ComponentPool {

		public:
			ComponentPool()
				: _pool(nullptr), _next(nullptr), _refBlock(nullptr)
			{
			}

			~ComponentPool()
			{
				//delete[] _pool;
				if ( _pool )
					free(_pool);
				if ( _refBlock )
					free(_refBlock);
			}

			template<typename T>
			void InitialisePool(size_t poolSize)
			{
				_poolSize = poolSize;
				//_pool = new T[_poolSize];
				_pool = calloc( sizeof(T), poolSize );
				_refBlock = calloc( sizeof(T), (size_t)1 );
#ifdef _BURST_DEBUG
				std::cout << "Initialising pool of component " << typeid(T).name() << " (ID: " << GetComponentID<T>() << ") with a size of: " << poolSize << std::endl;
				std::cout << "Size of the pool: " << sizeof(T) * poolSize << " bytes." << std::endl;
				std::cout << "Pool is at adress: " << _pool << std::endl;
#endif
				_next = _pool;
				_poolID = T::GetStaticComponentID();
				_count = 0;
			}

			template<typename T, typename... Args>
			T* CreateComponent(Entity& entity, Args... args)
			{
				if ( _poolSize < _count + 1 ) {
					throw std::out_of_range::exception(); // Error: pool has no more space
					return nullptr;
				}

				//_componentAccessors[entity] = (T*)_next;
				//T newComponent = T(args...);
				//memcpy(_componentAccessors[entity], (void*)&newComponent, sizeof(T));
				//T* newComponent = new ( _next ) T(args...);
				_componentAccessors[entity] = (T*)(new ( _next ) T(args...));//(T*)_next;
				_componentAccessors[entity]->Attach(entity); 

				_next = static_cast<char*>( _next ) + sizeof(T);

				while ( memcmp(_refBlock, _next, sizeof(T)) != 0 ) {
					_next = static_cast<char*>( _next ) + sizeof(T);
				}
				_count++;
#ifdef _BURST_DEBUG
				std::cout << "New " << typeid(T).name() << " at adress: 0x" << (int*)(_componentAccessors[entity]) << std::endl;
				std::cout << "Next will be at adress: 0x" << (int*)(_next) << std::endl;
				std::cout << "----" << std::endl;
#endif
				return (T*)_componentAccessors[entity];
			}

			void RemoveComponent(Entity& entity)
			{
				void* ptrToComponent = (void*)_componentAccessors[entity];
				_componentAccessors.erase(entity);
				//memset(ptrToComponent, 0, sizeof(T));
				_next = ptrToComponent;
				_count--;
			}

			const size_t NumberOf() const
			{
				return _count;
			}

			Component* At(Entity& entity)
			{
				if ( _componentAccessors.find(entity) != _componentAccessors.end() ) {
					return _componentAccessors[entity];
				}
				return nullptr;
			}

			std::unordered_map<Entity, Component*>& View()
			{
				return _componentAccessors;
			}

			const bool Initialised()
			{
				return _pool != nullptr;
			}


		private:
			void* _pool;
			size_t _poolSize;
			ComponentID _poolID;
			size_t _count;

			void* _next;
			void* _refBlock;
			
			std::unordered_map<Entity, Component*> _componentAccessors;
	};

}