#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

class Flight
{
public:
	Flight();
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
	void displayFlight(string orgin, string dest, string TripType, string date, string date2,
		int price, int duration, int layover);

private:
	string departingFrm,
		arrivingTo,
		tripType,
		date1,
		date2;
	int duration, layover;
	void getTripData();
	string generatePrice();
};

Flight::Flight()
{
	getTripData();
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

string Flight::generatePrice()
{

	return string();
}
