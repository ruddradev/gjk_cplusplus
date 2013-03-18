#include "Square.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
Square::Square(void)
{
}
Square::Square(vector<Vector> list)
{
	pointList=list;
}
Vector Square::getSupport(Vector dir)
{
	short idir,jdir,index;
	double error=0.0;
	double xside,yside;
	Vector support;
	dir.i=dir.i/dir.norm();
	dir.j=dir.j/dir.norm();
	idir=dir.i<0?0:1;
	jdir=dir.j<0?0:1;
	index=pow(4,(double)jdir)*pow(2,(double)idir);
	if(index==8)
		index=3;
	Vector centre((pointList[0].i+pointList[2].i)/2.0,(pointList[0].j+pointList[2].j)/2.0,0);
	vector<Vector> sidepts;
	vector<Vector> axisVec(4);		//gives vector aligned with the rectangle axes
	sidepts.reserve(4);
	support=pointList[index-1];
	for(int l=0;l<=3;l++)
	{
		if(l==3)
		{
			xside=(pointList[l].i+pointList[0].i)/2.0;
			yside=(pointList[l].j+pointList[0].j)/2.0;
		}
		else
		{
			xside=(pointList[l].i+pointList[l+1].i)/2.0;
			yside=(pointList[l].j+pointList[l+1].j)/2.0;
		}
		sidepts.push_back(*new Vector(xside,yside,0));
		axisVec[l]=(sidepts[l]-centre);
		axisVec[l].i=axisVec[l].i/axisVec[l].norm(); 
		axisVec[l].j=axisVec[l].j/axisVec[l].norm();
		error=(axisVec[l]-dir).norm()/dir.norm();
		if( error >-0.03 && error<0.03)
			support=pointList[l];
	}
	
	cout<<"Square Dir="<<dir.i<<" "<<dir.j<<endl;
	cout <<"Square Support="<<support.i<<" "<<support.j<<endl;
	return support;
}
Square::~Square(void)
{
}
