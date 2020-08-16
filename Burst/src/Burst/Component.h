#pragma once

#include "Types.h"

namespace Burst {

	class Component {
		public:
			Component() 
				: _entity(INVALID_ENTITY)
			{
			}

			virtual ~Component()
			{
			}

			void Attach(Entity& entity)
			{
				_entity = entity;
			}

		protected:
			Entity _entity;
	};

}

/*
#define BURST_DECL_COMPONENT(type)	static Burst::ComponentID _ID; \
									static Burst::ComponentID GetStaticComponentID() { return _ID; }
#define BURST_COMPONENT(type)		Burst::ComponentID type::_ID = Burst::GetComponentID<type>();
*/

#define BURST_DECL_COMPONENT(type)	static inline Burst::ComponentID GetStaticComponentID() { return Burst::GetComponentID<type>(); }