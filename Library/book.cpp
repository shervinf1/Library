/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures
*/
#include "book.h"
/*****
	Default constructor
*****/

book::book()
{

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
Returns the title of book
*********/

string book::getTitle()
{
	return title;
}

/********
Returns the genreName of book
**********/

string book::getGenre()
{
	return genre;
}

/********
Returns the editor of book
**********/
string book::getEditor()
{
	return editor;
}
/********
returns the plot of the book
**********/

string book::getPlot()
{
	return plot;
}

/********
returns the release year of the book
**********/

string book::getReleaseYear()
{
	return release_year;
}
//IntSLList<author> *book::getAuthorList()
//{
//	return list;
//}

/********
 *
 *
Setters for all the variables
*
*
*******/


/********
sets the title
*******/

void book::setTitle(string var)
{
	title = var;
}

/********
set the editor
********/

void book::setEditor(string var)
{
	editor = var;
}


/********
set the genre name
********/

void book::setGenre(string var)
{
	genre = var;
}
/********
set the release year
********/

void book::setReleaseYear(string var)
{
	release_year = var;
}
/********
set the plot
********/

void book::setPlot(string var)
{
	plot = var;
}
//void book::setAuthorList(IntSLList<author> *l)
//{
//	list = l;
//}