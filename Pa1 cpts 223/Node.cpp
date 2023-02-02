#include "Node.h"
/*************************************************************
* Function: Node Constructor                                *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: Node Constructer
* Input parameters: Data
* Preconditions: InsertatFront is called when importing list       *
* Postconditions: Node is filled with command description and points            */
Node::Node(Data data) {
	this->data.setCommand(data.getCommand());
	this->data.setDescription(data.getDescription());
	this->data.setPoints(data.getPoints());

}
Data Node::getData() {
	return data;
}
Node* Node::getpNext() {
	return pNext;
}
Node* Node::getpPrev() {
	return pPrev;
}
void Node::setPnext(Node* nextNode) {
	pNext = nextNode;
}
void Node::setpPrev(Node* prevNode) {
	pPrev = prevNode;
}
/*************************************************************
* Function: Node DeConstructor                                *
* Date Created: 1/20                                   *
* Date Last Modified: 1/20                                   *
* Description: destroys node
* Preconditions: Delete node is called from option or program is exited       *
* Postconditions: Node is destroyed          */
Node::~Node() {
	cout << "Deleting Node" << endl;
}