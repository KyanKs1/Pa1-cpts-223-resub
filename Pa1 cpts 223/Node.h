#pragma once
#include "Data.h"
class Node
{
public:
	Node(Data data);
	~Node();
	Data getData();
	Node* getpNext();
	void setPnext(Node* nextNode);
	Node* getpPrev();
	void setpPrev(Node* prevNode);

private:
	Data data;
	Node* pPrev;
	Node* pNext;
};

