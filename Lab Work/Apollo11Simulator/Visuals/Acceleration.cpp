#include "Acceleration.h"

Acceleration::Acceleration()
{
   ddx = 0.0;
   ddy = 0.0;
}
Acceleration::Acceleration(double ddx, double ddy)
{
   this->ddx = ddx;
   this->ddy = ddy;
}
double Acceleration::getDdx() const
{
   return ddx;
}
double Acceleration::getDdy() const
{
   return ddy;
}
void Acceleration::setDdx(double ddx)
{

}
void Acceleration::setDdy(double ddy)
{

}