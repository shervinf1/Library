/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures
*/
#include "genre.h"

/*****
	Default constructor
*****/

genre::genre() {
}

/******
	Special constructor
*******/
genre::genre(string name)
{
	genreName = name;
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
returns the value string type of private field genreName

*********/
string genre::getGenreName()
{
	return genreName;
}
/********
 *
 *
Setters for all the variables
*
*
*******/


/********
sets the private field genreName to inserted value in paramter
*******/

void genre::setGenreName(string var)
{
	genreName = var;
}


