#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define sd(x) scanf("%d",&x)
#define MAX 1000000

int primes[MAX];
vector<int> lucky;

void preprocessing() {
	for(int i = 2; i < MAX; i++) {
		if(primes[i] == 0) {
			primes[i] = 1;
			for(int c = 2; c * i < MAX; c++) {
				int mul = c * i;
				primes[mul] -= 1;
				if(primes[mul] + 3 == 0)  lucky.push_back(mul);
			}
		}
	}
	sort(lucky.begin(),lucky.end());
}

int main() {
	preprocessing();
	int t,n;
	sd(t);
	while(t--) {
		sd(n);
		printf("%d\n",lucky[n-1]);
	}
	return 0;
}
