#pragma once

#include "Types.h"
#include "Entity.h"
#include "Component.h"

#include <unordered_map>
#include <iostream>

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

				//std::cout << "Initialising pool of component ID: " << GetComponentID<T>() << " with a size of: " << poolSize << std::endl;
				//std::cout << "Size of the pool: " << sizeof(T) * poolSize << std::endl;
				//std::cout << "Pool is at adress: " << _pool << std::endl;

				_next = _pool;
				_poolID = GetComponentID<T>();
				_count = 0;
			}

			template<typename T>
			T* CreateComponent(Entity& entity)
			{
				if ( _poolSize < _count + 1 ) {
					throw std::out_of_range::exception("Error: pool has no more space");
					return nullptr;
				}

				_componentAccessors[entity._guid] = (T*)_next;
				_componentAccessors[entity._guid]->Attach(entity);

				_next = static_cast<char*>( _next ) + sizeof(T);
				//while ( !memcmp(_refBlock, _next, sizeof(T)) ) {
				//	_next = static_cast<char*>( _next ) + sizeof(T);
				//}
				_count++;

				//std::cout << "New component returned at adress: " << returned << std::endl;
				//std::cout << "Next component will be at adress: " << _next << std::endl;

				//std::cout << "The size of component with ID: " << GetComponentID<T>() << " is: " << sizeof(T) << "  bytes" << std::endl;
				//std::cout << "The size between ptr returned and next is: " << ( (char*)_next ) - ( (char*)returned ) << std::endl;

				return (T*)_componentAccessors[entity._guid];
			}

			template<typename T>
			void RemoveComponent(Entity& entity)
			{
				T* ptrToComponent = (T*)_componentAccessors[entity._guid];
				_componentAccessors.erase(entity._guid);
				memset(ptrToComponent, 0, sizeof(T));
				_next = ptrToComponent;
			}

			const size_t NumberOf() const
			{
				return _count;
			}

			Component* At(Entity& entity)
			{
				// TODO: check if base of T = Component
				if ( _componentAccessors.find(entity._guid) != _componentAccessors.end() ) {
					return _componentAccessors[entity._guid];
				}
				return nullptr;
			}

			std::unordered_map<GUID, Component*>& View()
			{
				return _componentAccessors;
			}


		private:
			void* _pool;
			size_t _poolSize;
			ComponentID _poolID;
			size_t _count;

			void* _next;
			void* _refBlock;

			std::unordered_map<GUID, Component*> _componentAccessors;
	};

}