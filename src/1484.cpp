#include <cstdio>
#include <algorithm>

using namespace std;
#define SIZE 5001

int num[SIZE];
int min_invers(int* num, int n)
{
	int min;
	int revers = 0;
	for (int i = 0; i < n; i++ )
	for (int j = i+1; j < n; j++)
	{
		if (num[i] > num[j])
			revers++;
	}
	min = revers;
	for (int i = n-1; i > 0; i-- )
	{
			revers += 2*num[i]+1-n;
			min = min > revers?revers:min;
	}
	return min;
}

int main()
{
	int n;
	while (scanf("%d",&n) != -1)
	{
		for (int i = 0; i < n; i++ )
			scanf("%d",&num[i]);
		printf("%d\n",min_invers(num,n));
	}
	return 0;
}