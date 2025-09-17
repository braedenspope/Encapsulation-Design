//Operator Overloading Problem Set: Braeden Pope, Aiden Patterson, Ethan Mangum.

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;


//Class to store an angle.
class Angle {
private:
   double angleRadians;
   
   //Converts a number in radians to degrees.
   double convertToDegrees(double radian)
   {
      double degree;
      degree = radian * (180 / M_PI);
      return degree;
   }

   //Converts a number in degrees to radians.
   double convertToRadians(double degree)
   {
      double radian;
      radian = degree * (M_PI / 180);
      return radian;
   }

   //Reduces radians to be between 0 and 2 pi.
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

   //Default constructor.
   Angle() 
   {
      angleRadians = 0.0;
   }

   //Non-default constructor.
   Angle(double radians) {
      radians = normalize(radians);
      angleRadians = radians;
   }

   double getDegrees()
   {
      //gets the angle in degrees.
      return convertToDegrees(angleRadians);
   }

   //gets the angle in radians.
   double getRadians()
   {
      return angleRadians;
   }
   
   //sets the angle in degrees.
   void setDegrees(double degree)
   {
      angleRadians = convertToRadians(degree);
   }

   //sets the angle in radians.
   void setRadians(double radian)
   {
      angleRadians = radian;
   }

   //displays the angle in degrees.
   void display(ostream& out)
   {
      out.setf(ios::fixed | ios::showpoint);
      out.precision(1);
      setRadians(normalize(getRadians()));
      out << getDegrees() << endl;
   }

   //Assignment Operator
   void operator=(const Angle& rhs)
   {
      this->angleRadians = rhs.angleRadians;
   }

   //Equals-to Operator
   bool operator==(const Angle& rhs)
   {
      if (this->angleRadians == rhs.angleRadians) 
      {
         return true;
      } 
      else
      {
         return false;
      }
   }

   //Not-Equals-To Operator
   bool operator!=(const Angle& rhs)
   {
      if (this->angleRadians != rhs.angleRadians)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

};

//Subtraction Operator
Angle operator-(Angle rhs)
{
   Angle angle1(rhs.getRadians() + M_PI);
   return angle1;
}

//Extraction Operator
ostream& operator<<(ostream& out, Angle& rhs)
{
   rhs.display(out);
   return out;
}


//Insertion Operator
istream& operator>>(istream& in, Angle& rhs)
{  
   double num;
   in >> num;
   rhs.setDegrees(num);
   return in;
}

//Increment Prefix Operator
Angle& operator++(Angle& rhs)
{
   rhs.setRadians(rhs.getDegrees() + 1.0);
   return rhs;
}

//Increment Postfix Operator
Angle& operator++(Angle& rhs, int postfix)
{
   Angle angleReturn(rhs.getRadians());
   rhs.setDegrees(rhs.getDegrees() + 1.0);
   return angleReturn;
}


//Decrement Prefix Operator
Angle& operator--(Angle& rhs)
{
   rhs.setDegrees(rhs.getDegrees() - 1.0);
   return rhs;
}

//Decrement Postfix Operator
Angle& operator--(Angle& rhs, int postfix)
{
   Angle angleReturn(rhs.getRadians());
   rhs.setDegrees(rhs.getDegrees() - 1.0);
   return angleReturn;
}

/************************************
 * MAIN
 * Simple driver
 ***********************************/
int main()
{
   Angle a1(10.0);
   Angle a2(20.0);

   while (true)
   {
      // extraction
      cout << "<a1> ";
      cin >> a1;

      // increment postfix
      a2 = a1++;
      cout << "a2 = a1++;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // increment prefix
      a2 = ++a1;
      cout << "a2 = ++a1;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // compare
      cout << "a1 == a2 : " << (a1 == a2) << endl;
      cout << "a1 != a2 : " << (a1 != a2) << endl;

      // decrement prefix
      a2 = --a1;
      cout << "a2 = --a1;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // decrement postfix
      a2 = a1--;
      cout << "a2 = a1--;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // compare
      cout << "a1 == a2 : " << (a1 == a2) << endl;
      cout << "a1 != a2 : " << (a1 != a2) << endl;

      // negative
      a2 = -a1;
      cout << "a2 = -a1: "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      cout << endl;
   }

   return 0;
}
