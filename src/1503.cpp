#include<cstdio>

using namespace std;
#define SIZE 31
int LG[SIZE][SIZE];

void first()
{
	int i,j;
	LG[0][0] = 0;
	LG[1][0] = LG[1][1] = 1;
	for( i = 2; i < SIZE; i++ )
	{
		LG[i][0] = i;
		for( j = 1; j < i; j++ )
			LG[i][j] = LG[i-1][j]+LG[i-1][j-1]+1;
		for( j = i; j < SIZE; j++ )
			LG[i][j] = (1<<i)-1;
	}
}
int main()
{
	int x,y,i;
	i = 0;
	first();
	while( scanf("%d%d",&x,&y) && (x != 0 || y != 0 ))
		printf("Case %d: %d\n",++i,LG[x][y]);
	return 0;
}
