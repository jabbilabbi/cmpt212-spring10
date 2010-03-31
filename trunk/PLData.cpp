#include "PLData.h"

PLData::PLData(void)
{
}

PLData::~PLData(void)
{
}

bool PLData::operator<(const PLData & a) const
{
	if(strcmp(person->getLastName().c_str(), a.person->getLastName().c_str()))
		return true;
	return(false);
	/*
	if(strcmp(lastName.c_str(), a.lastName.c_str()) < 0)
		return true;
	else if(strcmp(lastName.c_str(), a.lastName.c_str()) > 0)
		return false;
	else if(strcmp(firstName.c_str(), a.firstName.c_str()) < 0) //If last names are equal, check first name
		return true;
	else 
		return false;*/
}