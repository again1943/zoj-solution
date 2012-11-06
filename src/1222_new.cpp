#include<cstdio>
using namespace std;

int last_digit( int n )
{
	int i;
	int five = 0;
	int last = 1;
	int copy = n;
	static int result_table[5][4] = 
	{
		{1,1,1,1},
		{2,6,8,4},
		{4,2,6,8},
		{6,8,4,2},
		{5,4,2,6},
	};
	static int last_bable[] = 
	{6,6,2,6,4,4,4,8,4,6, 1,1,2,6,4,4,4,8,4,6};
	
	while( ( i = copy/5 ) >= 10 )
	{
		for( int j = i*5+1; i <= copy; i++ )	
			last  = (last*(j%1000))%1000;
		copy = i;
		five += i;
	}
	return result_table[ last_bable[last%10] ][five%4];
}
int main()
{
	int n;
	while( scanf("%d",&n) != -1 )
		printf("%d\n",last_digit(n));
	return 0;
}
