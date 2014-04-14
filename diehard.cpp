#include <iostream>
#include <cstdio>
#define sd(x) scanf("%d",&x)
#define MAX 2510

int max(int a,int b) {
	return (a>b?a:b);
}

int arr[MAX][MAX][3];

int f(int h,int a,int state) {
	if(state == 0) {
		h+=3;
		a+=2;
	} else if(state == 1) {
		h-=5;
		a-=10;
	} else {
		h-=20;
		a+=5;
	}
	if(h <= 0 || a <= 0) return 0;
	if(arr[h][a][state]) return arr[h][a][state];
	if(state == 0)
		return arr[h][a][state] = max(f(h,a,1),f(h,a,2)) + 1;
	else if(state == 1)
		return arr[h][a][state] = max(f(h,a,0),f(h,a,2)) + 1;
	else
		return arr[h][a][state] = max(f(h,a,1),f(h,a,0)) + 1;
}
int main() {
	int t,h,a;
	sd(t);
	while(t--) {
		sd(h);sd(a);
		printf("%d\n",max(f(h,a,0),max(f(h,a,1),f(h,a,2))));
	}
}
