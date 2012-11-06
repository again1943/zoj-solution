#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define SIZE 26
#define BUF_SIZE 256

char buf[BUF_SIZE];
int A[SIZE],B[SIZE],C[SIZE];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int main()
{
	int* p;
	int i,idx,sum,carry;
	while( gets(buf) != NULL )	
	{
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));

		for( i = sum = idx = 0,p = A; buf[i] != 0; i++ )
		{
			if( buf[i] >= '0' && buf[i] <= '9' )
				sum = sum*10 + buf[i]-'0';
			if( buf[i] == ',' )
			{
				p[idx++] = sum;	
				sum = 0;
			}
			if( buf[i] == ' ' )
			{
				p[idx++] = sum;
				p = B;
				reverse(A,A+idx);
				sum = idx = 0;
			}
		}
		p[idx++] = sum;
		reverse(B,B+idx);
		for( i = carry = 0; i < SIZE; i++ )
		{
			carry += A[i]+ B[i];
			if( carry >= prime[i] )
			{
				C[i] = carry-prime[i];
				carry = 1;
			}
			else
			{
				C[i] = carry;
				carry = 0;
			}
		}
		for( i = 25; i >= 0 && C[i] == 0; i-- );
		printf("%d",C[i--]);
		while( i >= 0 )
			printf(",%d",C[i--]);
		printf("\n");
	}
	return 0;
}
