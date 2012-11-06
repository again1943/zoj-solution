#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAXN 301
#define MAXM 9
#define _cp(a,b) ((a)<(b)?(a):(b))
typedef int elemt;

int matrix[MAXN][MAXN];
struct RMQ{
	int n , m;
	elemt b [ MAXM ] [ MAXN ] [ MAXM ] [ MAXN ] ;
	void init( int x , int y, int a[][MAXN]);
	elemt ans( int i , int j , int k , int l );
}rmq;

void RMQ::init( int x ,int y,int a [][MAXN] )
{
	int i,j,k,k1,p,p1;
	n = x , m = y;                   
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			b[0][i+1][0][j+1]=a[i][j];

	for(i=1;i<=m;i++)
		for(p=2,k=1;p<=n;p*=2,k++)
			for (j=0;j<=n-p+1;j++)
				b [k][j][0][i] =_cp(b[k-1][j][0][i],b[k-1][j+p/2][0][i]); 

	for (i=1;i<=n;i++)
		for(p=2,k=1;p<=m;p*=2,k++)
			for (j=0;j<=m-p+1;j++)
				b [0][i][k][j]=_cp(b[0][i][k-1][j],b[0][i][k-1][j+p/2]); 

	for(p=2,k=1;p<=m;p*=2,k++)
		for (i=1;i<=m-p+1;++i)
			for (p1=2,k1=1;p1<=n;p1*=2,k1++)
				for (j=1;j<=n-p1+1;++j)
					b[k1][j][k][i]=_cp(b[k1-1][j][k-1][i],_cp( b[k1-1][j+p1/2][k-1][i],_cp(b[k1-1][j][k-1][i+p/2],b[k1-1][j+p1/2][k-1][i+p/2]))); 
}

elemt RMQ::ans( int i , int j , int k , int l )
{
	int x=(int)(log(double(k-i+1))/log(2.0));
	int y=(int)(log(double(l-j+1))/log(2.0));
	return _cp(b[x][i][y][j],_cp(b[x][k-(1<<x)+1][y][j] ,_cp(b[x][i][y][l-(1<<y)+1] ,b[x][k-(1<<x)+1][y][l-(1<<y)+1])));
}

int main()
{
	int scale;
	int q;
	int x,y,m,n;
	int test_case;
	scanf("%d",&test_case);
	for (int t = 0; t < test_case; t++ )
	{
		scanf("%d",&scale);
		for( int i = 0; i < scale ; i++ )
		for( int j = 0; j < scale ; j++ )
			scanf("%d",&matrix[i][j]);
		scanf("%d",&q);
		rmq.init(scale,scale,matrix);
		for( int i = 0; i < q; i++ )
		{
			scanf("%d%d%d%d",&x,&y,&m,&n);
			printf("%d\n",rmq.ans(x,y,m,n));
		}
	}
	return 0;
}