#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
#define SIZE 200008

bool prime[SIZE/2];
int UP[SIZE],DOWN[SIZE];

void do_prime( int n )
{
	memset(prime,1,sizeof(prime));	
	for( int i = 2; i <= SIZE/4+1; i++ )
	{
		if( prime[i] == true )
		{
			for( int j = 2; j*i < SIZE/2; j++ ) 
				prime[i*j] = false;
		}
	}
}

int GCD( int a, int b)
{
	int temp;
	int min_ = min(a,b);
	int max_ = max(a,b);
	while( max_ % min_ != 0 )
	{
		temp = min_;
		min_ = max_%min_;
		max_ = temp;
	}
	return min_;
}

double do_calc(int P,int Q, int R, int S)
{
	int i,j,gcd;
	double result = 1.0;
	int size_up,size_down;
	if( 2*Q > P )
		Q = P-Q;
	if( 2*S > R )
		S = R-S;
	int up_size[3],down_size[3];
	up_size[0] = P;
	up_size[1] = S;
	up_size[2] = R-S;
	down_size[0] = R;
	down_size[1] = Q;
	down_size[2] = P-Q;
	sort(up_size,up_size+3,greater<int>());
	sort(down_size,down_size+3,greater<int>());
	size_up = size_down = 0;
	for( i = 0; i < 3; i++ )
	{
		if( up_size[i] > down_size[i] )
		{
			for( j = up_size[i]; j > down_size[i]; j-- )
				UP[size_up++] = j;
		}
		else
		{
			for( j = down_size[i]; j > up_size[i]; j-- )
				DOWN[size_down++] = j;
		}
	}
	for( i = 0; i < size_up; i++ )
	{
		for( j = 0; UP[i] != 1 && j < size_down; j++ )
		{
			if( prime[UP[i]] == true && prime[DOWN[j]] == true )
					continue;
			else if( prime[UP[i]] == true && prime[DOWN[j]] == false )
			{
				if( DOWN[j] % UP[i] == 0 )	
				{
					DOWN[j] /= UP[i];
					UP[i] = 1;
				}
				else
					continue;
			}
			else if( prime[UP[i]] == false && prime[DOWN[j]] == true )
			{
				if( UP[i] % DOWN[j] == 0 )	
				{
					UP[i] /= DOWN[j];
					DOWN[j] = 1;
				}
				else
					continue;
			}
			else
			{
				if( (gcd = GCD(UP[i],DOWN[j])) != 1 )
				{
					UP[i] /= gcd;
					DOWN[j] /= gcd;
				}
			}
		}
	}
	for( i = 0; i < size_up && i < size_down; i++ )
		result *= UP[i]/(double)DOWN[i];
	if( i == size_up )
	{
		for(;i < size_down; i++ )
			result /= DOWN[i];
	}
	else
	{
		for( ; i < size_up; i++ )
			result *= UP[i];
	}
	return result;
}
int main()
{
	int p,q,r,s;
	do_prime(SIZE/2);
	while( scanf("%d%d%d%d",&p,&q,&r,&s) != -1 )
		printf("%0.5lf\n",do_calc(p,q,r,s));
	return 0;
}
