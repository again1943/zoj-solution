#include<stdio.h>

int main()
{
	char c;
	int sum;
	int pos;
	scanf("%c",&c);
	while( c != '#' )
	{
		sum = (c-'A')+1;
		pos = 1;
		while( ( c = getchar() ) != '\n')
			sum += (++pos)*( c == ' ' ? 0 : c-'A'+1);
		printf("%d\n",sum);
		scanf("%c",&c);
	}
	return 0;
}
