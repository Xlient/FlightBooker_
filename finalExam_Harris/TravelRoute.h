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

	std::vector<std::string> international = { "PEK","DXB", "HND", "LHR", "HKG", "CDG", "AMS", "DEL","FRA ","ICN","IST","CGK","BKK","MAD","SIN"};
};

Travel_Route::Travel_Route()
{
}

Travel_Route::~Travel_Route()
{
}

 bool Travel_Route::is_Domestic(std::string org, std::string dest){
	 int index = 0,
		 position = -1;
	 bool found = false;
	 while (index < domestic.size() && !found)
	 {
		 if (domestic[index]== org || domestic[index] == dest)
		 {
			 isDomestic = true;
		 }
		 index++;
	 }
	 
	 
	 return isDomestic;
}
