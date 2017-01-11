 #include "stdafx.h"
#include "BSTree.h"
#include <iostream>


BSTree::BSTree()
{
	root = nullptr;
}

BSTree::~BSTree()
{
	void Empty();
}

bool BSTree::isEmpty()const
{
	return root == nullptr;
}

void BSTree::Empty() 
{
	Empty(root);
}

void BSTree::Empty(Node *root)
{
	if (root != nullptr) 
	{
		Empty(root->left);
		Empty(root->right);
		delete root->pAcct;
		delete root;
	}
}

bool BSTree::Insert(Account *acc)
{
	if (root != nullptr)
	{
		Insert(acc, root);
	}
	else
	{
		root = new Node;
		root->pAcct = acc;
		root->left = nullptr;
		root->right = nullptr;
	}
	return true;
}

bool BSTree::Insert(Account *acc, Node *root)
{
	if (acc->getID() < root->pAcct->getID())
	{
		if (root->left != nullptr)
		{
			Insert(acc, root->left);
		}
		else
		{
			root->left = new Node;
			root->left->pAcct = acc;
			root->left->left = nullptr;
			root->right->right = nullptr;
		}
	}
	else if(acc->getID()>root->pAcct->getID())
	{
		if (root->right != nullptr)
		{
			Insert(acc, root->right);
		}
		else
		{
			root->right = new Node;
			root->right->pAcct = acc;
			root->right->left = nullptr;
			root->right->right = nullptr;
		}
	}
	return true;
}

void BSTree::Display()const
{
	Display(root);
}

void BSTree::Display(Node *root)const
{
	if (root != nullptr)
	{
		Display(root->left);
		cout << *(root->pAcct) << endl;
		Display(root->right);
	}
}

bool BSTree::Retrieve(const int &id, Account * &acc) const
{
	return Retrieve(id, acc, root);
}

bool BSTree::Retrieve(const int &id, Account *&acc, Node *root)const
{
	if (root != nullptr)
	{
		if (id == root->pAcct->getID())
		{
			acc = root->pAcct;
			return true;
		}
		if (id < root->pAcct->getID())
		{
			return Retrieve(id, acc, root->left);
		}
		else
		{
			return Retrieve(id, acc, root->right);
		}
	}
	return false;
}