#include<map>
#include<string>
#include<cstdio>
#include<utility>
#include<iostream>
#include<algorithm>
using namespace std;
#define TEAM_CNT 52

struct problem_t
{
	bool accept;	
	int submit_count;
	int accept_time;
	problem_t()
	{
		accept = false;	
		submit_count = 0;
		accept_time = -1;
	}
	void init()
	{
		accept = false;
		submit_count = 0;
		accept_time = -1;
	}
};

struct comp_t
{
	bool operator()(const problem_t& a, const problem_t& b )
	{
		if( a.accept_time > 0 && b.accept_time > 0 )		
			return a.accept_time < b.accept_time;
		if( a.accept_time > 0 && b.accept_time < 0 )
			return true;
		return false;
	}
};
struct team_t
{
	string name;
	int solve_problem;
	int total_time;
	int last_time;
	problem_t* problems;	
	team_t()	
	{
		problems = new problem_t[10];	
	}
	void init()
	{
		solve_problem = 0;	
		total_time = 0;
		last_time = -1;
		for( int i = 0; i < 10; i++ ) 
			problems[i].init();
	}
	void argument()	
	{
		last_time = -1;
		sort(problems,problems+10,comp_t());
		for( int i = 0; i < 10; i++ )	
		{
			if( problems[i].accept != true )	
				continue;
			solve_problem += 1;
			total_time += problems[i].accept_time+20*(problems[i].submit_count-1);	
			last_time = max(last_time,problems[i].accept_time);
		}
	}
}teams[TEAM_CNT];

struct sort_t
{
	bool operator()(const team_t& a, const team_t& b )
	{
		if( a.solve_problem != b.solve_problem )	
			return a.solve_problem > b.solve_problem;
		if( a.total_time != b.total_time )
			return a.total_time < b.total_time;
		for( int i = a.solve_problem-1; i >= 0; i-- )
		{
			if( a.problems[i].accept_time != b.problems[i].accept_time )
				return a.problems[i].accept_time < b.problems[i].accept_time;
			if( a.problems[i].submit_count != b.problems[i].submit_count )
				return a.problems[i].submit_count > b.problems[i].submit_count;
		}
		return a.name < b.name;
	}
};
bool same( const team_t& a, const team_t& b )
{
	if( a.solve_problem != b.solve_problem )	
		return false;
	if( a.total_time != b.total_time )
		return false;
	for( int i = a.solve_problem-1; i >= 0; i-- )
	{
		if( a.problems[i].accept_time != b.problems[i].accept_time )
			return false;
		if( a.problems[i].submit_count != b.problems[i].submit_count )
			return false;
	}
	return true;
}
int main()
{
	char c;
	map<string,int>M;
	problem_t* p;
	int n,submit,time,test_case,k,i,idx;
	string name,accept;
	cin >> test_case;
	for( k = 0; k < test_case; k++ )
	{
		cin >> n >> submit;
		for(i = 0; i < n; i++ )
		{
			cin >> name;
			M.insert(make_pair(name,i));
			teams[i].init();
			teams[i].name = name;
		}
		for( i = 0; i < submit; i++ )
		{
			cin >> time >> name >> c >> accept;	
			idx = M[name];
			p = &teams[idx].problems[c-'A'];
			if( p->accept == true )
				continue;
			p->submit_count++;
			if( accept == "accepted" )
			{
				p->accept = true;
				p->accept_time = time;
			}
		}
		for( i = 0; i < n; i++ )	
			teams[i].argument();
		sort(teams,teams+n,sort_t());
		cout << 1 << " " << teams[0].name << " " 
		<< teams[0].solve_problem << " " << teams[0].total_time << endl;
		for( i = 1,idx = 1; i < n; i++ )
		{
			if( same(teams[i],teams[i-1]) == false )
				idx = i+1;
			cout << idx << " " << teams[i].name << " " 
			<< teams[i].solve_problem << " " << teams[i].total_time << endl;
		}
		M.clear();
	}
	return 0;
}
