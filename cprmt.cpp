#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char a[1001],b[1001];
int cnt[26];

int main()
{
    while(scanf("%s%s",a,b)!=EOF) {
        memset(cnt,0,sizeof(cnt));
    	for(int i=0;a[i];++i)
    	cnt[a[i]-'a']++;
    	sort(b,b+strlen(b));
    	for(int i=0;b[i];++i) {
        if(cnt[b[i]-'a']) {
        	printf("%c",b[i]);
        	cnt[b[i]-'a']--;
    	}
    	}
    	printf("\n");
    }
    return 0;
}
