/**********************************************************************************
* Programmer: Kyan Kotschevar-Smead                                                *
* Class: CptS 223                                          *
* Programming Assignment:1                                       *
* Date:1/20/2023                                                                      *
*                                                                                *
* Description: Program is linux game game where users match descriptions to commands
*                                                                                *
*********************************************************************************/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "data.h"
#include"Node.h"
#include"List.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;


int main() {
	cout << "Please Choose one of the options below" << endl;
	cout << "1. Game Rules \n2. Play new Game \n3. load previous game\n4. add command\n5. remove command" << endl;
	cout << "6. Display all commands \n7. Save and exit " << endl;
	int scores[10] = {};
	string names[10] = {};
	int choice = 0;
	List gamelist;
	gamelist.loadList();
	while (choice != 7)
	{
		cin >> choice;
		if (choice == 1) {
			cout << "The point of the game is to match linux defintions to a command. By responding to the " <<
				"question correctly you have the chance to gain points while if wring the potenial to lose. Good Luck" << endl;
		}//Print Description
		if (choice == 2) {
			string userI;
			if (gamelist.getName() == "") {
				string userI;
				cout << "Enter Name " << endl;
				cin >> userI;
				gamelist.setName(userI);
			}
			cout << "How Many Questions: (int 5-30): " << endl;
			cin >> userI;
			gamelist.playGame(atoi(userI.c_str()));

		}//Play new Game
		if (choice == 3) {
			ifstream file;
			file.open("Profiles.csv");
			string q1;
			char str[30];
			string temp;
			int u = 0;
			while (!file.eof() && u<=9)
			{
				getline(file, q1);
				strcpy(str, q1.c_str());
				temp = strtok(str, ",");
				names[u] = temp;
				temp = strtok(NULL, ",");
				scores[u] = atoi(temp.c_str());
				u++;
			}
			cout << "Choose User" << endl;
			for (int i = 0; i < u; i++)
			{
				
				cout << "(" << i << ")" << names[i] << " " << scores[i] << endl;
			}
			int userp;
			cin >> userp;
			gamelist.setName(names[userp]);
			gamelist.setScore(scores[userp]);

			cout << "Profile Set" << endl;

		}// Set profile



		if (choice == 4) {
			string temp;
			Data newData;
			cout << "Please State the Name Of Command you want to add" << endl;
			cin >> temp;
			Node* pTemp = gamelist.getPhead();
			int same = 0;
			while (pTemp != nullptr)
			{
				if (pTemp->getData().getCommand() == temp) {
					same++;
				}
				pTemp = pTemp->getpNext();
			}
			if (same > 0)
			{
				cout << "Invaild Command Try Again" << endl;
			}
			else {
				newData.setCommand(temp);
				cout << "Please Enter Description" << endl;
				cin >> temp;
				newData.setDescription(temp);
				cout << "Points Worth (INT)" << endl;
				cin >> temp;
				newData.setPoints(atoi(temp.c_str()));
				gamelist.InsertAtFront(newData);
			}
		}//Add command


		if (choice == 5) {
			cout << "Name of Command wanting to delete?" << endl;
			string temp;
			cin >> temp;
			int same = 0;
			Node* pTemp = gamelist.getPhead();
			while (pTemp != nullptr)
			{
				if (pTemp->getData().getCommand() == temp) {
					same++;
					gamelist.removeNode(pTemp);
					break;

				}
				pTemp = pTemp->getpNext();
			}
			
			if (same == 0) {
				cout << "Could not find existenice of command to delete" << endl;
			}
		}//Delete Command

		if (choice == 6) {
			gamelist.printList();
		}//Print Commmands

		cout << "Please Choose one of the options below" << endl;
		cout << "1. Game Rules \n2. Play new Game \n3. load previous game\n4. add command\n5. remove command" << endl;
		cout << "6. Display all commands \n7. Save and exit " << endl;
	}
	ofstream myFile;
	myFile.open("Profiles.csv",ios::app);
	
	myFile << endl;
	myFile << gamelist.getName() << "," << gamelist.getScore();
	myFile.close();
	//Program End
}



/*
Linked List:
Advantage: Biggest advantage to the linkedlist was the ability to insert and delete at will. (Allocating Data)
Specfically when importanting data into the linkedList at the start of the program and with the add new
options.
Disadvantage:
One of the biggest disadvantages of the linked list was with the randomization aspect.
When generating a random number, it meant i had to travese through thru the list x amount of times till i find the xth node
Comparitivly with an array, i could generate a number and immidaitly find its index.

Array:
Advantage:
Being able to display names with a user input directly associated with an array index
Disadvantage:
Limited space for the amount profiles i can store up to a predetermined amount.







*/