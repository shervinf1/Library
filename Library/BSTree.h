/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures

Binary Search Tree
This class implements the Binary Search Tree using templates
Each list has one attribute:
	-root: first node in tree

Considerations:
1. root points to null in an empty list

******************/

#include "BSTNode.h"

template <class T>
class BSTree {
public:
	//Default constructor: creates an empty tree
	BSTree();

	//Destructor: deallocate memory
	~BSTree();

	//insert(T val): creates a new node with val as info, 
	void insert(T val);

	//remove(T val): remove the first node with val as info, 
	//if the node is removed, returns true, otherwise returns false
	bool remove(T val);

	//search(T val): returns a pointer to node with val as info
	BSTNode<T>* search(T val);

	//If the tree is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printInOrder(): InOrder Traversal
	void printInOrder();

	//printPreOrder(): PreOrder Traversal
	void printPreOrder();

	//printPostOrder(): PostOrder Traversal
	void printPostOrder();

	BSTNode<T>* getRoot();
	//void printInOrderCDLL();


private:
	BSTNode<T> *root; //A pointer to the first node

	void visitInOrder(BSTNode<T> *node);//Recursive support method for printInOrder
	void visitPreOrder(BSTNode<T> *node);//Recursive support method for printPreOrder
	void visitPostOrder(BSTNode<T> *node);//Recursive support method for printPostOrder
	//void visitInOrderCDLL(BSTNode<T> *node);
	BSTNode<T>* recursiveSearch(BSTNode<T> *node, T val);//Recursive support method for search
	bool recursiveSearchForRemove(BSTNode<T> *node, T val);//Recursive support method for remove
	BSTNode<T>* findLowest(BSTNode<T> *node);//Extract the lowest node in a subtree rooted on node

};

/****************
	Default constructor: creates an empty Binary Search tree
*****************/
template <class T>
BSTree<T>::BSTree()
{
	root = 0;
}

//Destructor that deallocates memory
template <class T>
BSTree<T>::~BSTree()
{
	delete root;
}

template<class T>
BSTNode<T>* BSTree<T>::getRoot()
{
	return root;
}
//insert(T val): creates a new node with val as info,
template<class T>
void BSTree<T>::insert(T val)
{
	if (root == 0)
	{
		root = new BSTNode<T>(0, val, 0);
	}
	else
	{
		BSTNode<T> *tmp, *sRoot = NULL;
		tmp = root;

		while (tmp != 0)
		{
			sRoot = tmp;
			if (val.getGenreName() < sRoot->getInfo().getGenreName())
			{
				tmp = tmp->getLeft();
			}
			else
			{
				tmp = tmp->getRight();
			}
		}
		if (val.getGenreName() < sRoot->getInfo().getGenreName())
		{
			sRoot->setLeft(new BSTNode<T>(0, val, 0));
		}
		else
		{
			sRoot->setRight(new BSTNode<T>(0, val, 0));
		}
	}
}

//search(T val): returns a pointer to node with val as info
template<class T>
BSTNode<T>* BSTree<T>::search(T val)
{
	return recursiveSearch(root, val);
}

template<class T>
BSTNode<T>* BSTree<T>::recursiveSearch(BSTNode<T> *node, T val)
{
	BSTNode<T>* res;
	res = 0;
	if (node != 0) {
		if (val.getGenreName() == node->getInfo().getGenreName())
			res = node;
		else if (val.getGenreName() < node->getInfo().getGenreName())
			res = recursiveSearch(node->getLeft(), val);
		else
			res = recursiveSearch(node->getRight(), val);
	}
	return res;
}

//printPreOrder(): PreOrder Traversal
template<class T>
void BSTree<T>::printPreOrder()
{
	visitPreOrder(root);
}

template<class T>
void BSTree<T>::visitPreOrder(BSTNode<T> *node)
{
	if (node != 0)
	{
		cout << "-" << node->getInfo() << "-";
		visitPreOrder(node->getLeft());
		visitPreOrder(node->getRight());
	}
}

//printInOrder(): InOrder Traversal
template<class T>
void BSTree<T>::printInOrder()
{
	visitInOrder(root);
}

template<class T>
void BSTree<T>::visitInOrder(BSTNode<T> *node)
{
	if (node != 0)
	{
		visitInOrder(node->getLeft());
		cout << "-" << node->getInfo().getGenreName() << "-";
		visitInOrder(node->getRight());
	}
}

//printPostOrder(): PostOrder Traversal
template<class T>
void BSTree<T>::printPostOrder()
{
	visitPostOrder(root);
}
//This recursive method visits the tree in post order one by one and prints out the nodes information
template<class T>
void BSTree<T>::visitPostOrder(BSTNode<T> *node)
{
	if (node != 0)
	{
		visitPostOrder(node->getLeft());
		visitPostOrder(node->getRight());
		cout << "-" << node->getInfo().getGenreName << "-";
	}
}

//This method looks for the lowest valued node in the tree which is on the left side and returns the node when found
template<class T>
BSTNode<T>* BSTree<T>::findLowest(BSTNode<T> *node)
{
	BSTNode<T> *tmp;
	if (node->getLeft() == 0)
	{
		tmp = node;
	}
	else
	{
		while (node->getLeft->getLeft() != 0)
			node = node->getLeft();
		tmp = node->getLeft();
		node->setLeft(tmp->getRight());
	}
	return tmp;
}

//remove(T val): remove the first node with val as info, 
	//if the node is removed, returns true, otherwise returns false
template<class T>
bool BSTree<T>::remove(T val)
{
	bool res = false;
	if (root != 0)
	{
		if (root->getInfo() == val)//renove root
		{
			if (root->getLeft() == 0 && root->getRight() == 0)
			{
				delete root;
				root = 0;
			}
			else
			{
				BSTNode<T> *tmp;
				tmp = root;
				if (root->getLeft() == 0)
				{
					root = root->getRight();
				}
				else if (root->getRight() == 0)
				{
					root = root->getLeft();
				}
				else
				{
					BSTNode<T> *lowest;
					lowest = findLowest(root->getRight());
					if (root->getRight() == lowest)//The lowest is it's right child
					{
						lowest->setLeft(root->getLeft());
						root = lowest;
					}
					else
					{
						root = lowest;
						root->setLeft(tmp->getLeft());
						root->setRight(tmp->getRight());
					}
				}
				delete tmp;
			}
			res = true;
		}
		else
			res = recursiveSearchForRemove(root, val);
	}
	return res;
}template<class T>

//This recursive method will go thoughout the tree and locate the specific node and remove it 
bool BSTree<T>::recursiveSearchForRemove(BSTNode<T> *node, T val)
{
	bool res;
	res = false;
	BSTNode<T> *tmp, *found;
	if ((node->getLeft() != 0) && val < node->getInfo())
	{
		if (node->getInfo()->getInfo == val)
		{
			found = node->getLeft();
			if (found->getRight() == 0)
			{
				node->setLeft(found->getLeft());
			}
			else
			{
				tmp = findLowest(found->getRight());
				node->setLeft(tmp);
			}
			res = true;
		}
		else
			res = recursiveSearchForRemove(node->getLeft(), val);
	}
	else if ((node->getRight() != 0) && (val > node->getInfo()))
	{
		if (node->getRight()->getInfo() == val)
		{
			found = node->getRight();
			if (found->getRight == 0)
			{
				node->setRight(found->getLeft());
			}
			else
			{
				tmp = findLowest(found->getRight());
				node->setRight(tmp);
			}
			res = true;
		}
		else
		{
			res = recursiveSearchForRemove(node->setRight(), val);
		}
	}
	return res;
}

//If the tree is empty, returns true
	//otherwise, returns false
template<class T>
bool BSTree<T>::isEmpty()
{
	bool res;
	res = false;
	if (root == 0)
	{
		res = true;
	}
	return res;
}
