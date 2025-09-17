#pragma once

#include "point.h"
#include "Velocity.h"
#include "Thrust.h"
#include "uiDraw.h"

class Lander
{
private:
   bool status;
   Point pt;
   Velocity v;
   double angle;
   Point ptUpperRight;
   double fuel;
   double weight;
   double thrust;
   double g;

public:
   Lander(Point ptUpperRight);
   void reset();
   bool isDead();
   bool isLanded();
   bool isFlying();
   Point getPosition();
   double getFuel() const;
   void draw(Thrust thrust, ogstream & gout);
   void input(Thrust thrust, Interface ui);
   void coast();
   void land();
   void crash();

};

