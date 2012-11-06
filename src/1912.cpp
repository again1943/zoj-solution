#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define EQUA_LEN 256

char equa_one[EQUA_LEN];
char equa_two[EQUA_LEN];
char copy_equ[EQUA_LEN];

struct equation_t
{
	int x;
	int y;
	int c;
}equation[2];

struct ret_t
{
	int up_x;
	int dw_x;
	int up_y;
	int dw_y;
	bool x_;
	bool y_;
};

void format_print( ret_t& ret )
{
	if( ret.x_ == false )
		printf("don't know\n");
	else if( ret.up_x == 0 )
		printf("0\n");
	else if( ret.dw_x == 1 )
		printf("%d\n",ret.up_x);
	else
		printf("%d/%d\n",ret.up_x,ret.dw_x);

	if( ret.y_ == false )
		printf("don't know\n");	
	else if( ret.up_y == 0 )
		printf("0\n");
	else if( ret.dw_y == 1 )
		printf("%d\n",ret.up_y);
	else
		printf("%d/%d\n",ret.up_y,ret.dw_y);
}

int GCD( int a, int b)
{
	int temp;
	int max_ = max(a,b);
	int min_ = min(a,b);
	while( max_ % min_ != 0 )
	{
		temp = min_;
		min_ = max_%min_;
		max_ = temp;
	}
	return min_;
}

ret_t solve( equation_t& a, equation_t& b )
{
	int gcd,sign;
	ret_t ret;
	int t1,t2;		

	if( a.x == 0 && a.y == 0 && b.y == 0 && b.x == 0 )
	{
		ret.x_ = ret.y_ = false;
		return ret;
	}
	else if( a.x != 0 && a.y == 0 && b.x == 0 && b.y == 0 )
	{
		if( b.c != 0 )
		{
			ret.x_ = ret.y_ = false;
			return ret;
		}
		ret.y_ = false;		
		t1 = a.x;
		t2 = a.c;
		ret.x_ = true;
		if( t2 == 0 )
			ret.up_x = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_x = t1;
			ret.up_x = sign < 0? -t2:t2;
		}
		return ret;
	}
	else if( a.x == 0 && a.y != 0 && b.x == 0 && b.y == 0 )
	{

		if( b.c != 0 )
		{
			ret.x_ = ret.y_ = false;
			return ret;
		}
		ret.x_ = false;		
		t1 = a.y;
		t2 = a.c;
		ret.y_ = true;
		if( t2 == 0 )
			ret.up_y = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_y = t1;
			ret.up_y = sign < 0? -t2:t2;
		}
		return ret;
	}
	else if( a.x == 0 && a.y == 0 && b.x != 0 && b.y == 0 )
	{

		if( a.c != 0 )
		{
			ret.x_ = ret.y_ = false;
			return ret;
		}
		ret.x_ = true;		
		t1 = b.x;
		t2 = b.c;
		ret.y_ = false;
		if( t2 == 0 )
			ret.up_x = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_x = t1;
			ret.up_x = sign < 0? -t2:t2;
		}
		return ret;
	}
	else if( a.x == 0 && a.y == 0 && b.x == 0 && b.y != 0 )
	{

		if( a.c != 0 )
		{
			ret.x_ = ret.y_ = false;
			return ret;
		}
		ret.y_ = true;		
		t1 = b.y;
		t2 = b.c;
		ret.x_ = false;
		if( t2 == 0 )
			ret.up_y = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_y = t1;
			ret.up_y = sign < 0? -t2:t2;
		}
		return ret;
	}
	else if( a.x == 0 && b.x == 0 && b.y != 0 && a.y != 0 )
	{
		if( a.y*b.c != a.c*b.y )				
		{
			ret.x_ = ret.y_ = false;
			return ret;

		}
		ret.y_ = true;		
		t1 = b.y;
		t2 = b.c;
		ret.x_ = false;
		if( t2 == 0 )
			ret.up_y = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_y = t1;
			ret.up_y = sign < 0? -t2:t2;
		}
		return ret;
	}
	else if( a.x != 0 && b.x != 0 && b.y == 0 && a.y == 0 )
	{
		if( a.x*b.c != a.c*b.x )				
		{
			ret.x_ = ret.y_ = false;
			return ret;

		}
		ret.x_ = true;		
		t1 = b.x;
		t2 = b.c;
		ret.y_ = false;
		if( t2 == 0 )
			ret.up_x = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_x = t1;
			ret.up_x = sign < 0? -t2:t2;
		}
		return ret;
	}
	t1 = a.x*b.y-b.x*a.y;
	t2 = a.c*b.y-b.c*a.y;
	if( t1 == 0 )		
		ret.x_ = false;
	else
	{
		ret.x_ = true;
		if( t2 == 0 )
			ret.up_x = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_x = t1;
			ret.up_x = sign < 0? -t2:t2;
		}
	}

	t1 = a.y*b.x-b.y*a.x;
	t2 = a.c*b.x-b.c*a.x;
	if( t1 == 0 )		
		ret.y_ = false;
	else
	{
		ret.y_ = true;
		if( t2 == 0 )
			ret.up_y = 0;
		else
		{
			sign = t1*t2;
			gcd = GCD(abs(t1),abs(t2));
			t1 = abs(t1)/gcd;
			t2 = abs(t2)/gcd;
			ret.dw_y = t1;
			ret.up_y = sign < 0? -t2:t2;
		}
	}
	return ret;
}

int eat_num( char* e , int& pos )
{
	int ret = 0;
	while( e[pos] >= '0' && e[pos] <= '9')
		ret  = ret*10+e[pos++]-'0';
	return ret;
}
void fill_equ( char* equa, equation_t& equation )
{
	int i,idx,mid,d,sign;	
	strcpy(copy_equ,equa);
	for( i = idx = 0; copy_equ[i] != 0; i++ ) 
	{
		if( copy_equ[i] != ' ' )
			equa[idx++] = copy_equ[i];
		if( copy_equ[i] == '=' )
			mid = idx-1;
	}
	equa[idx] = 0;

	sign = 1;
	i = d = 0;
	equation.x = equation.y = equation.c = 0;
	while( i < mid )
	{
		if( equa[i] == '-' )						
		{
			if( i == 0 || equa[i-1] != '-' )	
				sign = 0;
			else
				sign = 1;
			i += 1;
		}
		else if( equa[i] == '+' )
		{
			sign = 1;	
			i += 1;
		}
		else if( equa[i] == 'x' )
		{
			equation.x += (sign == 1)?1:-1;		
			sign = 1;
			i += 1;
		}
		else if( equa[i] == 'y' )
		{
			equation.y += (sign == 1)?1:-1;
			sign = 1;
			i += 1;
		}		
		else
		{
			d = eat_num(equa,i);
			if( equa[i] == 'x' )
			{
				equation.x += (sign == 1)?d:-d;
				i += 1;
			}
			else if( equa[i] == 'y' )
			{
				equation.y += (sign == 1)?d:-d;
				i += 1;
			}
			else
				equation.c -= (sign == 1)?d:-d;
			sign = 1;
		}
	}

	sign = 1;
	i = mid+1;
	while( i < idx )
	{
		if( equa[i] == '-' )						
		{
			if( i == 0 || equa[i-1] != '-' )	
				sign = 0;
			else
				sign = 1;
			i += 1;
		}
		else if( equa[i] == '+' )
		{
			if( i > 0 && equa[i-1] == '-' )
				sign = 0;
			else
				sign = 1;	
			i += 1;
		}
		else if( equa[i] == 'x' )
		{
			equation.x -= (sign == 1)?1:-1;		
			sign = 1;
			i += 1;
		}
		else if( equa[i] == 'y' )
		{
			equation.y -= (sign == 1)?1:-1;
			sign = 1;
			i += 1;
		}		
		else
		{
			d = eat_num(equa,i);
			if( equa[i] == 'x' )
			{
				equation.x -= (sign == 1)?d:-d;
				i += 1;
			}
			else if( equa[i] == 'y' )
			{
				equation.y -= (sign == 1)?d:-d;
				i += 1;
			}
			else
				equation.c += (sign == 1)?d:-d;
			sign = 1;
		}
	}
}
int main()
{
	int n,i;
	ret_t ret;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		if( i != 0 )
			printf("\n");
		while( gets(equa_one) && equa_one[0] == 0 );
		while( gets(equa_two) && equa_two[0] == 0 );
		fill_equ(equa_one,equation[0]);
		fill_equ(equa_two,equation[1]);
		ret = solve(equation[0],equation[1]);
		format_print(ret);
	}
	return 0;
}

