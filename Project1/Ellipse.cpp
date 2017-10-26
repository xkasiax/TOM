#include "Ellipse.h"

Ellipse::Ellipse(void)
{
}

Ellipse::~Ellipse(void)
{
}

Ellipse::Ellipse(double x0, double y0, double xrad, double yrad, double param, int angle) {
	this->x0 = x0;
	this->y0 = y0;
	this->A = A;
	this->B = B;
	this->param = param;
	this->angle = angle;
}
