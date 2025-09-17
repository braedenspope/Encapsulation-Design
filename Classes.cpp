/*****************************************************************************
* W03ProblemSet.cpp : Made by Aiden Patterson, Ethan mangum, and Braeden Pope
*****************************************************************************/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class Angle {
private:
   double angleRadians;
   double convertToDegrees(double radian)
   {
      double degree;
      degree = radian * (180 / M_PI);
      return degree;
   }

   double convertToRadians(double degree)
   {
      double radian;
      radian = degree * (M_PI / 180);
      return radian;
   }

   double normalize(double angle)
   {
      double normalAngle = angle;
      while (normalAngle > 2 * M_PI)
      {
         normalAngle -= (2 * M_PI);
      }
      return normalAngle;
   }

public:
   double getDegrees()
   {
      return convertToDegrees(angleRadians);
   }

   double getRadians()
   {
      return angleRadians;
   }

   void setDegrees(double degree)
   {
      angleRadians = convertToRadians(degree);
   }

   void setRadians(double radian)
   {
      angleRadians = radian;
   }

   void display()
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(1);
      setRadians(normalize(getRadians()));
      cout << "Degrees: " << getDegrees() << endl;
   }
};

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