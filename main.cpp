#include <iostream>
//#include "Vector.h"
#include "Collision.h"
using namespace std;



int main()
{
   Vector p1(0.4,0.5,0),p2(0,3,0),p3(3,0,0),q1(1,1,0),q2(5,5,0),q3(5,6,0);
   Vector list1[3],list2[3];
   list1[0]=p1;
   list1[1]=p2;
   list1[2]=p3;
   list2[0]=q1;
   list2[1]=q2;
   list2[2]=q3;
   cout<<p3.Geti() <<" "<<list1[2].Geti()<<endl;
   Vector dir(-1,-1,0);
   Vector mD=Vector::maxDot(list1,dir);
   cout<<mD.Geti()<<" "<<mD.Getj()<<" "<<mD.Getk()<<endl;  
   Polyhedra one(list1),two(list2);
   Collision c1(one,two);
   c1.checkCollision(); 
   getchar();
    return 0;
}
