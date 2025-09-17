#pragma once
#include "point.h"
#include "uiDraw.h"

class Star
{
private:
   Point pt;
   char phase;

public:
   Star();
   void reset(double width, double height);
   void draw(ogstream & gout);
};

