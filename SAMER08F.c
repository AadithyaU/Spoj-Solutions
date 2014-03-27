#include<stdio.h>
int main()
{
    long long int n;
    while(1)
    {
        scanf("%lld",&n);
        if(!n) break;
        printf("%lld\n",(n*(n+1)*(2*n+1))/6);
    }
    return 0;
}
