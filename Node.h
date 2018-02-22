#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;
using std::fstream;

class Node {
	friend class BST;
public:
	Node(char alphChar, string morseData);
	~Node();

	char getData();
	string getMorse(); 
	//void setData(string newData);
	void setLeft(Node *newLeft);
	void setRighte(Node *newRight);

private:
	char mData;
	string mMorse; 

	Node *mpLeft;
	Node *mpRight;

	Node *& getmpLeft();
	Node *& getmpRight();
};
#endif