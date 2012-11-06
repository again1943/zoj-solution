#include<cstdio>

#define MAX 32769
//#define DEBUG

#ifdef DEBUG
#include<iostream>
#endif

using namespace std;
void count_prime( bool* prime, int N )
{
	int i,j;
	for( i = 2; i < N; i++ )
		prime[i] = true;
	for( i = 2; i < N; i++ )
	{
		if( prime[i] == true )
		{
			for( j = 2*i; j < N; j += i )
				prime[j] = false;
		}
	}
}

int result( const bool* prime, int N )
{
	int i;
	int count = 0;
	for( i = 2; i < N/2+1; i++ )
	{
		if( prime[i] == true && prime[N-i] == true )
			count++;
	}
	return count;
}
int main()
{
	int num;
	bool prime[MAX];
#ifdef DEBUG	
	for( int i = 0; i < (int)prime.size() ; i++ )
		cout << prime[i] << endl;		
#endif	
	count_prime( prime ,MAX );
#ifdef DEBUG
	for( int i = 0; i < (int)prime.size();i++ )
		cout << prime[i] << endl;
#endif
	scanf("%d",&num);
	while( num != 0 )
	{
		printf("%d\n",result( prime,num ));
		scanf("%d",&num);
	}

	return 0;
}
