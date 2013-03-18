#include <iostream>
#include "Collision.h"
using namespace std;
//#define (a)sameDir(b) (Vector::dot(a,b)>0?true:false) 

Collision::Collision(Polyhedra* one,Polyhedra* two)
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
	Vector aDot=a->getSupport(dir);
	Vector bDot=b->getSupport(negDir);
	support=aDot-bDot;
	return support;
}
Vector Collision::updateDir()
{
	Vector dir,AB,AC,AD,AO,tPlane;
	vector<Vector> temp;
	temp.reserve(3); 
	size_t n=simplex.size();
	//cout<<"Elemets in Simplex="<<n<<endl;
	switch(n)
	{
	case 2:
		//cout<<"In case 2"<<endl;
		AB=(simplex.at(0)-simplex.at(1));
		AO=origin-simplex.at(1);
		dir=Vector::cross(Vector::cross(AB,AO),AB);
		break;
	case 3:
		AB=simplex.at(1)-simplex.at(2);
		AC=simplex.at(0)-simplex.at(2);
		AO=origin-simplex.at(2);
		//cout<<"In case 3"<<endl;
		//cout<<"A="<<simplex.at(2).i<<" "<<simplex.at(2).j<<endl;
		//cout<<"B="<<simplex.at(1).i<<" "<<simplex.at(1).j<<endl;
		//cout<<"C="<<simplex.at(0).i<<" "<<simplex.at(0).j<<endl;
		tPlane=Vector::cross(AC,AB);
		if(Vector::dot(Vector::cross(AC,tPlane),AO)>0)
		{
			//cout<<"Vector::dot(Vector::cross(AC,tPlane),AO)>0="<<Vector::dot(Vector::cross(AC,tPlane),AO)<<endl;
			dir=Vector::cross(AC,Vector::cross(AO,AC));					//need to mend later for 3D
			simplex.erase(simplex.begin()+1);
		}
		else if(Vector::dot(Vector::cross(AC,tPlane),AO)==0)
			{
				//cout<<"Vector::dot(Vector::cross(AC,tPlane),AO)==0"<<endl;
				break;
			}
		else if(Vector::dot(Vector::cross(tPlane,AB),AO)<0)
		{
			Vector cr=Vector::cross(tPlane,AB);
			//cout<<"Vector::dot(Vector::cross(tPlane,AB),AO)<0"<<Vector::dot(Vector::cross(tPlane,AB),AO)<<endl;

			if(Vector::dot(tPlane,AO)>0)
			{
				//cout<<"Vector::dot(tPlane,AO)>0"<<endl;
				dir=tPlane;
			}
			else if(Vector::dot(tPlane,AO)==0)
			{
				//cout<<"~Vector::dot(tPlane,AO)==0"<<endl;
				break;
				
			}
			else
				dir=origin-tPlane;
		}
		else if(Vector::dot(Vector::cross(tPlane,AB),AO)>0)
		{	
			//cout<<"Vector::dot(Vector::cross(tplane,AB),AO)>0"<<endl;
			dir=Vector::cross(AB,Vector::cross(AO,AB));	    //mend later
			simplex.erase(simplex.begin() );
		}
		else
			break;
	case 4:
		
		//Vector newPoint=simplex.back();
		//simplex.pop_back();
		//simplex.push_back(newPoint);
		break;
	}
	//cout<<"dir="<<dir.i<<" "<<dir.j<<" "<<dir.k<<endl; 
	return dir;
}
bool Collision::checkCollision()
{
	Vector d(1,-1,0);
	Vector s=Collision::support(d);
	simplex.push_back(s);
	d=(origin-d);
	while(true)
	{
		s=Collision::support(d);
		if(Vector::dot(d,s)<0)
		{
			//cout<<"No Intersection"<<endl;
			return false;
			break;
		}
		simplex.push_back(s);
		d=Collision::updateDir();
		if(d.i==0 && d.j==0 )
		{
			//cout<<"Intersection"<<endl;
			return true;
			break;
		}
		else if(d.k==-1)
		{
			//cout<<"No Intersection"<<endl;
			return false;
			break;
		}
	}
}
Collision::~Collision(void)
{
}
