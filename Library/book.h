/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures


Book Class
*/
#include <string>
#include <iostream>
using namespace std;
/**********************************
Class Declaration

***********************/
class book {
public:
	book();//Default constructor
	string getTitle(); //get title or name of the book
	string getPlot(); //get plot of the book
	string getEditor(); //get editor of the book
	string getReleaseYear(); //get release year of the book
	string getGenre(); //get genre of the book
	//IntSLList<author> *getAuthorList();

	void setTitle(string); //set title 
	void setPlot(string); //Set plot
	void setEditor(string); //Set editor
	void setReleaseYear(string); //set releaseyear 
	void setGenre(string);//Set the genre
	//void setAuthorList(IntSLList<author> *);
private:

	string title;
	string genre;
	string plot;
	string release_year;
	string editor;
	//IntSLList<author> *list = new IntSLList<author>;
};

