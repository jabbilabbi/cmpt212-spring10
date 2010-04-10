/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */


#include "Person.h"
#include "Author.h"
//#include "Parser.cpp"
#include "PLData.h"
#include <iostream>
#include <set>
#include <vector>

bool openFile(string fileName);
void closeFile();
Person *parsePerson(char* str, Person *person, vector<string> *labels);
set<PLData> *parse(set<PLData> *dictionary);

int main()
{

	set<PLData> masterList;
	
	cout<<openFile("H:\\list.txt")<<endl;
	parse(&masterList);

	Person *grace = new Person;
	vector<string> labels;
	parsePerson("Grace#Slick#1939#American#singer#The lead singer of Jefferson Airplane.#Singer#Band#Label3", grace, &labels);
	cout<<labels[2];

	cout<<grace->display()<<endl<<endl;


	Person guy;
	guy.setBiography("The leader of Great Britan during the second World War.");
	guy.setDate(1875);
	guy.setFirstName("Winston");
	guy.setLastName("Churchill");
	guy.setNationality("British");
	guy.setTitle("Prime Minister");
	vector<string> lab;
	lab.insert(lab.begin(), "ALABEL");
	PLData p;
	p.person = &guy;
	p.labels = lab;
	masterList.insert(p);

	cout<<p.person->display()<<endl<<endl;

	Author guy2;
	guy2.setBiography("A guy.");
	guy2.setDate(1992);
	guy2.setFirstName("John");
	guy2.setLastName("Smith");
	guy2.setNationality("American");
	guy2.setTitle("Writer");
	guy2.addBook("A Biographical Dictionary");
	guy2.addBook("Another dictionary");
	guy2.addBook("Dictionary");
	guy2.removeBook("Dictionary");
	guy2.addBook("Dictionary1");
	guy2.changeBook("Dictionary1", "Dictionary2");
	cout<<guy2.display()<<endl;

	cout<< bool(guy2<guy)<<endl;
	return 0;
}

