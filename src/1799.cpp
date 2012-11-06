/*
 * =====================================================================================
 *
 *       Filename:  1799.cpp
 *
 *    Description:  solution to zoj 1799
 *
 *        Version:  1.0
 *        Created:  2007年05月17日 20时21分05秒 CST
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
#include<algorithm>
#include<utility>

#define KEYWORD_LEN 20
#define TEXT_LEN 120

using namespace std;

struct elem_t
{
	char c;
	int pos;
};

elem_t keyword[KEYWORD_LEN];
char key[KEYWORD_LEN];
char text[TEXT_LEN];
char output[TEXT_LEN];
int main()
{
	int n,len;
	elem_t elem;
	while( scanf("%s",key) && strcmp(key,"THEEND") != 0 )	
	{
		scanf("%s",text);
		len = strlen(text);
		for(  n = 0; key[n] != '\0'; n++ )
		{
			elem.c = key[n];
			elem.pos = n;
			keyword[n] = elem;
		}
		
		for( int i = 0; i < n; i++ )
		for( int j = i+1; j < n;j++ )
		{
			if( keyword[i].c > keyword[j].c )
				swap(keyword[i],keyword[j]);
			else
			{
				if( keyword[i].pos > keyword[j].pos)
					swap(keyword[i],keyword[j]);
			}
		}

		int col = n;
		int row = len/n;
		for( int i = 0;i < n; i++ )
		{
			for( int j = 0;j < row; j++ )
				output[j*col+keyword[i].pos] = text[i*row+j];
		}
		output[len] = '\0';
		printf("%s\n",output);

	}
	return 0;
}
