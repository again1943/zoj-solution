/*
 * =====================================================================================
 *
 *       Filename:  2851.cpp
 *
 *    Description:  solution to zoj 2851
 *
 *        Version:  1.0
 *        Created:  2007年10月18日 14时46分44秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

void do_format( const string& line, int& tabs, int& spaces )
{
	int size = line.size();
	for( int i = 0; i < size ; i ++ )		
		if( line[i] == '\t' )
			tabs++;
	for( int i = size-1; i >= 0; i-- )
	{
		if( line[i] == ' ' )
			spaces++;
		else if( line[i] == '\t' )
			spaces += 4;
		else
			break;
	}
}
int main()
{
	int n;
	string line;
	int tabs;
	int spaces;
	cin >> n;
	for( int i = 0; i < n; i++ )
	{
		tabs = spaces = 0;	
		while( getline(cin,line) && line != "##" )
			do_format(line,tabs,spaces);
		printf("%d tab(s) replaced\n",tabs);
		printf("%d trailing space(s) removed\n",spaces);
	}
	return 0;
}

