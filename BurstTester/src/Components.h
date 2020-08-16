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
	float _x, _y, _z;
	BURST_DECL_COMPONENT(Transform)
};


class Sprite : public Burst::Component {
public:

private:
	BURST_DECL_COMPONENT(Sprite)
};


class Mesh : public Burst::Component {
public:

private:
	BURST_DECL_COMPONENT(Mesh)
};
