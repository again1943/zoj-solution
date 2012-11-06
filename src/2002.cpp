#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAXN 512

int books[MAXN];
int sums[MAXN];
size_t matrix[MAXN][MAXN];

void output(int* books,int i,int p, int limit)
{
	int t,sum;
	if( p == 1 )
	{
		printf("%d",books[1]);
		for( t = 2; t <= i; t++ )
			printf(" %d",books[t]);
		return;
	}
	if( i == p )
	{
		printf("%d",books[1]);
		for( t = 2; t <= i; t++ )
			printf(" / %d",books[t]);
	}
	else
	{
		t = i-1;
		sum = books[i];
		while( t >= p && sum + books[t] <= limit )
		{
			sum += books[t];
			t -= 1;
		}
		output(books,t,p-1,limit);
		printf(" /");
		t += 1;
		while( t <= i )
		{	
			printf(" %d",books[t]);
			t += 1;
		}
	}
}
void copy_books(int* books,int n, int p)
{
	size_t v;
	int i,j,k;
	vector<int> vec;
	memset(matrix,-1,sizeof(matrix));	
	matrix[0][0] = 0;
	for( i = 0; i <= p; i++ )
		matrix[i][0] = 0;
	for( i = 1; i <= p; i++ )
	for( j = 1; j <= n; j++ )
	for( k = 0; k < j; k++ )	
	{
		v = max(matrix[i-1][k],(size_t)(sums[j]-sums[k]));
		if( matrix[i][j] > v )
			matrix[i][j] = v;
	}
	output(books,n,p,matrix[p][n]);
	printf("\n");
}

int main()
{
	int k,t,n,p,i;
	scanf("%d",&t);
	for(k = 0; k < t; k++)
	{
		scanf("%d%d",&n,&p);
		books[0] = sums[0] = 0;
		for( i = 1; i <= n; i++ )
		{
			scanf("%d",&books[i]);
			sums[i] = sums[i-1]+books[i];
		}
		copy_books(books,n,p);
	}
	return 0;
}