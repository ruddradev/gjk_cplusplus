#include <iostream>
#include "Collision.h"
using namespace std;
//#define (a)sameDir(b) (Vector::dot(a,b)>0?true:false) 

Collision::Collision(Polyhedra one,Polyhedra two)
{
	a=one;
	b=two;
	const size_t size=4;
	simplex.reserve(size);
}
Vector Collision::support(Vector dir)
{
	Vector support;
	Vector negDir=origin-dir;
	Vector aDot=Vector::maxDot(a.pointList,dir);
	Vector bDot=Vector::maxDot(b.pointList,negDir);
	support=aDot-bDot;
	return support;
}
Vector Collision::updateDir(std::vector<Vector> sim)
{
	Vector dir,AB,AC,AD,AO,tPlane;
	size_t n=sim.size();
	switch(n)
	{
	case 2:
		//cout<<"In case 2"<<endl;
		AB=(sim[0]-sim[1]);
		AO=origin-sim[1];
		dir=Vector::cross(Vector::cross(AB,AO),AB);
		break;
	case 3:
		AB=sim[1]-sim[1];
		AC=sim[0]-sim[2];
		AO=origin-sim[2];
		//cout<<"In case 3"<<endl;
		tPlane=Vector::cross(AC,AB);
		if(Vector::dot(Vector::cross(AC,tPlane),AO)>0)
		{
			//cout<<"Vector::dot(Vector::cross(AC,tPlane),AO)>0"<<endl;
			dir=Vector::cross(AC,Vector::cross(AO,AC));
		}
		else if(Vector::dot(Vector::cross(AC,tPlane),AO)==0)
			{
				//cout<<"Vector::dot(Vector::cross(AC,tPlane),AO)==0"<<endl;
				break;
			}
		else if(Vector::dot(Vector::cross(tPlane,AB),AO)<0)
			if(Vector::dot(tPlane,AO)>0)
				dir=tPlane;
			else if(Vector::dot(tPlane,AO)==0)
				break;
			else
				dir=origin-tPlane;
		else if(Vector::dot(Vector::cross(tPlane,AB),AO)>0)
			dir=Vector::cross(AB,Vector::cross(AO,AB));
		else
			break;
	case 4:
		break;
	}
	return dir;
}
bool Collision::checkCollision()
{
	Vector d(1,-1,-1);
	Vector s=Collision::support(d);
	simplex.push_back(s);
	d=(origin-d);
	while(true)
	{
		s=Collision::support(d);
		if(Vector::dot(d,s)<0)
		{
			cout<<"No Intersection"<<endl;
			return false;
			break;
		}
		simplex.push_back(s);
		d=Collision::updateDir(simplex);
		if(d.i==0 && d.j==0 && d.k==0)
		{
			cout<<"Intersection"<<endl;
			return true;
			break;
		}
	}
}
Collision::~Collision(void)
{
}
