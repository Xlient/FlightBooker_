#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>

class Screen
{
public:
	Screen();
	~Screen();
	static void placeCursor(HANDLE, int, int);
	static void displayPrompts(HANDLE);
	static void draw_rect(int l, int w);

private:

};

Screen::Screen()
{
}

Screen::~Screen()
{
}


void Screen::placeCursor(HANDLE screen, int row, int col) { // this method places the cursor at 
	//spesfic points on the x and y coordinates on the console screen
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

 void  Screen::displayPrompts(HANDLE screen) {
	using std::cout;
	using std::endl;

	placeCursor(screen, 3, 25);
	cout << "------- Book Your Trip -------" << endl;
	placeCursor(screen, 5, 25);
	cout << "From:\t" << "\t to:\t" << endl;
	placeCursor(screen, 7, 25);
	cout << "Trip Type: " << endl;
	placeCursor(screen, 9, 25);
	cout << "Dates :           :          " << endl;

}

  void Screen::draw_rect(int l, int w)
 {
	  using std::cout;
	  cout << "-"; //loops and prints out a "-" until the max width for one side is reached
	  for (int i = 0; i < w - 1; i++)
	  {
		  cout << "-";
	  }
	  cout << "-\n";
	
	  for (int i = 0; i < 10; i++)
	  {
		  cout << "\n";
	  }

	  for (int i = 0; i < w - 1; i++)
	  {
		  cout << "-";
	  }
	  
  }
 
