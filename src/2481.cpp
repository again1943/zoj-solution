/*
 * =====================================================================================
 *
 *       Filename:  acm2481.cpp
 *
 *    Description:  solution to zoj 2481
 *
 *        Version:  1.0
 *        Created:  2007年03月10日 21时02分29秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int new_end;
	int container[101];

	cin >> n;
	while( n != 0 )
	{
		for( int i = 0; i < n; i++  )
			cin >> container[i];
		stable_sort(container,container+n);
		new_end = unique(container,container+n)-container;

		cout << container[0];
		for( int i = 1; i < new_end; i++ )
			cout << " " << container[i];
		cout << endl;
		cin >> n;
	}

	return 0;
}
