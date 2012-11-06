#include<cstdio>
#include<cstring>
#define MAX_SIZE 1024
int power[8] = {1,3,9,27,81,243,729,2187};
int width[8] = {0,1,3,9,27,81,243,729};
char fractal[MAX_SIZE][MAX_SIZE];

char out3[2][9][10] = 
{
	{
		"X X   X X",
		" X     X ",
		"X X   X X",
		"   X X   ",
		"    X    ",
		"   X X   ",
		"X X   X X",
		" X     X ",
		"X X   X X"
	},
	{
		"X X   X X",
		" X     X",
		"X X   X X",
		"   X X",
		"    X",
		"   X X",
		"X X   X X",
		" X     X",
		"X X   X X"
	}
};

void fill_b( int n,int x,int y )
{
	int i,j;
	for( i = 0; i < power[n-1]; i++ )	
	for( j = 0; j < width[n]; j++ )
		fractal[x+i][y+j] = ' ';
}
void print( int n,int right, int x,int y )
{
	int i,j;
	if( n == 3 )
	{
		for( i = 0; i < 9; i++ )
		for( j = 0; j < 9; j++ )
			fractal[x+i][y+j] = out3[right][i][j];
	}
	else
	{
		print(n-1,0,x,y);//0
		fill_b(n-1,x,y+width[n-1]);//1
//		for( i = 0; i < power[n-2]; i++ )
//			fractal[x+i][y+width[n-1]*2] = ' ';
		print(n-1,right,x,y+width[n-1]*2);//2

		fill_b(n-1,x+power[n-2],y);//3

		print(n-1,right,x+power[n-2],y+width[n-1]);//4
		if( !right )//5
		{
		//	for( i = power[n-2]; i < power[n-2]*2; i++ )
		//		fractal[x+i][y+width[n-1]*2] = ' ';
			fill_b(n-1,x+power[n-2],y+width[n-1]*2);
		}

		print(n-1,0,x+power[n-2]*2,y);//6
		fill_b(n-1,x+power[n-2]*2,y+width[n-1]);//7
		//for( i = power[n-2]*2; i < power[n-1];i++ )
		//	fractal[x+i][y+width[n-1]*2] = ' ';
		print(n-1,right,x+power[n-2]*2,y+width[n-1]*2);//8
	}
}
int main()
{
	int n,i;
	while( scanf("%d",&n) && n > 0 )
	{
		if( n == 1 )
			printf("X\n-\n");
		else if( n == 2 )
			printf("X X\n X\nX X\n-\n");	
		else if( n == 3 )
			printf("X X   X X\n X     X\nX X   X X\n"
			"   X X\n    X\n   X X\n"
			"X X   X X\n X     X\nX X   X X\n-\n");
		else
		{
			memset(fractal,0,sizeof(fractal));
			print(n,1,0,0);
			for( i = 0; i < power[n-1]; i++ )
				printf("%s\n",fractal[i]);
			printf("-\n");
		}
	}
	return 0;
}
