#include "Lander.h"

Lander::Lander(Point ptUpperRight)
{
   this->ptUpperRight = ptUpperRight;
   pt.setX(ptUpperRight.getX() / 2.0);
   pt.setY(ptUpperRight.getY() / 2.0);
   status = false;
   angle = 0.0;
   fuel = 0.0;
   weight = 0.0;
   thrust = 0.0;
   g = 0.0;
}
void Lander::reset()
{

}
bool Lander::isDead()
{
   return false;
}
bool Lander::isLanded()
{
   return false;
}
bool Lander::isFlying()
{
   return true;
}
Point Lander::getPosition()
{
   return pt;
}
double Lander::getFuel() const
{
   return fuel;
}
void Lander::draw(Thrust thrust, ogstream & gout)
{
   gout.drawLander(pt, angle);
   gout.drawLanderFlames(pt, angle, thrust.isMain(), thrust.isCounter(), thrust.isClock());
}
void Lander::input(Thrust thrust, Interface ui)
{
   // move the ship around
   if (thrust.isMain())
      pt.setY(pt.getY() - 1);
   if (thrust.isCounter())
      pt.setX(pt.getX() - 1);
   if (thrust.isClock())
      pt.setX(pt.getX() + 1);
   if (ui.isUp())
      pt.setY(pt.getY() + 1);
}
void Lander::coast()
{

}
void Lander::land()
{

}
void Lander::crash()
{

}