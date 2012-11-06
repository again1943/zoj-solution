#include<cstdio>
#include<cstring>
using namespace std;
int letter[26] =
{ -1,1,2,3,-1,1,2,-1,-1,2,2,4,5,5,-1,1,2,6,2,3,-1,1,-1,2,-1,2 }; 
int main()
{
	char line[21];
	while( scanf("%s",line) != EOF )
	{
		char* p = line;
		int temp = 0;
		while( *p != '\0' )
		{
			if( letter[*p-'A'] == letter[*(p+1)-'A'] )
				p++;
			else
			{
				if( (temp = letter[*p-'A']) > 0 )
					printf( "%d",temp );
				p++;
			}
		}
		printf("\n");
	}
}
