#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
#define MAX_CNT 26
#define MAX_VAL 0x7fffffff

bool matrix[MAX_CNT][MAX_CNT];
int degree[MAX_CNT];
bool fort[MAX_CNT];

int bfs( int new_fort, int n )
{
	int val,item,i;
	int maxval,maxidx;
	bool touch[MAX_CNT];
	queue<int>Q;
	fort[new_fort] = true;		
	memset(touch,0,sizeof(touch));
	degree[new_fort] = 0;
	Q.push(new_fort);
	touch[new_fort] = true;

	while( Q.empty() != true )
	{
		item = Q.front();			
		Q.pop();
		val = degree[item];
		for( i = 0; i < n; i++ )
		{
			if( matrix[item][i] == true && touch[i] != true &&
				degree[i] > val + 1 )
			{
				degree[i] = val + 1;
				Q.push(i);
			}
		}
	}
	for( i = 0,maxval = -1; i < n; i++ )
	{
		if( maxval < degree[i] )	
		{
			maxval = degree[i];
			maxidx = i;
		}
	}
	return maxidx;
}
int main()
{
	int n,m,i,out;
	char c,a,b;
	scanf("%d %c %d",&n,&c,&m);
	getchar();
	memset(matrix,0,sizeof(matrix));
	while( scanf("%c %c",&a,&b) != -1 )
	{
		getchar();		
		matrix[a-'A'][b-'A'] = matrix[b-'A'][a-'A'] = true;
	}
	memset(fort,0,sizeof(fort));
	fill(degree,degree+MAX_CNT,MAX_VAL);
	printf("Program 8 by team X\n%c",c);	
	for( i = 0,out = c -'A'; i < m-1; i++ )
	{
		out = bfs(out,n);
		printf(" %c",out+'A');
	}
	printf("\nEnd of program 8 by team X\n");
	return 0;
}
