#include "Vector.h"
#include <iostream>

Vector& Vector::operator=(const Vector& rhs)
{
	i=const_cast<Vector&>(rhs).Geti ();
	//std::cout<<const_cast<Vector&>(rhs).Geti()<< "  "<<x<<std::endl;
	j=const_cast<Vector&>(rhs).Getj();
	k=const_cast<Vector&>(rhs).Getk();
  return *this;
} 
Vector::Vector()
{
	i=0.0;
    j=0.0;
    k=0.0;
}
Vector::Vector(double xDir,double yDir,double zDir)
{
    i=xDir;
    j=yDir;
    k=zDir;
    //ctor
}
Vector Vector::operator +(Vector vec)
{
	Vector temp;
	temp.i=i+vec.i;
	temp.j=j+vec.j;
	temp.k=k+vec.k;
	return temp;
}
Vector Vector::operator -(Vector vec)
{
	Vector temp(0.0,0.0,0.0);
	temp.i=i-vec.i;
	temp.j=j-vec.j;
	temp.k=k-vec.k;
	return temp;
}

double Vector::dot(Vector vec1,Vector vec2)
{
    double result;
    return vec1.i*vec2.i+vec1.j*vec2.j+vec1.k*vec2.k;
    return result;
}
Vector Vector::cross(Vector vec1,Vector vec2)
{
    Vector result(0.0,0.0,0.0);
    result.i=vec1.j*vec2.k-vec1.k*vec2.j;
    result.j=vec2.k*vec2.i-vec1.i*vec2.k;
    result.k=vec1.i*vec2.j-vec1.j*vec2.i;
    return result;
}

Vector Vector::maxDot(Vector(& list)[],Vector direction)
{
    double max=-1000000.0;
    double dotValue;
    Vector maxVec;
	//size_t size=Vector::SizeOfArray<Vector>(list);
	std::cout<<"List Size="<<sizeof(list)<<" "<<sizeof(list[0])<<std::endl;
    for(size_t i=0;i<size-1;i++)
    {
        dotValue=dot(list[i],direction);
        if(dotValue>max)
        {
			std::cout<<"inside if block in maxDot, list[i].i="<<list[i].Geti() <<std::endl;
            max=dotValue;
            maxVec=list[i];
        }

    }
    return maxVec;
}
Vector::~Vector()
{

}