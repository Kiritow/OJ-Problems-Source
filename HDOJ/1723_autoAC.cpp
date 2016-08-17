#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{   int a[50];
   int n,m;
   int i,j;
     while(cin>>n>>m && (n||m))
     {
         memset(a,0,sizeof(a));
         a[1]=1;
         for(i=1;i<=n;i++)
              for(j=1;j<=m;j++)
                if(i+j<=n)
                 a[i+j]+=a[i];
              cout<<a[n]<<endl;
     }
    return 0;
}
