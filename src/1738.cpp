#include<cmath>
#include<algorithm>
#include<cstdio>

#define SIZE 183
#define DATA_SIZE 32769

using namespace std;

int square[SIZE];
int data[DATA_SIZE];

int main()
{
	for( int i = 1; i < SIZE; i++ )
		square[i] = i*i;
	fill(data,data+DATA_SIZE,0);
	for( int i = 1; i < SIZE && square[i] < DATA_SIZE; i++ )
	{
		data[square[i]]++;
		for( int j = i; j < SIZE && square[i]+square[j] < DATA_SIZE; j++ )
		{
			data[square[i]+square[j]]++;
			for( int k = j; k < SIZE 
				&& square[i]+square[j]+square[k]< DATA_SIZE; k++ )
			{
				data[square[i]+square[j]+square[k]]++;
				for( int r = k; r < SIZE&&square[i]+square[j]+square[k]
						+square[r] < DATA_SIZE&&r < SIZE; r++ )
				{
					data[square[i]+square[j]+square[k]
						+square[r]]++;
				}
			}

		}
	}
	int n;
	while( scanf("%d",&n)&&n > 0)
		printf("%d\n",data[n]);
	return 0;
}
