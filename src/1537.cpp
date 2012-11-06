#include<cstdio>
#include<set>

int main()
{
	bool flag;
	int n,i,start,count;
	std::set<int>mod;
	while( scanf("%d",&n) != -1 )
	{
		if( n == 1 )
			printf("1 1\n");
		else if( n == 11 )
			printf("1 2\n");
		else if( n == 111 )
			printf("1 3\n");
		if ( n % 10 == 0 )
			printf("-1\n");
		else
		{
			for( i = 1; i < 10; i++ )
			{
				flag = false;
				mod.clear();
				mod.insert(i);

				for( start = (i*10+i)%n,count = 1;
					mod.find(start) == mod.end();
					start = (start*10+i)%n)
				{
					count++;
					mod.insert(start);	
					if( start == 0 )
					{
						flag = true;
						goto here;
					}
				}
			}
			here:
			if( flag == true )
				printf("%d %d\n",i,count);
			else
				printf("-1\n");
			
		/*
			for( start  = 1,count = 0,flag = false; 
				mod.find(start) == mod.end();start = (10*start+1)%n )
			{
				count++;	
				mod.insert(start);
				for(i = 1; i < 10; i++ )	
				{
					if( (start*i)%n == 0 ) 
					{
						flag = true;
						goto here;
					}
				}
			}
			here:
			if( flag == true )
				printf("%d count = %d\n",i,count);
			else
				printf("-1\n");
			mod.clear();
			*/
				
		}
	}
	return 0;
}
