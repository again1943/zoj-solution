/*
 * =====================================================================================
 *
 *       Filename:  1969.cpp
 *
 *    Description:  solution to zoj 1969
 *
 *        Version:  1.0
 *        Created:  2007年10月25日 13时59分49秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
#define SIZE 50

char line[SIZE];

char* to_string( int n )
{
	int idx = 0;
	static char ret_str[20];
	if( n == 0 )
	{
		ret_str[0] = '0';
		ret_str[1] = '\0';
		return ret_str;
	}
	while( n != 0 )
	{
		ret_str[idx++] = n%10 + '0';	
		n /= 10;
	}
	ret_str[idx] = '\0';
	return ret_str;
}
bool test_true( char* line)
{
	int i,j;
	char* c;
	char x[20],y[20],z[20];		
	for( i = 0; line[i] != '+'; i++ )
		x[i] = line[i];
	x[i] = '\0';
	reverse(x,x+i);

	for( j = 0,i += 1; line[i] != '='; i++,j++ )
		y[j] = line[i];
	y[j] = '\0';
	reverse(y,y+j);

	strcpy(z,line+i+1);
	
	c = to_string(atoi(x)+atoi(y));
	i = j = strlen(z);	
	while( z[j-1] == '0' && j > 1 ) 
		j--;
	z[j] = '\0';
	return strcmp(c,z) == 0 ? true:false;
}

int main()
{
	while( scanf("%s",line) != -1 )
		printf("%s\n",test_true(line)?"True":"False");
	return 0;
}

