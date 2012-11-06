/*
 * =====================================================================================
 *
 *       Filename:  1006.cpp
 *
 *    Description:  solution to zoj 1006
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 08时57分51秒 CST
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
#define SIZE 71
using namespace std;

char ciphertext[SIZE];
char plaintext[SIZE];

inline int get_code(char c )
{
	if( c == '_' )
		return 0;
	else if( c == '.' )
		return 27;
	else
		return c-'a'+1;
}
inline char get_char(int code )
{
	if( code == 0 )
		return '_';
	else if( code == 27)
		return '.';
	else
		return 'a'+code-1;
}

int main()
{
	int k,n,i;

	while( scanf("%d",&k ) && k != 0 )
	{
		scanf("%s",ciphertext);
		n = strlen(ciphertext);
		for( i = 0; i < n; i++ ) 
		{
			plaintext[k*i%n] = get_char((get_code(ciphertext[i])+i)%28);
		}
		plaintext[n] = '\0';
		printf("%s\n",plaintext);
	}
	return 0;

}
