//takes me so long to AC -_____________-!!
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[3],b[3],r[3];
double A[3],B[3];
int x[3][3];
double y[3][3];

inline int fval( int* b, int x )	
{
	return (x*x*x+b[2]*x*x+b[1]*x+b[0]);
}
void solve_root( int* b, int* r )
{
	int i,j,s,t;
	int value = abs(b[0]);	
	if( value == 0 )
	{
		r[0] = 0;	
		s = b[2];
		t = b[1];
	}
	else
	{
		for( i = 1; i <= value; i++ )	
		{
			if( value%i != 0 )
				continue;
			if( fval(b,i) == 0 )
				break;
			if( fval(b,-i) == 0 )
			{
				i = -i;
				break;
			}
		}
		//find i is one of the value;
		r[0] = i;
		s = b[2]+r[0];
		t = b[1]+r[0]*s;
	}
	r[1] = (int)((-s-sqrt((double)(s*s-4*t)))/2);
	r[2] = (int)((-s+sqrt((double)(s*s-4*t)))/2);
	if( r[1] < r[0] )		
		swap(r[1],r[0]);
	if( r[2] < r[1] )
		swap(r[2],r[1]);
}
void solve( int* a, int* b, int* r, double* A )
{
	int i,j;
	int d,m,n,t;
	solve_root(b,r);
	x[0][0] = x[0][1] = x[0][2] = 1;
	x[1][0] = r[1]+r[2];
	x[1][1] = r[0]+r[2];
	x[1][2] = r[0]+r[1];
	x[2][0] = r[1]*r[2];
	x[2][1] = r[0]*r[2];
	x[2][2] = r[0]*r[1];
	for( i = 0; i < 3; i++ )
	{
		for( j = 0; j < 3; j++ )
			y[i][j] = x[i][j];
	}
	B[0] = a[2];
	B[1] = -a[1];
	B[2] = a[0];
	if( x[0][0] != 0 && x[1][0] != 0 && x[2][0] != 0 )
	{
		y[1][1] = y[1][1]/y[1][0]-1;
		y[1][2] = y[1][2]/y[1][0]-1;
		y[2][1] = y[2][1]/y[2][0]-1;
		y[2][2] = y[2][2]/y[2][0]-1;
		B[1] = B[1]/y[1][0]-B[0];
		B[2] = B[2]/y[2][0]-B[0];
		A[1] = (B[1]*y[2][2]-B[2]*y[1][2])/(y[1][1]*y[2][2]-y[1][2]*y[2][1]);
		A[2] = (B[2]*y[1][1]-B[1]*y[2][1])/(y[1][1]*y[2][2]-y[1][2]*y[2][1]);
		A[0] = B[0]-A[1]-A[2];
	}
	else if( x[0][1] != 0 && x[1][1] != 0 && x[2][1] != 0 )
	{
		y[1][0] = y[1][0]/y[1][1]-1;
		y[1][2] = y[1][2]/y[1][1]-1;

		y[2][0] = y[2][0]/y[2][1]-1;
		y[2][2] = y[2][2]/y[2][1]-1;

		B[1] = B[1]/y[1][1]-B[0];
		B[2] = B[2]/y[2][1]-B[0];

		A[0] = (B[1]*y[2][2]-B[2]*y[1][2])/(y[1][0]*y[2][2]-y[1][2]*y[2][0]);
		A[2] = (B[2]*y[1][0]-B[1]*y[2][0])/(y[1][0]*y[2][2]-y[1][2]*y[2][0]);
		A[1] = B[0]-A[0]-A[2];

	}
	else
	{
		y[1][0] = y[1][0]/y[1][2]-1;
		y[1][1] = y[1][1]/y[1][2]-1;
		
		y[2][0] = y[2][0]/y[2][2]-1;
		y[2][1] = y[2][1]/y[2][2]-1;

		B[1] = B[1]/y[1][2]-B[0];
		B[2] = B[2]/y[2][2]-B[0];
		
		A[0] = (B[1]*y[2][1]-B[2]*y[1][1])/(y[1][0]*y[2][1]-y[1][1]*y[2][0]);
		A[1] = (B[2]*y[1][0]-B[1]*y[2][0])/(y[1][0]*y[2][1]-y[1][1]*y[2][0]);
		A[2] = B[0]-A[1]-A[0];
	}
}
int main()
{
	while( scanf("%d%d%d%d%d%d",
		&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]) &&
		(a[0] != 0 || a[1] != 0 || a[2] != 0 ))
	{
		solve(a,b,r,A);
		printf("%d %d %d %0.2lf %0.2lf %0.2lf\n",
				r[0],r[1],r[2],A[0],A[1],A[2]);
	}
	return 0;
}
