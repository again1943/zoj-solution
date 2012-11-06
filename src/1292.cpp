/***************************************************************************
 *            1292.cpp
 *
 *  Sat May  5 03:04:32 2007
 *  Copyright  2007  User:Fatrat
 *  Email:again1943@163.com
 ****************************************************************************/
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

void add_large_number(const string& first,
				/*const string& second,*/ string& target)
{
	int temp;
	int carry = 0;
	size_t len = first.size() > target.size()?first.size():target.size();
	for( size_t i = 0;i <len; i++ )
	{
		temp = 0;
		if( i < first.size() )
			temp += first[i]-'0';
		if( i < target.size() )
			temp += target[i]-'0';
		temp += carry;
		carry = temp/10;
		temp %= 10;
		target[i] = temp+'0';
	}
	if( carry != 0 )
		target.push_back(carry+'0');
}
int main()
{
	int test_case;
	string temp,target;
	cin >> test_case;
	int t = 0;
	while( test_case-- )
	{
		if( t++ )
			cout << endl;
		getchar();
		cin >> target;
		reverse(target.begin(),target.end());
		if( target != "0" )
		{
			while( cin >> temp && temp != "0" )
			{
				reverse(temp.begin(),temp.end());
				add_large_number(temp,target);				
			}
		}
		reverse(target.begin(),target.end());
		cout << target << endl;
	}
	return 0;	
}
