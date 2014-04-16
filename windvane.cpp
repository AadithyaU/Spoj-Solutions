#include <iostream>
#include <cstdio>
using namespace std;

char city[2000][2000];

char clockwise[] = {'0','0','0','0','S','0','0','0','0','0','0','0','0','E','0','0','0','0','W','0','0','0','N','0','0','0'};
char anticlockwise[] = {'0','0','0','0','N','0','0','0','0','0','0','0','0','W','0','0','0','0','E','0','0','0','S','0','0','0'};

void change(int x1,int y1,int x2,int y2,int d) {

	for(int i = x1; i <= x2;i++) {
		for(int j = y1; j <= y2; j++) {
			if(d)	city[i][j] = anticlockwise[city[i][j] - 'A'];
			else 	city[i][j] = clockwise[city[i][j] - 'A'];
		}
	}
}

int main() {
	int m,n;
	while(scanf("%d %d",&m,&n) == 2) {
		for(int i = 0; i < m;i++)
			scanf("%s",city[i]);
		int num;
		scanf("%d",&num);
		char op;
		int x1,x2,y1,y2,d;
		getchar();
		for(int k = 0; k < num; k++) {
			scanf("%c",&op);
			if(op == 'C') {
				scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&d);
				change(x1-1,y1-1,x2-1,y2-1,d);
			} else if(op == 'D') {
				scanf("%d %d",&x1,&x2);
				printf("%c\n",city[x1-1][x2-1]);
			}
			getchar();
		} 
	}
	return 0;
}
