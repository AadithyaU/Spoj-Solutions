#include <iostream>
#include <cstdio>
using namespace std;
#define sd(x) scanf("%d",&x)

int v[2001];
int r[2001][2001];

int max(int a,int b) {
	return (a > b ? a : b);	
}

int calc(int i , int j , int n) {
	if(r[i][j] != -1) return r[i][j];
	int m = j-i+1;
	m = n - m + 1;
	if(i == j) return m * v[i];
	return r[i][j] = max(calc(i+1,j,n)+ m * v[i],calc(i,j-1,n) + m * v[j]);
}

int main() {
	int n;
	while(sd(n) == 1) {
		for(int i = 0; i < n; i++)
			sd(v[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				r[i][j] = -1;
		printf("%d\n",calc(0,n-1,n));
	}
	return 0;
}
