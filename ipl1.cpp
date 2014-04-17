#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

long double dp[121][11][301];

long double findprob(int balls,int wkt,int target) {
	
	if(target <= 0) return 1.0;
	if(wkt == 10 || balls == 120) return 0.0;
	if(int(dp[balls][wkt][target]) >= 0) return dp[balls][wkt][target];
	return dp[balls][wkt][target] = 
		 (findprob(balls+1,wkt,target)  
		+ findprob(balls+1,wkt,target-1) 
		+ findprob(balls+1,wkt,target-2) 
		+ findprob(balls+1,wkt,target-3) 
		+ findprob(balls+1,wkt,target-4) 
		+ findprob(balls+1,wkt,target-5) 
		+ findprob(balls+1,wkt,target-6) 
		+ findprob(balls+1,wkt+1,target) 
		+ findprob(balls,wkt,target-1) 
		+ findprob(balls,wkt,target-1)) / 10.0;

}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		for(int j = 0; j < 121; j++) 
			for(int k = 0; k < 11;k++)
				for(int l = 0; l < 301; l++) 
					dp[j][k][l] = -1;
		int target;
		float overs;
		char score[6];int i;
		scanf("%f %s %d",&overs,score,&target);
		int curscore=0;int curwkt=0;
		for(i = 0; score[i]; i++) 
			if(score[i] == '/') break;
	
		for(int j = 0; j < i; j++) 
			curscore = (curscore * 10) + (score[j] - '0');
		for(int j = i + 1; score[j]; j++) 
			curwkt = (curwkt * 10) + (score[j] - '0');
		if(curscore >= target) {
			printf("100.00\n");
			continue;
		} 
		if(curwkt == 10) {
			printf("0.00\n");
			continue;
		}
		int noofballs = (int(overs) * 6) + 10 * (overs - int(overs));
		long double ans = findprob(noofballs,curwkt,target - curscore);
		printf("%Lf\n",ans * 100);
	}
	return 0;
}
