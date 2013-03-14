#include "Point.h"

Point& Point::operator=(const Point& rhs)
{
	x=const_cast<Point&>(rhs).Getx ();
	//std::cout<<const_cast<Point&>(rhs).Getx()<< "  "<<x<<std::endl;
	y=const_cast<Point&>(rhs).Gety();
	z=const_cast<Point&>(rhs).Getz();
  return *this;
} 

Point::Point()
{
	x=0;
	y=0;
	z=0;
}
Point::Point(double xPt,double yPt, double zPt):Vector(xPt,yPt,zPt)
{
    x=xPt;
    y=yPt;
    z=zPt;//ctor
}
Point:: Point(double xPt,double yPt):Vector(xPt,yPt,0)
{
   x=xPt;
   y=yPt;
   z=0.0;
}

Point::~Point()
{
    //dtor
}
