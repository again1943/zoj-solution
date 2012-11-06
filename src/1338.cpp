#include <cstdio>
using namespace std;

struct count_t 
{
	int time;
	int len;
};

int main()
{
	int first,second;
	count_t up,down;
	int status;
	int count;
	int current_len;
	while (scanf("%d",&first) && first != 0 )
	{
		up.time = down.time = 0;
		up.len = down.len = 0;
		status = current_len = 0;
		count = 1;
		while (scanf("%d",&second) && second != 0 )
		{
			count++;
			switch(status)
			{
				case 0:
					current_len++;
					if (second > first)
						status = 1;
					if (second < first )
						status = -1;
					break;
				case 1:
					if (second >= first)
						current_len++;
					else
					{
						up.time++;
						up.len += current_len;
						current_len = 1;
						status = -1;
					}
					break;
				default:
					if (second <= first)
						current_len++;
					else
					{
						down.time++;
						down.len += current_len;
						current_len = 1;
						status = 1;
					}
					break;
			}
			first = second;
		}
		if(status == 1)
		{
			up.time++;
			up.len += current_len;
		}
		else if( status == -1 )
		{
			down.time++;
			down.len += current_len;
		}
		else
		{
			up.time = down.time = 0;
			down.len = up.len = 0;
		}
		printf("Nr values = %d:  %0.6lf %0.6lf\n",count,
			(up.time == 0 )?0:((double)up.len)/up.time,
			(down.time == 0)?0:((double)down.len)/down.time);
	}
	return 0;
}

