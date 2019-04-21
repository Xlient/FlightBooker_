#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<random>
#include"TravelRoute.h"
using namespace std;

class Flight
{
public:
	Flight(default_random_engine r);
	~Flight();
	string getOrgin() {
		return departingFrm;
	}
	string getDestination() {
		return arrivingTo;
	}
	string getTripType() {
		return tripType;
	}
	string getDate1() {
		return date1;
	}
	string getDate2() {
		return date2;
	}
	//void displayFlight(string orgin, string dest, string TripType, string date, string date2,
		//int price, int duration, int layover);

private:
	string departingFrm, arrivingTo,
		tripType, date1, date2;

	int duration, layover;
	void getTripData();
	double generatePrice(default_random_engine r, bool d);
};

Flight::Flight(default_random_engine r)
{
	getTripData();
	Travel_Route rt;
	cout << "your price is...: " << endl;
	cout << generatePrice(r, rt.is_Domestic(departingFrm, arrivingTo));
}

Flight::~Flight()
{
}

void Flight::getTripData()
{
	/*Method reads trip information and saves
	the data into member variables to be use later*/
	string value;
	fstream inputFile("Data.txt", ios::in);

	inputFile >> departingFrm;
	inputFile >> arrivingTo;
	inputFile >> tripType;
	inputFile >> date1;
	inputFile >> date2;

}

double Flight::generatePrice(default_random_engine r, bool isdom)
{
	double price;
	if (isdom == true)
	{
		uniform_real_distribution<double> distDom(60, 600);
		price = distDom(r);
	}
	else {
		uniform_real_distribution<double> distr(300, 2000);

		 price = distr(r);
	}
	return price;
}
