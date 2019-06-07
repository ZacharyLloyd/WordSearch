#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*I was told by my step dad that this is the proper way to
use namespace and everything included in it. This is how he
does it in the industry to ensure other people know what you used.*/
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

int main() 
{
	//Used for the paragraph and ten words
	string paragraph;
	string tenWords;

	//My words and the strings
	vector <string> Words;
	vector <string> str;

	//The number of words count limit
	int counts[10];

	//Used to access the files throughout the program
	ifstream tenWordsFile;
	ifstream paragraphFile;

	//Opening the tenwords file
	tenWordsFile.open("tenwords.txt");

	//Opening the paragraphs file
	paragraphFile.open("paragraphs.txt");

	//Output file where the words will actually be counted
	ofstream outFile("outputfile.txt");

	//Setting the word count to zero
	for (int i = 0; i < sizeof(counts) / sizeof(int); i++) 
	{
		counts[i] = 0;
	}

	//Where the program reads each word into a vector to be stored
	while (tenWordsFile >> tenWords)
	{
		Words.push_back(tenWords);
	}

	//Close the tenwords file
	tenWordsFile.close();

	//Reading in the paragraph file into a vector
	while (paragraphFile >> paragraph)
	{
		str.push_back(paragraph);
	}

	//Closing the paragraph file
	paragraphFile.close();

	/*This is where the 10 qoesa in the file will run through the words
	in the paragraphs amd compare them if the algorithm finds a word with
	the same word case it will add a word count to that word*/
	for (int j = 0; j < Words.size(); j++)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if(str[i] == Words[j])
			(counts[j])++;
		}
	}
	
	//This is for the word count for each word to be recorded in the output file
	for (int i = 0; i < Words.size(); i++)
	{
		cout << Words[i] << " : " << counts[i] << endl;
		outFile << Words[i] << " : " << counts[i] << endl;
	}
	//Close the output file
	outFile.close();
	system("pause");
	return 0;
}