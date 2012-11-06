#include<cstdio>
int main()
{
	int s,a,b,c,r;
	while(scanf("%d%d%d%d",&s,&a,&b,&c,&c) && ( s != 0 || a != 0 || b != 0 || c != 0 ))
	{
		r = 1080;
		r += (s >= a)?(s-a)*9:(s+40-a)*9;	
		r += (b >= a)?(b-a)*9:(b+40-a)*9;		
		r += (b >= c)?(b-c)*9:(b+40-c)*9;
		printf("%d\n",r);
	}
	return 0;
}
