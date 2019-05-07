#ifdef WIN32
#define NOMINMAX
#undef min
#undef max
#endif
#pragma once
#include<iostream>
#include<string>
#include<chrono>
#include<random>
#include<ctime>
#include<Windows.h>
#include"Flight.h"
#include"ScreenOutput.h"
#include<iomanip>

class Flight_Generator
{
public:
	Flight_Generator();
	~Flight_Generator();
	
	 Flight getSelectFlight() {
		return selectedFlight;
	}
	 void showFlight(Flight*);
	 void generateFlights();

private:
	Flight selectedFlight;
	int flightNum;
	static const int SIZE = 12;
	Flight FlightSession[SIZE];
	Flight *flPrt = FlightSession;
	void FillArr(Flight*, const int);
	void displayAllFlights(Flight*, int);
	 void showMenu(Flight*, int);
	void SortLowestPrice(Flight*, int );
	void SortHighestPrice(Flight*, int);
	 void SelectFlight(Flight*, int);
	

};

Flight_Generator::Flight_Generator(){
	
	
	
}

Flight_Generator::~Flight_Generator()
{
	
}

void Flight_Generator::generateFlights() {
	FillArr(flPrt, SIZE);
	displayAllFlights(flPrt, SIZE);
	showMenu(flPrt, SIZE);
	SelectFlight(flPrt, SIZE);
 }
 void Flight_Generator::displayAllFlights(Flight *allFlights, int size)
{
	 std::cout << "\n Showing all flights \n";
	
	 for (int i = 0; i < size; i++)
	 {
		 showFlight(&allFlights[i]);
		 std::cout << "\n";
	 }

	

}

void Flight_Generator::FillArr(Flight *F, const int sz)
{
	for (int i = 0; i < sz; i++)
	{ 
		Flight currflight;
			F[i] = currflight;
	}
}

void Flight_Generator::showFlight(Flight *Thisflight){
	
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << Thisflight->getDate1();
	std::cout << "\n \n------------ \n";
	std::cout << "$" << fixed << setprecision(2) << Thisflight->getprice();
	std::cout << "\n\n------------ \n";
	std::cout <<"Departing at: " << Thisflight->getDepartTime();
	std::cout << "\tArriving at: " << Thisflight->getArrivalTime();

	std::cout << "\n \n"<< Thisflight->getOrgin() << "\t-------"<<Thisflight->getLayover() << 
		"-------> " << Thisflight->getDestination();

	std::cout << " \n \n fl:" << Thisflight->getFlightNumber() << "\n";

	std::cout << "--------------------------------------------------------------------\n";


}

void Flight_Generator::showMenu(Flight *allFlights, int size)
{
	char option;
	
	std::cout << "\n-------------------------------";
	std::cout << " \n Sort by:  Lowest price  Press l:  | \tHighest price  Press h: ";
	std::cin >> option;
	
	

	if (option == 'l')
	{
		SortLowestPrice(allFlights, size);
	}
	else if (option == 'h')
	{
		SortHighestPrice(allFlights, size);
	}

	else if (option == ' ' && option == ' ') {
		
	}
	else
	{
		std::cout << " \n Please enter a vaild option: l or h \n";
	}

}

void Flight_Generator::SortLowestPrice(Flight *allflights, int SIZE)
{
	Flight temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < (SIZE - 1); count++)
		{
			if (allflights[count].getprice() > allflights[count + 1].getprice()) {
				temp = allflights[count];
				allflights[count] = allflights[count + 1];
				allflights[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	system("CLS");
	displayAllFlights(allflights, SIZE);
}

 void Flight_Generator::SortHighestPrice(Flight *allflights, int SIZE)
{

	 Flight temp;
	 bool swap;
	 do
	 {
		 swap = false;
		 for (int count = 0; count < (SIZE - 1); count++)
		 {
			 if (allflights[count].getprice() < allflights[count + 1].getprice()) {
				 temp = allflights[count];
				 allflights[count] = allflights[count + 1];
				 allflights[count + 1] = temp;
				 swap = true;
			 }
		 }
	 } while (swap);

	 system("CLS");
	 displayAllFlights(allflights, SIZE);
}

  void Flight_Generator::SelectFlight(Flight *flightsArr, int Size)
 {
	  std::cout << "\n Enter the flight number of the flight you would like to select: \n";
	  cin >> flightNum;

	  int last = Size - 1, middle, first = 0,
		  position = -1;
	  bool found = false;
	  while (!found && first <= last)
	  {
		  middle = (first + last) / 2;
		  if (flightsArr[middle].getFlightNumber() == flightNum)
		  {
			  found = true;
			  position = middle;
		  }
		  else if (flightsArr[middle].getFlightNumber() > flightNum)
		  {
			  last = middle - 1;
		  }
		  else {
			  first = middle + 1;
		  }
	  }
	  if (position == -1) { position = 11; }
	
		selectedFlight = flightsArr[position];
	
 }
