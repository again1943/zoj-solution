#include<iostream>
#include<utility>
#define MAX_FACTOR 32


int wheel[] =
{		1, 2, 2, 4, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 
		2, 6, 4, 6, 8, 4, 2, 4, 2, 4, 14, 4, 6, 2, 10, 2, 6, 6, 4, 2, 
		4, 6, 2, 10, 2, 4, 2, 12, 10, 2, 4, 2, 4, 6, 2, 6, 4, 6, 6, 6, 
		2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 6, 8, 6, 10, 2, 4, 6, 2, 6, 
		6, 4, 2, 4, 6, 2, 6, 4, 2, 6, 10, 2, 10, 2, 4, 2, 4, 6, 8, 4, 
		2, 4, 12, 2, 6, 4, 2, 6, 4, 6, 12, 2, 4, 2, 4, 8, 6, 4, 6, 2, 
		4, 6, 2, 6, 10, 2, 4, 6, 2, 6, 4, 2, 4, 2, 10, 2, 10, 2, 4, 6, 
		6, 2, 6, 6, 4, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 6, 4, 8, 
		6, 4, 6, 2, 4, 6, 8, 6, 4, 2, 10, 2, 6, 4, 2, 4, 2, 10, 2, 10, 
		2, 4, 2, 4, 8, 6, 4, 2, 4, 6, 6, 2, 6, 4, 8, 4, 6, 8, 4, 2, 
		4, 2, 4, 8, 6, 4, 6, 6, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 
		4, 2, 10, 2, 10, 2, 6, 4, 6, 2, 6, 4, 2, 4, 6, 6, 8, 4, 2, 6, 
		10, 8, 4, 2, 4, 2, 4, 8, 10, 6, 2, 4, 8, 6, 6, 4, 2, 4, 6, 2, 
		6, 4, 6, 2, 10, 2, 10, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 
		6, 6, 6, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 8, 4, 6, 2, 6, 6, 
		4, 2, 4, 6, 8, 4, 2, 4, 2, 10, 2, 10, 2, 4, 2, 4, 6, 2, 10, 2, 
		4, 6, 8, 6, 4, 2, 6, 4, 6, 8, 4, 6, 2, 4, 8, 6, 4, 6, 2, 4, 
		6, 2, 6, 6, 4, 6, 6, 2, 6, 6, 4, 2, 10, 2, 10, 2, 4, 2, 4, 6, 
		2, 6, 4, 2, 10, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 2, 12, 6, 
		4, 6, 2, 4, 6, 2, 12, 4, 2, 4, 8, 6, 4, 2, 4, 2, 10, 2, 10, 6, 
		2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2, 10, 6, 8, 6, 4, 2, 
		4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 6, 4, 6, 2, 6, 4, 2, 4, 2, 
		10, 12, 2, 4, 2, 10, 2, 6, 4, 2, 4, 6, 6, 2, 10, 2, 6, 4, 14, 4, 
		2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 
		4, 2, 4, 12, 2, 12 
};


/* to defact a very large integer number, the factors are in array "factors"*/
int defact (int n0, int max_n_factors, int *factors)
{
	int n = n0, d, q;
  	int n_factors = 0;
  	int w = 0;
  	int END = sizeof(wheel)/sizeof(int);

  	if(n <= 1)
    		return n_factors;
  	d = 2;
  	do
    	{
      		q = n / d;
      		while (n == q * d)
		{
	  		factors[n_factors++] = d;
	  		n = q;
	  		q = n / d;
		}
      		
		d += wheel[w++];
      		
		if (w == END)
			w = 5;
    	}while (d <= q);

  	if (n != 1 || n0 == 1)
      		factors[n_factors++] = n;

  	return n_factors;
}

int get_elem( int e, int n)
{
	int temp = e;	
	int count = 0;
	while( temp < n )
	{
		count += n/temp;
		temp *= e;
	}
	return count;
}

bool divide(int x, int y)
{
	int n;
	int factor[MAX_FACTOR];
	std::pair<int,int> fact[MAX_FACTOR];
	n = defact(y,MAX_FACTOR,factor);
	
	int index = 0;
	fact[index++] = std::make_pair(factor[0],1);
	for( int i = 1;i < n; i++ )
	{
		if( factor[i] == fact[index-1].first )
			fact[index-1].second++;
		else
			fact[index++] = std::make_pair(factor[i],1);
	}
	for( int i = index-1; i >= 0; i-- )
	{
		if( get_elem(fact[i].first,x) < fact[i].second )
			return false;
	}
	return true;
	
}
int main()
{
	int x,y;
	bool status;
	while( std::cin >> x >> y )
	{
		if( x <= 1 )
			status = ((y==1)?true:false);
		else	
		{
			if( y == 0 )
				status = false;
			else if( y == 1 )
				status = true;
			else 
				status = divide(x,y);
		}
		std::cout << y << ( status ==true?" divides ":" does not divide ") 
		 << x << "!" << std::endl;
	}
}
