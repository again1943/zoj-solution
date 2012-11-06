#include<string>
#include<iostream>
#include<map>
#include<utility>
using namespace std;
pair<string,string> parse( const string& line )
{
	size_t pos = line.find(" ");
	string second( line,0,pos);
	string first( line,pos+1,line.size() );
	return make_pair( first,second );
}
int main()
{
	map<string,string>dictionary;
	string fm_word;
	string line;
	getline( cin , line );
	while( line != "\n" && line != "" )
	{
		pair<string,string>index = parse( line );
		dictionary.insert( index );
		line.clear();
		getline( cin ,line );
	}

	while( cin >> fm_word )
	{
		map<string,string>::iterator pos = 
			dictionary.find( fm_word );
		if( pos != dictionary.end() )
			cout << pos->second << endl;
		else
			cout << "eh" << endl;
		fm_word.clear();
	}
	return 0;
}
