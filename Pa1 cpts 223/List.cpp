#include "List.h"

List::List() {
	this->pHead = nullptr;
	this->score = 0;
}

List:: ~List() {
	cout << "Destroying List" << endl;
}
/*************************************************************
* Function: INsertAtFront                                *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: inserts new node at front of list
* Input parameters: Data
* Preconditions: load list or add command is called    *
* Postconditions: new node added to the front           */
void List::InsertAtFront(Data data) {
	if (pHead == nullptr) {
		pHead = new Node(data);
		pHead->setPnext(nullptr);
	}
	else
	{
		Node* temp = new Node(data);
		pHead->setpPrev(temp);
		temp->setPnext(pHead);
		pHead = temp;
	}
}

Node* List::getPhead() {
	return pHead;
}
/*************************************************************
* Function: Delete Node                                *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: Does node pointer manioulation and deletes node
* Input parameters: Data
* Preconditions: Dekete option is choosin      *
* Postconditions: Node is delted      */
void List::removeNode(Node* dNode) {
	if (dNode->getpPrev() != nullptr) {
		dNode->getpPrev()->setPnext(dNode->getpNext());
	}
	if (dNode->getpNext() != nullptr) {
		dNode->getpNext()->setpPrev(dNode->getpPrev());
	}
	delete dNode;
}
void List::setName(string name) {
	this->name = name;
}
string List::getName() {
	return name;
}
void List::setScore(int score) {
	this->score = score;
}
int List::getScore() {
	return score;
}

/*************************************************************
* Function: LoadList                            *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description:
* Input parameters: Data
* Preconditions: program is ran*
* Postconditions: list is loaded with data           */
void List::loadList() {
	ifstream file;
	file.open("commands.csv");
	Data com;
	string q1;
	char str[300];
	string temp;

	while (!file.eof())
	{
		getline(file, q1);
		strcpy(str, q1.c_str());
		temp = strtok(str, ",");
		com.setCommand(temp);
		temp = strtok(NULL, ",");
		com.setDescription(temp);
		temp = strtok(NULL, ",");
		com.setPoints(atoi(temp.c_str()));
		InsertAtFront(com);
	}
	file.close();
}

/*************************************************************
* Function: Printlist                                 *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: prints entire linked list
* Input parameters: Data
* Preconditions: program is ran
* Postconditions: displayed throughout     */
void List::printList() {
	Node* tempNode = pHead;
	while (tempNode != nullptr)
	{
		cout << tempNode->getData().getCommand() << endl;
		cout << tempNode->getData().getDescription() << endl;
		cout << endl;
		tempNode = tempNode->getpNext();

	}
}

/*************************************************************
* Function:  Playgame                     *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: Linux commands are loaded and game is played
* Input parameters: Data
* Preconditions: play new game is selected    *
* Postconditions:           */
void List::playGame(int num) {
	int i = 0;
	int useri = 0;
	while (i < num)
	{
		Node* pTemp = pHead;
		Node* q1 = nullptr;
		Node* q2 = nullptr;
		srand(time(NULL));
		int random = rand() % 31;
		int count = 0;
		while (count < random && pTemp->getpNext()!= nullptr)
		{
			pTemp = pTemp->getpNext();
			count++;
		}

		if (pTemp->getpPrev() == nullptr)
		{
			q1 = pTemp->getpNext();
			q2 = q1->getpNext();
		}
		else if (pTemp->getpNext() == nullptr) {
			q1 = pTemp->getpPrev();
			q2 = q1->getpPrev();
		}
		else {
			q1 = pTemp->getpNext();
			q2 = pTemp->getpPrev();
		}
		cout << "Pick the correct description for : " << pTemp->getData().getCommand() << endl;
		int r2 = rand() % 3 + 1;
		if (r2 == 1) {
			cout << "(1) " << pTemp->getData().getDescription() << " " << pTemp->getData().getPoints() << endl;
			cout << "(2) " << q1->getData().getDescription() << " " << q1->getData().getPoints() << endl;
			cout << "(3) " << q2->getData().getDescription() << " " << q2->getData().getPoints() << endl;
		}
		else if(r2 == 2) {
			
			cout << "(1) " << q1->getData().getDescription() << " " << q1->getData().getPoints() << endl;
			cout << "(2) " << pTemp->getData().getDescription() << " " << pTemp->getData().getPoints() << endl;
			cout << "(3) " << q2->getData().getDescription() << " " << q2->getData().getPoints() << endl;
		}
		else if (r2 == 3)
		{
			cout << "(1) " << q1->getData().getDescription() << " " << q1->getData().getPoints() << endl;
			cout << "(2) " << q2->getData().getDescription() <<  " " << q2->getData().getPoints() << endl;
			cout << "(3) " << pTemp->getData().getDescription() << " " << pTemp->getData().getPoints() << endl;
		}
		cin >> useri;
		
		if (useri == r2) {
			cout << "Correct +" << pTemp->getData().getPoints() << endl;
			score = score + pTemp->getData().getPoints();
		}
		else {
			cout << "Incorrect -" << pTemp->getData().getPoints() << endl;
			score = score - pTemp->getData().getPoints();
		}

		i++;
	}
	cout << name << score << endl;
	
	
}

