#include<algorithm>
#include<utility>
#include<cstdio>
using namespace std;

#define NUM 1000001
#define QUERY 3392928

int query[QUERY];
int num[NUM];

void pre_set()
{
	int pos_n,pos_q;
	num[0] = 0;
	num[1] = 0;
	for( int i = 2; i < NUM; i++ )
		num[i] = 1;
	for( int i = 2; i*i < NUM; i++ )
	{
		num[i*i] += i;
		for( int j = i+1; j*i < NUM; j++ )
			num[j*i] += i+j;
	}

	sort(num+1,num+NUM);		
	query[0] = query[1] = 1;	

	for( pos_n = 2,pos_q = 1; pos_n < NUM; pos_n++ )
	{
		if( num[pos_n] == pos_q	)
			query[pos_q]++;
		else
		{
			pos_q++;
			while( pos_q < num[pos_n] )
			{
				query[pos_q] = query[pos_q-1];
				pos_q++;
			}
			query[pos_q] = query[pos_q-1] + 1;
		}
	}
}
int main()
{
	int n;	
	pre_set();
	while( scanf("%d",&n) != -1 )
	{	
		if( n > 3392928 )
			printf("1000000\n");	
		else
			printf("%d\n",query[n]);
	}
	return 0;
}
