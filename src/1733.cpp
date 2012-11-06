#include<cstdio>
#include<cstring>
#define SIZE 200
using namespace std;

int cost[SIZE][SIZE];
int max_value( const char* X, const char* Y )
{
	int len_x = strlen(X)-1;
	int len_y = strlen(Y)-1;
	for( int i = 1; i <= len_x;i++ )
		for( int j = 1 ; j <= len_y ; j++ )
		{
			if( X[i] == Y[j] )
			{	
				cost[i][j] = cost[i-1][j-1] + 1; 
			}
			else 
				cost[i][j] = cost[i-1][j] >= cost[i][j-1]? cost[i-1][j]:
					cost[i][j-1];
		}
	return cost[len_x][len_y];
}
int main()
{
	char X[SIZE]={'a'};
	char Y[SIZE]={'a'};
	while( scanf("%s%s",X+1,Y+1) != EOF )
	{
		printf("%d\n",max_value(X,Y));
	}
	return 0;
}
