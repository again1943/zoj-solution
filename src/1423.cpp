#include<cstdio>
#include<cstring>
using namespace std;
#define LINE_LEN 256
char line[LINE_LEN];
char trip[LINE_LEN];
int index_;

void trip_blank( char* line )
{
	int a = 0;	
	int b = 0;
	while( line[b] != 0 )
	{
		if( line[b] == ' ' )	
			b += 1;
		else
			line[a++] = line[b++];
	}
	line[a] = 0;
}
int work( char* line, int pos )
{
	char elem;
	int left,tag;
	int size = strlen(line);
	while( line[pos] != 0 )		
	{
		if( (line[pos] >= 'A' && line[pos] <= 'Z')||
			line[pos] == '-' || line[pos] == '+' )	
			trip[index_++] = line[pos++];	
		else if( line[pos] == ')' )
			return pos;
		//only '(' left here 
		else
		{
			if( pos == 0 
				|| line[pos-1] == '(' 
				|| line[pos-1] == '+'
				|| (pos+2 < size && line[pos-1] == '-' && line[pos+2] == ')'))
				pos = work(line,pos+1) + 1;
			else if(pos+1 < size && line[pos-1] == '-' && line[pos+1] == '(' )
			{
				tag = pos+1;					
				left = 1;
				while( line[tag] == '(' )
				{
					left += 1;
					tag += 1;
				}
				elem = line[tag];
				tag += 1;
				while( tag < size && left != 0 && line[tag] == ')')
				{
					left -= 1;
					tag += 1;
				}
				if( left == 0 )
				{
					pos = tag;
					trip[index_++] = elem;
				}
				else
				{
					trip[index_++] = line[pos];
					pos = work(line,pos+1);
					trip[index_++] = line[pos++];
				}
			}
			else
			{
				trip[index_++] = line[pos];
				pos = work(line,pos+1);
				trip[index_++] = line[pos++];
			}	
		}
	}
	trip[index_] = 0;
	return pos;	
}
int main()
{
	int m,i;	
	scanf("%d",&m);
	getchar();
	for( i = 0; i < m; i++ )
	{
		gets(line);
		index_ = 0;
		trip_blank(line);
		work(line,0);
		printf("%s\n",trip);
	}
	return 0;
}
