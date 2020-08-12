#pragma once

namespace Burst {
	
	typedef size_t GUID;
	static constexpr GUID INVALID_GUID = -1;

	typedef size_t ComponentID;
	static inline ComponentID NextComponentID()
	{
		static ComponentID nextID = 0;
		return nextID++;
	}

	template<typename T>
	static ComponentID GetComponentID()
	{
		static ComponentID typeID = NextComponentID();
		return typeID;
	}

}