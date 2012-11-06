#include<math.h>
#include<stdio.h>
int get_int( int X )
{
	double t = sqrt( 8*X+1 );
	double root_one = (t-1)/2;
	double root_two = ( t-3)/2;
	int up = (int)( root_one );
	int down = (int)(root_two);
	return  ( (double)up <= root_one && (double)up>=root_two )?up:down;
}
int main()
{
	int test_case;
	int i,j;
	int num;
	int X;
	scanf("%d",&test_case);
	getchar();
	scanf("%d",&num);
	while( num != 0 )
	{
		X = get_int(num);
		/*printf("X=%d,one=%d,num=%d\n",X,X*(X+1)/2,num );*/
		printf("%d %d\n",num,X*(X+1)*(2*X+1)/6+(num-X*(X+1)/2)*(X+1));
		scanf("%d",&num);
	}
	for( i = 1; i < test_case; i++ )
	{
		getchar();
		printf("\n");
		scanf("%d",&num);
		while( num != 0 )
		{
			X = get_int(num);
			/*printf("X=%d,one=%d,num=%d\n",X,X*(X+1)/2,num );*/
			printf("%d %d\n",num,X*(X+1)*(2*X+1)/6+(num-X*(X+1)/2)*(X+1));
			scanf("%d",&num);
		}

	}
	return 0;
}
