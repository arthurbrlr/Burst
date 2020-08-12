#pragma once

#include "Burst.h"
#include <iostream>

#define BURST_COMPONENT(type) Burst::ComponentID type::_ID = Burst::GetComponentID<type>();

class Transform : public Burst::Component {
	public:
		Transform()
			: _x(0), _y(0), _z(0)
		{
		}

		void Set(float x, float y)
		{
			_x = x;
			_y = y;
		}


		void Print()
		{
			std::cout << "Transform for entity : " << _entityGuid << " > " << _x << " ; " << _y << " ; " << _z << std::endl;
		}

	private:
		static Burst::ComponentID _ID;
		float _x, _y, _z;
};
BURST_COMPONENT(Transform)


class Sprite : public Burst::Component {
public:

private:
	static Burst::ComponentID _ID;
};
BURST_COMPONENT(Sprite)


class Mesh : public Burst::Component {
public:

private:
	static Burst::ComponentID _ID;
};
BURST_COMPONENT(Mesh)