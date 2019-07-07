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
1. head point to null in an empty list
2. There is not need of a tail pointer
******************/

#include "IntDLLNode.h"

template <class T>
class circDLList {
public:
	//Default constructor: creates an empty list
	circDLList();

	//Destructor: deallocate memory
	~circDLList();

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

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printList(): prints all nodes in the list from tail to head
	void printRevList();

	//Searches for a node and returns such node
	IntDLLNode<T>*searchNode(T i);

	IntDLLNode<T>* getHead();

private:
	IntDLLNode<T> *head; //A pointer to the first node
	int size;
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
	head = 0;
	size = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
	while (!isEmpty())
		this->deleteFromHead();
}

/***********************
	Implement other methods

***********************/
template<class T>
IntDLLNode<T>* circDLList<T>::getHead()
{
	return head;
}
template <class T>
void circDLList<T>::addToHead(T val) {
	if (head != 0) {
		//Not an empty list
		IntDLLNode<T> *tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
		head = tmp;
		size++;
	}
	else { //An empty list
		cout << "Empty list" << endl;
		head = new IntDLLNode<T>(0, val, 0);
		head->setPrev(head);
		head->setNext(head);
		size++;
	}
}
template <class T>
void circDLList<T>::addToTail(T val) {
	if (head != 0) {
		//Not an empty list
		IntDLLNode<T> *tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
		size++;
	}
	else {
		//An empty list
		head = new IntDLLNode<T>(0, val, 0);
		head->setPrev(head);
		head->setNext(head);
		size++;
	}
}

template <class T>
void circDLList<T>::deleteFromHead()
{
	if (head != 0) {
		IntDLLNode<T> *tmp;
		tmp = head;
		if (head == head->getNext())
		{//One node list
			head = 0;
		}
		else { //list with more than one node
			head->getNext()->setPrev(head->getPrev());
			head->getPrev()->setNext(head->getNext());
			head = head->getNext();
		}
		delete tmp;
	}
}

template <class T>
void circDLList<T>::deleteFromTail()
{
	if (head != 0) {
		IntDLLNode<T> *tmp;
		tmp = head->getPrev();
		if (head == head->getNext()) {
			//One node list
			head = 0;
		}
		else { //A list with more than one node
			tmp->getPrev()->setNext(head);
			head->setPrev(tmp->getPrev());
		}
		delete tmp;
	}
}

template <class T>
void circDLList<T>::sortInsert(T val) {
	if (head == 0) {
		addToHead(val);
	}
	else
	{
		IntDLLNode<T> *tmp, *tmp2 = NULL;
		tmp = head;

		while ((val.getTitle() < tmp->getInfo().getTitle()) && (tmp->getNext() != head))
		{
			tmp2 = tmp;
			tmp = tmp->getNext();
		}

		if ((tmp->getNext() == head) && (val.getTitle() < tmp->getInfo().getTitle()))
		{
			addToTail(val);
		}
		else
		{
			if ((tmp == head) && (val.getTitle() > tmp->getInfo().getTitle()))
				addToHead(val);
			else
			{
				IntDLLNode<T> *newNode = new IntDLLNode<T>(tmp2, val, tmp);
				tmp2->setNext(newNode);
				tmp->setPrev(newNode);
			}
		}
		size++;
	}
}

template <class T>
void circDLList<T>::printList()
{
	IntDLLNode<T> *prtNode = NULL;
	prtNode = head;
	if (prtNode != 0) {
		while (prtNode->getNext() != head) {
			cout << "Title of the book: " << prtNode->getInfo().getTitle() << endl;
			cout << "Editor of the book: " << prtNode->getInfo().getEditor() << endl;
			cout << "Release Year of the book: " << prtNode->getInfo().getReleaseYear() << endl << endl;
			prtNode = prtNode->getNext();
		}
		cout << "Title of the book: " << prtNode->getInfo().getTitle() << endl;
		cout << "Editor of the book: " << prtNode->getInfo().getEditor() << endl;
		cout << "Release Year of the book: " << prtNode->getInfo().getReleaseYear() << endl;
	}
}


template <class T>
void circDLList<T>::printRevList()
{
	IntDLLNode<T> *prtNode = NULL;
	prtNode = head;
	if (prtNode != 0) {
		while (prtNode->getPrev() != head) {
			prtNode = prtNode->getPrev();
			cout << prtNode->getInfo() << " ";
		}
		cout << head->getInfo() << " ";
	}
}


template <class T>
bool circDLList<T>::isEmpty()
{
	bool res;
	res = false;
	if (head == 0)
	{
		res = true;
	}
	return res;
}

template <class T>
void circDLList<T>::insert(int pos, T val)
{
	if (head == 0) {
		addToHead(val);
	}
	else
	{
		IntDLLNode<T> *tmp, *tmp2;
		tmp = head;

		for (int i = 1; i < pos; i++)
		{
			tmp2 = tmp;
			tmp = tmp->getNext();
		}

		if ((tmp->getNext() == head))
		{
			addToTail(val);
		}
		else
		{
			if (tmp == head)
				addToHead(val);
			else
			{
				IntDLLNode<T> *newNode = new IntDLLNode<T>(tmp2, val, tmp);
				tmp2->setNext(newNode);
				tmp->setPrev(newNode);
			}
		}
		size++;
	}
}
template <class T>
IntDLLNode<T>*circDLList<T>::searchNode(T i)
{
	IntDLLNode<T> *tmp;
	tmp = head;
	if (head == 0)
	{
		cout << "The list is empty" << endl;
		return 0;
	}
	else
	{
		while ((tmp != head) && (tmp->getInfo().getTitle() != i.getTitle()))
		{
			tmp = tmp->getNext();
		}
		return tmp;
	}
}