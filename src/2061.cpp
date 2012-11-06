#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//#define MAX_PEOPLE 128
#define MAX_DIGIT 180
char ticket[MAX_DIGIT];

int divide( char* num,int n )
{
	int value,carry,i;
	int size = strlen(num);						
	for( i = size-1,carry = value = 0; i >= 0; i-- )
	{
		value = (num[i]-'0')+carry*10;
		if( value < n )
			num[i] = '0';
		else
			num[i] = value/n+'0';
		carry = value%n;
	}
	for( i = size; i >= 1 && num[i-1] == '0'; i-- );	
	num[i] = 0;		
	return i;
}
int multiply(char* num,int n )
{
	int i,value,carry;
	for( i = value = carry = 0; num[i] != 0; i++ )	
	{
		value = (num[i]-'0')*n+carry;
		num[i] = value%10+'0';
		carry = value/10;
	}
	while( carry != 0 )	
	{
		num[i++] = carry%10+'0';	
		carry /= 10;
	}
	num[i] = 0;
	return i;
}

/*
void total()
{
	int i,j;	
	memset(ticket,0,sizeof(ticket));
	strcpy(ticket[0][0],"1");
	for( i = 1; i <= 100; i++ )
	{
		multiply(ticket[i-1][0],ticket[i][0],i);
		for( j = 1; j <= i; j++ )
		{
			multiply(ticket[i-1][j-1],ticket[i][j],(i+j-1)*(i+j)*i);
			divide(ticket[i][j],i+1);
		}
	}
}*/

#define STEP_10 3628800
void cal_ticket( char* ticket,int m, int n )
{
	int mul,i,len;
	int total = n+m;
	strcpy(ticket,"1");
	multiply(ticket,STEP_10);
	for( i = 11; i+2 <= total; i += 3 )
	{
		mul = i*(i+1)*(i+2);
		multiply(ticket,mul);
	}
	for( mul = 1; i <= total; i++ )
		mul *= i;
	mul *= (m-n+1);
	multiply(ticket,mul);	
	len = divide(ticket,m+1);
	reverse(ticket,ticket+len);
}
int cal_ticket( int m, int n )
{
	int ret,i;
	for( i = ret = 1; i <= m+n; i++ )
		ret *= i;
	ret *= (m-n+1);
	ret /= (m+1);
	return ret;
}
int main()
{
	int m,n;
	int t = 0;
	while( scanf("%d%d",&m,&n) && ( m != 0 || n != 0 ) )
	{
		printf("Test #%d:\n",++t);	
		if( n > m )
			printf("0\n");
		else
		{
			if( n+m <= 10 )
				printf("%d\n",cal_ticket(m,n));	
			else
			{
				cal_ticket(ticket,m,n);
				printf("%s\n",ticket);
			}
		}
	}
	return 0;
}
