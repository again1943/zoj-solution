#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAXN 20001
struct item_t
{
	int n,t1,t2;
	int x,y;
}hyper[MAXN][4];
int factorial[8] ={1,1,2,6,24,120,720,5040};

int power( int x,int y,int n)
{
	int i;
	int t = 1;
	for( i = 0; i < y; i++ )
	{
		t *= x;
		if( t > n )
			return -1;
	}
	return t;
}

void compute(int n)
{
	int i,j,k,s,t,m,tmp;
	memset(hyper,-1,sizeof(hyper));
	hyper[1][0].n = hyper[1][1].n = hyper[1][2].n = hyper[1][3].n = 1;
	hyper[2][0].n = hyper[2][1].n = hyper[2][2].n = hyper[2][3].n = 1;
	hyper[3][0].n = hyper[3][1].n = hyper[3][2].n = hyper[3][3].n = 1;
	hyper[5][0].n = hyper[5][1].n = hyper[5][2].n = hyper[5][3].n = 1;
	hyper[7][0].n = hyper[7][1].n = hyper[7][2].n = hyper[7][3].n = 1;
	for( i = 2; i <= n; i++ )
	{
		for( j = 1; j <= i && (m = i+j) <= n; j++ )
		{
			for( k = 0; k < 4; k++ )
			{
				if( hyper[i][k].n <= 0 )
					continue;
				for( s = 0; s < 4; s++ )
				{
					if( hyper[j][s].n <= 0 )
						continue;
					tmp = hyper[i][k].n+hyper[j][s].n;
					if( hyper[m][1].n <= 0 ||
						tmp < hyper[m][1].n )
					{
						hyper[m][1].n = tmp;
						hyper[m][1].x = i;
						hyper[m][1].y = j;
						hyper[m][1].t1 = k;
						hyper[m][1].t2 = s;
					}
				}
			}
		}
		for( j = 1; j <= i && (m = i*j ) <= n; j++ )
		{
			for( k = 0; k < 4; k++ )
			{
				if( hyper[i][k].n <= 0 )
					continue;
				for( s = 0; s < 4; s++ )
				{
					if( hyper[j][s].n <= 0 )
						continue;
					tmp = hyper[i][k].n + hyper[j][s].n;
					if( hyper[m][2].n <= 0 || 
						tmp < hyper[m][2].n )
					{
						hyper[m][2].n = tmp;
						hyper[m][2].x = i;
						hyper[m][2].y = j;
						hyper[m][2].t1 = k;
						hyper[m][2].t2 = s;
					}
				}
			}
		}
		for( j = 2; (m = power(i,j,n)) >0 && j <= i; j++ )
		{
			for( k = 0; k < 4; k++ )
			{
				if( hyper[i][k].n <= 0 )
					continue;
				for( s = 0; s < 4; s++ )
				{
					if( hyper[j][s].n <= 0 )
						continue;
					tmp = hyper[i][k].n+hyper[j][s].n;
					if( hyper[m][3].n <= 0 ||
						tmp < hyper[m][3].n )
					{
						hyper[m][3].n = tmp;
						hyper[m][3].x = i;
						hyper[m][3].y = j;
						hyper[m][3].t1 = k;
						hyper[m][3].t2 = s;
					}
				}
			}
		}
		for( j = 2; (m = power(j,i,n))> 0 && j <= i; j++ )
		{
			for( k = 0; k < 4; k++ )
			{
				if( hyper[i][k].n <= 0 )
					continue;
				for( s = 0; s < 4; s++ )
				{
					if( hyper[j][s].n <= 0 )
						continue;
					tmp = hyper[i][k].n+hyper[j][s].n;
					if( hyper[m][3].n <= 0 || 
						tmp < hyper[m][3].n )
					{
						hyper[m][3].n = tmp;
						hyper[m][3].x = j;
						hyper[m][3].y = i;
						hyper[m][3].t1 = s;
						hyper[m][3].t2 = k;
					}
				}
			}
		}
		if( i < 3 || i > 7 )
			continue;

		t = factorial[i];
		for( k = 0; k < 4; k++ )
		{
			if( hyper[i][k].n > 0 && 
				( hyper[t][0].n <= 0 ||  hyper[i][k].n < hyper[t][0].n ) )
			{
				hyper[t][0].n = hyper[i][k].n;
				hyper[t][0].x = i;
				hyper[t][0].t1 = k;
			}
		}
	}
}

void print(int n,int d)
{
	if( n == 1 || n == 2 || n == 3 || n == 5 || n == 7 )
		printf("%d",n);
	else
	{
		switch(d)
		{
		case 0:
			print(hyper[n][d].x,hyper[n][d].t1);
			printf("!");
			break;
		case 1:
			printf("(");
			print(hyper[n][d].x,hyper[n][d].t1);
			printf("+");
			print(hyper[n][d].y,hyper[n][d].t2);
			printf(")");
			break;
		case 2:
			printf("(");
			print(hyper[n][d].x,hyper[n][d].t1);
			printf("*");
			print(hyper[n][d].y,hyper[n][d].t2);
			printf(")");
			break;
		default:
			printf("(");
			print(hyper[n][d].x,hyper[n][d].t1);
			printf("^");
			print(hyper[n][d].y,hyper[n][d].t2);
			printf(")");
			break;
		}
	}

}

void printk(int n)
{
	int m,d,i;
	m = 0x7fffffff;
	for( i = 0; i < 4; i++ )
	{
		if( hyper[n][i].n > 0 && hyper[n][i].n  < m )
		{
			m = hyper[n][i].n;
			d = i;
		}
	}
	print(n,d);
	printf("\n");
}
int main()
{
	int n;
	compute(MAXN-1);
	while( scanf("%d",&n) != -1 )
		printk(n);
	return 0;
}