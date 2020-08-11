#pragma once

#include "Types.h"
#include "Entity.h"

namespace Burst {

	class Component {
		public:
			Component() : _entityGuid(INVALID_GUID), _poolIndex(INVALID_POOL_INDEX)
			{
			}

			virtual ~Component()
			{
			}

			void Attach(Entity& entity)
			{
				_entityGuid = entity._guid;
			}

		protected:
			GUID _entityGuid;
			size_t _poolIndex;
	};

}

