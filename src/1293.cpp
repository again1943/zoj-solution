#include<cstdio>
using namespace std;

int get_floppy( int bytes )
{
	int lines;
	bytes = (bytes+1)/2;
	bytes += (bytes+1)/2;
	lines = (bytes+61)/62;
	return (lines+29999)/30000;
}
int main()
{
	int n,bytes;	

	n = 0;
	while( scanf("%d",&bytes) && bytes != 0 )
		printf("File #%d\nJohn needs %d floppies.\n\n",
				++n,get_floppy(bytes));
	return 0;
}
