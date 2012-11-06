#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define STR_LEN 16

char result[STR_LEN];
char addend[2][STR_LEN];

//useful m,c,x,i
int factor[26] = 
{
0,0,100,0,0,0,0, //ABCDEFG
0,1,0,0,0,1000,0,//HIJKLMN
0,0,0,0,0,0,0,//OPQRSTU
0,0,10,0,0//VWXYZ
};

int toval( char* str )
{
	int i = 0;
	int retval = 0;
	while( str[i] != 0 )
	{
		if( str[i] >= '2' && str[i] <= '9' )
		{
			retval += (str[i]-'0')*factor[str[i+1]-'a'];
			i += 2;
		}
		else if( str[i] >= 'a' && str[i] <= 'z' && factor[str[i]-'a'] != 0)
		{
			retval += factor[str[i]-'a'];	
			i += 1;
		}
		else
			return -1;
	}
	return retval;
}
void tostr( char* str, int val )
{
	int idx = 0;		
	if( val/1000 != 0 )
	{
		if( val/1000 > 1 )
			str[idx++] = val/1000+'0';	
		str[idx++] = 'm';
		val %= 1000;
	}
	if( val/100 != 0 )
	{
		if( val/100 > 1 )
			str[idx++] = val/100+'0';
		str[idx++] = 'c';
		val %= 100;
	}
	if( val/10 != 0 )
	{
		if( val/10 > 1 )
			str[idx++] = val/10+'0';
		str[idx++] = 'x';
		val %= 10;
	}
	if( val != 0 )
	{
		if( val > 1 )
			str[idx++] = val+'0';
		str[idx++] = 'i';
	}
	str[idx++] = 0;
}
int main()
{
	int n,i,temp;
	for( scanf("%d",&n),i = 0; i < n; i++ )
	{
		scanf("%s%s",addend[0],addend[1]);
		temp = toval(addend[0])+toval(addend[1]);
		tostr(result,temp);
		printf("%s\n",result);
	}
	return 0;
}


