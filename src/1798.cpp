#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 16

bool touch[MAXN];
bool circle[MAXN][MAXN];

void process(int prefix,char* line)
{
	int i,d,n;
	char word[10];
	for( i = d = 0; line[i] != 0; i++)
	{
		if( line[i] >= '0' && line[i] <= '9')
			word[d++] = line[i];
		else
		{
			word[d] = 0;
			n = atoi(word);
			circle[prefix][n] = circle[n][prefix] = true;
			d = 0;
		}
	}
	word[d] = 0;
	if( word[0] != 0 )
	{
		n = atoi(word);
		circle[prefix][n] = circle[n][prefix] = true;
	}
}

bool bfs( int start, int n, int c)
{
	bool ret;
	int i;
	if( c == n && circle[start][0] == true )
		return true;
	for( i = 0; i <= n; i++ )
	{
		if( circle[start][i] == true && touch[i] != true )
		{
			touch[i] = true;
			if( (ret = bfs(i,n,c+1)) == true )
				return true;
			touch[i] = false;
		}
	}
	return false;
}
int main()
{
	int m,i;
	int t = 0;
	char line[128];
	while( scanf("%d",&m) && m != 0)
	{
		memset(touch,false,sizeof(touch));
		memset(circle,false,sizeof(circle));
		getchar();
		for( i = 1; i <= m; i++ )
		{
			gets(line);
			process(i,line);
		}
		touch[0] = true;
		if( bfs(0,m,0) == true )
			printf("Case %d: Granny can make the circuit.\n",++t);
		else
			printf("Case %d: Granny can not make the circuit.\n",++t);
	}
	//Case 1: Granny can make the circuit.
	//	Case 2: Granny can not make the circuit.
	return 0;
}