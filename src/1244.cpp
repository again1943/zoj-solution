#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

map<string,bool>variables;
int main()
{
	int n;
	int program;
	string c;

	string first;
	string second;

	bool flag;
	
	map<string,bool>::iterator pos;

	cin >> n;

	program = 0;
	while( n != 0 )
	{
		program++;

		variables.insert(make_pair("a",true));	
		for( int i = 0; i < n; i++ )
		{
			cin >> first >> c >> second;
			if( ( pos = variables.find(second)) == variables.end())
			{
				variables.insert(make_pair(second,false));
				if( (pos = variables.find(first))==variables.end())
					variables.insert(make_pair(first,false));
				else
					pos->second = false;
			}
			else
			{
				if(pos->second == false )
				{
					if( (pos = variables.find(first))==variables.end())
						variables.insert(make_pair(first,false));
					else
						pos->second = false;
				}
				else
				{
					if( (pos = variables.find(first))==variables.end())
						variables.insert(make_pair(first,true));
					else
						pos->second = true;
	
				}
			}
			first.clear();
			second.clear();
			c.clear();
		}

		flag = false;
		cout << "Program #" << program << endl;
		for( pos = variables.begin(); pos != variables.end();++pos)
		{
			if( pos->second == true )
			{
				cout << pos->first << " ";
				flag = true;
			}
		}
		if( flag == false )
			cout << "none";
		cout << endl;
		cout << endl;
		variables.clear();
		cin >> n;

	}
	return 0;
}

