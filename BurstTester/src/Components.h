#pragma once

#include "Burst.h"
#include <iostream>

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
		//static Burst::ComponentID _ID;
		BURST_COMPONENT(Transform)
		float _x, _y, _z;
};


class Sprite : public Burst::Component {
public:

private:
	//static Burst::ComponentID _ID;
	BURST_COMPONENT(Sprite)
};


class Mesh : public Burst::Component {
public:

private:
	//static Burst::ComponentID _ID;
	BURST_COMPONENT(Mesh)
};
