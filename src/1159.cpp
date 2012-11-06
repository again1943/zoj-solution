/*
 * =====================================================================================
 *
 *       Filename:  1159.cpp
 * *    Description:  solution to zoj 1159 * *        Version:  1.0
 *        Created:  2007年05月04日 21时21分41秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<utility>


struct string
{
	char line[24];
	bool operator==(const string& one)
	{
		return strcmp(line,one.line)== 0;
	}
};
/*
bool operator>(const string& one,const string& two)
{
	return strcmp(one.line,two.line) > 0;
}
*/

bool operator<(const string& one,const string& two)
{
	return strcmp(one.line,two.line) < 0;
}
inline char get_code(char c )
{
	switch(c)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return c;
		case 'A':
		case 'B':
		case 'C':
			return '2';
		case 'D':
		case 'E':
		case 'F':
			return '3';
		case 'G':
		case 'H':
		case 'I':
			return '4';
		case 'J':
		case 'K':
		case 'L':
			return '5';
		case 'M':
		case 'N':
		case 'O':
			return '6';
		case 'P':
		case 'R':
		case 'S':
			return '7';
		case 'T':
		case 'U':
		case 'V':
			return '8';
		case 'W':
		case 'X':
		case 'Y':
			return '9';
		default:
			return -1;
	}
}
inline void get_standard(const string& source,string& target )
{
	char c;
	char count = 0;
	for( int i = 0; source.line[i] != '\0'; i++ )	
		if( (c = get_code(source.line[i])) > 0 )
		{
			target.line[count++] = c;
			if( count == 3 )
				target.line[count++] = '-';
		}
	target.line[count] = '\0';
}
struct sort_op
{
	bool operator()(const std::pair<string,int>&one,const std::pair<string,int>&two )
	{
	//	return one.second < two.second;
		return strcmp(one.first.line,two.first.line) <= 0;
	}
};
int main()
{

	int n,s;
	int t = 0;
	int test_case;
	string line;
	string standard;
	std::map<string,int>telphone_num;
	std::vector<std::pair<string,int> >backup;
	std::vector<std::pair<string,int> >total;
	std::map<string,int>::iterator pos;

	std::scanf("%d",&test_case);
	while( test_case-- )
	{
		getchar();
		if( t++ )
			std::printf("\n");
		std::scanf("%d",&n);
		while( n-- )
		{
			std::scanf("%s",line.line);
			get_standard(line,standard);
			if( (pos = telphone_num.find(standard)) == telphone_num.end())
			{
				telphone_num.insert(std::make_pair(standard,total.size()));
				total.push_back(std::make_pair(standard,1));
			}
			else
				total[pos->second].second++;
		}
#ifdef DEBUG
		printf("----------------------------\n");
		for( size_t i  = 0; i < total.size(); i++ )
			printf("%s %d\n",total[i].first.line,total[i].second);
		printf("----------------------------\n");
#endif
		for( size_t i = 0; i < total.size();i++ )
			if( total[i].second  > 1 )
				backup.push_back(total[i]);
		if( backup.size() == 0 )
			std::printf("No duplicates.\n");
		else
		{
#ifdef DEBUG
		printf("----------------------------\n");
		for( size_t i  = 0; i < backup.size(); i++ )
			printf("%s %d\n",backup[i].first.line,backup[i].second);
		printf("----------------------------\n");
#endif

		std::sort(backup.begin(),backup.end(),sort_op());
#ifdef DEBUG
		printf("----------------------------\n");
		for( size_t i  = 0; i < backup.size(); i++ )
			printf("%s %d\n",backup[i].first.line,backup[i].second);
		printf("----------------------------\n");
#endif

			for( size_t i = 0; i < backup.size(); i++ )
				printf("%s %d\n",backup[i].first.line,backup[i].second);
		}
		telphone_num.clear();
		total.clear();
		backup.clear();

	}
	return 0;
}


