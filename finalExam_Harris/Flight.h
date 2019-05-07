#pragma once
#define NOMINMAX
#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include<random>
#include"date.h"
#include"TravelRoute.h"



using namespace std;

class Flight
{
public:
	Flight();
	~Flight();
	std::string getOrgin() {
		return departingFrm;
	}
	std::string getDestination() {
		return arrivingTo;
	}
	std::string getTripType() {
		return tripType;
	}
	std::string getDate1() {
		return date1;
	}
	std::string getDate2() {
		return date2;
	}

	std::string getLayover();

	std::string getDepartTime() {
	return depart_time;
	}
	std::string getArrivalTime() {
		return arrival_time;
	}
	int getFlightNumber() {
		return flightNum;
	}
	int getDuration() {
		return duration;
	}
	double getprice() {
		return price;
	}
	

private:
	std::string departingFrm, arrivingTo,
		tripType, date1, date2;
	std::string depart_time;
	std::string arrival_time;
	
	int duration = 0, layover = 0;
	int flightNum;
	double price = 0.00;

	void getTripData();
	void setPrice(default_random_engine r, bool d);
	void setTravelTime(default_random_engine r, bool d);
	void setFlight_Time(default_random_engine r);
	void setFlightNum(default_random_engine r);

};

Flight::Flight()
{	//Delcaring a seed and initializing it to the current time
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine rand(seed);
	getTripData();
	Travel_Route rt;
	setPrice(rand, rt.is_Domestic(departingFrm, arrivingTo));
	setTravelTime(rand, rt.is_Domestic(departingFrm, arrivingTo));
	 setFlight_Time(rand);
	 setFlightNum(rand);
}

Flight::~Flight()
{
}
 std::string Flight::getLayover()
{
	 std::string strLayover;
		if (layover !=0)
		{
			strLayover = std::to_string(layover) + "hrs";
		}
		else
		{
			strLayover = "Non-Stop";
		}
		return strLayover;
	}


/*Method reads trip information and saves
	the data into member variables to be use later*/
void Flight::getTripData()
{
	
	string value;
	fstream inputFile("mydata.txt", ios::in);

	inputFile >> departingFrm;
	inputFile >> arrivingTo;
	inputFile >> tripType;
	inputFile >> date1;
	inputFile >> date2;
	inputFile.close();
}
//generates random prices based on if the flight is domestic or International Returns the price
void Flight::setPrice(default_random_engine r, bool isdom)
{
	
	if (isdom == true)
	{
		std::uniform_real_distribution<double> distDom(100, 600);
		price = distDom(r);
	}
	else {
		std::uniform_real_distribution<double> distr(400, 2000);

		 price = distr(r);
	}
	
}

 void Flight::setTravelTime(default_random_engine r, bool isdom)
{

	 int timeInAir;
	 if (isdom = true)
	 {
		 std::uniform_int_distribution<int> dist_d(0, 5);
		 timeInAir = dist_d(r);
		 uniform_int_distribution<int> dist_l(0, 6);
		 layover = dist_l(r);
	 }
	 else
	 {
		 std::uniform_int_distribution<int> dist_d(5, 17);
		 timeInAir = dist_d(r);
		 std::uniform_int_distribution<int> dist_l(0, 8);
		 layover = dist_l(r);
	 }
	 duration = timeInAir + layover;
}

 void Flight::setFlight_Time(default_random_engine r)
 {
	 
	 int hour, minute;

	 //Generating a departure time
	 uniform_int_distribution<int> randint(0, 12);
	 hour = randint(r);
	 uniform_int_distribution<int> randint2(1, 59);
	 minute = randint2(r);
	 
	 auto now = std::chrono::system_clock::now();
	 auto randtime = now - std::chrono::hours(hour) - std::chrono::minutes(minute);
	
	 // getting the arrival time based on Departure time + flight duration

	 auto now2 = std::chrono::system_clock::now();
	 auto randtime2 = randtime + std::chrono::hours(duration);
	 
	 depart_time = date::format("%H:%M %I %p",randtime);
	arrival_time = date::format("%H:%M %I %p", randtime2);
 }

 void Flight::setFlightNum(default_random_engine r)
 {
	 std::uniform_int_distribution<int> randNum(1000, 2000);
	 flightNum = randNum(r);
 }
