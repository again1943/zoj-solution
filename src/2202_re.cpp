/*
 * =====================================================================================
 *
 *       Filename:  acm2202.cpp
 *
 *    Description:  sulution to zoj 2202
 *
 *        Version:  1.0
 *        Created:  2007年03月15日 21时03分24秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat form Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */


#include<string>
#include<iostream>
using namespace std;

int decode(string& code, int start, int end )
{
	int count = 0;
	if( start < end )
	{
		if( start + 1 == end && code[start] != '0' )
			count++;
		else if( start + 2 == end )
		{
			if( code[start] != '0'&&code[start] != '0')		
				count ++;
			if( code[start] >= '1' && code[start] <= '2'
				&& code[start+1] >= '0'&& code[start+1] <= '6' )
				count++;
		}
		else
		{
			if( code[start] != '0')		
				count += decode(code,start+1,end);
			if( code[start] >= '1' && code[start] <= '2'
				&& code[start+1] >= '0'&& code[start+1] <= '6' )
				count += decode(code,start+2,end);

		}
	}

	return count;
}
int main()
{
	string code;	
	cin >> code;
	while( code != "0" )
	{
		cout << decode(code,0,static_cast<int>(code.size())) << endl;
		code.clear();
		cin >> code;
	}

	return 0;
}
