#include <iostream>
#include <cstdio>
#include <string.h>
#define sd(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)

char vowels[5] = {'a','e','i','o','u'};
char con[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
int posi[26] = {0,0,1,2,1,3,4,5,2,6,7,8,9,10,3,11,12,13,14,15,4,16,17,18,19,20};
char un[50001];
char en[50001];

int main() {
	int t,i;
	int count[26];
	sd(t);
	while(t--) {
		memset(count,0,sizeof(count));
		ss(un);
		int size = strlen(un);
		un[size] = '\0';
		for(i = 0; i < size; i++) {
				char c = un[i];
				int cnt = count[c - 'a']++;
				if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
					int pos = posi[(int) c - 'a'];
					pos = (pos + ( 5 * cnt)) % 21;
					en[i] = con[pos];
				} else {
					int pos = posi[(int) c - 'a'];
					pos = (pos + ( 21 * cnt)) % 5;
					en[i] = vowels[pos];
				} 
		}
		en[i] = '\0';
		printf("%s\n",en);
	}
	return 0;
}	
