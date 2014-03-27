#include <stdio.h>
#include <math.h>

int main() {
	int t,n,m,i;
	int move[1000];
	int a,b,k;
	int j = 1;
	int count = 0;
	int flag = 0;
	scanf("%d",&t);
	while(t--) {
	count = 0;
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i ++) 
		scanf("%d",&move[i]);
	for(i = 0;i < m;i ++) {
		scanf("%d %d %d",&a,&b,&k);
		if(k) {
			if(move[a-1] == move[b-1]) {
				flag = 1;
				count++;
				//break;
			} else continue;

		} else {
			if(move[a-1] != move[b-1]) {
				flag = 1;
				count++;
				//break;
			} else continue;
		}
	} 
		if((count * 2) < m) 
			printf("Case #%d: yes\n ", j);
		else 
			printf("Case #%d: no\n", j);
		j++; 
	}
	return 0;
}
