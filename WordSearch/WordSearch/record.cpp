#include <iostream>
#include "record.h"



Record::Record()
{
}
Record::~Record()
{
}
Record::Record(int inputInt, string inputString)
{
	rName = inputString;
	rVal = inputInt;
}
int Record::getVal()
{
	return rVal;
}
void Record::setVal(int inVal)
{
	rVal = inVal;
}
string Record::getName()
{
	return rName;
}
void Record::setName(string inName)
{
	rName = inName;
}