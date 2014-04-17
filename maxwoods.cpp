#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#define sd(x) scanf("%d",&x) 
#define RIGHT 1
#define LEFT 0
using namespace std;

int m,n;
char trees[1000][1000];
int dp[1000][1000][3];

int findmax(int i , int j , int direction) {
	//base condition.. it cannot move further when the following conditions are met
	if(j < 0 || j >= n || i >= m || i < 0 || trees[i][j] == '#' )
		return 0;
	//if not empty.. return 
	if(dp[i][j][direction] != -1) return dp[i][j][direction];
	int c = 0; 
	if(trees[i][j] == 'T') c++;
	return dp[i][j][LEFT] = max(findmax(i+1 ,j , 1 - direction),findmax(i , j-1 , direction)) + c;
}

int main() {
	int t;
	sd(t);
	while(t--) {
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&m,&n);
		for(int i = 0; i < m; i++)
			scanf("%s",trees[i]);
		printf("%d\n",findmax(0,0,RIGHT));
	}
	return 0;
}
