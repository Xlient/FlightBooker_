#pragma once
#include<iostream>
#include<string>
#include<vector>

class Travel_Route
{
public:
	Travel_Route();
	~Travel_Route();

bool is_Domestic(std::string orgin, std::string destination);

private:
	typedef std::string Destination;
	bool isDomestic = false;
	std::vector<std::string> domestic ={ "ATL","LAX","ORD", "DFW", 
							"DEN", "JFK", "SFO", "LAS", 
							"SEA", "CLT", "EWR","MCO", "PHX", 
							"MIA", "IAH", "BOS", "MSP","DTW",
							"FLL","PHL", "LGA", "BWI","SLC",
							"DCA", "IAD", "SAN", "MDW","TPA",
								"HNL", "PDX"};

	std::vector<std::string> international = { "PEK","DXB", "HND", "LHR", "HKG", "CDG",
		"AMS", "DEL","FRA ","ICN","IST","CGK","BKK","MAD","SIN"};
};

Travel_Route::Travel_Route()
{
}

Travel_Route::~Travel_Route()
{
}
/* this method preforms a simple linear search to find a domestic flight. if a domestic flight is not found then it returns false.*/
 bool Travel_Route::is_Domestic(std::string org, std::string dest){
	 int index = 0, index2 = 0;
	
	 bool found_orgin = false, found_destination = false;
	 //This is searching for the Orgin
	 while (index < domestic.size() && !found_orgin)
	 {
		
		 if (domestic.at(index) == org)
		 {
			 found_orgin = true;
			 
		 }
			 

			 index++;
		 }

	 while (index2 < domestic.size() && !found_destination) {

		 if (domestic.at(index2) == dest)
		 {
			 found_destination = true;
		 }
		 index2++;
	 }

			 if (found_orgin == true && found_destination == true) {

				 isDomestic = true;
			 }
			 return isDomestic;
		 }
