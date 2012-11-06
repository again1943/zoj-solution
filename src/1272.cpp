#include<cstdio>
#include<cstring>
#include<algorithm>

#define MAXN 64

char input[MAXN];
char output[MAXN];
char other[MAXN];

int mul( char* digit, int idx, int n )
{
	int i,val;
	int carry = 0;	
	for( i = 0; i < idx; i++ )
	{
		val = (digit[i]-'0')*n+carry;
		carry = val/10;
		digit[i] = val % 10+'0';
	}
	while( carry != 0 )
	{
		digit[i++] = carry%10+'0';	
		carry /= 10;
	}
	digit[i] = 0;
	return i;
}
int add( char* digit, int idx, int n )
{
	int i,val;
	int carry = 0;
	for( i = 0; i < idx && n != 0; i++ )
	{
		val = carry+n%10+digit[i]-'0';
		carry = val/10;
		digit[i] = val%10+'0';
		n /= 10;
	}
	if( n != 0 )
	{
		while( n != 0 )	
		{
			val = carry+n%10;
			carry = val/10;
			digit[i++] = val%10+'0';
			n /= 10;
		}
	}
	else
	{
		while( i < idx )
		{
			val = carry+digit[i]-'0';	
			carry = val/10;
			digit[i++] = val%10+'0';
		}
	}
	digit[i] = 0;
	return i;
}
int div( char* digit, int idx, int n, int* mod )
{
	int i;
	int val = 0;
	for( i = val = 0; i < idx; i++ )
	{
		val = val*10 + digit[i]-'0';
		digit[i] = val/n+'0';
		val %= n;
	}
	i = 0;
	*mod = val;
	while( digit[i] == '0' )
		i++;
	for( idx = 0; digit[i] != 0; i++ )
		digit[idx++] = digit[i];
	digit[idx] = 0;
	return idx;
}
void digit2word( char* digit, char* word )
{
	int i,val;
	int idx = 0;
	strcpy(other,digit);
	int n = strlen(other);
	while( other[0] != 0 )
	{
		n = div(other,n,26,&val);
		word[idx++] = val+'a'-1;
	}
	word[idx] = 0;
	std::reverse(word,word+idx);
}
void word2digit( char* word, char* digit )
{
	int i,idx;
	int n = strlen(word);
	if( word[0] - 'a' + 1 < 10 )
	{
		digit[0] = word[0]-'a'+1+'0';
		digit[idx = 1] = 0;
	}
	else
	{
		digit[0] = (word[0]-'a'+1)%10+'0';
		digit[1] = (word[0]-'a'+1)/10+'0';
		digit[idx = 2] = 0;
	}
	for( i = 1; i < n; i++ )
	{
		idx = mul(digit,idx,26);		
		idx = add(digit,idx,word[i]-'a'+1);
	}
}
void format( char* digit,bool rev )
{
	int i,idx;
	int n = strlen(digit);
	if( rev == false )
		std::reverse(digit,digit+n);
	strcpy(other,digit);
	for( i = idx = 1; other[i] != 0; i++ )
	{
		if( i % 3 != 0 ) 	
			digit[idx++] = other[i];
		else
		{
			digit[idx++] = ',';
			digit[idx++] = other[i];
		}
	}
	digit[idx] = 0;
	std::reverse(digit,digit+idx);
}
void detail( char* input, char* output )
{
	if( input[0] >= '0' && input[0] <= '9' )		
	{
		digit2word(input,output);	
		format(input,false);
	}
	else
	{
		word2digit(input,output);
		format(output,true);
	}
}
int main()
{
	while( scanf("%s",input) && strcmp(input,"*") != 0 )	
	{
		memset(output,0,sizeof(output));
		detail(input,output);	
		if( input[0] >= '0' && input[0] <= '9' )
			printf("%-22s%s\n",output,input);
		else
			printf("%-22s%s\n",input,output);
	}
	return 0;
}
