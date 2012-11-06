#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
#define LINE_SIZE 128

char first[LINE_SIZE];
char second[LINE_SIZE];

int GCD( int a, int b )
{
	int temp;
	int max_ = max(a,b);		
	int min_ = min(a,b);

	while( max_ % min_ != 0 )
	{
		temp = min_;
		min_ = max_%min_;
		max_ = temp;
	}
	return min_;
}

int get_max(char* first, char* second)
{
	int max_,i,temp,len;
	char* x = first;
	char* y = second;
	int len_x = strlen(first);
	int len_y = strlen(second);
	if( len_x > len_y )
	{
		swap(x,y);
		swap(len_x,len_y);
	}
	
	for( len = 1,max_ = 0; len <= len_x; len++ )
	{
		for( i = temp = 0; i < len; i++ )	
			temp += (x[i] == y[len_y-len+i])?1:0;
		max_ = max(max_,temp);
	}
	for( len = len_y-len_x-1; len >= 0; len-- )
	{
		for( i = temp = 0; i < len_x; i++ )	
			temp += (x[i] == y[len+i])?1:0;
		max_ = max(max_,temp);
	}
	for( len = len_x-1; len > 0; len-- )
	{
		for( i = 0,temp = 0; i < len; i++ )
			temp += (x[len_x-len+i] == y[i])?1:0;
		max_ = max(max_,temp);
	}
	return max_;
}

int main()
{
	int total_len,gcd,max_con;
	while(scanf("%s",first) && strcmp(first,"-1") != 0)	
	{
		scanf("%s",second);
		max_con = get_max(first,second);	
		total_len = strlen(first)+strlen(second);

		if( max_con == 0 )
			printf("appx(%s,%s) = 0\n",first,second);
		else if( max_con*2 == total_len )
			printf("appx(%s,%s) = 1\n",first,second);
		else
		{		
			gcd = GCD(total_len,2*max_con);
			printf("appx(%s,%s) = %d/%d\n",
				first,second,2*max_con/gcd,total_len/gcd);
		}
	}
	return 0;
}
