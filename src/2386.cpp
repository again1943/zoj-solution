#include<cstdio>
#include<algorithm>
using namespace std;

#define ELEM_CNT 500001
int elem[ELEM_CNT];
int C[ELEM_CNT];
int S[ELEM_CNT];
long long merge(  int A[], int len_a, int B[], int len_b ) 
{
	int i = 0;
	int j = 0;
	int idx = 0;	
	long long ret = 0;
	while( i < len_a && j < len_b )
	{
		if( A[i] <= B[j] )			
			C[idx++] = A[i++];
		else if( A[i] > B[j] )
		{
			C[idx++] = B[j++];
			ret += len_a-i;
		}
	}
	while( j < len_b )
		C[idx++] = B[j++];
	while( i < len_a )
		C[idx++] = A[i++];
	copy(C,C+idx,A);
	return ret;
}

/* use a recursive merge_sort_(...) to count the inverse,this is correct,but
a little slower...try to use a none recursive merge_sort_ later..*/

long long merge_sort_( int A[], int n )
{
	int mid = n/2;	
	long long ret = 0;	
	
	if( n == 1 || (n == 2 && A[0] <= A[1] ))
		return 0;
	if( n == 2 && A[0] > A[1] )
	{
		swap(A[0],A[1]);
		return 1;
	}
	ret += merge_sort_(A,mid);
	ret += merge_sort_(A+mid,n-mid);
	return (ret += merge(A,mid,A+mid,n-mid));
}


inline long long do_work( int A[],int n )
{
	return merge_sort_(A,n);	
}

int main()
{
	int n,i;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
			scanf("%d",&elem[i]);
		printf("%lld\n",do_work(elem,n));
	}
	return 0;
}
