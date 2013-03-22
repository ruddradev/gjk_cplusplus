#include "Sphere.h"
#include <iostream>
using namespace std;

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
	//cout<<"Sphere Dir="<<newVec.i<<" "<<newVec.j<<" "<<newVec.k<<endl;
	//cout <<"Sphere Support="<<support.i<<" "<<support.j<<" "<<support.k<<endl;
	return support;
}

Sphere::~Sphere(void)
{
}
