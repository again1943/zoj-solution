#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#define MAXN 24

int elem[MAXN];
bool in[MAXN];	

int valid( int* elem, int n )
{
	int i,total,avg;
	for( i = total = 0; i < n; i++ )
		total += elem[i];
	if( total % 4 != 0 )
		return -1;
	avg = total/4;
	for( i = 0; i < n; i++ )
		if( elem[i] > avg )
			return -1;	
	return avg;
}

bool doit(int n, int start, int sum, int side,int depth )
{
	int i;
	if( depth > 2 )
		return false;
	for( i = start; i < n; i++ )			
	{
		if( in[i] != true && sum + elem[i] <= side )	
		{
			in[i] = true;
			if( sum + elem[i] == side )
			{
				if( depth == 2 || doit(n,0,0,side,depth+1) == true )	
					return true;
			}
			else 
			{
				if( doit(n,i+1,sum+elem[i],side,depth) == true )
					return true;
			}
			in[i] = false;
		}
	}
	return false;
}

bool square( int* elem, int n )
{
	int item;
	memset(in,0,sizeof(in));
	if( (item = valid(elem,n)) < 0 )
		return false;
	std::sort(elem,elem+n,std::greater<int>());
	return doit(n,0,0,item,0);
}
int main()
{
	int n,i,k,test;
	scanf("%d",&test);
	for( k = 0; k < test; k++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%d",&elem[i]);	
		printf("%s\n",square(elem,n)?"yes":"no");			
	}
	return 0;
}

