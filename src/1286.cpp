#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define LINE_LENGTH 64
char line[LINE_LENGTH];
bool slump(char* line, int& pos )
{
	if( line[pos] != 'D' && line[pos] != 'E' )	
		return false;
	pos += 1;	
	if( line[pos] != 'F' )
		return false;
	while( line[pos] == 'F' )
		pos += 1;
	if( line[pos] == 'G' )	
	{
		pos += 1;
		return true;
	}
	else
		return slump(line,pos);	
}
bool slimp(char* line ,int& pos)
{
	if( line[pos++] != 'A' )	
		return false;
	if( line[pos] == 'H' )
	{
		pos += 1;
		return true;
	}
	if( line[pos] == 'B' )		
	{
		pos += 1;
		if( slimp(line,pos) != true )
			return false;
	}
	else
	{
		if( slump(line,pos) != true )	
			return false;
	}
	return (line[pos++] == 'C');
}
bool slurpy(char* line, int& pos )
{
	return (slimp(line,pos) && slump(line,pos) && line[pos]==0);
}
int main()
{
	int n,i;
	int pos;
	scanf("%d",&n);
	printf("SLURPYS OUTPUT\n");
	for( i = 0; i < n; i++ )
	{
		pos = 0;
		scanf("%s",line);
		printf("%s\n",slurpy(line,pos)?"YES":"NO");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
