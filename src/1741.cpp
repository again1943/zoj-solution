#include<map>
#include<iostream>
#include<string>
#include<utility>
#include<cstring>
using namespace std;
#define CAPTAL_LETTER 0
#define SMALL_LETTER 1
#define NUMBER 2
#define LEFT_BRAKET 3
#define RIGHT_BRAKET 4
#define OTHER_LETTER 5

map<string,int>M;
int letter( char c )
{
	if( c >= 'A' && c <= 'Z' )
		return CAPTAL_LETTER;
	if( c >= 'a' && c <= 'z' )
		return SMALL_LETTER;	
	if( c >= '0' && c <= '9' )
		return NUMBER;
	if( c == '(' )
		return LEFT_BRAKET;
	if( c == ')' )
		return RIGHT_BRAKET;
	return OTHER_LETTER;
}
string eat_elem(const string& name, int& pos )
{
	string ret;
	ret.push_back(name[pos++]);	
	if( letter(name[pos]) == SMALL_LETTER )
		ret.push_back(name[pos++]);
	return ret;
}
int eat_num( const string& name, int& pos )
{
	int ret = 0;
	if( letter(name[pos]) != NUMBER )
		return 1;
	else
	{
		ret = name[pos++]-'0';
		if( letter( name[pos] ) == NUMBER )
			ret = ret*10+name[pos++]-'0';
	}
	return ret;
}
int parse(const map<string,int>& M, const string& name, int& pos )
{
	string elem;
	int left = 0;
	int current = 0;
	int atom_number;
	int size = name.size();
	map<string,int>::const_iterator iter;
	while( pos < size )
	{
		switch( letter(name[pos]) )	
		{
			case CAPTAL_LETTER:
				elem = eat_elem(name,pos);
				atom_number = eat_num(name,pos);	
				if((iter = M.find(elem)) == M.end())
					return -1;
				left += iter->second*atom_number;
				break;
			case LEFT_BRAKET:
				pos += 1;
				if( (current = parse(M,name,pos)) < 0 )			
					return -1;
				atom_number = eat_num(name,pos);	
				left += current*atom_number;
				break;
			case RIGHT_BRAKET:
				pos += 1;		
				return left;
			default:	
				pos += 1;			
				break;
		}
	}
	return  left;
}
inline int do_work( const map<string,int>& M, const string& name )
{
	int pos = 0;
	return parse(M,name,pos);
}
int main()
{
	int weight,ret;
	string name;		
	while( cin >> name && name != "END_OF_FIRST_PART" ) 	
	{
		cin >> weight;		
		M.insert(make_pair(name,weight));
	}
	while( cin >> name && name != "0" )
	{
		if( (ret = do_work(M,name)) < 0)
			cout << "UNKNOWN" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}
