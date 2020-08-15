#pragma once

#include "Burst.h"
#include <iostream>

#define BURST_COMPONENT(type) Burst::ComponentID type::_ID = Burst::GetComponentID<type>();

class Transform : public Burst::Component {
	public:
		Transform(float x = 0.f, float y = 0.f, float z = 0.f)
			: _x(x), _y(y), _z(z)
		{
		}

		void Set(float x, float y)
		{
			_x = x;
			_y = y;
		}


		void Print()
		{
			std::cout << "Transform for entity : " << _entity << " > " << _x << " ; " << _y << " ; " << _z << std::endl;
		}

	private:
		static Burst::ComponentID _ID;
		float _x, _y, _z;
};


class Sprite : public Burst::Component {
public:

private:
	static Burst::ComponentID _ID;
};


class Mesh : public Burst::Component {
public:

private:
	static Burst::ComponentID _ID;
};
