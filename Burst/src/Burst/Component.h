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

#define BURST_DECL_COMPONENT(type) public: static Burst::ComponentID GetStaticComponentID() { return _ID; } private: static Burst::ComponentID _ID;
#define BURST_COMPONENT(type) Burst::ComponentID type::_ID = Burst::GetComponentID<type>();
