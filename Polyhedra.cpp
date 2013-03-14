#include <stdlib.h>
#include "Polyhedra.h"


Polyhedra::Polyhedra()
{
	//pointList=(Point*)calloc(1,sizeof(Point));
	pointList=(Point*)1000;
}
Polyhedra::Polyhedra(Vector list[])
{
   pointList=list;
    //ctor
}

Polyhedra::~Polyhedra()
{
//    delete [] pointList;
    //dtor
}
Vector Polyhedra::getSupport(Vector dir)
{
	return Vector::maxDot(pointList,dir); 
}