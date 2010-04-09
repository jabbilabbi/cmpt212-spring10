/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */

#include <fstream>
#include <string>
#include "Person.h"
#include "PLData.h"
#include <iostream>
#include <set>

using namespace std;



fstream file;

bool openFile(string fileName){
	file.open(fileName.c_str(), fstream::out);
	if(file.is_open()) //Check file is open, if not return failure.
		return(true);
	else
		return(false);
}

void closeFile(){
	if(file.is_open()) //Only close file if it is open.
		file.close();
}

char* copySub(char* input, int start, int end){
	char* temp = (char*)malloc(100*sizeof(char));
	int tempNum = start;
	for(start; start< end; start++)
		temp[start-tempNum] = input[start];
	temp[end-tempNum] = NULL; //Ensure string is terminated.
	return temp;
}

int findNext(char* str, int from){
	int position;
	for(position = from+1; position < 255 && str[position] != '#' && str[position] != '\0' && str[position] != '/'; position++)
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
	
	for(;pos < 255;){ //If not less then 255 the line has ended.
		temp = copySub(str, pos, findNext(str,pos));
		labels->push_back(temp);
		pos = findNext(str,pos)+1;	
	}

	return person;
}


set<PLData> *parse(set<PLData> dictionary){
	if(!file.is_open()) //If file not opened, terminate, return null.
		return NULL;
	
	char* line = (char*)malloc(sizeof(char)*256);

	Person *newPerson = new Person;
	vector<string> labels;
	bool isLabel = true;

	while(!file.eof()){ //While file not empty.
		
		file.getline(line, 256);

		bool isPerson = false;
		for(int i = 0; i < 255 && line[i] != '\n'; i++){
			if(line[i] == '#') //If this character is found, the line must be a person, otherwise its a book
				isPerson = true;
		}

		if(!isPerson){
			//Since this line is not a person it must be books associated with an author.

		}else{
			//This line is a person.
			PLData newPLData;
			newPLData.person = newPerson;
			newPLData.labels = labels;
			dictionary.insert(newPLData); //Put last person in the data struct as they are finished.
			newPerson = new Person; //make new person to get populated
			labels.clear(); //reset labels
			parsePerson(line, newPerson, &labels); //Parse the new person but dont put in struct yet as there may be more info.
		}
/*
		if(isLabel){ //Appends the label to the label vector if a label is found.
			string temp;
			temp.assign(line);
			labels.push_back(temp);
		}
		else
		{
			bool isPerson = false;
			
			
		}
*/
	}
}