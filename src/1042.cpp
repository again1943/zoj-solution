#include<cstdio>
#include<algorithm>
using namespace std;
#define MESSAGE_LEN 82

int  k[3],len[3];
char line[MESSAGE_LEN];
char copy_line[MESSAGE_LEN];
int  group[3][MESSAGE_LEN];

void right_rotate( char* line, int* group_pos, int n, int k)
{
	int i,pos;
	for( i = 0; i < n; i++ )	
	{
		pos = (i+k)%n;	
		line[group_pos[pos]] = copy_line[group_pos[i]];
	}
}

void decrypt( int* k, char* line )
{
	int i;
	len[0] = len[1] = len[2] = 0;
	for( i = 0; line[i] != 0; i++ )			
	{
		if( line[i] >= 'a' && line[i] <= 'i' )	
			group[0][len[0]++] = i;	
		else if( line[i] >= 'j' && line[i] <= 'r' )
			group[1][len[1]++] = i;
		else
			group[2][len[2]++] = i;
	}
	strcpy(copy_line,line);
	for( i = 0; i < 3; i++ )
		right_rotate(line,group[i],len[i],k[i]);
}
int main()
{
	while(scanf("%d%d%d",&k[0],&k[1],&k[2]) && k[0] != 0 )
	{
		scanf("%s",line);	
		decrypt(k,line);
		printf("%s\n",line);
	}
	return 0;
}
