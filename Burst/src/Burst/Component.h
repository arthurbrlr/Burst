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
			ComponentID _ID;
	};

}

#define BURST_COMPONENT(type) Burst::ComponentID type::_ID = Burst::GetComponentID<type>();
