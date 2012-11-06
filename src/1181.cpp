#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	set<string> dict;
	string temp;
	cin >> temp;
	while( temp != "XXXXXX" )
	{
		dict.insert( temp );
		temp.clear();
		cin >> temp;
	}
	temp.clear();
	cin >> temp;
	if( temp != "XXXXXX" )
	{
		bool flag = false;
		stable_sort( temp.begin(),temp.end() );
		if( dict.find( temp ) != dict.end() )
		{
			cout << temp << endl;
			flag = true;
		}
		while( next_permutation( temp.begin(),temp.end() ))
		{
			if( dict.find( temp ) != dict.end() )
			{
				cout << temp << endl;
				flag = true;
			}
		}

		if( flag == false )
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
		temp.clear();
		cin >> temp;
		while( temp != "XXXXXX" )
		{
			flag = false;
			cout << endl;
			stable_sort( temp.begin(),temp.end() );
			if( dict.find( temp ) != dict.end() )
			{
				cout << temp << endl;
				flag = true;
			}
			while( next_permutation( temp.begin(),temp.end() ))
			{
				if( dict.find( temp ) != dict.end() )
				{
					cout << temp << endl;
					flag = true;
				}
			}

			if( flag == false )
				cout << "NOT A VALID WORD" << endl;
			cout << "******" << endl;
			temp.clear();
			cin >> temp;
		}
	}
	return 0;
}
