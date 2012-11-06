#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define OP_LEN 1024

char integer[OP_LEN];
char decimal[OP_LEN];
char result[2][OP_LEN];

size_t multiply(char* input,size_t insize, int base)
{
	size_t i,value,carry;
	for( i = carry = 0; i < insize; i++ )
	{
		value = (input[i]-'0')*base+carry;
		carry = value/10;
		input[i] = value%10+'0';
	}
	while( carry > 0 )
	{
		input[insize++] = carry%10+'0';
		carry /= 10;
	}
	input[insize] = 0;
	return insize;
}
int defact(int base,char* input)
{
	int size,power;
	result[1][0] = '1';
	result[1][1] = 0;
	size = 1;
	power = 0;
	while( strcmp(result[1],input) != 0 )
	{	
		size = multiply(result[1],size,base);
		power += 1;
	}
	return power;
}
int factor(int base, int power,char* output)
{
	int i,t,size,carry,value;
	size = 1;
	output[0] = '1';
	for( t = 0; t < power; t++ )
	{
		for( i = carry = 0; i < size; i++ )
		{
			value = (output[i]-'0')*base + carry;
			output[i] = value%10+'0';
			carry = value/10;
		}
		while( carry > 0 )
		{
			output[size++] = carry%10+'0';
			carry /= 10;
		}
	}
	output[size] = 0;
	reverse(output,output+size);
	return size;
}
void reciprocal(char* input, char* output)
{
	int i,p;
	int size = strlen(input);
	int zero_count = 0;
	for( i = size-1,zero_count = 0; i >= 0; i-- )
	{
		if( input[i] == '0' )
			zero_count += 1; 
		else
			break;
	}
	memcpy(result[0],input,i+1);
	result[0][i+1] = 0;
	reverse(result[0],result[0]+i+1);
	if( result[0][0] == '5' )
	{
		p = defact(5,result[0]);
		zero_count += p;
		size = factor(2,p,result[0]);
	}
	else
	{
		p = defact(2,result[0]);
		zero_count += p;
		size = factor(5,p,result[0]);
	}
	//reverse(result[0],result[0]+size);
	output[0] = '0';
	output[1] = '.';
	for( i = 0; i < zero_count-size; i++ )
		output[i+2] = '0';
	memcpy(output+i+2,result,size);
	output[i+2+size] = 0;
	
}

int main()
{
	printf("Problem 4 by team x\n");
	while(scanf("%s",integer) != -1)
	{
		printf("\n");
		printf("1 / %s =\n",integer);
		reciprocal(integer,decimal);
		printf("%s\n",decimal);
	}
	printf("End of problem 4 by team x\n");
}