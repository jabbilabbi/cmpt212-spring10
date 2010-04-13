/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */
#pragma once;
#include <fstream>
#include <string>
#include "Person.h"
#include "Author.h"
#include "PLData.h"
#include <iostream>
#include <set>

using namespace std;

#define WRITE true
#define READ false
#define MAX_LINE_LENGTH 5000

/* The parser is responsible for opening a file, reading its contents into a PLData set
	It is also responsible for writing a PLData set into a file						*/

bool openFile(string fileName, fstream *file, bool write){
	if(write)
		file->open(fileName.c_str(),fstream::out);
	else
		file->open(fileName.c_str(), fstream::in);
	if(file->is_open()) //Check file is open, if not return failure.
		return(true);
	else
		return(false);
}

void closeFile(fstream *file){
	if(file->is_open()) //Only close file if it is open.
		file->close();
}

char* copySub(char* input, int start, int end){
	char* temp = (char*)malloc(MAX_LINE_LENGTH*sizeof(char));
	int tempNum = start;
	for(start; start < end; start++)
		temp[start-tempNum] = input[start];
	temp[end-tempNum] = NULL; //Ensure string is terminated.
	return temp;
}

int findNext(char* str, int from){
	int position;
	if(str[from] == '\0')
		return(MAX_LINE_LENGTH);
	for(position = from+1; position < MAX_LINE_LENGTH-1 && str[position] != '#' && str[position] != '\0' && str[position] != '/'; position++)
		;
	return position;
}

Person *parsePerson(char *str, Person *person, vector<string> *labels){
	//Breaks up str on # symbols and loads the data into a person object
	//Also adds the labels of this author to the labels passed in
	int pos = 0;
	char* temp = (char*)malloc(sizeof(char)*100);
	string result;
	
	temp = copySub(str, pos, findNext(str,pos));
	pos = findNext(str,pos)+1;
	result.assign(temp);
	person->setFirstName(result);

	temp = copySub(str, pos, findNext(str,pos));
	pos = findNext(str,pos)+1;
	result.assign(temp);
	person->setLastName(result);

	temp = copySub(str, pos, findNext(str,pos));
	pos = findNext(str,pos)+1;
	person->setDate(atoi(temp));

	temp = copySub(str, pos, findNext(str,pos));
	pos = findNext(str,pos)+1;
	result.assign(temp);
	person->setNationality(result);

	temp = copySub(str, pos, findNext(str,pos));
	pos = findNext(str,pos)+1;
	result.assign(temp);
	person->setTitle(result);

	temp = copySub(str, pos, findNext(str,pos));
	pos = findNext(str,pos)+1;
	result.assign(temp);
	person->setBiography(result);
	
	for(;pos < MAX_LINE_LENGTH-1 && str[pos-1] != '\0';){ //If not less then 255 the line has ended.
		temp = copySub(str, pos, findNext(str,pos));
		labels->push_back(temp);
		pos = findNext(str,pos)+1;	
		if(str[pos-1] == '\0')
			break;
	}

	return person;
}

void addPerson(set<PLData> *dict, Person *per, vector<string> lab){
	//Puts a person and a label into the biographical dictionary.
	PLData newPLData;
	newPLData.person = per;
	newPLData.labels = lab;
	dict->insert(newPLData);
}

void sortLabels(vector<string> *labels){
	//Sorts a vector of labels which are strings using insertion sort.
	for(int i = 0; i < labels->size(); i++){
		for(int j = i; j < labels->size(); j++){
			if(labels->at(i) > labels->at(j)){
				string tmp;
				tmp = labels->at(i);
				labels->at(i) = labels->at(j);
				labels->at(j) = tmp;
			}
		}
	}
}

set<PLData> *parse(set<PLData> *dictionary, vector<string> *labelList, string fileName){
	fstream file;
	if(!openFile(fileName, &file, READ)) //If file not opened, terminate, return null.
		return NULL;
	
	char* line = (char*)malloc(sizeof(char)*MAX_LINE_LENGTH);

	Author *newPerson = new Author;
	vector<string> labels;
	bool isLabel = true;
	bool firstPerson = true;
	while(!file.eof()){ //While file not empty.
		
		file.getline(line, MAX_LINE_LENGTH);
		
		bool isPerson = false;
		for(int i = 0; i < MAX_LINE_LENGTH-1 && line[i] != '\0'; i++){
			if(line[i] == '#'){ //If this character is found, the line must be a person, otherwise its a book
				isPerson = true;
				isLabel = false; //When a person line is encountered, the initial label list is done
			}
		}
		if(isLabel){
			//Initial label list element
			labelList->push_back(line);
			sortLabels(labelList);
		}else if(!isPerson){
			//Since this line is not a person it must be books associated with an author.
			newPerson->addBook(line);
			if(file.eof()) //If this is the last person in the file can write immediately.
				addPerson(dictionary, newPerson, labels);
		}else{
			//This line is a person.
			isLabel = false; //The initial label list is over as soon as a person is read;
			if(!firstPerson){
				addPerson(dictionary, newPerson, labels);
			}
			firstPerson = false;
			newPerson = new	Author; //make new person to get populated
			labels.resize(0); //reset labels
			
			parsePerson(line, newPerson, &labels); //Parse the new person but dont put in struct yet as there may be more info.
			
			if(file.eof()) //If this is the last person in the file it can write immediately.
			{
				addPerson(dictionary, newPerson, labels);
			}
		}
		
	}
	closeFile(&file);

	return dictionary;
}

bool saveFile(set<PLData> *dictionary, vector<string> *labelList, string fileName){
	/* Returns TRUE (1) if the write was successful, FALSE (0) otherwise */

	fstream file;
	if(!openFile(fileName, &file, WRITE)) //If file cannot be written, return fail.
		return false;
	
	//Write Labels
	sortLabels(labelList);
	for(int i = 0; i < labelList->size(); i++)
		file<<labelList->at(i)<<endl;

	//Write People/Books

	set<PLData>::iterator iter;

	
	for(iter = dictionary->begin(); iter != dictionary->end(); iter++){
		string line;
		line+= iter->person->getFirstName() + "#";
		line+= iter->person->getLastName() + "#";
		line+= iter->person->getDate() + "#";
		line+= iter->person->getNationality() + "#";
		line+= iter->person->getTitle() + "#";
		line+= iter->person->getBiography();
		for(int i = 0; i < iter->labels.size(); i++)
			line += "#" + iter->labels[i];
		file<<line<<endl;
		if(iter->person->author()){
			Author *newAuth;
			newAuth = (Author*)iter->person;
			for(int i = 0; i < newAuth->getBooks().size(); i++)
				file<<newAuth->getBooks()[i]<<endl;
		}
	}

	closeFile(&file);

	return true; //If this point reached, save was successful.
}