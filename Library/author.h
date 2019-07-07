/**********************
Shervin Firouzdehghan
S01172145
Genre class
******************/
//#include "IntSLList.h"
#include <string>
#include <iostream>
using namespace std;
/**********************************
Class Declaration

***********************/
class author {
public:
	author();//Default constructor
	author(string, string); //Special constructor

	string getFirstName(); //get first name of the book
	string getLastName(); //get last name of the book
	string getFullName(); //get full name of the book

	void setFirstName(string); //set first name
	void setLastName(string); //Set last name

private:

	string firstName, lastName;
};



