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

#define BURST_DECL_COMPONENT(type)	public: static inline Burst::ComponentID GetStaticComponentID() { return Burst::GetComponentID<type>(); } private: