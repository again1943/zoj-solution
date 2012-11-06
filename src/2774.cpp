/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007年02月27日 21时02分32秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<utility>

//#ifndef MAX
//#define MAX 100
//#endif

using namespace std;
void perform( string& first, string& second,string& result )
{
	result.clear();
	for( size_t len = 0; len < first.size(); len++ )
	{
		result.push_back(second[len]);
		result.push_back(first[len]);
	}

	first = result.substr(0,first.size());
	second =result.substr(first.size(),first.size());
}
int main()
{
	pair<string,string> twins,old;
	string target,want;
	int test_case,size,time;
	cin >> test_case;
	for( int i = 0;i < test_case;i++ )
	{
		cin >> size;
		cin >> twins.first >> twins.second;
		cin >> want;
		time = 0;
		old = twins;
		do
		{
			perform( twins.first, twins.second,target );
			time++;
			if( want == target )
			{
				cout << i+1 << " " << time << endl;
				break;
			}
		}while( old != twins );
		if( old == twins )
			cout << i+1 << " -1" << endl;
		twins.first.clear();
		twins.second.clear();
		want.clear();
	}

	return 0;
}
