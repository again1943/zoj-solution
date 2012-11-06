#include<cstdio>
#include<cmath>
using namespace std;

int do_step( int x, int y)
{
	int step = y-x;
	if( step == 0 )
		return 0;
	if( step == 1 )
		return 1;
	if( step == 2 )
		return 2;
	if( step == 3||step == 4 )
		return 3;
	int root = (int)sqrt((double)step);
	if( root*root == step )
		return 2*root-1;
	else if( root*root+(2*root+1)/2 < step )
		return 2*root+1;
	else
		return 2*root;
}
int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y) != -1)
		printf("%d\n",do_step(x,y));
	return 0;
}