#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
#define NUM_CN 26

int safecracker(char* line,int n, int target, char* ret )
{
	int a,b,c,d,e;			
	int v,w,x,y,z;
	for( a = 0; a < n; a++ )
	{
	for( b = 0; b < n; b++ )
	{
		if( b == a )
			continue;
	for( c = 0; c < n; c++ )
	{
		if( c == a || c == b )
			continue;
	for( d = 0; d < n; d++ )
	{
		if( d == a || d == b || d == c )
			continue;
	for( e = 0; e < n; e++ )
	{
		if( e ==a || e == b || e ==c || e == d)
			continue;
		v = line[a]-'A'+1;
		w = line[b]-'A'+1;
		x = line[c]-'A'+1;
		y = line[d]-'A'+1;
		z = line[e]-'A'+1;
		if( (int)(v-w*w+x*x*x-y*y*y*y+z*z*z*z*z) == target )
		{
			ret[0] = line[a];	
			ret[1] = line[b];
			ret[2] = line[c];
			ret[3] = line[d];
			ret[4] = line[e];
			ret[5] = 0;
			return 1;
		}
	}
	}
	}
	}
	}
	return -1;	
}
int main()
{
	char ret[6];
	char line[NUM_CN];
	int target,n;
	while( scanf("%d%s",&target,line) && strcmp(line,"END") != 0 )
	{
		n = strlen(line);
		sort(line,line+n,greater<char>());
		if( safecracker(line,n,target,ret) < 0 )
			printf("no solution\n");
		else
			printf("%s\n",ret);
	}
	return 0;
}
