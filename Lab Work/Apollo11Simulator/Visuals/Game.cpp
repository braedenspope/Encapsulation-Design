#include "Game.h"

Game::Game(Point ptUpperRight) : lander(ptUpperRight), ground(ptUpperRight)
{
   this->ptUpperRight = ptUpperRight;
}
void Game::reset()
{

}
Thrust Game::input(Interface ui)
{
   Thrust thrust;
   thrust.set(ui);

   return thrust;
}
void Game::gamePlay(Thrust thrust, Interface ui)
{
   lander.input(thrust, ui);
}
void Game::display(Thrust thrust, ogstream & gout)
{
   for (int i = 0; i < 50; i++)
   {
      stars[i].draw(gout);
   }
   ground.draw(gout);
   lander.draw(thrust, gout);
   gout.setPosition(Point(10.0, ptUpperRight.getY()-20));
   gout << "Fuel:     " << lander.getFuel() << " lbs" << "\n";
   gout << "Altitude: " << lander.getPosition().getY() << " meters" << "\n";
   gout << "Speed:    " << "12.91 m/s" << "\n";
}