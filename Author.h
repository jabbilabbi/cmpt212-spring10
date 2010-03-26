#pragma once

#include "Person.h"
#include <vector>

class Author : public Person
{
public:
	Author(void);
	~Author(void);
	
private:
	vector<string> book;
	string bookList(int index);

};
