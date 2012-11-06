#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define STICK_CNT 64
int stick[STICK_CNT];
bool square( int  item )
{
	int x = (int)sqrt((double)item);		
	return (item == x*x || item == (x+1)*(x+1) || item == (x-1)*(x-1));
}
int main()
{
	int n,t,k,i,item;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d",&n);
		memset(stick,0,sizeof(stick));
		item = 1;	
		while( 1 )					
		{
			for( i = 0; i < n; i++ )		
			{
				if( stick[i] == 0 || square(stick[i]+item) == true)			
				{
					stick[i] = item++;
					break;
				}
			}
			if( i >= n )
				break;
		}
		printf("%d\n",item-1);	
		
	}
	return 0;
}
