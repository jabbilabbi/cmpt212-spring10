/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */

#pragma once
#include "Person.h"
#include "Author.h"
//#include "Parser.cpp"
#include "PLData.h"
#include <iostream>
#include <set>
#include <vector>
#include <fstream>

set<PLData> *parse(set<PLData> *dictionary,  vector<string> *labelList, string fileName);
bool saveFile(set<PLData> *dictionary, vector<string> *labelList, string fileName);
void addPerson(set<PLData> *dict, Person *per, vector<string> lab);

int main()
{

	set<PLData> *masterList = new set<PLData>;
	vector<string> *labels = new vector<string>;
	
	masterList=parse(masterList,labels, "H:\\list.txt");

	set<PLData>::iterator iter;
	
	for(iter = masterList->begin(); iter != masterList->end(); iter++){
		cout<< iter->person->display() <<endl<<endl;

		iter->labels.size();
		iter->person->author();

		//cout<<iter->person->getBooks()[0];
		
	}

	saveFile(masterList,labels, "H:\\newList.txt");

  //How to make a person using individual attributes and put them in the master list.
	Person *guy = new Person;
	guy->setBiography("The former leader of the US.");
	guy->setDate(1875);
	guy->setFirstName("George");
	guy->setLastName("Bush");
	guy->setNationality("Amerikan");
	guy->setTitle("Pres");
	guy->setBiography("biography....");
	vector<string> lab;
	lab.push_back("Leader");
	addPerson(masterList, guy, lab);

	
	//How to make an author, again with individual attributes. Insertion into master list is same as before.
	Author *guy2 = new Author;
	guy2->setBiography("A guy.");
	guy2->setDate(1992);
	guy2->setFirstName("John");
	guy2->setLastName("Smith");
	guy2->setNationality("American");
	guy2->setTitle("Writer");
	guy2->addBook("A Biographical Dictionary");
	guy2->addBook("Another dictionary");
	guy2->addBook("Dictionary");
	guy2->removeBook("Dictionary");
	guy2->addBook("Dictionary1");
	guy2->changeBook("Dictionary1", "Dictionary2");
	//cout<<guy2.display()<<endl;
	addPerson(masterList, guy2, lab);
	


	return 0;
}

