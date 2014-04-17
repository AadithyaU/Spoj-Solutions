#include <iostream>
#include <cstdio>
#include <algorithm>
#define sd(x) scanf("%d",&x) 
#define sl(x) scanf("%lld",&x) 
using namespace std;

struct work
{
	int start,end;
}w[100000];

bool compare(struct work a,struct work b)
{
	if (a.end == b.end)
		return a.start<b.start;
	return a.end<b.end;
}
int main()
{
	int t;
	sd(t);
	while(t--)
	{
		int n,end=-1,count=0;
		sd(n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&w[i].start,&w[i].end);
		sort(w,w+n,compare);

		for(int i=0;i<n;i++) {	
			if(w[i].start>=end) {
				count ++;
				end = w[i].end;
			} 
		}
		printf("%d\n",count);
	}
	return 0;
}
