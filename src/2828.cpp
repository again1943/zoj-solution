#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

std::set<std::string> dic;

int main()
{
	int dic_count;
	int word_count;
	int test_case;
	std::string word;
	std::vector<std::string> vec;

	std::cin >> test_case; 
	for( int i = 0; i < test_case; i++ )
	{
		if( i != 0 )
			std::cout << std::endl;
		std::cin >> dic_count;	
		for( int j = 0; j < dic_count; j++ )
		{
			std::cin >> word;		
			dic.insert(word);
		}
		std::cin >> word_count;
		for( int j = 0; j < word_count; j++ )
		{
			std::cin >> word;
			if( dic.find(word) != dic.end() )
			{
				std::cout << word << std::endl;
				continue;
			}
			for( size_t k = 0; k < word.size()-1; k++ )
			{
				std::swap(word[k],word[k+1]);	
				if( dic.find(word) != dic.end())
					vec.push_back(word);
				std::swap(word[k],word[k+1]);	
			}
			if( vec.size() != 0 )
			{
				std::sort(vec.begin(),vec.end());	
				std::cout << vec[0];
				for( size_t k = 1; k < vec.size(); k++ )
					std::cout << "," << vec[k];
				std::cout << std::endl;
				vec.clear();
				continue;
			}
			std::cout << word << std::endl;
		}
		dic.clear();
	}
	return 0;
}
