#include <iostream>
#include <cstdio>
#include <climits>
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%llu",&x)

int count[2000];
int main() {
	int t;
	unsigned long long n,divby2;
	sd(t);
	while(t--) {
		sl(n);
		divby2 = n/2;
		if(n % 2 == 0) divby2--;
		printf("%lld\n",(divby2 * divby2) % n);
	}
	return 0;
}	
