#define NOMINMAX
#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include"FlighGenerator.h"
#include"Flight.h"
#include"ScreenOutput.h"
#include<iomanip>
#include"UserInfo.h"

class TripSummary
{
public:
	TripSummary();
	~TripSummary();

private:
	struct UserInfo Input;
	double tax;
	double subtotal;
	double total;
	void getSummary(Flight*, struct UserInfo *Input);
	void getPersonalInfo(struct UserInfo *Input);
};

TripSummary::TripSummary()
{
	Flight_Generator flGen;

	getSummary(&flGen.getSelectFlight(), &Input);
}

TripSummary::~TripSummary()
{
}

 void TripSummary::getSummary(Flight *myflight, UserInfo *Input)
{
	 getPersonalInfo(Input);
	 Flight_Generator flg;

	 system("CLS");
	 HANDLE Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	 Screen::draw_rect(300, 100);
	 Screen::placeCursor(Screen,6, 50);
	 std::cout << "  Trip Summary  ";
	 Screen::placeCursor(Screen, 8, 34);
	 std::cout << "Name:" << Input->name; 
	 Screen::placeCursor(Screen, 9, 34);
	 std::cout << "Age: " << Input->age;
	 Screen::placeCursor(Screen, 10, 34);
	 std::cout  << "Country: " << Input->country;
	 Screen::placeCursor(Screen, 12, 15);
	 std::cout << " \n Selected flight : ";
	 Screen::placeCursor(Screen, 16, 0);

	 flg.showFlight(myflight);
	 
	 subtotal = myflight->getprice();
	 tax = myflight->getprice() * .15;
	 total = subtotal + tax;

	 std::cout << "\n SubTotal: " << fixed << setprecision(2)<< subtotal;
	 std::cout << "\n Tax: " << fixed << setprecision(2) << tax;
	 std::cout << "\n Total: " << fixed << setprecision(2) << total;
}

 void TripSummary::getPersonalInfo(UserInfo * Input)
 {
	 system("CLS");
	 std::cout << "Personal Information \n ----------------------------------- \n";
	 std::cout << " \n Enter your name:";
		 cin >> Input->name;

		 std::cout << " \n Enter your age:";
		 cin >> Input->age;

		 std::cout << " \n Enter Country:";
		 cin >> Input->country;

	 std:cout << "\n ---------------------------------------------------";
 }
