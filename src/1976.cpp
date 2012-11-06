#include<cstdio>
#include<algorithm>
#define SIZE 256
using namespace std;

unsigned long long get_result( unsigned long long x,unsigned long long int y)
{
        int i,j;
        unsigned int k = x > y ? y:x;
	unsigned long long result;
        static unsigned long long buf[SIZE];
        if( k == 0 )
		result = 1;
        else if( k == 1 )
		result = x+y;
        else if( k == 2 )
                result = (x+y)*(x+y-1)/2;
        else if( k == 3 )
                result = (x+y)*(x+y-1)*(x+y-2)/6;
        else if( k == 4 )
                result = (x+y)*(x+y-1)*(x+y-2)*(x+y-3)/24;
        else if( k == 5 )
                result = (x+y)*(x+y-1)*(x+y-2)*(x+y-3)*(x+y-4)/120;
        else
        {
                fill(buf,buf+SIZE,0);
                buf[0] = 1;
                for( i = 1; i < x+y+1; i++ )
                for( j = k > i ? i:k; j > 0 ; j-- )
                        buf[j] += buf[j-1];
		result = buf[k];
        }

	return result;
}

int main()
{
        unsigned long long  m,n;
        while( scanf("%lld%lld",&m,&n) && (m != 0 || n != 0) )
                printf("%lld\n",get_result(m,n));
        return 0;
}
