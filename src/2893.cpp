#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAXLEN 100000
#define MAXSUM 16

char line[2][MAXLEN];
char text[MAXSUM][MAXLEN];


void set_text()
{
	int i,j;
	text[0][0] = 0;
	strcat(text[0],"{}");
	for(i = 1; i < MAXSUM; i++ )
	{
		text[i][0] = 0;
		strcat(text[i],"{");		
		strcat(text[i],text[0]);
		for( j = 1; j < i; j++ )
		{
			strcat(text[i],",");
			strcat(text[i],text[j]);
		}
		strcat(text[i],"}");
	}
}
int elem_find( char text[][MAXLEN], char* msg )
{
	int i;	
	for( i = 0; i < MAXSUM; i++ )
		if( strcmp(msg,text[i]) == 0 )
			return i;
	return 0;
}
int main()
{
	int i,test_case,x,y;
	
	set_text();	
	scanf("%d",&test_case);
	for( i = 0; i < test_case; i++ )
	{
		scanf("%s%s",line[0],line[1]);
		x = elem_find(text,line[0]);
		y = elem_find(text,line[1]);
		printf("%s\n",text[x+y]);
	}
	return 0;
}
