#include "Node.h"

Node::Node(char alphChar, string morseData)
{

	mData = alphChar;
	mMorse = morseData; 
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node:: ~Node()
{
	cout << "Your Node has been deleted ;) have a nice day." << endl; 
}
//Getters
char Node::getData()
{
	return mData; 
}

string Node::getMorse()
{
	return mMorse; 
}

Node *& Node::getmpLeft()
{
	return mpLeft;
}

Node *& Node::getmpRight()
{
	return mpRight;
}

//Setters
/*void Node::setData(char newData)
{
	mData = newData; 
}*/
void Node::setLeft(Node *newLeft)
{
	mpLeft = newLeft;
}
void Node::setRighte(Node *newRight)
{
	mpRight = newRight;
}