#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle(void)
{
	radius=0.0;
}
Circle::Circle(double r,Vector c)
{
	radius=r;
	centre=c;
}
Vector Circle::getSupport(Vector dir)
{
	double nor=sqrt(dir.i*dir.i+dir.j*dir.j+dir.k*dir.k);
	Vector newVec;
	//double dirMod=dir.norm();
	newVec.i=(dir.i/nor)*radius;
	newVec.j=(dir.j/nor)*radius;
	newVec.k=0.0;
	Vector support;
	support=newVec+centre;
	cout<<"Circle Dir="<<newVec.i<<" "<<newVec.j<<endl;
	cout <<"Circle Support="<<support.i<<" "<<support.j<<endl;
	return support;
	
}
Circle::~Circle(void)
{
}
