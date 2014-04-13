#include <stdio.h>
 
int main()
{
    int T,t,N,M,i,j,sub = 9999999999;
    int n[1005];
    int m[1005];
    scanf("%d",&T);
    for(t = 0; t < T; t++)
    {
        sub = 9999999999;
        scanf("%d",&N);
        for(i = 0; i< N; i++)
            scanf("%d",&n[i]);
        scanf("%d",&M);
        for(i = 0; i< M; i++)
        {
            scanf("%d",&m[i]);
            for(j = 0; j< N; j++)
                if (abs(m[i]-n[j]) < sub)
                    sub = abs(m[i]-n[j]);
        }
        printf("%d\n",sub);
    }
    return 0;
}
