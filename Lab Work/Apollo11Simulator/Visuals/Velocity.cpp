#include "Velocity.h"

Velocity::Velocity()
{
   dx = 0.0;
   dy = 0.0;
}
Velocity::Velocity(double dx, double dy)
{
   this->dx = dx;
   this->dy = dy;
}
double Velocity::getDx() const
{
   return dx;
}
double Velocity::getDy() const
{
   return dy;
}
double Velocity::getSpeed()
{
   return 0.0;
}
void Velocity::setDx(double dx)
{

}
void Velocity::setDy(double dy)
{

}
void Velocity::add(Acceleration accel, double time)
{

}