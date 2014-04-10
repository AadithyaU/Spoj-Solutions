#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	char ch;
	int z,power;long n;
	while(1) {
		cin>>n>>ch>>z;
		if(n == 0) break;
		if(n ==  1 && z == 0) { cout<<"1\n"; break; }
		n = n * (pow(10,z));
		power=1;
		while(power<=n)
			power=power*2;
		power=power/2;
		printf("%d\n",( 2 * (n - power) + 1));
	}
	return 0;
}
