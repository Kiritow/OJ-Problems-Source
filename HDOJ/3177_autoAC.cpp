#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int a[1005],b[1005];
    int i,j,e;
    int n,v,c;
    cin>>n;
    for(e=1;e<=n;e++)
    {
        cin>>v>>c;
        for(i=0;i<c;i++)
        {
           cin>>a[i]>>b[i];             
        }         
        for(i=0;i<c-1;i++)
           for(j=i+1;j<c;j++)
              if(b[i]-a[i]<b[j]-a[j])
              {
                swap(a[i],a[j]);
                swap(b[i],b[j]);           
              }
       for(i=0;i<c;i++)
       {
          if(v>=b[i])
          {
            v=v-a[i];         
          }
          else
          {
             v=-1;
             break; 
          }
       }  
          if(v==-1)
          {
            cout<<"No"<<endl;      
          }
          else
          {
            cout<<"Yes"<<endl;  
          }
    }
    return 0;
}
