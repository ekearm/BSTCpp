#ifndef BST_H
#define BST_H
#include "Node.h"

using namespace::std;

class BST 
{
public:
	BST(); 
	BST(BST &rhs);
	~BST();

	Node * getRoot();

	void setRoot(Node * newRoot);
	void insert (char newData, string morse);
	void inOrder();
	void $echo2();
	void $interpetor(); 


private:
	Node *mpRoot;
	Node * $search(Node *pTree, char unKnown);
	void $echo(Node *pTree);
	void insert(Node *& pTree,  char &newData, string &morse);
	void destroyTree(Node *pTree);

};
#endif