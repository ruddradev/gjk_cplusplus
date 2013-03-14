#ifndef POINT_H
#define POINT_H
#include "Vector.h"
#include <iostream>

class Point: public Vector
{
    public:
		Point();
		Point(double,double, double);
		Point(double,double);
		Point& Point::operator=(const Point &);
        virtual ~Point();
       const double Getx() { return x; }
        void Setx(double val) { x = val; }
       const double Gety() { return y; }
        void Sety(double val) { y = val; }
       const double Getz() { return z; }
        void Setz(double val) { z = val; }
    protected:
    private:
        double x;
        double y;
        double z;
};

#endif // POINT_H
