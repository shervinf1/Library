/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures

author class
*/
#include "author.h"
/*****
	Constructors
*****/
/*****
	Default constructor
*****/

author::author()
{

}

/******
	Special constructor
*******/

author::author(string first, string last)
{
	firstName = first;
	lastName = last;
}

/********
 *
 *
 * Getters for all the variables
 *
 *
 *
*********/

/********
returns the first name of the author
*********/

string author::getFirstName()
{
	return firstName;
}



/********
returns the last name of the author
**********/

string author::getLastName()
{
	return lastName;
}
/********
returns the full name of the author
**********/
string author::getFullName()
{
	return firstName + lastName;
}

/********
 *
 *
Setters for all the variables
*
*
*******/


/********
sets the first name of the author
*******/

void author::setFirstName(string var)
{
	firstName = var;
}

/********
sets the last name of the author
********/
void author::setLastName(string var)
{
	lastName = var;
}