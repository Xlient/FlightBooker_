#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include<chrono>
#include<random>
#include<ctime>
#include"Flight.h"
using namespace std;
struct UserInfo
{
	string name;
	string departingFROM;
	string ArrivingTo;
	string Trip;
	string date1, date2;
	
	
};
void placeCursor(HANDLE, int, int);
void displayPrompts(HANDLE);
void getUserInput(HANDLE, UserInfo&);
void displayUserInput(HANDLE, UserInfo);
void saveData(UserInfo);

/*Unfinished*/
int main() {
	/*
	*/
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine rand(seed);
	UserInfo Input;

	HANDLE Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	displayPrompts(Screen);
	getUserInput(Screen, Input);
	Flight f1(rand);
	system("pause");

}
// Console control methods 
void placeCursor(HANDLE screen, int row, int col) { // this method places the cursor at 
	//spesfic points on the x and y coordinates on the console screen
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

void displayPrompts(HANDLE screen) {
	placeCursor(screen, 3, 25);
	cout << "------- Book Your Trip -------" << endl;
	placeCursor(screen, 5, 25);
	cout << "From:\t" <<  "\t to:\t" << endl;
	placeCursor(screen, 7, 25);
	cout << "Trip Type: "<< endl;
	placeCursor(screen, 9, 35);
	cout << "Dates :           :          " << endl;

}
void getUserInput(HANDLE screen, UserInfo &input) {
	placeCursor(screen, 5, 30);
	getline(cin, input.departingFROM);
	placeCursor(screen, 5, 45);
	getline(cin, input.ArrivingTo);
	placeCursor(screen, 7, 37);
	getline(cin, input.Trip);
	placeCursor(screen, 9, 42);
	getline(cin, input.date1);
	placeCursor(screen, 9, 56);
	getline(cin, input.date2);
	saveData(input); // saves data to file
}
void saveData(UserInfo input) {
	try
	{
		ofstream FlightData;
		FlightData.open("Data.txt");
		
		FlightData << input.departingFROM << endl;
		FlightData << input.ArrivingTo << endl;
		FlightData << input.Trip << endl;
		FlightData << input.date1<< endl;
		FlightData << input.date2 << endl;
	}
	catch (const std::exception&)
	{
		cout << "unable to save  data please try again..." << endl;
	}
	
}