#include <stdlib.h>
#include "Polyhedra.h"


Polyhedra::Polyhedra()
{
}
Polyhedra::Polyhedra(vector<Vector> list)
{
   pointList=list;
    //ctor
}

Polyhedra::~Polyhedra()
{
    //dtor
}
Vector Polyhedra::getSupport(Vector dir)
{
	return Vector::maxDot(pointList,dir); 
}