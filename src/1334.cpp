/*
 * =====================================================================================
 *
 *       Filename:  1334.cpp
 *
 *    Description:  zoj 1334
 *
 *        Version:  1.0
 *        Created:  2007年10月12日 15时42分13秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstring>
#include<algorithm>
#include<cstdio>

#define SIZE 17
using namespace std;

int base_max_7[SIZE] = {0,0,127,2186,16383,78124,279935,
			823542,2097151,4782968,9999999,
			19487170,35831807,62748516,
			105413503,170859374,268435455 };

char line[SIZE];
char dest[SIZE];

int to_base_10( int base )
{
	int result = 0;	
	int size = strlen(line);
	for( int i = 0; i < size; i++ )
	{
		if( line[i] >= '0' && line[i] <= '9' )	
			result = result*base+(line[i]-'0');
		else
			result = result*base+(line[i]-'A'+10);
	}
	return result;
}
void to_base_dest(int source,int base )
{
	int idx = 0;
	int tmp;
	while( source != 0 )	
	{
		tmp = source%base;
		dest[idx++] = tmp >= 10 ? (tmp-10)+'A':tmp+'0';	
		source /= base;
	}
	dest[idx] = '\0';
	reverse(dest, dest+idx);
}

int main()
{
	int from,to,tmp;
	while( scanf("%s%d%d",line,&from,&to) != -1 )
	{
		tmp = to_base_10(from);			
		if( tmp > base_max_7[to] )
			strcpy(dest,"ERROR");
		else
			to_base_dest(tmp,to);
		tmp = strlen(dest);
		for( int i = 0; i < 7-tmp;i++ )
			printf(" ");
		printf("%s\n",dest);
	}
	return 0;
}

