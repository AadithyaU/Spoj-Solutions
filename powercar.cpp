#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <string.h>
using namespace std;
#define sd(x) scanf("%d",&x)

int n;
char track[2000];
int arr[2000][2000][2];

int findMinValue(int pos, int state, int bullets){
    
    if(pos == n-1){	
        if(state) return 2;	
        return 0;
    }
    
    if(arr[pos][bullets][state] != -1)
        return arr[pos][bullets][state];
    
    int minn = INT_MAX;
    
    if(!state) {
    if(track[pos+1] != '#')
        minn = min(minn, 1+findMinValue(pos+1,0,bullets));
    if(bullets>0)
        minn = min(minn, 1+findMinValue(pos+1,0,bullets-1));
    minn = min(minn,4+findMinValue(pos+1,1,bullets));
    }
    else {
        minn = min(minn, 2+findMinValue(pos+1,1,bullets));
    if(track[pos]!='#')
        minn = min(minn,2+findMinValue(pos,0,bullets));   
    }
    return arr[pos][bullets][state] = minn;
}



int main() {
	int t,b;
	sd(t);
	while(t--) {
	memset(arr,-1,sizeof(arr));
	sd(n);sd(b);
		scanf("%s",track);
		printf("%d\n",findMinValue(0,0,b));
	}
} 
