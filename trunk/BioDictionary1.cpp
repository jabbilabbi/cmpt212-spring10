// BioDictionary1.cpp : Defines the entry point for the console application.
//
#include "Person.h"
#include <iostream>

int main()
{
	Person guy;
	guy.setBiography("The leader of Great Britan during the second World War.");
	guy.setDate(1875);
	guy.setFirstName("Winston");
	guy.setLastName("Churchill");
	guy.setNationality("British");
	guy.setTitle("Prime Minister");
	cout<<guy.display()<<endl;

	Person guy2;
	guy2.setBiography("A guy.");
	guy2.setDate(1992);
	guy2.setFirstName("John");
	guy2.setLastName("Smith");
	guy2.setNationality("American");
	guy2.setTitle("Writer");
	cout<<guy2.display()<<endl;

	cout<< bool(guy2<guy);
	return 0;
}

