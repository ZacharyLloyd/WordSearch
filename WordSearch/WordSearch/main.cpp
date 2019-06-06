#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "record.h"

using namespace std;

void main() 
{
	vector<Record *> recordList;
	Record * recordPtr;
	string inputString;
	int inputInt;

	do {
		cout << "ENter an interger and a string (enter 99 or q/Q to quit): ";
		cin >> inputInt;
		cin >> inputString;
		if (inputInt == 99 || inputString == "q" || inputString == "Q") break;
		recordPtr = new Record(inputInt, inputString);
		recordList.push_back(recordPtr);
	} while (true);
	// Display input records
	cout << "\nTotal number of records entered = " << recordList.size() << endl;
	for (unsigned int i = 0; i < recordList.size(); i++)
	{
		cout << "Record.val = " << recordList[i]->getVal();
		cout << "  Record.name = " << recordList[i]->getName() << endl;
	}
	system("pause");

	//Save records into file
	cout << "\nSaving records to file....\n";
	ofstream outFile("outputfile.txt");
	outFile << recordList.size() << endl;
	for (unsigned int i = 0; i < recordList.size(); i++)
	{
		outFile << recordList[i]->getVal() << " ";
		outFile << recordList[i]->getName() << endl;
	}
	outFile.close();
	system("pause");

	//Read records from file
	cout << "\nReading records from file...\n";
	recordList.clear();
	int numberRecords;
	ifstream inFile("outputfile.txt");

	if (inFile.is_open())
	{
		inFile >> numberRecords;
		for (int i = 0; i < numberRecords; i++)
		{
			recordPtr = new Record();
			inFile >> inputString;
			inputInt = stoi(inputString, nullptr, 10);
			recordPtr->setVal(inputInt);
			inFile >> inputString;
			recordPtr->setName(inputString);
			recordList.push_back(recordPtr);
		}
		//Displaying the input records
		cout << "\nTotal number of records from file = " << recordList.size() << endl;
		for (unsigned int i = 0; i < recordList.size(); i++)
		{
			cout << "Record.val = " << recordList[i]->getVal();
			cout << "  Record.name = " << recordList[i]->getName() << endl;
		}
		inFile.close();
	}
	else
	{
		cout << "\nCannot open \"outputfile.txt\"." << endl;
	}
	system("pause");
}