#include "Author.h"

Author::Author(void)
{
}

Author::~Author(void)
{
}

string bookList(int index)
{
	/*if(book.size() <= index)
		return ".";
	else            NEED TO FIX THIS
		return book[index]+", "+bookList(index+1);
		*/
	return "";
}

string display()
{
	return /*Person::display() +*/ " " + bookList(0);
}

