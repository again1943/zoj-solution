#include<map>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

void parse_word( string& line,map<string,int>&M )
{
	string word;
	map<string,int>::iterator item;
	for( size_t i = 0; i < line.size(); i++ )
	{
		if( line[i] >= 'a' && line[i] <= 'z')
			word.push_back(line[i]);
		else if(line[i] >= 'A' && line[i] <= 'Z' )
			word.push_back(line[i]-'A'+'a');
		else
		{
			if( word.size() != 0 )
			{
				if( (item = M.find(word)) == M.end())
					M.insert(make_pair(word,1));
				else
					item->second += 1;
				word.clear();
			}
		}	
	}
	if( word.size() != 0 )
	{
		if( (item = M.find(word)) == M.end())
				M.insert(make_pair(word,1));
		else
			item->second += 1;
	}
}
int main()
{
	int n;
	int t = 0;
	bool none;
	string line;
	map<string,int>M;	
	map<string,int>::iterator item;
	while( cin >> n )
	{
		if( t++ )
			cout << endl;
		none = true;
		while( getline(cin,line) && line != "EndOfText" )	
			if( line != "" )
				parse_word(line,M);
		for( item = M.begin(); item != M.end(); ++item )
		{
			if( item->second == n )		
			{
				cout << item->first << endl;
				none = false;
			}
		}
		if( none == true )
			cout << "There is no such word." << endl;
		M.clear();
	}
	return 0;
			
}
