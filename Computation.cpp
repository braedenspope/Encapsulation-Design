/*************************************************************
 * 1. Name:
 *      Aiden Patterson
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part of the program was finding and fixing the small
 *      errors I made along the way. There were a lot of small things I 
 *      did wrong while writing the functions, and I had to hunt them all
 *      down and fix them all and it was not easy
 * 5. How long did it take for you to complete the assignment?
 *      It took me about 2 and a half hours to complete this assignment
 **************************************************************/

#define _USE_MATH_DEFINES
#include <iostream>  // for CIN and COUT
#include <cmath>
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
 // your function goes here
double calcDistance(double s, double v, double a, double t)
{
   double test = s + v;
   double distance = s + v * t + 0.5 * a * pow(t, 2);
   return distance;
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
 // your function goes here
double calcAccel(double f, double m)
{
   double accel = f / m;
   return accel;
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
 // your function goes here
double calcVelocity(double v, double a, double t)
{
   double velocity = v + a * t;
   return velocity;
}

/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
 // your function goes here
double calcVertical(double a, double total)
{
   double y = total * cos(a);
   return y;
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
 // your function goes here
double calcHorizontal(double a, double total)
{
   double x = total * sin(a);
   return x;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
 // your function goes here
double calcTotal(double x, double y)
{
   double total = sqrt(pow(x, 2) + pow(y, 2));
   return total;
}


/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
 // your function goes here
double degreeToRadian(double d)
{
   double radian = 2 * M_PI * (d / 360);
   return radian;
}

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
 // your function goes here
double prompt(string msg)
{
   double response;
   cout << msg;
   cin >> response;
   return response;
}

/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
   // Prompt for input and variables to be computed
   double dx = prompt("What is your horizontal velocity (m/s)? ");
   double dy = prompt("What is your vertical velocity (m/s)? ");
   double y = prompt("What is your altitude (m)? ");
   double x = prompt("What is your position (m)? ");
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
   double t = prompt("What is the time interval (s)? ");
   double aRadians;            // Angle in radians
   double accelerationThrust;  // Acceleration due to thrust 
   double ddxThrust;           // Horizontal acceleration due to thrust
   double ddyThrust;           // Vertical acceleration due to thrust
   double ddx;                 // Total horizontal acceleration
   double ddy;                 // Total vertical acceleration
   double v;                   // Total velocity

   aRadians = degreeToRadian(aDegrees);
   accelerationThrust = calcAccel(THRUST, WEIGHT);
   ddxThrust = calcHorizontal(aRadians, accelerationThrust);
   ddyThrust = calcVertical(aRadians, accelerationThrust);
   // Go through the simulator five times
     // your code goes here
   for (int i = 0; i < 5; i++)
   {
      ddx = ddxThrust;
      ddy = ddyThrust + GRAVITY;
      dx = calcVelocity(dx, ddx, t);
      dy = calcVelocity(dy, ddy, t);
      v = calcTotal(dx, dy);

      x = calcDistance(x, dx, ddx, t);
      y = calcDistance(y, dy, ddy, t);

      // Output
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << "\tNew position:   (" << x << ", " << y << ")m\n";
      cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
      cout << "\tTotal velocity:  " << v << "m/s\n\n";

   }
     


   return 0;
}