#pragma once

#include <string>

using namespace std;

class Person
{
public:
	Person(void);
	virtual ~Person(void);
	void setFirstName(string newName);
	string getFirstName();
	void setLastName(string newName);
	string getLastName();
	void setDate(int newDate);
	int getDate();
	void setNationality(string newNationality);
	string getNationality();
	void setTitle(string newTitle);
	string getTitle();
	void setBiography(string newBiography);
	string getBiography();
	virtual string display();
	bool operator<(const Person & a) const; 
	bool operator>(const Person & a) const;
private:
	string firstName;
	string lastName;
	int date;
	string nationality;
	string title;
	string biography;
};
/*
  TO DO
    * Overloaded comparison operators based on {last name, first name} where for example Adam Smith would be less than Patti Smith but greater than Winston Churchill.
    * Constructors and destructors as required*/