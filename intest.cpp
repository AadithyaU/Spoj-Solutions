#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	long long n,k,t,count;
	scanf("%lld %lld",&n,&k);
	while(n-- > 0) {
		for(int i = 0;i < n; i++) {
			scanf("%lld", &t);
			if(!(t & (k - 1)))
				count++; 
		}
		printf("%lld\n",count);
		count = 0; 
	}
	return 0;
}
