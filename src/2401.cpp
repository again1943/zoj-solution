#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define SRC_LEN 210
char first[SRC_LEN];
char second[SRC_LEN];
char target[SRC_LEN*2];
bool flag[SRC_LEN][SRC_LEN];

int main()
{
	bool real;
	int n,i,j,t,first_,second_,target_;	
	scanf("%d",&n);
	for( t = 1; t <= n; t++ )
	{
		scanf("%s%s%s",first+1,second+1,target+1);
		target_ = strlen(target+1);
		first_ = strlen(first+1);
		second_ = strlen(second+1);

		first[0] = second[0] = target[0] = 0;
		memset(flag,0,sizeof(flag));
		flag[0][0] = true;

		if( first_+second_ != target_)
		{
			printf("Data set %d: no\n",t+1);
			continue;
		}
		for( i = 1; i <= target_; i++ )
		{
			real = false;	
			for( j = 0; j <= i-1; j++ )			
			{
				if( j > first_ || i-j-1 > second_ ||
					flag[j][i-j-1] == false )
					continue;
				if( first[j+1] == target[i] )	
				{
					flag[j+1][i-j-1] = true;
					real = true;
				}
				if( second[i-j] == target[i] )
				{
					flag[j][i-j] = true;
					real = true;
				}
			}
			if( real == false )
				break;
		}
		if( flag[first_][second_] == false )
			printf("Data set %d: no\n",t);
		else
			printf("Data set %d: yes\n",t);
	}
	return 0;
}
