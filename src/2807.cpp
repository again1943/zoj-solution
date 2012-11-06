/*
 * =====================================================================================
 *
 *       Filename:  2807.cpp
 *
 *    Description:  solution to zoj 2807
 *
 *        Version:  1.0
 *        Created:  2007年04月29日 07时23分22秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<iostream>
using namespace std;

int main()
{
	int n;
	int strip,count;
	int result;
	cin >> n;
	for( int i = 0; i < n; i++ )
	{
		cin >> count;
		result = 0;
		for( int j = 0;j < count;j++ )
		{
			cin >> strip;
			result += strip;
		}
		cout << result-count+1 << endl;
	}
	return 0;
}

