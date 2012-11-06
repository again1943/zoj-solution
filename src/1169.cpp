#include<cstdio>
#include<cstring>
using namespace std;
#define LETTER_TABLE 26
#define SQUARE_TABLE 5
#define MESSAG_LENTH 256

char key[MESSAG_LENTH];
char msg[MESSAG_LENTH];
int table[LETTER_TABLE];
char crypt[MESSAG_LENTH*2];
char square[SQUARE_TABLE][SQUARE_TABLE];

void build_table( char* key, int* table,char square[][SQUARE_TABLE] )
{
	int i,j,x,y;
	for( i = x = y = 0; key[i] != 0; i++ )
	{
		if( key[i] < 'A' || key[i] > 'Z' 
			|| table[key[i]-'A'] != -1 )
			continue;
		if( key[i] == 'I' )// take care of special 'I' and 'J'
		{
			if( table['J'-'A'] != -1 )// if table['J'] set
			{
				table['I'-'A'] = table['J'-'A'];
				continue;
			}
			// if table['J'] not set
		}
		if( key[i] == 'J' )
		{
			if( table['I'-'A'] != -1 )
			{
				table['J'-'A'] = table['I'-'A'];
				continue;
			}
		}
		square[x][y] = key[i];
		table[key[i]-'A'] = x*SQUARE_TABLE+y;
		y += 1;
		if( y == SQUARE_TABLE )
		{
			x += 1;
			y = 0;
		}
	}
	for( i = 0; i < LETTER_TABLE; i++ )
	{
		if( table[i] != -1 )
			continue;
		if( 'A'+i == 'I' )
		{
			if( table['J'-'A'] != -1 )
			{
				table['I'-'A'] = table['J'-'A'];
				continue;
			}
		}
		if( 'A' + i == 'J' )
		{
			if( table['I'-'A'] != -1 )
			{
				table['J'-'A'] = table['I'-'A'];
				continue;
			}
		}
		square[x][y] = 'A'+i;
		table[i] = x*SQUARE_TABLE+y;
		y += 1;
		if( y == SQUARE_TABLE )
		{
			x += 1;
			y = 0;
		}
	}
	for( i = 0; i < SQUARE_TABLE; i++ ) 
	for( j = 0; j < SQUARE_TABLE; j++ )
	{
		if( square[i][j] == 'J' )
		{
			square[i][j] = 'I';
			return;
		}
	}
}
void copymsg( char* msg, char* dst )
{
	int i,j,idx;
	for( i = j = 0; msg[i] != 0; i++ )
	{
		if( msg[i] >= 'A' && msg[i] <= 'Z' )
			msg[j++] = msg[i];
	}
	msg[j] = 0;
	dst[0] = msg[0];
	for( i = idx = 1; msg[i] != 0; i++ )
	{
		if( msg[i] == msg[i-1] || 
			(msg[i] == 'I' && msg[i-1] == 'J')
			||(msg[i] == 'J' && msg[i-1] == 'I'))	
			dst[idx++] = ((msg[i] == 'Q')?'Z':'Q');
		dst[idx++] = msg[i];
	}
	if( idx % 2 != 0 )
		dst[idx++]  = ((msg[i-1] == 'Q')?'Z':'Q');
	dst[idx] = 0;
}
void real_crypt( char* dst,char* crypt, int* table, char square[][SQUARE_TABLE] )
{
	int i,x0,y0,x1,y1,idx;
	for( i = idx = 0; dst[i] != 0; i += 2 )	
	{
		x0 = table[dst[i]-'A']/SQUARE_TABLE;
		y0 = table[dst[i]-'A']%SQUARE_TABLE;
		x1 = table[dst[i+1]-'A']/SQUARE_TABLE;
		y1 = table[dst[i+1]-'A']%SQUARE_TABLE;
		if( idx != 0 )
			crypt[idx++] = ' ';
		if( x0 == x1 )
		{
			crypt[idx++] = square[x0][(y0+1)%SQUARE_TABLE];
			crypt[idx++] = square[x1][(y1+1)%SQUARE_TABLE];
		}
		else if( y0 == y1 )
		{
			crypt[idx++] = square[(x0+1)%SQUARE_TABLE][y0];	
			crypt[idx++] = square[(x1+1)%SQUARE_TABLE][y1];
		}
		else
		{
			crypt[idx++] = square[x0][y1];	
			crypt[idx++] = square[x1][y0];
		}
	}
	crypt[idx] = 0;
}
void encode( char* key, char* msg, char* crypt )
{
	char dst[MESSAG_LENTH];	
	memset(table,-1,sizeof(table));
	build_table(key,table,square);
	copymsg(msg,dst);
#if 0
	printf("%s\n",dst);
#endif
	real_crypt(dst,crypt,table,square);
}
int main()
{
	while( gets(key) && strcmp(key,"999") != 0 )
	{
		gets(msg);
		encode(key,msg,crypt);
		printf("%s\n",crypt);
	}
	return 0;
}
