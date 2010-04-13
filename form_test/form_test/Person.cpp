/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */

#include "Person.h"

Person::Person(void)
{
}

Person::~Person(void)
{
}

void Person::setFirstName(string newName)
{
	firstName = newName;
}

string Person::getFirstName()
{
	return(firstName);
}

void Person::setLastName(string newName)
{
	lastName = newName;
}

string Person::getLastName()
{
	return(lastName);
}

void Person::setDate(int newDate)
{
	date = newDate;
}

int Person::getDate()
{
	return(date);
}

void Person::setNationality(string newNationality)
{
	nationality = newNationality;
}

string Person::getNationality()
{
	return(nationality);
}

void Person::setTitle(string newTitle)
{
	title = newTitle;
}

string Person::getTitle()
{
	return(title);
}

void Person::setBiography(string newBiography)
{
	biography = newBiography;
}

string Person::getBiography()
{
	return(biography);
}

string Person::display()
{
	/*Returns a string formatted in a easy to read format, ie:
	  "Winston Churchill (1874). British Prime Minister. Leader of Great Britan during....." */

	char* year = new char(4*sizeof(char));
	itoa(date, year, 10); //Convert the date (int type) to string.

	return (firstName+" "+lastName+" ("+year+"). "+nationality+" "+title+". "+biography+".");
}

bool Person::operator<(const Person & a) const
{
	
	if(strcmp(lastName.c_str(), a.lastName.c_str()) < 0)
		return true;
	else if(strcmp(lastName.c_str(), a.lastName.c_str()) > 0)
		return false;
	else if(strcmp(firstName.c_str(), a.firstName.c_str()) < 0) //If last names are equal, check first name
		return true;
	else 
		return false;
}

bool Person::operator>(const Person & a) const
{
	if(strcmp(lastName.c_str(), a.lastName.c_str()) > 0)
		return true;
	else if(strcmp(lastName.c_str(), a.lastName.c_str()) < 0)
		return false;
	else if(strcmp(firstName.c_str(), a.firstName.c_str()) > 0) //If last names are equal, check first name
		return true;
	else 
		return false;
}

bool Person::author(){
	return false;
}