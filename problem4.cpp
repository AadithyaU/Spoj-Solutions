#include <iostream>
#include <cstdio>
#include <string.h>
#define sd(x) scanf("%d",&x)
using namespace std;
#define MAX 10001
int primes[MAX];
void preprocess() {
	memset(primes,0,sizeof(primes));
	for(int i = 2; i < MAX; i++) {
		if(primes[i] == 0) {
			primes[i] = 1;
			for(int c = 2; c * i < MAX; c++) {
				int mul = c * i;
				primes[mul] -= 1;
			}
		}
	}
}

int credits[6];
int main() {
	int t,n,test = 0;
	preprocess();
	sd(t);
	while(t--) {
		test++;
		sd(n);
		if(primes[n] != 1) printf("%d:NOTPRIME\n",test);	
		else if(n == 3) printf("%d:2\n",test);
		else  printf("%d:1\n",test);
	}
	return 0;
}
