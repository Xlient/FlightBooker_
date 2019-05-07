
#include<iostream>
#include"date.h"
#include<Windows.h>
#include<string>
#include<fstream>
#include<chrono>
#include<random>
#include"Flight.h"
#include"ScreenOutput.h"
#include"FlighGenerator.h"
#include"Summary.h"
#include"UserInfo.h"
using namespace std;



void getUserInput(HANDLE, UserInfo&);
void displayUserInput(HANDLE, UserInfo);
void saveData(UserInfo*);


int main() {


	
	UserInfo Input;
	

	HANDLE src = GetStdHandle(STD_OUTPUT_HANDLE);
	Screen::displayPrompts(src);
	getUserInput(src, Input);
	system("pause");
	Flight_Generator gflight;
	gflight.generateFlights();
	TripSummary sum;
	cout << "\n";
	system("pause");
	return 0;

}
// Console control methods 

void getUserInput(HANDLE screen, UserInfo &input) {
	Screen::placeCursor(screen, 5, 30);
	getline(cin, input.departingFROM);
	Screen::placeCursor(screen, 5, 45);
	getline(cin, input.ArrivingTo);
	Screen::placeCursor(screen, 7, 37);
	getline(cin, input.Trip);
	Screen::placeCursor(screen, 9, 32);
	getline(cin, input.date1);
	Screen::placeCursor(screen, 9, 46);
	getline(cin, input.date2);
	saveData(&input); // saves data to file
}
void saveData(UserInfo* input) {


	try
	{
		ofstream FlightData("mydata.txt", ios::out   | ios::trunc);

		FlightData << input->departingFROM << endl;
		FlightData << input->ArrivingTo << endl;
		FlightData << input->Trip << endl;
		FlightData << input->date1 << endl;
		FlightData << input->date2 << endl;
		FlightData.close();

	}
	catch (const std::exception&)
	{
		cout << "unable to save  data please try again..." << endl;
	}
}