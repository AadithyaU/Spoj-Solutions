#include <iostream>
#include <cstdio>
#include <math.h>
#define sl(x) scanf("%lld",&x)

int main() {
	long long int t;
	sl(t);
	while(t != -1) {
		float s =((-3+pow(-3+12*t,1.0/2))/6);
		if(s-(int)s == 0) printf("Y\n");
		else printf("N\n");
		sl(t);
	}
	return 0;
}	



