/*
 * =====================================================================================
 *
 *       Filename:  2585.cpp
 *
 *    Description:  solution to zoj 2582
 *
 *        Version:  1.0
 *        Created:  2007年04月29日 05时30分03秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cmath>
#include<algorithm>
#include<cstdio>

int main()
{
	char line[100];
	int n,sum;
	int vec[26];
	std::scanf("%d",&n);
	getchar();
	for( int i = 0; i < n; i++ )
	{
		sum = 0;
		std::fill(vec,vec+26,0);
		std::gets(line);
		for(int j = 0; line[j] != '\0'; j++ )
			vec[line[j]-'a']++;
		std::gets(line);
		for(int j = 0; line[j] != '\0'; j++ )
			vec[line[j]-'a']--;
		for( int j = 0; j < 26;j++ )
			sum += abs(vec[j]);
		std::printf("Case #%d:  %d\n",i+1,sum);
	}
	return 0;

}

