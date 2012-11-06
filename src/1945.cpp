#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define LINE_LEN 256 

char line[LINE_LEN];

double eat( const char* line )
{
	int idx;
	double ret;
	char value[16];
	if( line[1] != '=' )			
		return -1;
	for( idx = 2; (line[idx] >= '0' && line[idx] <= '9')||line[idx] == '.'; idx++ )
		value[idx-2] = line[idx];
	value[idx-2] = 0;
	ret = atof(value);
	switch( line[idx] )
	{
		case 'm':
			ret /= 1000;
			break;
		case 'k':
			ret *= 1000;
			break;
		case 'M':
			ret *= 1000000;
		default:
			break;
	}
	return ret;
}
void do_work( const char* line, double& I,double& P,double& U)
{
	int i;	
	I = P = U = -1;
	for( i = 0; line[i] != 0; i++ )
	{
		switch( line[i] )	
		{
			case 'I':
				I = eat(line+i);
				break;
			case 'P':
				P = eat(line+i);
				break;
			case 'U':
				U = eat(line+i);
				break;
			default:
				break;
		}
		if( ( I >= 0 && P >= 0 )||
			( P >= 0 && U >= 0 )||
			( I >= 0 && U >= 0 ))
			break;
	}
}
int main()
{
	int n,i;
	double I,P,U;	
	scanf("%d",&n);	
	getchar();
	for( i = 1; i <= n; i++ )
	{
		gets(line);
		printf("Problem #%d\n",i);
		do_work(line,I,P,U);
		if( I < 0 )
			printf("I=%0.2lfA\n\n",P/U);	
		else if( P < 0 )
			printf("P=%0.2lfW\n\n",U*I);
		else
			printf("U=%0.2lfV\n\n",P/I);
	}
	return 0;
}
