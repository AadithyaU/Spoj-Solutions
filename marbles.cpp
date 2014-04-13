#include <cstdio>
#define sd(x) scanf("%d",&x)

long long ncr(int n, int m){
    if(m>n-m) m=n-m;
    long long ans=1;
    for(int i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    return ans;
}

int main(){
    int t,n,k;
    sd(t);
    while(t--) {
        sd(n);sd(k);
        printf("%lld\n",ncr(n-1,k-1));
    }
    return 0;
}
