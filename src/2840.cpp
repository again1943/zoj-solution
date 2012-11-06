/*
 * =====================================================================================
 *
 *       Filename:  2840.cpp
 *
 *    Description:  solution to zoj 2840
 *
 *        Version:  1.0
 *        Created:  2007年05月01日 12时56分41秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void match(const string& query,const vector<string>&file,vector<string>&output)
{
	string left,right;
	int pos = query.find('*');	
	left = query.substr(0,pos);
	right = query.substr(pos+1,query.size()-1-pos);

	for( int i = 0; i < file.size(); i++ )
	{
		if( file[i].size() >= left.size()+right.size()&&  
				file[i].find(left)==0 &&
				right == file[i].substr(file[i].size()-right.size(),right.size()))
			output.push_back(file[i]);
	}
}
int main()
{
	string temp,query;
	vector<string>file;
	vector<string>satisfy;

	int n_file,n_query;
	int t = 0;
	while( cin >> n_file )
	{
		if( t++ )
			cout << endl;
		for( int i = 0;i  < n_file; i++ )	
		{
			cin >> temp;
			file.push_back(temp);
		}
		cin >> n_query;
		for( int i = 0; i < n_query; i++ )
		{
			cin >> query;
			match(query,file,satisfy);
			if( satisfy.size() == 0)
				cout << "FILE NOT FOUND" << endl;
			else
			{
				for( int j = 0; j < satisfy.size(); j++)
					cout << (j==0?"":", ")<< satisfy[j];
				cout << endl;
			}
			satisfy.clear();

		}
		file.clear();
	}
	return 0;
}
