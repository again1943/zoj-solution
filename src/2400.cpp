#include<iostream>
using namespace std;
int power[9] = {11,23,29,37,41,43,47,53,59};
char fact[9][80] = 
		{
			{"23 * 89 = 2047 = ( 2 ^ 11 ) - 1"},
			{"47 * 178481 = 8388607 = ( 2 ^ 23 ) - 1"},
			{"233 * 1103 * 2089 = 536870911 = ( 2 ^ 29 ) - 1"},
			{"223 * 616318177 = 137438953471 = ( 2 ^ 37 ) - 1"},
			{"13367 * 164511353 = 2199023255551 = ( 2 ^ 41 ) - 1"},
			{"431 * 9719 * 2099863 = 8796093022207 = ( 2 ^ 43 ) - 1"},
			{"2351 * 4513 * 13264529 = 140737488355327 = ( 2 ^ 47 ) - 1"},
			{"6361 * 69431 * 20394401 = 9007199254740991 = ( 2 ^ 53 ) - 1"},
			{"179951 * 3203431780337 = 576460752303423487 = ( 2 ^ 59 ) - 1"}
		};
int main()
{
	int i;
	int n;
	cin >> n;

	for( i = 0; i < 9; i++ )
	{
		if( power[i] > n )	
			break;
	}
	if( i >= 9 )
		i = 9;
	for( int j = 0; j <= i-1; j++ )
		cout << fact[j] << endl;
	return 0;
}
