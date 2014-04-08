#include <iostream>
#include <cstdio>

#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)

long long int gcd(long long int a,long long int b) {
	long long int rem;
	while(b > 0) {
		rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}

int main() {
	int t; 
	long long int a,b,l;
	sd(t);
	while(t--) {
		sl(a);sl(b);
		l = gcd(b,a);
		printf("%lld %lld\n",b/l,a/l);
	}
	return 0;
}
