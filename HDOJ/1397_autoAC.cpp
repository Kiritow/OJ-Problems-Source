#include<iostream>
#define N 4000
#define MAX 32770
using namespace std;
int su[N],tot;
void prime()
{
    tot=1;
    su[0]=2;
    for(int i=3;i<MAX;i+=2)
    {
        int ok=1;
        for(int j=0;j<tot;j++)
        {
            if(su[j]*su[j]>i) break;
            if(i%su[j]==0) {ok=0;break;}
        }
        if(ok) su[tot++]=i;
    }
}
int main()
{
    int n;
    prime();
    while(cin>>n&&n)
    {
       int num=0;
       for(int i=0;2*su[i]<=n;i++)
       {
           int a=0,b=tot;
           while(a<b)
           {
              int mid=(a+b)/2;
              if(su[i]+su[mid]==n) {num++;break;}
              if(su[i]+su[mid]<n) a=mid+1;
              if(su[i]+su[mid]>n) b=mid;
           }
       }
       cout<<num<<endl;
    }
    return 0;
}
