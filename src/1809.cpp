#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

#define INIT_CHILD 8
#define NAME_LEN 32

struct file_t
{
	int nd;
	int sd;
	file_t* dir;
	std::vector<std::string>* file;	
	char name[NAME_LEN];
}root;

void dfs( file_t* root, char* line)
{
	int size;
	file_t *dir;
	//char** file;
	while( 1 )
	{
		switch(line[0])
		{
		case 'f':
			if( root->file == 0 )
				root->file = new std::vector<std::string>;
			root->file->push_back(std::string(line));
			break;
		case 'd':
			if(root->nd == root->sd)
			{
				dir = root->dir;
				size = root->sd?root->sd*2:INIT_CHILD;
				root->dir = (file_t*)malloc(sizeof(file_t)*size);
				memset(root->dir,0,sizeof(file_t)*size);
				if( root->sd != 0 )
					memcpy(root->dir,dir,sizeof(file_t)*root->sd);
				root->sd = size;
				free(dir);
			}
			dir = &root->dir[root->nd++];
			strcpy(dir->name,line);
			scanf("%s",line);
			dfs(dir,line);
			break;
		case ']':
		case '*':
		default:
			return;
		}
		scanf("%s",line);
	}
}
inline void ident(int n)
{
	for(int i = 0; i < n; i++ )
		printf("|     ");
}
struct com
{
	bool operator()(const char* a, const char* b)
	{
		return (strcmp(a,b) < 0);
	}
};
void print(file_t* root,int d)
{
	int i;
	ident(d);
	printf("%s\n",root->name);
	for( i = 0; i < root->nd; i++ )
		print(&root->dir[i],d+1);

	if( root->dir != 0 )
		free(root->dir);
	if( root->file != 0 && root->file->size()!= 0)
	{
		std::sort(root->file->begin(),root->file->end());
		for( i = 0; i < (int)root->file->size(); i++ )
		{
			ident(d);
			std::string& ref = root->file->at(i);
			printf("%s\n",ref.c_str());
		}
	}
	if( root->file != 0)
	{
		root->file->clear();
		delete root->file;
	}
}
int main()
{
	int t = 0;

	char line[32];
	while( 1 )
	{
		scanf("%s",line);
		if(strcmp(line,"#") == 0)
			break;
		else
		{
			memset(&root,0,sizeof(root));
			strcpy(root.name,"ROOT");
			dfs(&root,line);
			if(t != 0 )
				printf("\n");
			printf("DATA SET %d:\n",++t);
			print(&root,0);
		}
	}
}