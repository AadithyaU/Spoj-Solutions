#include <cstdio>
using namespace std;

int main(){
	int C;
	scanf("%d",&C);
	while(C--){
		int N, K, T, F;
		scanf("%d%d%d%d",&N,&K,&T,&F);
		printf("%d\n", (F - N)/(K-1) + F);
	}

	return 0;
}
