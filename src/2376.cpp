#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int test_case;	
	int pole, ants;
	int middle,min,max;
	int temp;
	int result;
	scanf("%d",&test_case);
	for( int i = 0; i < test_case; i++ )
	{
		scanf("%d%d",&pole,&ants);	
		scanf("%d",&temp);
		middle = min = max = temp;
		for( int j = 1; j < ants; j++ )
		{
			scanf("%d",&temp);
			if( temp < min )
				min = temp;
			if( temp > max )
				max = temp;
			if( abs((double)(temp-(pole+1)/2)) < abs( (double)(middle-(pole+1)/2)))
				middle = temp;	
		}
		middle = (middle > (pole+1)/2) ? pole-middle:middle;
		result = (max-min)+((min>pole-max)?min:pole-max);	
		printf("%d %d\n",middle,result);	
	}
	return 0;
}
