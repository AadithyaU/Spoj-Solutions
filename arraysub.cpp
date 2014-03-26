#include <iostream>
using namespace std;
#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
main()
{
    long n;
    cin >> n;
    long *arr = new  long[n];
    for( long i=0;i<n;i++)
        cin >> arr[i];
     long k;
    cin >> k;
     long max=arr[0];
    for(long i=1;i<k;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    if(k!=n)
    cout<<max<<" ";
    else cout<<max;
    for( long i=k;i<n;i++)
    {
        if(arr[i-k]==max)
        {max=-1;
        for(int j=i-k+1;j<=i;j++)
        if(arr[j]>max)
        max=arr[j];
        if(i!=n)
        cout<<max<<" ";
        else cout<<max;

        }
        else{
        if(arr[i]>max)
        {   max=arr[i];

        if(i!=n)
        cout<<max<<" ";
        else 
        cout<<max;
        }
        else
        {
        if(i!=n)
        cout<<max<<" ";
        else cout<<max;}
        }
    }

        cout<<endl;
    return(0);
}
