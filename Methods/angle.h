#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class Angle
{
private:
	double angleRadians;

	double convertToDegrees(double radian) const;
	double convertToRadians(double degree) const;
	double normalize(double angle) const;

public:
	Angle();
	Angle(double degree);
	Angle(const Angle & angle);
	double getRadians() const;
	double getDegrees() const;
	void setRadians(double degree);
	void setDegrees(double radian);
	void display();
};
