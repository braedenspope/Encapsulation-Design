#include "Star.h"

Star::Star()
{
   phase = random(0, 255);
   pt.setX(random(0, 400));
   pt.setY(random(0, 400));
}
void Star::reset(double width, double height)
{
   pt.setX(width);
   pt.setY(height);
}
void Star::draw(ogstream & gout)
{
   gout.drawStar(pt, phase);
   phase++;
}