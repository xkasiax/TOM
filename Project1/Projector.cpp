#include "Projector.h"
#include "Ellipse.h"
#include "Phantom.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

using namespace std;

Projector::Projector(void)
{

}

Projector::~Projector(void)
{
}

double Projector::proj_dowolna(Ellipse& e, double theta, double t) {
	double p = 0, a2, s, gamma;

	a2 = (pow(e.A / 2, 2) * pow(cos(theta-e.angle), 2)) + (pow(e.B / 2, 2) * pow(sin(theta - e.angle), 2));
	s = sqrt(pow(e.x0, 2) + pow(e.y0, 2));
	gamma = atan2(e.y0, e.x0);

	if ((double)(abs(t))<=sqrt(a2)) {
		p = ((2 * e.param * e.A / 2 * e.B / 2) / a2) * sqrt(a2 - pow(t - s * cos(gamma - theta), 2));
	}
	return p;
}

double** Projector::proj_ellipse(Ellipse & e)
{
	int beams = 256;
	int angles = 300;

	double** sinogram = 0;
	sinogram = new double*[beams];
	for (int t = 0; t < beams; t++) {
		sinogram = new double*[angles];
		for (int theta = 0; theta < angles; theta++) {
		
			double dt = ((double)t / (double)beams) * 2 - 1;
			double dtheta = ((double)theta / (double)angles)* M_PI;

			sinogram[t][theta] = proj_dowolna(e, dtheta, dt);

			
		}
	}
	return sinogram;
}

double ** Projector::proj_phantom(Phantom & ph)
{
	double** temporary;
	int beams = 256;
	int angles = 300;

	double** sinogram2 = 0;
	sinogram2 = new double*[beams];
	for (int t = 0; t < beams; t++) {
		sinogram2 = new double*[angles];
	}

	for (int i = 0; i < 256; i++) {
		for (int J = 0; J < 300; J++) {
			sinogram2[i][J] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		temporary = proj_ellipse(*ph.ellipses[i]);
		
		for (int i = 0; i < 256; i++) {
			for (int J = 0; J < 300; J++) {
				sinogram2[i][J] += temporary[i][J];
			}
		}
	}
	return nullptr;
}



