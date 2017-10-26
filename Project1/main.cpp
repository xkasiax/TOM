#include "Projector.h"
#include "Phantom.h"
#include <fstream>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

string DecToBin(int number)
{
	if (number == 0) return "0";
	if (number == 1) return "1";

	if (number % 2 == 0) return DecToBin(number / 2) + "0";
	else
		return DecToBin(number / 2) + "1";
}

int main() {
	double max = 0;
	double min = 9999999;
	double foobar[3][2] = { { 2.0,4.0 },{ 4.0,7.0 },{ 4325434.0, 54645.0001 } };
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<2; j++) {
			if (max<foobar[i][j])
				max = foobar[i][j];
			if (min>foobar[i][j])
				min = foobar[i][j];
		}
	}

	double toBedzieKonwertowaneNaInta;
	int foobarint[3][2];
	double m = min * 4095 / (min - max);
	double k = 4095 / (max - min);
	int skonwertowaneNaInta;

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<2; j++) {
			toBedzieKonwertowaneNaInta = foobar[i][j] * k + m;
			skonwertowaneNaInta = int(toBedzieKonwertowaneNaInta);
			foobarint[i][j] = skonwertowaneNaInta;
		}
	}

	Phantom fantom;
	Projector prodzektor;
	ofstream myFile;
	myFile.open("wynikowyPlik.bin");
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<2; j++) {
			myFile << (foobarint[i][j]) << " ";
		}
		myFile << endl;
	}

	myFile.close();
	return 0;
}