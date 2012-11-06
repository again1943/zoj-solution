#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<queue>
using namespace std;

#define MAX_FILE 101
bool files[MAX_FILE][MAX_FILE];
int touch[MAX_FILE];

//caustion how to decide whether a directed graph has a circle
bool circle(int c, int n )
{
	int i;
	touch[c] = 1;
	for( i = 1; i < n; i++ )
	{
		if( files[c][i] != true || touch[i] == 2 )
			continue;
		if( touch[i] == 1 || circle(i,n) == true)
			return true;
	}
	touch[c] = 2;
	return false;
}
int main()
{
	int n,x,y,i,last,max_file;
	while( scanf("%d",&n) && n > 0 )
	{
		max_file = -1;
		memset(files,0,sizeof(files));
		memset(touch,0,sizeof(touch));
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			if( x != y )
				files[x][y] = true;
			max_file = max(max_file,max(x,y));
		}
		scanf("%d",&last);
		max_file = max(last,max_file);
		printf("%s\n",circle(last,MAX_FILE)?"No":"Yes");
	}
	return 0;
}
