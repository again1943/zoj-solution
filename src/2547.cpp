#include<cstdio>
using namespace std;
int data[31];

void do_first()
{	
	int i,j;
	data[0] = 1;	
	data[1] = 0;
	data[2] = 3;
	for( i = 3; i < 31; i++ )
	{
		data[i] = 0;
		if( i%2 == 0 )
		{
			data[i] += 3*data[i-2];	
			for( j = i-4; j >= 0; j -= 2)
				data[i] += 2*data[j];
		}
	}
}
int main()
{
	int n;
	do_first();
	while( scanf("%d",&n) && n >= 0 )
		printf("%d\n",data[n]);
	return 0;
}
