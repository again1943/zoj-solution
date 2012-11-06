#include<cstdio>
#include<queue>
using namespace std;
struct msg
{
	char name[80];
	int parameter;
	int priority;
};
struct op
{
	bool operator()( msg one, msg two )
	{
		return one.priority > two.priority;
	}
};

int main()
{
	char command[10];
	msg message;
	priority_queue<msg,vector<msg>,op> msg_queue;
	while( scanf("%s",command) != -1 )
	{
		if( strcmp( command,"GET" ) == 0 )
		{
			if( msg_queue.empty() == true )
				printf("EMPTY QUEUE!\n");
			else
			{
				message = msg_queue.top();
				msg_queue.pop();
				printf("%s %d\n",message.name,message.parameter);
			}	
		}
		if( strcmp(command,"PUT") == 0 )
		{
			scanf("%s%d%d",message.name,&message.parameter,&message.priority);
			msg_queue.push( message );
		}
	}
	return 0;
}

