#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define CODE_LEN 6
#define WORD_LEN 84
#define WORD_CNT 10004
#define MORSE_LEN 10004

int decode[MORSE_LEN];
int dictlen[WORD_CNT];
char text[MORSE_LEN];
char dict[WORD_CNT][WORD_LEN];

int morse_len[] = 
{
	2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,
	4,3,3,1,3,4,3,4,4,4
};
char morse_code[][CODE_LEN]=
{
	/*ABCD*/".-","-...","-.-.","-..",
	/*EFGH*/".","..-.","--.","....",
	/*IJKL*/"..",".---","-.-",".-..",
	/*MNOP*/"--","-.","----",".--.",
	/*QRST*/"--.-",".-.","...","-",
	/*UVWX*/"..-","...-",".--","-..-",
	/*YZ*/"-.--","--.."
};

int to_morse( char* from, char* to )
{
	int i,idx;
	for( i = idx = 0; from[i] != 0; i++ )
	{
		strcpy(to+idx,morse_code[from[i]-'A']);
		idx += morse_len[from[i]-'A'];
	}
	to[idx] = 0;
	return idx;
}
int morse_decode( char* text, char dict[][WORD_LEN], int n )
{
	int i,j,len;
	memset(decode,0,sizeof(decode));
	len = strlen(text);
	decode[0] = 1;
	for( i = 0; i < len; i++ )
	{
		if( decode[i] == 0 )
			continue;
		for( j = 0; j < n; j++ )
		{
			if( i+dictlen[j] <= len && memcmp(text+i,dict[j],dictlen[j]) == 0 )
				decode[i+dictlen[j]] += decode[i];
		}
	}
	return decode[len];
}
int main()
{
	int i,t,d,n;
	char word[21];
	scanf("%d",&d);
	for( t = 0; t < d; t++ )
	{
		scanf("%s%d",text,&n);
		for( i = 0; i < n; i++ )
		{
			scanf("%s",word);	
			dictlen[i] = to_morse(word,dict[i]);
		}
		printf("%d\n",morse_decode(text,dict,n));
	}
	return 0;
}
