#include<string>
#include<map>
#include<iostream>

using namespace std;

map<string,bool>dict;

int main()
{
	string word;
	while( cin >> word )
	{
		dict.insert( make_pair( word,false ));
		word.clear();
	}
	for( map<string,bool>::iterator pos = dict.begin(); pos != dict.end();++pos )
	{
		string line = pos->first;
		for( size_t i = 0; i < line.size()-1; i++ )
		{
			string first = string(line,0,i+1);
			string second = string(line,i+1,line.size());
			//cout << "-------------------------" << endl;
			//cout << "line = " << line << endl;
			//cout << "first = " << first << endl;
			//cout << "second = " << second << endl;
			//cout << "-------------------------" << endl;
			if( dict.find( first ) != dict.end() &&
				dict.find( second )!= dict.end() )
				{	
					cout << line << endl;
					break;
				}
		}
	}
	
	return 0;
}

