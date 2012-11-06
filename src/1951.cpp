#include<cstdio>
#define SIZE 1000000
using namespace std;
bool Prime[SIZE+1];
void Init()
{
	Prime[0]=Prime[1]=false;
	for( unsigned int i = 2; i < SIZE+1;i++ )
		Prime[i] = true;
	for( unsigned int i = 2; i < SIZE+1; i++ )
	{
		if( Prime[i]== true )
			for( unsigned int  j = 2; j*i < SIZE+1; j++ )
					Prime[j*i] = false;
	}
}

int main()
{
	int Num;
	int i;
	scanf("%d",&Num);
	Init();
	while( Num != 0 )
	{
		for( i = 3; i < Num/2+1; i++ )
			if( Prime[i]== true && Prime[Num-i] == true )
				break;
		if( i < Num )
			printf("%d = %d + %d\n",Num,i,Num-i);
		else
			printf("Goldbach\n");
		scanf("%d",&Num);
	}
	return 0;
}
