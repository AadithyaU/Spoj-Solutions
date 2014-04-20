#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

double dp[120][10][300];

double findprob(int balls,int wkt,int target) {
	
	if(target <= 0) return 1;
	if(wkt == 10 || balls == 120) return 0;
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
		+ findprob(balls,wkt,target-1)) / 10;

}

int main() {
	int t;
	scanf("%d",&t);
	memset(dp,-1.0,sizeof(dp));
	while(t--) {
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
		int noofballs = (int(overs) * 6) + 10 * (overs - int(overs));
		double ans = findprob(noofballs,curwkt,target - curscore);
		char val[2000]; int l;
		sprintf(val,"%.12lf",ans * 100);
		for(l = 0; val[l]; l++) {
			if(val[l] == '.') break;
			printf("%c",val[l]);
		}
		for(int k = l; k < l + 3; k++) 
			printf("%c",val[k]);
		printf("\n");
	}
	return 0;
}
