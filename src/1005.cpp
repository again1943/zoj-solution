#include<cstdio>
using namespace std;

int main()
{
	int x,y,z;
	int A,B;
	while(scanf("%d%d%d",&x,&y,&z) != -1)
	{
		A = B = 0;
		while( B != z )		
		{
			A = x;	
			printf("fill A\n");
			B += A;	
			if( B > y )
			{
				B -= y;
				printf("pour A B\nempty B\npour A B\n");
			}
			else
				printf("pour A B\n");	
		}
		printf("success\n");
	}
	return 0;
}
