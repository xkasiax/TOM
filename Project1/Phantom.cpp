#include "Phantom.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

Phantom::Phantom(void)
{
	this->ellipses[0] = new Ellipse(0, 0, 0.92, 0.69, 2, 90*M_PI/180);
	this->ellipses[1] = new Ellipse(0, -0.0184, 0.874, 0.6624, -0.98, 90 * M_PI / 180);
	this->ellipses[2] = new Ellipse(0.22, 0, 0.310, 0.11, -0.02, 72 * M_PI / 180);
	this->ellipses[3] = new Ellipse(-0.22, 0, 0.410, 0.16, -0.02, 108 * M_PI / 180);
	this->ellipses[4] = new Ellipse(0, 0.35, 0.25, 0.21, 0.01, 90 * M_PI / 180);
	this->ellipses[5] = new Ellipse(0, 0.1, 0.046, 0.046, 0.01, 0);
	this->ellipses[6] = new Ellipse(0, -0.1, 0.046, 0.046, 0.01, 0);
	this->ellipses[7] = new Ellipse(-0.08, -0.605, 0.046, 0.023, 0.01, 0);
	this->ellipses[8] = new Ellipse(0, -0.605, 0.023, 0.023, 0.01, 0);
	this->ellipses[9] = new Ellipse(0.06, -0.605, 0.046, 0.023, 0.01, 90 * M_PI / 180);
}

Phantom::~Phantom(void)
{
}
