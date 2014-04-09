#include <iostream>
#include <cstdio>
#include <climits>
#include <string.h>
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)

int count[2000];
int main() {
	int t,ele,pos; long n,max;
	sd(t);
	while(t--) {
		max = LONG_MIN;
		memset(count,0,sizeof(count));
		scanf("%ld\n",&n);
		for(long i = 0; i < n; i++) {
			sl(ele);
			if((++count[ele + 1000]) > max) { max = count[ele + 1000]; pos = ele; }
		}
		if(max > (n / 2)) printf("YES %ld\n",pos);
		else printf("NO\n");
	}
	return 0;
}	
