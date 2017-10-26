#pragma once

class Ellipse
{
public:
	double x0, y0;
	double A, B;
	double param;
	double angle;

public:
	Ellipse(void);
	Ellipse(double x0, double y0, double A, double B, double param, int angle);
	~Ellipse(void);
};
