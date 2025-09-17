#pragma once
#include "Acceleration.h"

class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity();
   Velocity(double dx, double dy);
   double getDx() const;
   double getDy() const;
   double getSpeed();
   void setDx(double dx);
   void setDy(double dy);
   void add(Acceleration accel, double time);
};

