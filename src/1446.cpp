#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAXN 20001

struct item_t
{
	int n,t;	
	int x,y;
}hyper[MAXN];

int factorial[8] ={1,1,2,6,24,120,720,5040};

int power( int x,int y,int n)
{
	int i;
	int t = 1;
	for( i = 0; i < y; i++ )
	{
		t *= x;
		if( t > n )
			break;
	}
	return t;
}

void compute(int n)
{
	int i,j,sum,m;
	memset(hyper,-1,sizeof(hyper));
	hyper[1].n = hyper[2].n = hyper[3].n = hyper[5].n = hyper[7].n = 1;	
	for( i = 2; i <= n; i++ ) 
	{
		for( j = 1; j <= i && (m = i+j) <= n ; j++ )	
		{
			sum = hyper[i].n + hyper[j].n;
			if( hyper[m].n <= 0 || sum < hyper[m].n ) 
			{
				hyper[m].n = sum;	
				hyper[m].t = 1;
				hyper[m].x = i;
				hyper[m].y = j;
			}
		}
		for( j = 2; j <= i && (m = i*j) <= n; j++ )
		{
			sum = hyper[i].n + hyper[j].n;
			if( hyper[m].n <= 0 || sum < hyper[m].n ) 
			{
				hyper[m].n = sum;	
				hyper[m].t = 2;
				hyper[m].x = i;
				hyper[m].y = j;
			}


		}
		for( j = 2; j <= i && (m = power(i,j,n)) <= n; j++ )
		{
			sum = hyper[i].n + hyper[j].n;
			if( hyper[m].n <= 0 || sum < hyper[m].n ) 
			{
				hyper[m].n = sum;	
				hyper[m].t = 3;
				hyper[m].x = i;
				hyper[m].y = j;
			}
		}
		for( j = 2; j <= i && (m = power(j,i,n)) <= n; j++ )
		{
			sum = hyper[i].n + hyper[j].n;
			if( hyper[m].n <= 0 || sum < hyper[m].n ) 
			{
				hyper[m].n = sum;	
				hyper[m].t = 3;
				hyper[m].x = j;
				hyper[m].y = i;
			}
		}
		if( i >= 3 && i <= 7 )
		{
			m = factorial[i];
			sum = hyper[i].n;
			if( hyper[m].n <= 0 || sum < hyper[m].n ) 
			{
				hyper[m].n = sum;	
				hyper[m].t = 0;
				hyper[m].x = i;
			}
		}
	}
}
void print(int n)
{
	if( n == 1 || n == 2 || n == 3 || n == 5 || n == 7 )
		printf("%d",n);
	else
	{
		switch(hyper[n].t)
		{
		case 0:
			print(hyper[n].x);
			printf("!");
			break;
		case 1:
			printf("(");
			print(hyper[n].x);
			printf("+");
			print(hyper[n].y);
			printf(")");
			break;
		case 2:
			printf("(");
			print(hyper[n].x);
			printf("*");
			print(hyper[n].y);
			printf(")");
			break;
		default:
			printf("(");
			print(hyper[n].x);
			printf("^");
			print(hyper[n].y);
			printf(")");
			break;
		}
	}

}

int main()
{
	int n;
	compute(MAXN-1);
	while( scanf("%d",&n) != -1 )
	{
		print(n);
		printf("\n");
	}
	return 0;
}
