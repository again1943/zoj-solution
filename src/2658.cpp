#include<cstdio>
#include<cstring>
char first[128];
char second[128];

int appear[2][26];
int count[101];

bool possible( char* first, char* second )
{
	int i;
	if( strlen(first) != strlen(second))
		return false;
	memset(appear,0,sizeof(appear));
	memset(count,0,sizeof(count));
	for( i = 0; first[i] != 0; i++ )
	{
		appear[0][first[i]-'A'] += 1;				
		appear[1][second[i]-'A'] += 1;
	}
	for( i = 0; i < 26; i++ )
	{
		count[appear[0][i]] += 1;
		count[appear[1][i]] -= 1;
	}
	for( i = 0; i < 101; i++ )
		if( count[i] != 0 )
			return false;
	return  true;
}
int main()
{
	while( scanf("%s%s",first,second) != -1 )	
		printf("%s\n",possible(first,second)?"YES":"NO");
	return 0;
}
