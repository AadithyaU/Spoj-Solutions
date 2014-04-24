#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lu",&x) 
char player[2][6] = { "Alice","Bob" };

int f(int t,int p,int s,int m) {
	
	if(t == 0 || t == 1)
		return 1 - m;
	
	if(p == 0) {
		if(s % 2) return 1 - m; 
		return m;
	}
	
	int s1 = 0;
	if(s < 1) s1 = 1;
	
	int rem = p + s + s1 -1;
	
	if(rem % 2) return f(t - 2, p - 1,s, 1 - m);
	if(s < 1) return f(t - 1, p - 1 , s + 1, 1 - m);
	return f(t - 1,p, s - 1,1 - m);
}

int main() {
	int t;
	unsigned long n;
	sd(t);
	while(t--) {
		sl(n);
			if(!((n) & (n - 1)) || n == 0) {
				printf("Bob\n"); 
				break; 
			}
			int pair = 0;
			bitset<32> b(n);
			for(int j = 0; j < 31; j++) {
				if(b.test(j) && b.test(j+1)) {
			 		pair++;
					j++;
				}
			}
			int total = b.count();
			int single = total - (pair * 2);
			cout<<b<<endl;
			printf("%s\n",player[f(total,pair,single,0)]);
	}
	return 0;
}
