#include<cstdio>
#include<algorithm>
#include<iterator>
using namespace std;

#define SIZE 15

void dummy( int buf[], int count )
{
	printf("%d",buf[0]);
	for( int i=1;i<count;++i)
			printf(" %d", buf[i] );
	printf("\n");

}

void comb( int n, int m,int buff[], int src[],int& count)
{
	if( m == 0 )
	{
		dummy(buff,count);
		return;
	}
	for( int i=0; i<= n - m; ++i )
	{
		buff[count++] = src[n-i-1];
		comb( n-i-1, m-1,buff,src,count );
		--count;
	}
}


void do_perform(int* elems, int n)
{
	int buf[6];
	int count = 0;
	sort(elems,elems+n,greater<int>());			
	comb(n,6,buf,elems,count);
}

int main()
{
	int n;
	int elems[SIZE];

	scanf("%d",&n);
	for(int i = 0; i < n; i++ )
		scanf("%d",&elems[i]);
	do_perform(elems,n);

	while( scanf("%d",&n) && n != 0 )
	{
		for(int i = 0; i < n; i++ )
			scanf("%d",&elems[i]);
		printf("\n");
		do_perform(elems,n);
	}
	return 0;
}
