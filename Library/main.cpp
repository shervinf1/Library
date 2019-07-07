/*
Shervin Firouzdehghan
S01172145
Data Structures and Algorithms
COMP 315
Final Project
Library Database using data stuctures
*/


#include "BSTree.h"
#include "genre.h"
#include <iostream>
#include <string>
using namespace std;

/*
Below I am creating three new pointers one of each data structure with its specific type
*/
BSTree<genre> *BST = new BSTree<genre>();
circDLList<book> *CDLL = new circDLList<book>();
IntSLList<author> *SLL = new IntSLList<author>();
void validateMenu(char&);
void visitInOrderCDLL(BSTNode<genre>*);
char menu();
void case1();
void case2();
//void case3();
void case5();
void case6();
void case7();
void searchForBook(BSTNode<genre> *, string);
void searchForBookCDLL(IntDLLNode<book> *, string);
void searchForBookToModify(BSTNode<genre> *, string);



//This is the main method and it carries the switch statement that will decide what the program will do depending on what the user has selected
int main(int argc, char* argv[])
{
	char choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case '1':
			case1();
			break;
		case '2':
			case2();
			break;
		case '3':
			cout << "Modify a book" << endl;
			//case3();
			break;
		case '4':
			cout << "Listing all Genres" << endl;
			BST->printInOrder();
			cout << endl;
			break;
		case '5':
			case5();
			break;
		case '6':
			case6();
			break;
		case '7':
			case7();
			break;
		}
	} while (choice != '8');
	cout << "Goodbye!" << endl;

	//Deleting temporary pointers
	delete BST;
	delete SLL;
	delete CDLL;
	return 0;

}
/*
this method validate weather the user entered the correct answer or not from the main menu
*/
void validateMenu(char &var)
{
	while (var != '1' && var != '2' && var != '3' && var != '4' && var != '5' && var != '6' && var != '7' && var != '8')
	{
		cout << "The menu item you selected does no exist...\n Please from below: " << endl;
		var = menu();
	}
}
/*
This method menu displays the menu and accepts a char variable as a answer and proceeds to validate wether it is in the accepted
range or not.

*/
char menu()
{
	char op;

	cout << "***********************************" << endl;
	cout << "Select one of the following options" << endl;
	cout << "***********************************" << endl;
	cout << "   1. Add a genre" << endl;
	cout << "   2. Add a book" << endl;
	cout << "   3. Modify a book" << endl;
	cout << "   4. List all genre" << endl;
	cout << "   5. List all books by genre" << endl;
	cout << "   6. List all books for a selected genre" << endl;
	cout << "   7. Search for a book" << endl;
	cout << "   8. Exit" << endl;
	cout << "***********************************" << endl;
	cin >> op;
	validateMenu(op);
	system("CLS");
	return op;
}

/*
This method case1 is for the first option in the menu.
it asks the user for a genre input and the programs reads it and inserts it into
the binary seatch tree as an object of the class genre
*/
void case1()
{
	string genInput;
	genre* newGenre = new genre();
	cout << "Enter the name of the Genre you want to add: " << endl;
	cin >> genInput;
	newGenre->setGenreName(genInput);
	BST->insert(*newGenre);
	delete newGenre;
}
/*
This method case2 is for the second option in the menu.
it asks the user for a genre input from the genres that are inserted already in the BST
and proceeds to ask information about the book and stores that information in a pointer variable called newBook
and then procees to insert that pointer inside the Circular doubly linked list depending on which genre was selected.
*/
void case2()
{
	book* newBook = new book();
	author* newAuthor = new author();
	genre* newGenre = new genre();
	string genreInput, title, plot, editor, releaseYear, firstname, lastname;
	int anum;
	BST->printInOrder();
	cout << endl << "Select from the following genres: " << endl;
	cin >> genreInput;
	newBook->setGenre(genreInput);
	newGenre->setGenreName(genreInput);
	cout << "Enter title of the book: " << endl;
	cin >> title;
	newBook->setTitle(title);
	cout << "Enter editor of the book: " << endl;
	cin >> editor;
	newBook->setEditor(editor);
	cout << "Enter release year of the book: " << endl;
	cin >> releaseYear;
	newBook->setReleaseYear(releaseYear);
	cout << "Enter plot of the book: " << endl;
	cin >> plot;
	newBook->setPlot(plot);
	cout << "How many authors does the book have: " << endl;
	cin >> anum;
	for (int i = 0; i < anum; i++)
	{
		cout << "Enter authors first name: " << endl;
		cin >> firstname;
		newAuthor->setFirstName(firstname);
		cout << "Enter authors last name: " << endl;
		cin >> lastname;
		newAuthor->setLastName(lastname);
	}

	//This selection structure is for validating wethere there is already a cicrular doubly linked list or not for the genre
	//If there is then it will simply add the new book pointer
	//If not then it will create two new pointers, one type CDLL and one SLL and insert the values entered from the book into corresponding lists

	if (!BST->search(*newGenre)->getCDLL())
	{
		circDLList<book>* CDLL = new circDLList<book>();
		IntSLList<author> *SLL = new IntSLList<author>();

		CDLL->sortInsert(*newBook);
		SLL->sortInsert(*newAuthor);
		BST->search(*newGenre)->setCDLL(CDLL);
		CDLL->searchNode(*newBook)->setAuthor(SLL);
	}
	else
	{
		BST->search(*newGenre)->getCDLL()->sortInsert(*newBook);
	}

	delete newBook;
	delete newGenre;
	delete newAuthor;

}
void case5()
{
	visitInOrderCDLL(BST->getRoot());
}

//Method  uses recursion to print out each genre starting from the root of the tree and displays the circular doubly linked list in each genre
void visitInOrderCDLL(BSTNode<genre> *node)
{
	if (node != 0)
	{
		visitInOrderCDLL(node->getLeft());
		cout << node->getInfo().getGenreName() << endl;
		node->getCDLL()->printList();
		cout << endl;
		visitInOrderCDLL(node->getRight());
	}
}


/*
This method option 6 on the menu to display all the books from a valid genre that the user will enter
after the user entered a genre program will search for genre in BST and proceed to print the Circular doubly linked list
*/
void case6()
{
	string genreInput;
	BST->printInOrder();
	cout << "Enter a genre from above to showcase all the books from such genre" << endl;
	cin >> genreInput;
	genre* newGenre = new genre(genreInput);
	newGenre->setGenreName(genreInput);
	BST->search(*newGenre)->getCDLL()->printList();
	cout << endl;
	delete newGenre;
}

/*
This method asks the user for the title of the book they are trying to look for
and with that string title the program does a search using recursion to look through
each and every Circular doubly linked list until it either finds the book title or not.
If it does find the book title it will show all the information including the author or
author's of such book.
*/
void case7()
{
	string titleInput;
	cout << "Please enter title of book you want to search for: " << endl;
	cin >> titleInput;
	searchForBook(BST->getRoot(), titleInput);
}
//This method is a method which uses recursion to go through each BST node and each circular doubly linked list to find the certain book title entered and display it
void searchForBook(BSTNode<genre> *node, string title)
{
	if (node != 0) {
		searchForBookCDLL(node->getCDLL()->getHead(), title);
		searchForBook(node->getLeft(), title);
		searchForBook(node->getRight(), title);
	}
	else
	{
		return;
	}
}
void searchForBookCDLL(IntDLLNode<book> *node, string title)
{
	IntDLLNode<book>* ptrNode;
	ptrNode = node;
	if (node == node->getNext())
	{
		return;
	}
	else
	{
		while (ptrNode->getInfo().getTitle() != title && ptrNode != ptrNode->getNext())
		{
			ptrNode = ptrNode->getNext();
		}
	}

	if (ptrNode->getInfo().getTitle() == title)
	{
		cout << "Title: " << ptrNode->getInfo().getTitle() << endl;
		cout << "Editor: " << ptrNode->getInfo().getEditor() << endl;
		cout << "Release Year: " << ptrNode->getInfo().getReleaseYear() << endl;
		cout << "Plot: " << ptrNode->getInfo().getPlot() << endl;
	}
	else
	{
		return;
		cout << "Book entered does not exist..." << endl;
	}
}
