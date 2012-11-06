/*
 * =====================================================================================
 *
 *       Filename:  2584.cpp
 *
 *    Description:  solution to zoj 2584
 *
 *        Version:  1.0
 *        Created:  2007年04月29日 04时01分25秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 320
#define QUERY 1001

using namespace std;
char big_number[QUERY][MAX];
char factor[MAX];

void mutilby2(char* fac )
{
	char* p;
	int temp = 0;
	int carry = 0;	
	for( p = fac; *p != '\0'; p++ )
	{
		temp = carry + ((*p-'0')<<1);	
		carry  = temp/10;
		temp = temp%10;
		*p = temp+'0';
	}
	if( carry != 0 )
	{
		*p++ = carry+'0';
		*p = '\0';
	}
}
void add(char* a,char* b,char* c)
{
	char*p = a;
	char*q = b;
	char*r = c;

	int temp = 0;
	int carry = 0;

	while( *p != '\0' && *q != '\0' )
	{
		temp = carry + (*p-'0')+(*q-'0');	
		carry = temp/10;
		temp = temp%10;
		*r++ = temp+'0';
		p++;
		q++;
	}
	p = (*p == '\0')?q:p;

	while( *p != '\0' )
	{
		temp = carry + (*p-'0');	
		carry = temp/10;
		temp = temp%10;
		*r++ = temp+'0';
		p++;
	}
	if( carry != 0 )
	{
		*r++ = carry+'0';
		*p = '\0';
	}

}
inline void output(int index )
{
	int n = strlen(big_number[index]);	
	while( --n >= 0 )
		putchar(big_number[index][n]);
	putchar('\n');
}

void compute_big_number()
{
	strcpy(big_number[0],"0");
	strcpy(big_number[1],"1");
	strcpy(factor,"1");
	for( int i = 2; i < QUERY; i++ )
	{
		add(big_number[i-2],factor,big_number[i]);
		mutilby2(factor);
	}
}

int main()
{
	int index;
	compute_big_number();	
	while( scanf("%d",&index) != -1 )
	{
		if( index > 1 )
			output(index-1);
		else
			printf("0\n");
	}
	return 0;

}

