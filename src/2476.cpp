#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define MAX_LEN 32

char line[MAX_LEN];

double convert_f( char* line )
{
	int i,j;
	char copy[MAX_LEN];	
	for( i = j = 0; line[i] != 0; i++ )
	{
		if( line[i] != '$' && line[i] != ',' )
			copy[j++] = line[i];
	}
	copy[j] = 0;
	return atof(copy);
}

double convert_s( char* line, double value )
{
	char x;
	int i,j,c;
	char copy[MAX_LEN];
	sprintf(copy,"%0.2lf",value);
	i = strlen(copy);
	line[0] = copy[i-1];
	line[1] = copy[i-2];
	line[2] = copy[i-3];
	for( i = i-4,c = 0,j = 3; i >= 0; i-- )
	{
		line[j++] = copy[i];	
		c += 1;
		if( c == 3 )
		{
			line[j++] = ',';	
			c = 0;
		}
	}
	if( line[j-1] == ',' )
		line[j-1] = '$';
	else
		line[j++] = '$';
	line[j] = 0;
	for( i = 0, j = j-1; i < j; i++,j-- )
	{
		x = line[i];
		line[i] = line[j];
		line[j] = x;
	}
}
int main()
{
	int n,i;
	double value;
	while( scanf("%d",&n) && n != 0 )
	{
		value = 0;	
		for( i = 0; i < n; i++ )
		{
			scanf("%s",line);
			value += convert_f(line);
		}
		convert_s(line,value);
		printf("%s\n",line);
	}
	return 0;
}
