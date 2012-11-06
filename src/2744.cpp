#include<cstdio>
#include<cstring>
using namespace std;

#define SIZE 5002
char line[SIZE];

int check(int pos, int start,int end )
{
	int sum = 1;
	int left = pos-1;
	int right = pos+1;
	while(left >= start && right <= end )
	{
		if(line[left] == line[right])
		{
			sum++;
			left--;
			right++;
		}
		else
			break;
	}
	left = pos-1;
	right = pos;
	while(left >= start && right <= end )
	{
		if(line[left] == line[right])
		{
			sum++;
			left--;
			right++;
		}
		else
			break;
	}
	return sum;
}
int main()
{
	int n;
	int sum;
	while(scanf("%s",line) != -1)
	{
		
		n = strlen(line);
		if(n ==1 )
			sum = 1;
		else if( n == 2 && line[0] == line[1] )
			sum = 3;
		else if( n == 2 && line[0] != line[1] )
			sum = 2;
		else
		{
			sum = 1;
			for( int i = 1; i < n-1; i++ )
				sum += check(i,0,n-1);
			sum += (line[n-2] == line[n-1] )?2:1;
		}
		printf("%d\n",sum);
	}
	return 0;
}