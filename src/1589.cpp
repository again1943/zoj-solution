#include <cstdio>
#include <cstdlib>
#include <cstring>


#define MAXN 26

int matrix[MAXN][MAXN];


int main()
{
	int n,m,i,k,a,b,c;
	char	line[16];
	bool	none;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d",&m);
		memset(matrix,0,sizeof(matrix));
		for( k = 0; k < m; k++ )
		{
			scanf("%s",line);
			if( line[1] == '<' )
				matrix[line[0]-'A'][line[2]-'A'] = 1;
			else
				matrix[line[2]-'A'][line[0]-'A'] = 1;
		}
		for( a = 0; a < MAXN; a++ )
		for( b = 0; b < MAXN; b++ )
		for( c = 0; c < MAXN; c++ )
			if( matrix[b][a] > 0 && matrix[a][c] > 0 && matrix[b][c] == 0 )
				matrix[b][c] = 2;
		printf("Case %d:\n",i+1);
		none = true;
		for( a = 0; a < MAXN; a++ )
		for( b = 0; b < MAXN; b++ )
		{
			if( matrix[a][b] == 2 )
			{
				none = false;
				printf("%c<%c\n",a+'A',b+'A');
			}
		}
		if( none == true )
			printf("NONE\n");

	}
	return 0;
}