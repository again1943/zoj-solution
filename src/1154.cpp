/*
 * =====================================================================================
 *
 *       Filename:  1154.cpp
 *
 *    Description:  solution to zoj 1154
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 09时33分30秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<iostream>
#include<string>
using namespace std;

bool get_result(const string& target,int base)
{
	int digit = 0;
	long long sum = 0;
	for( size_t i = 0; i < target.size(); i++ )
		digit += target[i]-'0';	
	for( size_t i = 0; i < target.size(); i++ )
		sum = ((target[i]-'0')+sum*base)%digit;
	return sum%digit == 0;
}
int main()
{
	int n,base;
	int t = 0;
	string target;
	cin >> n;
	while( n-- )
	{
		if( t++ )
			cout << endl;
		while(cin >> base && base != 0 )	
		{
			cin >> target;
			printf("%s\n",(get_result(target,base) == true)?"yes":"no");
		}
	}
	return 0;

}

