#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>

using namespace std;

class FlightGenerator
{
public:
	FlightGenerator() {

	}
	

private:
	string departingFrm,
		arrivingTo,
		tripType,
		date1,
		date2;
	int duration, layover;
};

