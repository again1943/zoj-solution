#include<iostream>
#include<string>
#include<utility>
#include<map>

using namespace std;
int main()
{
	map<string,unsigned int> hay_point;
	unsigned int point;
	unsigned int text;
	unsigned int value = 0;
	cin >> point >> text;
	pair<string,unsigned int> temp;
	string word;
	for( unsigned int i = 0; i < point;i++)
	{	
		cin >> temp.first >> temp.second;
		hay_point.insert( temp );

	}
	for( unsigned int i = 0; i < text; i++)
	{
		word.clear();
		value = 0;
		cin >> word;
		while( word != ".")
		{
			map<string,unsigned int>::iterator pos = hay_point.find(word);
			if ( pos != hay_point.end())
				value += pos->second;
			word.clear();
			cin >> word;
		}
		cout << value << endl;
	}
	return 0;
}


