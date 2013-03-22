#pragma once

#include "Polyhedra.h"

class Sphere: public Polyhedra
{
	Vector centre;
	double radius;
	
public:
	Sphere(void);
	Sphere(double r,Vector c);
	virtual Vector getSupport(Vector);
	~Sphere(void);
};