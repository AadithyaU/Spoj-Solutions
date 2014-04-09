#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
    int t;
    char str1[100],str2[100],opr[2],opr1[2],str5[100];
    
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
    cin>>str1>>opr>>str2>>opr1>>str5;
    
        if((strchr(str1,'m'))!=NULL)
       
        {
                           int y=atoi(str2);
                           int z=atoi(str5);
                           int l=z-y;
                          
                         cout<<l<<" + "<<y<<" = "<<z<<endl;
                                 }
           else if ((strchr(str2,'m'))!=NULL)
           {
             
                           int y=atoi(str1);
                           int z=atoi(str5);
                           int l=z-y;
                          cout<<y<<" + "<<l<<" = "<<z<<endl;
                
          }
            else if ((strchr(str5,'m'))!=NULL)
            {
                           int y=atoi(str1);
                           int z=atoi(str2);
                           int l=z+y;
                        
                           cout<<y<<" + "<<z<<" = "<<l<<endl;
                 }
            }
    return 0;
    
    }
