#include <iostream>
#include <cstdio>

#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)

long long int seat;
char seat_arr[10] = { 'A','W','W','A','A','M','W','W','M','A'};
char seat_side[10] = { 'L','L','L','L','R','R','R','R','R','R'};

int main() {
	int t; int row;
	sd(t);
	while(t--) {
		sl(seat); 
		if(seat == 1) printf("poor conductor\n");
		else {
			row = (int) ((seat - 2) / 5) + 1;	
			printf("%d %c %c\n",row,seat_arr[rem % 10],seat_side[rem % 10]);
		}

	}
	return 0;
}
