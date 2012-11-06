#include<map>
#include<set>
#include<vector>
#include<string>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

map<string,int>M;
set<string> S;
vector<vector<string> > V;
vector<vector<string>* >VP;

void output( int n )
{
	cout << "Group of size " << (*VP[n]).size() << ":";
	cout << " " << (*VP[n])[0];
	for( size_t i = 1; i < VP[n]->size(); i++ )
		if( (*VP[n])[i-1] != (*VP[n])[i] )
			cout << " " << (*VP[n])[i];
	cout << " ." << endl;
}
struct sort_t
{
	bool operator()(const vector<string>* a, const vector<string>* b )
	{
		if( a->size() != b->size() )
			return a->size() > b->size();
		else
			return (*a)[0] < (*b)[0];
	}
};
int main()
{
	int index;
	string key,word;
	map<string,int>::iterator iter;
	while( cin >> word )
	{
		key = word;	
		sort(key.begin(),key.end());		
		if( (iter = M.find(key)) != M.end())
			index = iter->second;
		else
		{
			index = V.size();
			V.push_back(vector<string>());		
			M.insert(make_pair(key,index));
		}
		V[index].push_back(word);
	}
	for( size_t i = 0; i < V.size(); i++ )
	{
		VP.push_back(&V[i]);	
		sort(V[i].begin(),V[i].end());
	}
	sort(VP.begin(),VP.end(),sort_t());
	for( size_t i = 0; i < 5 && i < VP.size(); i++ )
		output(i);

	return 0;
}
