#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_SIZE 24
bool prime[64];
bool mask[MAX_SIZE];
int elem[MAX_SIZE];

void init()
{
	int i,j;
	memset(prime,1,sizeof(prime));
	prime[0] = prime[1] = false;
	for( i = 2; i < 64; i++ )
	{
		if( prime[i] == true )
		{
			for( j = 2; j*i < 64; j++ )
				prime[j*i] = false;
		}
	}
}
void dfs(int n, int idx) 
{
	int i,j;
	for( i = 1; i <= n; i++ )
	{
		if( mask[i] == true && prime[elem[idx-1]+i] == true)
		{
			elem[idx++] = i;	
			if( idx == n )
			{
				if( prime[elem[idx-1]+elem[0]] == true )
				{
					printf("%d",elem[0]);
					for( j = 1; j < idx; j++ )
						printf(" %d",elem[j]);
					printf("\n");
				}
			}
			else
			{
				mask[i] = false;
				dfs(n,idx);
				mask[i] = true;
			}
			idx -= 1;
		}
	}
}
int main()
{
	int n;		
	int t = 0;
	init();
	while( scanf("%d",&n) != -1 )
	{
		memset(mask,1,sizeof(mask));
		printf("Case %d:\n",++t);
		if( n % 2 == 0 )
		{
			elem[0] = 1;
			mask[1] = false;
			dfs(n,1);
		}
		printf("\n");
	}
	return 0;
}
