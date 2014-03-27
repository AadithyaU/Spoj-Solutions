#include <iostream>
#include <cstdio>
#include <cmath>

int gcd(int a, int b)
{
  int c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

using namespace std;
int main() {
	int t,s1,s2,diff;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d", &s1, &s2);
			if(s1 < s2) 
				diff = s2 - s1;
			else
				diff = s1 - s2;
			if( s1 < 0 ) s1 = -s1;
			if( s2 < 0 ) s2 = -s2;
			printf("%d\n", diff/gcd(s1,s2));
		}
	return 0;
}
