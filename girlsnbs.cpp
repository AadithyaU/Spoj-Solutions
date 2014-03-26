#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
int main() {
	int girls , boys;
	int min,max;
	while(1) {
		scanf("%d %d", &girls, &boys);
		if(girls == -1 && boys == -1)
			break;
		if( girls > boys) {
			max = girls;
			min = boys;
		} else {
			min = boys;
			max = girls;
		}
		printf("%d\n",ceil(max/min));
	}
	return 0;
}
