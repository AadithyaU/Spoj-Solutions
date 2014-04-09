#include <iostream>
#include <cstdio>
#include <string.h>
#define sd(x) scanf("%d",&x)

int main() {
	int t;long long int n;
	sd(t);
	while(t--) {
		scanf("%lld\n",&n);
		printf("%lld\n",(long long)((n * (( 3 * n) + 1)) / 2) % 1000007);
	}
	return 0;
}	
