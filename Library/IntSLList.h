/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures

Singly linked node
This class implements the singly linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next=null
******************/

#include "IntSLLNode.h"

template <class T>
class IntSLList {
public:
	//Default constructor: creates an empty list
	IntSLList();

	//Destructor: deallocate memory
	~IntSLList();

	//addToHead(T val): creates a new node with val as info, 
	//and this new node is the new head 
	void addToHead(T val);

	//addToTail(T val): creates a new node with val as info, 
	//and this new node is the new tail 	
	void addToTail(T val);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//sortInsert(T val): creates a new node, and it is inserted sortly
	void sortInsert(T val);

	//insert(int pos, T val): creates a new node, and it is inserted in position pos
	void insert(int pos, T val);

	//printList(): prints all nodes in the list
	void printList();
private:
	IntSLLNode<T> *head; //A pointer to the first node
	IntSLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntSLList<T>::IntSLList()
{
	tail = head = 0;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntSLList<T>::~IntSLList()
{
	//Declare a pointer prtNode	
	IntSLLNode<T> *prtNode;
	//prtNode points head
	prtNode = head;

	//While there is a node in the list, remove it
	while (prtNode != 0)
	{
		//prtNode points head->next
		prtNode = head->getNext();

		//delete head
		delete head;

		//the new head is prtNode
		head = prtNode;
	}
}

/***********************
	Implement the other methods here
***********************/
template <class T>
void IntSLList<T>::addToHead(T val)
{
	head = new IntSLLNode(val, head);
	if (tail == 0)
	{
		tail = head;
	}
}

template <class T>
void IntSLList<T>::addToTail(T val)
{
	if (tail != 0)
	{
		tail->setNext(new IntSLLNode<T>(val, 0));
		tail = tail->getNext();
	}
	else
	{
		head = tail = new IntSLLNode<T>(val, 0);
	}
}

template <class T>
void IntSLList<T>::deleteFromHead()
{
	if (head != 0)
	{
		IntSLLNode<T> *tmp;
		tmp = head;
		head = head->getNext();
		if (head == 0)
		{
			tail = 0;
		}
		delete tmp;
	}
}

template <class T>
void IntSLList<T>::deleteFromTail()
{
	if (head != 0)
	{
		IntSLLNode<T> *tmp;
		tmp = head;
		if (head != tail)
		{
			while (tmp->getNext() != tail)
			{
				tmp = tmp->getNext();
			}
			tail = tmp;
			tmp = tmp->getNext();
			tail->setNext(0);
		}
		else
		{
			head = tail = 0;
		}
		delete tmp;
	}
}

template <class T>
void IntSLList<T>::sortInsert(T val)
{
	if (head == 0)
	{
		addToTail(val);

	}
	else
	{
		IntSLLNode<T> *tmp, *tmp2 = NULL;
		tmp = head;
		while ((val.getLastName() < tmp->getInfo().getLastName()) && (tmp != tail))
		{
			tmp2 = tmp;
			tmp = tmp->getNext();
		}
		if ((tmp == tail) && (val.getLastName() < tmp->getInfo().getLastName()))
		{
			addToTail(val);
		}
		else
		{
			tmp2->setNext(new IntSLLNode<T>(val, tmp));
		}
	}
}

template <class T>
void IntSLList<T>::insert(int pos, T val)
{
	IntSLLNode<T> *pre;
	IntSLLNode<T> *cur;
	IntSLLNode<T> *tmp;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->getNext();
	}
	tmp->getInfo() = val;
	pre->setNext() = tmp;
	tmp->setNext() = cur;
}

template <class T>
void IntSLList<T>::printList()
{
	IntSLLNode<T> *prtNode = NULL;
	prtNode = head;
	while (prtNode != 0)
	{
		cout << prtNode->getInfo().getLastName() << " ";
		cout << prtNode->getInfo().getFirstName() << " ";
		prtNode = prtNode->getNext();
	}
	cout << endl;
}

template <class T>
bool IntSLList<T>::isEmpty()
{
	bool res;
	res = false;
	if (head == 0)
	{
		res = true;
	}
	return res;
}

