#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long modjos(long long n,long long  k) {
	if (n==1) return 1;
	return modjos(n-1,k+1)+k-1) % n+1;
}

int main() {
	int t;
	long long n;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		if(n == 1) printf("1\n");
		else 
			printf("%llu\n", modjos(n,1));
	}
	return 0;
}
