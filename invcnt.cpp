#include <iostream>
#include <cstdio>
#define sd(x) scanf("%d",&x) 
using namespace std;
long long merge(int a[],int low,int mid,int high,int temp[]) {
	int i ,j,k;
	long long count = 0;
	i = low;
	j = mid+1;
	while(i <= mid) {
		while( j <= high) {
			if( a[i] < a[j]) break;
			j++;
		}
		count+= j - (mid+1);
		i++;
	}
	i = low;
	k = low;
	j = mid+1;
	while(1) {
		if( i > mid || j > high) break;
		if(a[i] > a[j]) temp[k++] = a[j++];
		else if(a[i] < a[j]) temp[k++] = a[i++];
		else {
			temp[k++] = a[i++];
			j++;
		}
	}
	while( i <= mid)
		temp[k++] = a[i++];
	while( j <= high)
		temp[k++] = a[j++];
	for(k = low;k <= high; k++)
		a[k] = temp[k];
	return count;
}
long long mergesort(int a[],int low,int high,int temp[]) {
	if(low < high) {
		int mid = (low + high)/2;
		long long ans = 0;
		ans=mergesort(a,low,mid,temp);
		ans+=mergesort(a,mid+1,high,temp);
		ans+=merge(a,low,mid,high,temp);
		return ans;
	}
	return 0;
}
int main() {
	int t,n,i,j;
	sd(t);
	while(t--) {
		sd(n);
		int a[n],temp[n];
		for(i = 0; i < n; i++) 
			sd(a[i]);
		printf("%llu\n",mergesort(a,0,n-1,temp));
	}
}
