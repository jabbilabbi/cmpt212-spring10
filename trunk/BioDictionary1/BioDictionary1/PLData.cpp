/* Biographical Dictionary - CMPT 212 Final Project - SFU Spring 2010
   Alex Antonio alex_antonio@sfu.ca      Jeff Harris jwh4@sfu.ca   */

#include "PLData.h"

PLData::PLData(void)
{
}

PLData::~PLData(void)
{
}

bool PLData::operator < (const PLData & a) const
{
	if(strcmp(person->getLastName().c_str(), a.person->getLastName().c_str()) < 0)
		return true;
	else if(strcmp(person->getLastName().c_str(), a.person->getLastName().c_str()) > 0)
		return false;
	else if(strcmp(person->getFirstName().c_str(), a.person->getFirstName().c_str()) < 0) //If last names are equal, check first name
		return true;
	else 
		return false;
}

bool PLData::operator > (const PLData & b) const
{
	
	if(strcmp(person->getLastName().c_str(), b.person->getLastName().c_str()) > 0)
		return true;
	else if(strcmp(person->getLastName().c_str(), b.person->getLastName().c_str()) < 0)
		return false;
	else if(strcmp(person->getFirstName().c_str(), b.person->getFirstName().c_str()) > 0) //If last names are equal, check first name
		return true;
	else 
		return false;
}