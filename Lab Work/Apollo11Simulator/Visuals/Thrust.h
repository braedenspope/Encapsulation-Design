#pragma once

#include "uiInteract.h"

class Thrust
{
private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;

public:
   Thrust();
   void rotation();
   void mainEngineThrust();
   bool isMain();
   bool isClock();
   bool isCounter();
   void set(Interface ui);
};

