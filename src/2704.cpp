#include<cstdio>
#define SIZE 100002

char line[SIZE];
int match[SIZE];
int max;
int pos;

bool inline match_char( char x,char y )
{
	return (x == '(' && y == ')')||(x == '[' && y == ']');
}
int main()
{
	int temp;
	while( scanf("%s",line+1) != -1 )
	{
		max = pos = 0;			
		match[0] = 0;
		for( int i = 1; line[i] != '\0'; i++ )
		{
			if( i == 1 || line[i] == '(' || line[i] == '[' )		
			{
				match[i] = 0;
				continue;
			}
			if( match_char( line[i-1],line[i]) == true )
			{
				match[i] = match[i-2] + 2;
				if( max < match[i] )
				{
					max = match[i];
					pos = i;
				}
			}
			else
			{
				temp = i-match[i-1]-1;
				if( match[i-1] > 0 && temp >= 1 && 
					match_char( line[temp],line[i] ) == true ) 
				{
					match[i] = match[i-1] + 2;
					if( temp-1 >= 1 )
						match[i] += match[temp-1];
					if( max < match[i] )
					{
						max = match[i];
						pos = i;
					}	
				}
				else
					match[i] = 0;
			}
		}
		if( max > 0 )
		{
			for( int i = pos-max+1; i <= pos; i++ )
				printf("%c",line[i]);
		}
		printf("\n\n");

	}
	return 0;
}
