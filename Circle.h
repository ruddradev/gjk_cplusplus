#pragma once
#include "Polyhedra.h"

class Circle: public Polyhedra
{
	Vector centre;
	double radius;
	
public:
	Circle(void);
	Circle(double r,Vector c);
	virtual Vector getSupport(Vector);
	~Circle(void);
};
