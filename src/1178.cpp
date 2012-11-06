#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct sheet_t
{
	int frl,frr;
	int bkl,bkr;
}sheet[30];

int fill_sheet( int n )
{
	int i,t,c;
	int page = 0;
	memset(sheet,-1,sizeof(sheet));
	if( n == 1 )
	{
		sheet[1].frr = 1;
		return 1;
	}
	if( n % 4 == 0 )
		page = n/4;
	else
		page = n/4+1;
	for( i = t = 1; i <= page; i++ )
	{
		sheet[i].frr = t++;
		sheet[i].bkl = t++;
	}

	c = 0;
	i = page;
	while( t <= n )
	{
		if( c == 0 )
		{
			sheet[i].bkr = t++;	
			c++;
		}
		else
		{
			sheet[i--].frl = t++;
			c = 0;
		}
	}
	return page;
}
int main()
{
	int i,n,page;
	while(scanf("%d",&n) && n != 0 )
	{
		printf("Printing order for %d pages:\n",n);
		page = fill_sheet(n);
		for( i = 1; i <= page; i++ )
		{
			if( sheet[i].frl > 0 && sheet[i].frr > 0 )	
				printf("Sheet %d, front: %d, %d\n",
					i,sheet[i].frl,sheet[i].frr);
			if( sheet[i].frl < 0 && sheet[i].frr > 0 )
				printf("Sheet %d, front: Blank, %d\n",
					i,sheet[i].frr);
			if( sheet[i].frl > 0 && sheet[i].frr < 0 )
				printf("Sheet %d, front: %d, Blank\n",
					i,sheet[i].frl);

			if( sheet[i].bkl > 0 && sheet[i].bkr > 0 )	
				printf("Sheet %d, back : %d, %d\n",
					i,sheet[i].bkl,sheet[i].bkr);
			if( sheet[i].bkl < 0 && sheet[i].bkr > 0 )
				printf("Sheet %d, back : Blank, %d\n",
					i,sheet[i].bkr);
			if( sheet[i].bkl > 0 && sheet[i].bkr < 0 )
				printf("Sheet %d, back : %d, Blank\n",
					i,sheet[i].bkl);
		}
	}
	return 0;
}
