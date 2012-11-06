#include<cstdio>
using namespace std;

int boxes[13];

inline void set()
{
	for( int i = 0; i < 13; i++ )
		boxes[i] = 0;	
}
long long int fact(int i )
{
	long long int result = 1;
	while( i > 0 )
		result *= i--;
	return result;
}
long long int compute(int n)
{
	long long int result = fact(n);
	long long int x;
	for( int i = 1; i <=12; i++ )
	{
		if( boxes[i] > 0 )	
		{
			x = fact(i);
			for( int j = 0; j < boxes[i]; j++ ) 
				result /= fact(i);
			result /= fact(boxes[i]);
		}
	}
	return result;

}
int main()
{
	int n;
	int x;
	int sum;
	while( scanf("%d",&n)!= -1 )
	{
		set();
		sum = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf("%d",&x );
			sum += x;
			boxes[x]++;
		}
		printf("%lld\n",compute(sum));
	}
}
