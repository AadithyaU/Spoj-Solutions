#include <bits/stdc++.h>
using namespace std;

#define L long
#define LL long long
#define UL unsigned long
#define ULL unsigned long long 

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d %d",&x,&y)
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define sld(x) scanf("%ld",&x)
#define slu(x) scanf("%lu",&x)
#define slld(x) scanf("%ld",&x)
#define sllu(x) scanf("%llu",&x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)

#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n) 
#define REPE(i,n) FORE(i,0,n)
#define pb push_back
#define V vector
#define P pair
#define M map
#define S string
#define I int
#define C char
#define F float
#define D double
#define LD long double

#define prs(s) printf("%s",s)
#define prsn(s) printf("%s\n",s)
#define prss(s) printf("%s ",s)
#define prst(s) printf("%s\t",s)
#define pri(s) printf("%d",s)
#define prin(s) printf("%d\n",s)
#define pris(s) printf("%d ",s)
#define prit(s) printf("%d\t",s)
#define lf printf("\n")
#define R return
#define DESC(i) greater<i>()
#define MSET(x,y) memset((x),(y),sizeof(x))
#define max(x,y) (x>y?x:y)
#define max3(x,y,z) (max(max(x,y),z))
#define min(x,y) (x>y?y:x)
#define min3(x,y,z) (min(min(x,y),z))


I a[1001][1001];

I maxfromall(I n,I m,I x,I y) {

	I i,j;
	I maximum = INT_MIN;

	FOR(i,x-1,n)
		FOR(j,y-1,m) {
			I val = a[i][j] - (i-x>=0?a[i-x][j]:0) - (j-y>=0?a[i][j-y]:0) + (i-x>=0&&j-y>=0?a[i-x][j-y]:0);
			if(val > maximum)
				maximum = val;
		}
	
	
	return maximum;
	
}

I maxgems(I p, I n, I m) {
	
	if(p == 1) return maxfromall(n,m,1,1);

	I result = -1,i,j;
	int halfp = (p/2);
	FORE(i,1,halfp) {
		if(p % i == 0) {
			j = (p/i);
			if(i <= n && j <= m) {
				I val = maxfromall(n,m,i,j);
				result = max(result,val);
			}
			if(j <= n && i <= m) {
				I val =  maxfromall(n,m,j,i);
				result = max(result,val);
			}
		}
	}

	return result;
}

int main() {
	I n,m,i,j,t,p;
	sd2(n,m);
	
	REP(i,n) 
		REP(j,m) 
			sd(a[i][j]);
			
	FOR(i,0,n)
		FOR(j,1,m)
			a[i][j] = a[i][j-1] + a[i][j];
			
	FOR(i,1,n)
		FOR(j,0,m)
			a[i][j] += a[i-1][j];

	sd(t);
	
	REP(i,t) {
		sd(p);
		prin(maxgems(p,n,m));
	}
	
	return 0;
}
