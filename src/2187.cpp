#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MATRIX_SIZE 12
#define NAME_LEN 24
char source[MATRIX_SIZE][MATRIX_SIZE];
char target[MATRIX_SIZE][MATRIX_SIZE];

char line[NAME_LEN];

int main()
{
	int i,j,R,C;	
	while( scanf("%s",line) && strcmp(line,"ENDOFINPUT") != 0 )
	{
		scanf("%d%d",&R,&C);	
		for( i = 0; i < R; i++ )
		{
			getchar();
			for( j = 0; j < C; j++ )
				scanf("%c",&source[i][j]);
		}
		for( i = 0; i < R-1; i++ )
		for( j = 0; j < C-1; j++ )
			target[i][j] = (source[i][j]+source[i+1][j]+source[i][j+1]+source[i+1][j+1])/4;
		for( i = 0; i < R-1; i++ )
		{
			for( j = 0; j < C-1; j++ )
				printf("%c",target[i][j]);
			printf("\n");
		}
		scanf("%s",line);	
	}
	return 0;
}
