#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define EXP_LEN 64 
char expression[EXP_LEN]; 

inline bool eval( bool a,bool b, char op )
{
	switch( op )
	{
		case '&':	
			return a&&b;
		case '|':
			return a|b;
		default:	
			return !a;	
	}
}
inline bool value( char c )
{
	if( c == 'V' )
		return true;
	else
		return false;
}

bool evaluate( char* exp, int& pos )
{
	char op = 0;
	bool left = false;
	bool right = false;
	while( exp[pos] != 0 )
	{
		switch( exp[pos] )	
		{
			case '(':
				pos += 1;
				right = evaluate(exp,pos);
				if( op == 0 )
					left = right;
				else
					left = eval(left,right,op);	
				op = 0;
				break;	
			case ')':
				pos += 1;
				return left;
			case '!':
				while( exp[pos] == ' ' )
					pos += 1;
				pos += 1;
				if( exp[pos] != '(' )
				{
					right = !value(exp[pos]);
					pos += 1;
				}
				else
				{
					pos += 1;
					right = !evaluate(exp,pos);
				}
				if( op == 0 )
					left =right;
				else
					left = eval(left,right,op);
				op = 0;
				break;
			case '&':
			case '|':
				op = exp[pos];
				pos += 1;
				break;
			case 'F':
			case 'V':
				right = value(exp[pos]);			
				if( op == 0 )
					left = right;
				else
					left = eval(left,right,op);
				pos += 1;
				op = 0;
				break;
			default:
				pos += 1;
				break;
		}
	}
	return left;
}
int main()
{
	int t = 0;
	int pos = 0;
	while( gets(expression) != NULL )
	{
		printf("Expression %d: %c\n",++t,evaluate(expression,pos)?'V':'F');	
		pos = 0;
	}
	return 0;
}
