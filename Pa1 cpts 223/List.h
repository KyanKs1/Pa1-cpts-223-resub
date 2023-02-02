#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
#include <iostream>
#include <string>
#include <ctime>
#include<fstream>

class List
{
public:
	List();
	~List();
	Node* getPhead();
	void InsertAtFront(Data data);
	void removeNode(Node* dNode);
	void loadList();
	void printList();
	void playGame(int num);
	void setScore(int score);
	int getScore();
	string getName();
	void setName(string name);
private:
	Node* pHead;
	int score;
	string name;

};