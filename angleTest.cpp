/*****************************************************************************
* W05ProblemSet.cpp : Made by Aiden Patterson, Ethan Mangum, and Braeden Pope
*****************************************************************************/

#include "angle.h"
#include <iostream>

using namespace std;

int main()
{
   Angle bigDegree;
   bigDegree.setDegrees(1050);
   cout << "Normalized angle from degrees" << endl;
   bigDegree.display();
   cout << endl;

   Angle bigRadian;
   bigRadian.setRadians(7 * M_PI);
   cout << "Normalized angle from radians" << endl;
   bigRadian.display();
   cout << endl;

   Angle smallDegree;
   smallDegree.setDegrees(90.7);
   cout << "Angle that does not need to be normalized in Degrees" << endl;
   smallDegree.display();
   cout << endl;

   Angle smallRadian;
   smallRadian.setRadians(M_PI);
   cout << "Angle that does not need to be normalized in Radians" << endl;
   smallRadian.display();
   cout << endl;
}