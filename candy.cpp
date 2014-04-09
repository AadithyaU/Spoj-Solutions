#include <iostream>
#include <cstdio>
#include <algorithm>
#define sd(x) scanf("%d\n",&x)
using namespace std;

int a[10000];

int main() {
	int n,value,mean;
	long long int ans,move;
	sd(n);
	while(n != -1) {
		ans = 0;
		move = 0;
	for(int i = 0; i < n; i++) {
		sd(a[i]);
		ans+= a[i];
	} 
	if((ans % n) != 0) printf("-1\n");
	else {
		sort(a,a+n);
		mean = ans/n;
		for(int i = 0; i < n; i++) {
			if(a[i] >= mean) break;
			move+=(mean - a[i]);
		}
		printf("%lld\n", move);
	}
	sd(n);
	}
	return 0;
}	

