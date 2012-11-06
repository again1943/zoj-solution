#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define OCT_LEN 256

char oct_fac[OCT_LEN];
int dec_fac[OCT_LEN*2];

//0.456=(((6/8)+5)/8+4)/8
int main()
{
	int n,i,j,x,y;
	int idx;
	while( scanf("%s",oct_fac) != -1 )		
	{
		idx = 0;
		n = strlen(oct_fac);	
		for( i = n-1; oct_fac[i] != '.'; i-- )
		{
			x = oct_fac[i]-'0';	
			for( j = 0; j < idx; j++ )
			{
				y = x*10+dec_fac[j];
				dec_fac[j] = y/8;
				x = y%8;
			}
			while( x != 0 )
			{
				y = x*10;	
				dec_fac[idx++] = y/8;
				x = y%8;
			}
		}
		printf("%s [8] = 0.",oct_fac);
		for( i = 0; i < idx; i++ )
			printf("%d",dec_fac[i]);
		printf(" [10]\n");
	}
	return 0;
}
