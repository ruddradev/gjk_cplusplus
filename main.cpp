#include <iostream>
//#include "Vector.h"
#include "Collision.h"
using namespace std;



int main()
{
   Vector p1(0,0,0),p2(0,3,0),p3(3,3,0),p4(3,0,0),q1(5,0,0),q2(2.9,3.5,0),q3(3.1,3,0);
   vector<Vector> list1(4),list2(3);
   list1[0]=p1;
   list1[1]=p2;
   list1[2]=p3;
   list1[3]=p4;
   list2[0]=q1;
   list2[1]=q2;
   list2[2]=q3;
   Vector dir(-1,1,0);
   Polyhedra one(list1),two(list2);
   Collision c1(one,two);
   c1.checkCollision(); 
   getchar();
    return 0;
}
