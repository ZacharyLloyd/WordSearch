#ifndef FILESOBJ_H
#define FILESOBJ_H

#include <string>
using namespace std;

class Record
{
public:
	Record();
	~Record();
	Record(int, string);
	int getVal();
	void setVal(int);
	string getName();
	void setName(string);
private:
	int rVal;
	string rName;
};

#endif FILESOBJ_H