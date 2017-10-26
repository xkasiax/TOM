#pragma once
#include "Ellipse.h"
#include "Phantom.h"

class Projector
{
public:
	Projector(void);
	double proj_dowolna(Ellipse& e, double theta, double t);
	double** proj_ellipse(Ellipse& e);
	double** proj_phantom(Phantom& ph);
	~Projector(void);
};


