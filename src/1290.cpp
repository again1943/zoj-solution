#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MATRIX_LEN 128
#define NONE -1
char word[MATRIX_LEN];
char matrix[MATRIX_LEN][MATRIX_LEN];
int step[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

inline bool inside( int x, int y, int n )
{
	return (x >= 0 && x < n && y >= 0 && y < n);	
}

inline void parse( char* word, int code, int sx, int sy, int& ex, int& ey )
{
	int size = strlen(word);		
	ex = sx+(size-1)*step[code][0];	
	ey = sy+(size-1)*step[code][1];
}
int lookup( int x,int y,int n, char* word )
{
	int i,j,a,b;
	int size = strlen(word);
	for( i = 0; i < 8; i++ )
	{
		if(inside( x+(size-1)*step[i][0],y+(size-1)*step[i][1],n))
		{
			for( j = 1; j < size; j++ )	
			{
				a = x+j*step[i][0];
				b = y+j*step[i][1];
				if( matrix[a][b] != word[j] )
					break;
			}
			if( j == size )	
				return i;
		}
	}
	return NONE;
}
int main()
{
	int t = 0;
	int test_case,n,i,j,k,ret,x,y;
	scanf("%d",&test_case);
	for( k = 0; k < test_case; k++ )
	{
		scanf("%d",&n);		
		if( t++ )
			printf("\n");
		for( i = 0; i < n; i++ )
			scanf("%s",matrix[i]);
		while( scanf("%s",word) && strcmp(word,"0") != 0 )
		{
			if( (int)strlen(word) <= n )
			{
				for( i = 0; i < n; i++ )		
				for( j = 0; j < n; j++ )
				{
					if( matrix[i][j] == word[0] && (ret = lookup(i,j,n,word)) != NONE )
					{
						parse(word,ret,i,j,x,y);
						printf("%d,%d %d,%d\n",i+1,j+1,x+1,y+1);
						goto done;
					}
				}
			}
			printf("Not found\n");
			done:
				;
		}
	}
	return 0;
}
