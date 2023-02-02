#include "Data.h"
/*************************************************************
* Function: Data Constructor                                *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: Data Constructer
* Input parameters: 
* Preconditions:  Sets defualt values for data      *
* Postconditions: Data is filled with NULL command description and points            */
Data::Data() {
	 this->command = "";
	 this->description = "";
	 this->points = 0;
}

 string Data::getCommand() {
	 return command;
 }
 string Data::getDescription() {
	 return description;
 }
 int Data::getPoints() {
	 return points;
 }
 void Data::setCommand(string commmand) {
	 this->command = commmand;
 }
 void Data::setDescription(string description) {
	 this->description = description;  
 }
 void Data::setPoints(int points) {
	 this->points = points;
 }