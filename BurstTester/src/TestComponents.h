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
		BURST_DECL_COMPONENT(Transform)
		float _x, _y, _z;
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


class PtrComponent : public Burst::Component {
public:
	PtrComponent()
	{
		_pointerToSmthg = calloc(8, 8);
	}

	~PtrComponent()
	{
		delete _pointerToSmthg;
	}

	int* GetPointerAdress()
	{
		return (int*)( _pointerToSmthg );
	}

private:
	void* _pointerToSmthg = nullptr;

	BURST_DECL_COMPONENT(PtrComponent)
};
