#include <vector>
#include "Person.h"
#include <string>

#pragma once

class PLData
{
public:
	PLData(void);
	~PLData(void);
	Person *person;
	vector<string> labels;
	bool operator<(const PLData & a) const; //Only partially implemented
	bool operator>(const PLData & b) const;
};
