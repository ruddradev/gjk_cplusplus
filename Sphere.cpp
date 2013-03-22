#include "Sphere.h"

Sphere::Sphere(void)
{
	radius=0.0;

}
Sphere::Sphere(double r,Vector c)
{
	radius=r;
	centre=c;
}
Vector Sphere::getSupport(Vector dir)
{
	double crossMod=dir.norm();
	if(crossMod==0)
	return centre;
	Vector newVec;
	newVec.i=(dir.i/crossMod)*radius;
	newVec.j=(dir.j/crossMod)*radius;
	newVec.k=(dir.k/crossMod)*radius;
	Vector support;
	support=newVec+centre;
	return support;
}

Sphere::~Sphere(void)
{
}
