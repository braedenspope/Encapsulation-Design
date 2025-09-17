#include "Thrust.h"

Thrust::Thrust()
{
   mainEngine = false;
   clockwise = false;
   counterClockwise = false;
}
void Thrust::rotation()
{

}
void Thrust::mainEngineThrust()
{

}
bool Thrust::isMain()
{
   return mainEngine;
}
bool Thrust::isClock()
{
   return clockwise;
}
bool Thrust::isCounter()
{
   return counterClockwise;
}
void Thrust::set(Interface ui)
{
   if (ui.isDown())
   {
      mainEngine = true;
   }
   else
   {
      mainEngine = false;
   }
   if (ui.isLeft())
   {
      counterClockwise = true;
   }
   else
   {
      counterClockwise = false;
   }
   if (ui.isRight())
   {
      clockwise = true;
   }
   else
   {
      clockwise = false;
   }
}