#include<cstdio>
#include<algorithm>
using namespace std;

int d[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
int half[9] = {0,5,45,445,4445,44445,444445,4444445,44444445};
int digit_len( int num )
{
	int i;
	for( i = 1; i < 9; i++ )
		if( num < d[i] )
			break;
	return i;
}
int round_int( int num)
{
	int len = digit_len(num);
	if( len == 1 )	
		return num;
	if( num%d[len-1] >= half[len-1] )	
		return (num/d[len-1]+1)*d[len-1];
	return (num/d[len-1])*d[len-1];
}
int main()
{
	int n,i,num;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d",&num);
		printf("%d\n",round_int(num));	
	}
	return 0;
}
