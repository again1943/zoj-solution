#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

inline bool is_tag( char c )
{
	return c == '<' || c == '>';
}
inline bool is_space( char c )
{
	return (c == '\t' || c == '\n' || 
		c == '\r' || c == ' ');
}
void do_current( const string& current, string& total)
{
	size_t i = 0;
	string word;
	while( i < current.size() )
	{
		if( is_tag(current[i]) == true )
		{
			if( (word = current.substr(i+1,2 )) == "br" )
			{
				cout << total << endl;
				total.clear();	
			}
			else
			{
				if( total.size() != 0 )
				{
					cout << total << endl;
					total.clear();	
				}
				cout << "------------------------------"
					"------------------------------"
					"--------------------" << endl;
			}
			i += 4;
			word.clear();
		}
		else if( is_space(current[i]) == true )
		{
			if( word.size() != 0 )
			{
				if( word.size()+total.size()+1< 80 )		
				{
					if( total.size() != 0 )
						total.push_back(' ');
					total += word;
				}
				else
				{
					cout << total << endl;
					total = word;
				}
				word.clear();
			}

			i++;
		}
		else
			word.push_back(current[i++]);	
	}
}

string current;
string total;

int main()
{
	while( getline(cin,current) )
	{
		current.push_back('\n');
		do_current(current,total);			
	}
	if( total.size() != 0 )
		cout << total << endl;
	return 0;
}

