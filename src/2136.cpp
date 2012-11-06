#include<stdio.h>
#define SIZE 1001

int max_value( int* X, int size )
{
	int elem[SIZE+1];
	int first,last, middle;
	int length;
	int i;
	elem[0] = -1;
	elem[1] = X[0];
	length = 1;
	for( i = 1; i < size; i++ )
	{
		first = 0;
		last = length;
		while( first <= last )
		{
			middle = (first+last)/2;
			if( elem[middle] < X[i] )
				first = middle+1;
			else
				last = middle-1;
		}
		elem[first] = X[i];
		if( first > length )
			length++;
	}
	return length;
}
int main()
{
	int X[SIZE];
	int i,j;
	int size,test_case;
	scanf("%d",&test_case);
	getchar();
	scanf("%d",&size);
	for( j = 0; j < size; j++ )
		scanf("%d",X+j);
	printf("%d\n", max_value( X, size ) );
	for( i = 1; i < test_case; i++ )
	{
		getchar();
		scanf("%d",&size);
		for( j = 0; j < size; j++ )
			scanf("%d",X+j);
		printf("\n%d\n", max_value( X, size ) );
	}
	return 0;
}
