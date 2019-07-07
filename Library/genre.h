/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures
*/
//#include "circDLList.h"
#include <string>
#include <iostream>
using namespace std;
/**********************************
Class Declaration

***********************/
class genre {
public:
	genre();//Default constructor
	genre(string); //Special constructor with string as a parameter to set genreName by only constructor

	string getGenreName(); //get name of genre

	void setGenreName(string); //set title 


private:
	string genreName;


};
