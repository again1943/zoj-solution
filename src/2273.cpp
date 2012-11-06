#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_NUM 100000 
char output[1000000];
char outlet[MAX_NUM];

int open[][2] = {	{1,2},
			{3,9},
			{10,25},{90,263},{3008,37173},
			{26,89,},{264,946},
			{947,3007}
		};
char data[] = {"13000669"};
void set()
{
	int i;	
	memset(outlet,'7',sizeof(outlet));
	for( i = 0; i < 8; i++ )
		memset(outlet+open[i][0],data[i],open[i][1]-open[i][0]+1);
}

int main()
{
	int n;	
	int idx = 0;
	set();
	while( scanf("%d",&n) != -1 )
	{			
		output[idx++] = outlet[n];
		output[idx++] = '\n';
	}
	output[idx] = 0;
	printf("%s",output);
	return 0;
}
