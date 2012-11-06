#include<vector>
#include<cmath>
#include<cstdio>
int common_factor( int x,int y)
{
  	int temp;
  	int a = x > y ? x:y;
  	int b = x > y ? y:x;
  	while( a%b != 0 )
  	{
    		temp = a%b;
    		a = b;
    		b = temp;
  	}
  	return b;
}

int main()
{
  	int n,x,y,temp;
  	std::vector<int>elem;
  	std::scanf("%d",&n);
  	while( n != 0 )
  	{
	  	x = y = 0;
    		for( int i = 0; i < n; i++ )
    		{
      			std::scanf("%d",&temp);
      			elem.push_back(temp);
    		}
    		for( size_t i = 0; i < elem.size(); i++ )
    		for( size_t j = i+1; j< elem.size(); j++ )
    		{
			if(common_factor(elem[i],elem[j])== 1)
	  			x++;
			y++;
    		}
    		if( x== 0 )
      			std::printf("No estimate for this data set.\n");
    		else
    			std::printf("%0.6lf\n",sqrt(6*y/static_cast<double>(x)));
    		elem.clear();
   		std::scanf("%d",&n);
  	}
  	return 0;
}
