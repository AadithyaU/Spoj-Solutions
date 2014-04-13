#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		char a[31];
		scanf("%s",a);
		char c = 0;int k= 0,i = 0; unsigned long long ans = 1;
		do {
			if(a[i] != c) {
				ans = ans * (1ull << k);
				k = -1;
				c = a[i];
			}
			k++;
			i++;
		}while(a[i-1]);
		printf("%llu\n",ans);
	}
	return 0;
}
