/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */

#include "Author.h"

Author::Author(void)
{
}

Author::~Author(void)
{
}

string Author::listBooks(int index)
{
	/* returns a string of all books associated with this author */
	if(bookList.size() <= index)
		return ".";
	else if(index == 0)
		return bookList[index]+listBooks(index+1);
	else
		return ", "+bookList[index]+listBooks(index+1);
		
	return "";
}

string Author::display()
{
	/* Returns a string displaying information about the author,
	   and the authors book list */
	if(bookList.size() > 0) //Only print books if there are some to print.
		return Person::display() + " Books: " + listBooks(0);
	else
		return Person::display();
}

void Author::addBook(string book){
	/* book is added to the bookList */
	bookList.push_back(book);
}
	
void Author::removeBook(string book){
	/* If book exists, it is removed */
	int location = 0;
	while(location < bookList.size()){
		if(bookList.at(location) == book)
			bookList.erase(bookList.begin()+location);
		location++;
	}
}
	
void Author::changeBook(string book1, string book2){
	/* If book1 exists, it is replaced by book2 */
	int location = 0;
	while(location < bookList.size()){
		if(bookList.at(location) == book1){
			bookList.erase(bookList.begin()+location);
			bookList.insert(bookList.begin()+location, book2); 
		}
		location++;
	}
}

vector<string> Author::getBooks(){
	return bookList;
}

bool Author::author(){
	if(Author::bookList.size() > 0)
		return true;
	else
		return false;
}