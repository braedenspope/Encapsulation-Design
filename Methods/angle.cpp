#include "angle.h"

// default constructor
Angle::Angle()
{
   angleRadians = 0.0;
}

// constructor for getting an angle in degrees
Angle::Angle(double degree) 
{
   setDegrees(degree);
}

// copy constructor
Angle::Angle(const Angle & angle) 
{
   this->angleRadians = angle.getRadians();
}

// convert an angle from radians to degrees
double Angle::convertToDegrees(double radian) const
{
   double degree;
   degree = radian * (180 / M_PI);
   return degree;
}

//convert an angle from degrees to radians
double Angle::convertToRadians(double degree) const
{
   double radian;
   radian = degree * (M_PI / 180);
   return radian;
}

// normalize an angle so it is not larger than 360 degrees or 2pi
double Angle::normalize(double angle) const
{
   double normalAngle = angle;
   while (normalAngle > 2 * M_PI)
   {
      normalAngle -= (2 * M_PI);
   }
   return normalAngle;
}

// get the angle in degrees
double Angle::getDegrees() const
{
   return convertToDegrees(angleRadians);
}

// get the angle in radians
double Angle::getRadians() const
{
   return angleRadians;
}

// set the angle given an angle in degrees
void Angle::setDegrees(double degree)
{
   angleRadians = convertToRadians(degree);
}

// set the angle given an angle in radians
void Angle::setRadians(double radian)
{
   angleRadians = radian;
}

// display the normalized angle in degrees
void Angle::display()
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);
   setRadians(normalize(getRadians()));
   cout << "Degrees: " << getDegrees() << endl;
}
