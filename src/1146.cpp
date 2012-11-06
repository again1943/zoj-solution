#include<cstdio>
#include<cstring>
using namespace std;

void display_horizontal( int level,int w,char c )
{
	if( level == 1 )
	{
		switch( c )
		{
			case '1':
			case '4':
				for( int i = 0; i < w+2; i++ )
					printf(" ");
				break;
			case '0':
			case '2':
			case '3':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				printf(" ");
				for( int i = 0; i < w; i++ )
					printf("-");
				printf(" ");
				break;
			default:
				break;
		}
	}
	else if( level == 2 )
	{
		switch( c )
		{
			case '0':
			case '1':
			case '7':
				for( int i = 0; i < w+2; i++ )
					printf(" ");
				break;

			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '8':
			case '9':
				printf(" ");
				for( int i = 0; i < w; i++ )
					printf("-");
				printf(" ");
				break;
			default:
				break;
		}
	}
	else
	{
		switch( c )
		{
			case '1':
			case '4':
			case '7':
				for( int i = 0; i < w+2; i++ )
					printf(" ");
				break;
			case '0':
			case '2':
			case '3':
			case '5':
			case '6':
			case '8':
			case '9':
				printf(" ");
				for( int i = 0; i < w; i++ )
					printf("-");
				printf(" ");
				break;
			default:
				break;
		}
	}
}
void display_vertical( int level,int w,char c )
{
	if( level == 1 )	
	{
		switch( c )
		{
			case '0':
			case '4':
			case '8':
			case '9':
				printf("|");	
				for( int i = 0; i < w; i++ )
					printf(" ");
				printf("|");
				break;
			case '1':
			case '2':
			case '3':
			case '7':
				for( int i = 0; i < w+1; i++ )
					printf(" ");
				printf("|");
				break;
			case '5':
			case '6':
				printf("|");
				for( int i = 0; i < w+1; i++ )
					printf(" ");
				break;	
			default:
				break;

		}

	}
	else
	{
		switch(c)
		{
			case '0':
			case '6':
			case '8':
				printf("|");	
				for( int i = 0; i < w; i++ )
					printf(" ");
				printf("|");
				break;
			case '1':
			case '3':
			case '4':
			case '5':
			case '7':
			case '9':
				for( int i = 0; i < w+1; i++ )
					printf(" ");
				printf("|");

				break;
			case '2':
				printf("|");
				for( int i = 0; i < w+1; i++ )
					printf(" ");
				break;
			default:
				break;
		}
	}
}

int main()
{
	int i,j,width;
	char num[10];
	while(scanf("%d%s",&width,num) && width != 0  )
	{
		display_horizontal(1,width,num[0]);
		for( i = 1; num[i] != 0; i++ )
		{
			printf(" ");
			display_horizontal(1,width,num[i]);
		}
		printf("\n");

		for( j = 0; j < width; j++ )
		{
			display_vertical(1,width,num[0]);
			for( i = 1; num[i] != 0; i++ )
			{
				printf(" ");
				display_vertical(1,width,num[i]);
			}
			printf("\n");
		}

		display_horizontal(2,width,num[0]);
		for( i = 1; num[i] != 0; i++ )
		{
			printf(" ");
			display_horizontal(2,width,num[i]);
		}
		printf("\n");

		for( j = 0; j < width; j++ )
		{
			display_vertical(2,width,num[0]);
			for( i = 1; num[i] != 0; i++ )
			{
				printf(" ");
				display_vertical(2,width,num[i]);
			}
			printf("\n");
		}

		display_horizontal(3,width,num[0]);
		for( i = 1; num[i] != 0; i++ )
		{
			printf(" ");
			display_horizontal(3,width,num[i]);
		}
		printf("\n\n");
	}
	return 0;
}
