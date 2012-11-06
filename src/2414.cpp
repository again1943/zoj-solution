#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#define MAXN 10001

std::vector<int> prime_list;
int prime_pos[MAXN];

void calc_prime()
{
	int a,b;
	bool is_prime[MAXN];
	memset(is_prime,true,sizeof(is_prime));
	memset(prime_pos,-1,sizeof(prime_pos));
	is_prime[0] = is_prime[1] = false;
	for (a = 2; a < MAXN; a++) {
		if (!is_prime[a]) {
			continue;
		}
		prime_pos[a] = (int)prime_list.size();
		prime_list.push_back(a);
		for (b = a; a*b < MAXN; b++) {
			is_prime[a*b] = false;
		}
	}
}

//std::pair<int,int> prime_index[MAXN];
struct prime_index_t 
{
	int count;
	int prev;
	int prime;
} prime_index[MAXN];

void calc_prime_index()
{
	int a,b,p,c;
	memset(prime_index,-1,sizeof(prime_index));
	prime_index[0].count = prime_index[1].count = 0;
	prime_index[0].prev = prime_index[1].prev = -1;
	prime_index[0].prime = prime_index[1].prime = -1;
	for (a = 2; a < MAXN; a++) {
		if (a == 87) {
			int x = 0;
		}
		if (prime_pos[a] >= 0) {
			prime_index[a].count = 1;
			prime_index[a].prev = -1;
			prime_index[a].prime = a;
			continue;
		}

		std::vector<int>::iterator it = std::lower_bound(prime_list.begin(),prime_list.end(),a);
		b = it-prime_list.begin()-1;
		while (b >= 0) {
			p = prime_list[b];
			c = a-p;
			b -= 1;
			if (prime_index[c].count == 0) {
				continue;
			}
			if (prime_index[c].prime > p) {
				continue;
			}
			if (prime_index[a].count < 0 || prime_index[c].count+1 < prime_index[a].count ||
				(prime_index[c].count+1 == prime_index[a].count && p < prime_index[a].prime)) {
				prime_index[a].count = prime_index[c].count+1;
				prime_index[a].prev = c;
				prime_index[a].prime = p;
			}
		}
	}
}

void print_prime(int n)
{
	int b;
	printf("%d",prime_index[n].prime);
	b = prime_index[n].prev;
	while (b > 0) {
		printf(" %d",prime_index[b].prime);
		b = prime_index[b].prev;
	}
	printf("\n");
}

int main()
{
	int n;
	calc_prime();
	calc_prime_index();
	while(scanf("%d",&n) != -1) {
		if (prime_index[n].count == 0) {
			printf("0\n");
		} else {
			printf("%d\n",prime_index[n].count);
			print_prime(n);
		}
	}
	return 0;
}