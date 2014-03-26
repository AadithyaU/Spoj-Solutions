#include <stdio.h>
#include <math.h>
//defining pi as 2 * acos(0.0)
#define PI  2.0*acos(0.0)
#define MIN(a,b) ((a)<(b)?(a):(b))


int main() {
	
	int wid,height;
	double r1,h1,r2,h2,v1,v2;
	while(1) {
		scanf("%d %d",&wid,&height);
		//checking wether they are 0 0 
		if(!wid && !height)
			break;

		r1 = wid/(2.0*PI);
		h1 = height - 2*r1;
		r2 = MIN(height/(2.0*(PI+1.0)),wid/2.0);
		h2 = wid;
		//volume = PI * r * r * h
		v1 = (PI * r1 * r1 * h1);
		v2 = (PI * r2 * r2 * h2);
		if(v1 > v2) printf("%.3lf\n",v1);
		else printf("%.3lf\n",v2);
	}

}
