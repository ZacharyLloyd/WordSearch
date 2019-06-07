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
	string paragraph;
	string tenWords;
	
	vector <string> Words;
	vector <string> str;

	int counts[10];

	ifstream tenWordsFile;
	ifstream paragraphFile;

	tenWordsFile.open("tenwords.txt");

	paragraphFile.open("paragraphs.txt");

	ofstream outFile("outputfile.txt");

	for (int i = 0; i < sizeof(counts) / sizeof(int); i++) 
	{
		counts[i] = 0;
	}

	while (tenWordsFile >> tenWords)
	{
		Words.push_back(tenWords);
	}

	tenWordsFile.close();

	while (paragraphFile >> paragraph)
	{
		str.push_back(paragraph);
	}

	paragraphFile.close();

	for (int j = 0; j < Words.size(); j++)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if(str[i] == Words[j])
			(counts[j])++;
		}
	}

	for (int i = 0; i < Words.size(); i++)
	{
		cout << Words[i] << " : " << counts[i] << endl;
		outFile << Words[i] << " : " << counts[i] << endl;
	}

	outFile.close();
	system("pause");
	return 0;
}