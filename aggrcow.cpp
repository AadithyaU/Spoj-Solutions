#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
using namespace std;
#define ll long long int
 
#define MX 100005
int barns[MX];
int n,k;
int distribute( int m ){
    int p = 1;//placed at first barn.
    int last_barn_pos = barns[0];
    for( int i=1;i<n;i++){
        if( (barns[i] - last_barn_pos) >=m ){
            last_barn_pos = barns[i];
            p++;
        }
    }
    return p; //no. of cows placed.
}
int main(){
    int i,j;
    int t,cows;
    int mindis= 0; 
    int placed;
    int low, high;
    int mid = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&cows);
        for(i=0;i<n;i++){
            scanf("%d",&barns[i]);
        }
        sort( barns , barns+n);
        mindis = 0;
        low=0;
        high = barns[n-1] - barns[0];
        while( low<=high){
            mid = (low+high)/2;
            placed = distribute( mid );
            if( placed < cows ){ 
                high = mid - 1;
            }
            else{
                low = mid + 1;
                if( mid > mindis ) mindis = mid;
            }
        }
        printf("%d\n",mindis);
    }
    return 0;
}
