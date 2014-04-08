#include <iostream>
#include <cstdio>
#include <set>
#define sd(x) scanf("%d",&x)
using namespace std;

int main() {
	int t; int id,n,temp,temp1;
	sd(t); temp1 = t;
	set<int> f;
	while(t--) {
		sd(id);
		sd(n);
		f.insert(id);
		for(int i = 0; i < n; i++) {
			sd(temp);
			f.insert(temp);
		}
	}
	printf("%d\n",f.size() - temp1);
	return 0;
}
