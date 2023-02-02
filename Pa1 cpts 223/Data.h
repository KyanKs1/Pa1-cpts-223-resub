#pragma once
#include <iostream>
#include <string>
	using namespace std;
	class Data
	{
	public:
		Data();
		string getCommand();
		string getDescription();
		int getPoints();
		void setCommand(string command);
		void setDescription(string description);
		void setPoints(int points);
	private:
		string command;
		string description;
		int points;
	};


