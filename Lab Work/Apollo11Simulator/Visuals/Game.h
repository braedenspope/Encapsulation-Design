#pragma once

#include "Lander.h"
#include "point.h"
#include "ground.h"
#include "Star.h"
#include "Thrust.h"
#include "uiInteract.h"
#include "uiDraw.h"

class Game
{
private:
   Lander lander;
   Point ptUpperRight;
   Ground ground;
   Star stars[50];

public:
   Game(Point ptUpperRight);
   void reset();
   Thrust input(Interface ui);
   void gamePlay(Thrust thrust, Interface ui);
   void display(Thrust thrust, ogstream & gout);
};

