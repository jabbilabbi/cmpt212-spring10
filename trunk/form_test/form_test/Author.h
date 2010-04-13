/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */

#pragma once

#include "Person.h"
#include <vector>

class Author : public Person
{
public:
	Author(void);
	~Author(void);
	virtual string display();
	void addBook(string book);
	void removeBook(string book);
	void changeBook(string book1, string book2);
	vector<string> getBooks(); 
	virtual bool author();
private:
	vector<string> bookList;
	string listBooks(int index);

};
