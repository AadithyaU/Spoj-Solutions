#include <iostream>
#include <cstdio>
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%d\n",&x)

int main() {
	int t;
	long long n,value,ans;
	sd(t);
	while(t--) {
		ans = 0;
		sl(n);
		for(long i = 0; i < n; i++) {
			sl(value);
			ans+= value;
			ans %= n;
		} 
		if(ans == 0) printf("YES\n");
		else  printf("NO\n");
	}
	return 0;
}	

