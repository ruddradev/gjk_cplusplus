#pragma once
#include "Polyhedra.h"

class Square: public Polyhedra
{
public:
	Square::Square(vector<Vector>);
	virtual Vector getSupport(Vector);
	Square(void);
	~Square(void);
};