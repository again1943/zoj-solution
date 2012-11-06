#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define JEWELZ_LEN 1024
char jewelz[JEWELZ_LEN];
inline int next( int i, int n )
{
	return (i < n-1)?i+1:0;
}
inline int prev( int i, int n )
{
	return (i > 0)?i-1:n-1;
}
bool check_single( char* jewelz, int n, int pos )
{
	int left = prev(pos,n);
	int right = next(pos,n);
	while( jewelz[left] == jewelz[right] 
		&& prev(left,n) != right && prev(left,n) != next(right,n))	
	{
		left = prev(left,n);	
		right = next(right,n);
	}
	return ( jewelz[left] == jewelz[right]&&
			(prev(left,n) == right || prev(left,n) == next(right,n)));
}
bool check_double(char* jewelz, int n,int pos)
{
	int left = pos;	
	int right = next(pos,n);
	while( jewelz[left] == jewelz[right]
		&& prev(left,n) != right && prev(left,n) != next(right,n))
	{
		left = prev(left,n);
		right = next(right,n);
	}
	return (jewelz[left] == jewelz[right] && 
		(prev(left,n) == right || prev(left,n) == next(right,n)));
}
int check_sym( char* jewelz,int n, int pos )
{
	if( check_single(jewelz,n,pos) == true )
		return 1;
	if( check_double(jewelz,n,pos) == true )
		return 2;
	return -1;
}
int symmetric(char* jewelz, int n ,int& x,int& y)
{
	int i,ret;
	for( i = 0; i < n; i++ )	
	{
		if( (ret = check_sym(jewelz,n,i)) > 0 )		
		{
			x = i;	
			if( ret == 2 )
				y = next(i,n);
			return ret;
		}
	}
	return -1;
}
int main()
{
	int n,x,y,ret;
	while(scanf("%s",jewelz) != -1)		
	{
		n = strlen(jewelz);
		if( (ret = symmetric(jewelz,n,x,y)) < 0 )		
			printf("Not symmetric\n");
		else 
		{
			printf("Symmetric\n");
			if( ret == 1 )	
				printf("%d\n",x+1);
			else
				printf("%d-%d\n",x+1,y+1);
		}
	}
	return 0;
}
