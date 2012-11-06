#include<set>
#include<iostream>
#include<string>
using namespace std;

bool get_word( const string& line, string& word,int start, int len )
{
	word.clear();
	if( start+len+1 < line.size() )	
	{
		word.push_back(line[start]);
		word.push_back(line[start+len+1]);
		return true;
	}		
	return false;
}

bool detect( const string& line, int len )
{	
	int i;
	string word;
	set<string> S;	
	for( i = 0; get_word(line,word,i,len ) == true; i++ )			
	{
		if( S.find(word) != S.end())		
			return false;
		S.insert(word);
	}	
	return true;
}
bool surprising( const string& line )
{
	int i;
	int size = line.size();
	for( i = 0; i <= size-2; i++ )
		if( detect(line,i) == false )	
			return false;
	return true;
}
int main()
{
	string line;		
	while( getline(cin,line) && line != "*" )
		cout << line << " is" << (surprising(line)?" ":" NOT ") << "surprising." << std::endl;
	return 0;
}
