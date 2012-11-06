#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std;

bitset<30001>bit_set;
int main()
{
	int n,i;
	bool jolly;
	int first,second,diff;	
	while( scanf("%d",&n) != -1 )
	{
		scanf("%d",&first);
		if( n == 1 )
		{
			printf("Jolly\n");	
			continue;
		}
		bit_set.reset();
		for( i = 1,jolly = true; i < n; i++ )
		{
			scanf("%d",&second);
			if( jolly == false )
				continue;
			diff = abs(second-first);	
			if( diff > n-1 || diff < 1  )	
				jolly = false;
			else
			{
				bit_set[diff] = true;
				first = second;
			}	
		}
		if( jolly == false )
			printf("Not jolly\n");
		else
		{
			for( i = 1; i <= n-1; i++ )
				if( bit_set[i] == false )
					break;
			if( i >= n )
				printf("Jolly\n");
			else
				printf("Not jolly\n");
		}
	}
	return 0;
}
