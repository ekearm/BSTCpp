#include "BST.h"

BST::BST()
{
	ifstream file;
	file.open("Mourse.txt");
	char buffer [400];
	file.getline(buffer, 400);
	string alpha = strtok(buffer, " ");
	string morse = strtok(NULL," ");
	mpRoot = new Node(alpha[0], morse);

	while (!file.eof())
	{
		file.getline(buffer, 400);
		alpha = strtok(buffer, " ");
		morse = strtok(NULL, " ");
		insert(alpha[0], morse);
	}
	ifstream close("mourse.txt");
}
BST::BST(BST &rhs)
{
	this->mpRoot = rhs.mpRoot; 
}
BST:: ~BST()
{
	destroyTree(this->mpRoot);
}
Node * BST::getRoot()
{
	return mpRoot;
}
void BST::setRoot(Node * newRoot)
{
	mpRoot = newRoot;
}
void BST::insert(char newData, string morse)
{
	insert(this->mpRoot, newData, morse);
}
void BST::inOrder()
{
	$echo(this->mpRoot); 
}
void BST::insert(Node *& pTree, char &newData, string &morse)
{
	if (pTree == nullptr)
	{
		Node *pMem = nullptr;
		pMem = new Node(newData, morse);
		pTree = pMem; 
	}
	else if (newData > pTree->getData())
	{
		insert(pTree->getmpRight(), newData, morse);
	}
	else if (newData < pTree->getData())
	{
		insert(pTree->getmpLeft(), newData, morse);
	}
	else
	{
		cout << "duplicate failed" << endl; 
	}
}
void BST::$echo2()
{
	$echo(mpRoot);
}
void BST::$echo(Node *pTree)
{
	if (pTree != nullptr)
	{
		$echo(pTree->getmpLeft());
		cout << pTree->getData() << endl;
		$echo(pTree->getmpRight());
	}
}
void BST::destroyTree(Node *pTree)
{
	/*if (pTree != nullptr)
	{
		destroyTree(pTree->getmpLeft());
		destroyTree(pTree->getmpLeft());
		delete pTree;
	}*/
}

Node * BST::$search(Node *pTree, char unKnown)
{
	if (pTree == nullptr)
	{
		return nullptr;
	}
	else if (pTree->getData() == unKnown)
	{
		return pTree;
	}

	else
	{
		if (unKnown > pTree->getData())
		{
			$search(pTree->getmpRight(),unKnown);
		}
		else
		{
			$search(pTree->getmpLeft(), unKnown);
		}
	}
}
void BST::$interpetor()
{
	ifstream file2; 
	file2.open("Convert.txt");
	char buffer[1024];
	while (!file2.eof())
	{
		int i = 0;
		file2.getline(buffer, 1024);

		while (buffer[i] != NULL)
		{
			char temp = buffer[i];
			if (temp == ' ')
			{
				cout << "  ";
			}
			else if (temp == '\r')
			{
				cout << '\r';
			}
			else if (temp == '\n')
			{
				cout << '\n';
			}
			else
			{
				temp = toupper(temp);
				Node * tempNode = $search(mpRoot,temp);
				cout << tempNode->getMorse();
				cout << ' ';
			}
			i++;
		}
	}
}