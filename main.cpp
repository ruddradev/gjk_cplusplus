#include <iostream>
#include "Square.h"
#include "Circle.h"
#include "Collision.h"
#include "Sphere.h"
using namespace std;



int main()
{
   Vector p1(0,0,0),p2(3,0,0),p3(3,3,0),p4(0,3,0),q1(1,-4,0),q2(2.9,3.5,0),q3(3.1,3,0);
   Vector t1(5,2,0),t2(0,0,-0.3),t3(2,2,1);
   vector<Vector> list1(4),list2(3);
   list1[0]=p1;
   list1[1]=p4;		//filled in clockwise order of vertices(Defination of square)
   list1[2]=p3;
   //list1[3]=p2;
   list2[0]=t1;
   list2[1]=t2;
   list2[2]=t3;
   Polyhedra one(list1);
   //Polyhedra two(list2);
   //Square one(list1);
   //Vector circleNorm(0,-1,1);

	//Circle two(5.00,t2,circleNorm);
	Sphere two(4.1,q1);
   Collision c1(&one,&two);  //Avoid Object Slicing. Pass pointers to effect polymorphism
   c1.checkCollision(); 
   getchar();
    return 0;
}
