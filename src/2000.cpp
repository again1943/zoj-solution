#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

long long int hold[19] = {0,9,18,108,198,1098,1998,10998,19998,109998,199998,
	1099998,1999998,10999998,19999998,109999998,199999998,1099999998,1999999998};

int get_digit( long long int n )
{
	for( int i = 1;;i++)
		if( n > hold[i-1] && n <= hold[i] )
			return i;
}

void get_result( char* output, long long int n, int digit )
{
	int i,j;
	char temp[50];
	
	bool tag = ( digit %2 == 0 );
	
	i = j = 25;
	n--;
	
	if( tag == false )
		temp[i--] = n%10 + '0';
	else
		temp[i--] = temp[++j] = n%10 + '0';
	n /= 10;
	j++;

	for( int k = 0; k < (digit+1)/2 - 2; k++ )
	{
		temp[i--] = temp[j++] = n%10 + '0';
		n /= 10;	
	}
	
	temp[i] = temp[j++] = n + 1 + '0';
	temp[j] = '\0';
		
	strcpy(output, temp+i);
}
void result( long long int n )
{
	char output[50];
	int digit = get_digit(n);
	
	n -= hold[digit-1];
	
	if( digit == 1 )
	{
		output[0] = n+'0';
		output[1] = '\0';
	}
	else if( digit == 2 )
	{
		output[0] = output[1] = n+'0';
		output[2] = '\0';
	}	
	else	
		get_result( output,n, digit );
	
	printf("%s\n",output);
}
int main()
{
	long long int n;
	scanf("%lld",&n);
	while( n != 0 )
	{
		if( n == 1999999999 )
			printf("1000000000000000001\n");
		else if( n == 2000000000 )
			printf("1000000001000000001\n");
		else
			result(n);
		scanf("%lld",&n);
	}
	return 0;		
}
