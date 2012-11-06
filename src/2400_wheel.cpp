#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

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

int primes[18] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};

//#define long_num(i) ( ((1ll)<<(primes[i]))-1)
inline long long long_num( int i)
{
	return (1ll<<primes[i])-1;
}
long long winness(long long a, long long i,long long n)
{
	long long x,y;
	if( i == 0 )
		return 1;
	x = winness(a,i/2,n);

	if( x == 0 )
		return 0;
	y = (x*x)%n;

	if( y == 1 && x != 1 && x != n-1 )
		return 0;
	if( i %2 != 0 )
		y = (a*y)%n;
	return y;
}

bool is_prime( long long n)
{
	srandom(0);	
	return (winness((long long)rand(),n-1,n) == 1);
}

int defact (long long n0, int max_n_factors, long long *factors)
{
	long long n = n0, d, q;
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

/*void defact(long long n, vector<long long>& fact)
{
	size_t w = 0;
	long long s;
	size_t END = sizeof(wheel)/sizeof(int);

	s = 2;
	while( n != 1 )
	{
		while( n%s == 0 )
		{
			n /= s;
			fact.push_back(s);
		}
		s += wheel[w++];
		if( w == END)
			w = 0;
	}


}*/
int main()
{
	int n,size;
	long long fact[50];
	cin >> n;
	
	for( int i = 0; primes[i] <= n && i < 17; i++ )
	{
		if( is_prime(long_num(i)) == false )
		{
			size = defact(long_num(i),50,fact);
			
			cout << fact[0];
			for( int j = 1; j < size; j++ )
				cout << " * " << fact[j];
			cout << " = " << long_num(i) << " = "
				<< "( 2 ^ " << primes[i] << " ) - 1" << endl;
		}
	
	}
	
	return 0;
}

