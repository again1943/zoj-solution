#include<iostream>
#include<vector>
using namespace std;
void get_fact( int n, vector<int>& fact )
{
	int i = 2;
	while( i <= n )
	{
		if( n%i == 0 )
		{
			fact.push_back(i);
			while( n%i == 0 )
				n /= i;
		}
		else
			i++;
	}
}
int main()
{
	int n;
	int result;
	vector<int> fact;
	cin >> n;
	while( n != 0 )
	{
		result = n;
		fact.clear();
		get_fact(n,fact);
		for( size_t i = 0; i < fact.size(); i++ )
			result = (result/fact[i])*(fact[i]-1); 
		cout << result << endl;
		cin >> n;
	}
	return 0;
}
