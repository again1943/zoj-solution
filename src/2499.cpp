#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_SIZE 200002

struct point_t
{
	int r,c;
}stone[MAX_SIZE];
struct sort_r
{
	bool operator()(const point_t& a, const point_t& b )
	{
		if( a.r != b.r )
			return a.r < b.r;	
		return a.c < b.c;
	}
};
struct sort_c
{
	bool operator()(const point_t& a, const point_t& b )
	{
		if( a.c != b.c )
			return a.c < b.c;
		return a.r < b.r;
	}
};

int count( point_t* stone, int R, int C, int n )
{
	int i,last;
	int retval = 0;
	if( R <= 1 && C <= 1 )
		return 0;
	sort(stone,stone+n,sort_r());
	for(i = 0,last = 1; last <= R; last++ )
	{
		if( last != stone[i].r )	//last < stone[i].r
			retval += 1;
		else//last == stone[i].r
		{
			if( stone[i].c > 2 )			
				retval += 1;
			i += 1;
			while( i < n && stone[i].r == last )
			{
				if( stone[i].c-stone[i-1].c > 2 )		
					retval += 1;
				i += 1;
			}
			if( C-stone[i-1].c >= 2 )
				retval += 1;
		}
	}
	sort(stone,stone+n,sort_c());
	for(i = 0,last = 1; last <= C; last++ )
	{
		if( last != stone[i].c )
			retval += 1;
		else
		{
			if( stone[i].r > 2 )
				retval += 1;	
			i += 1;
			while( i < n && stone[i].c == last )
			{
				if( stone[i].r - stone[i-1].r > 2 )
					retval += 1;
				i += 1;
			}
			if( R-stone[i-1].r >= 2 )
				retval += 1;
		}
	}
	return retval;
}
int main()
{
	int R,C,n,i,k,t;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d%d",&R,&C,&n);
		for( i = 0; i < n; i++ )
			scanf("%d%d",&stone[i].r,&stone[i].c);
		printf("%d\n",count(stone,R,C,n));
	}
	return 0;
}
