#pragma once
class Acceleration
{
private:
   double ddx;
   double ddy;

public:
   Acceleration();
   Acceleration(double ddx, double ddy);
   double getDdx() const;
   double getDdy() const;
   void setDdx(double ddx);
   void setDdy(double ddy);
};

