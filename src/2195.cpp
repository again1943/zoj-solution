#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<iostream>
#include<stack>
#include<map>
struct person_t
{
	int age; 
	std::string name;
};

typedef std::multimap<std::string,person_t>::iterator iter;

struct comp_t
{
	bool operator()(const person_t& left,const person_t& right )
	{
		if( left.age > right.age )
			return true;
		else if( left.age < right.age )
			return false;
		else
			return left.name < right.name;
	}
};

std::multimap<std::string,person_t,std::greater<std::string> >multimap;
std::stack<iter>stack;

int main()
{
	int n;
	int test_case;		
	iter pos,base;
	std::pair<iter,iter>range;
	std::vector<person_t>vec(120);
	person_t person;
	std::string key;
	std::cin >> test_case;
	for( int i = 1; i <= test_case; i++ )
	{
		std::cin >> n;	
		for( int j = 0; j < n; j++ )
		{
			std::cin >> key >> person.name >> person.age;	
			multimap.insert(make_pair(key,person));
		}
		key = "Ted";
		range = multimap.equal_range(key);
		for( pos = range.first; pos != range.second; ++pos )
		{
			pos->second.age = 100-pos->second.age;
			stack.push(pos);
		}
		while( stack.empty() != true  )
		{
			base = stack.top();
			stack.pop();
			range = multimap.equal_range(base->second.name);
			for( pos = range.first; pos != range.second; ++pos )
			{
				pos->second.age = base->second.age-pos->second.age;
				stack.push(pos);
			}
		}
		int size = 0;
		std::cout << "DATASET " << i << std::endl; 
		for( pos = multimap.begin(); pos != multimap.end(); ++pos )
			vec[size++] = pos->second;
		std::sort(vec.begin(),vec.begin()+size,comp_t());
		for( int j = 0; j < size; j++ )
			std::cout << vec[j].name << " " << vec[j].age << std::endl;
			
		multimap.clear();
	}
	return 0;
}
