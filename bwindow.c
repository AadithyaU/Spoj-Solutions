#include<stdio.h>
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)

int main()
{
	int t;
	sd(t);
	while(t--) {
		unsigned long long int min=0,max=0,inner,outer;
		int n,i,pos;
		sd(n);
		for(i=0;i<n;i++) {
			sl(inner);sl(outer);
			if(inner>min) { pos = i; min = inner; }
			else if(outer>max) max=outer;
		}
		if(min>max) printf("%d\n",pos+1);
		else printf("-1\n");
	}
	return 0;
}
