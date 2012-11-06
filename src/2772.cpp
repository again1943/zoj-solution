/*
 * =====================================================================================
 *
 *       Filename:  acm2772.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007年02月28日 01时41分53秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
using namespace std;

int main()
{
	int test_case;
	int money;
	int quarter,dime,nickel,penny;
	cin >> test_case;
	for( int i = 0;i < test_case; i++ )
	{
		cin >> money;
		quarter = money/25;
		money %= 25;
		dime = money/10;
		money %= 10;
		nickel = money/5;
		money %= 5;
		penny = money;
		//1 4 QUARTER(S), 2 DIME(S), 0 NICKEL(S), 4 PENNY(S)
		cout << i+1 << " " 
			<< quarter << " QUARTER(S), "
			<< dime << " DIME(S), "
			<< nickel << " NICKEL(S), "
			<< penny << " PENNY(S)"
			<< endl;
	}
	return 0;
}
