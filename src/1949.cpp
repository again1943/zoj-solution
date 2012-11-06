#include<cstdio>
#define SIZE 100
using namespace std;
int Row[SIZE];
int Col[SIZE];
inline void init()
{
	for( int i = 0; i < SIZE; i++ )
		Col[i] = 1;
}
int main()
{
	int Size;
	int Parity;
	int C;
	scanf("%d",&Size);
	while( Size != 0 )
	{
		init();
		int flag = 0;
		int x,y;
		int xtime,ytime;
		for( int i = 0; i < Size; i++ )
		{
			Parity = 1;
			for( int j = 0; j < Size; j++ )
			{
				scanf("%d",&C);
				if( C == 1 )
				{
					Col[j] = -Col[j];
					Parity = -Parity;
				}
			}
			Row[i] = Parity;
		}
		xtime = ytime = 0;
		for( int i = 0; i < Size; i++ )
		{
			if( Row[i] < 0 )
			{
				xtime++;
				x=i;
			}
			if( Col[i] < 0 )
			{
				ytime++;
				y = i;
			}
		}
		if( xtime == 0 && ytime == 0 )
			printf("OK\n");
		else if( xtime == 1 && ytime == 1 )
			printf("Change bit (%d,%d)\n",x+1,y+1);
		else
			printf("Corrupt\n");
		scanf("%d",&Size);

	}
	return 0;
}
