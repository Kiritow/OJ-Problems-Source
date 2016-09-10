#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   int t,n,a,b,c;
   int q[5],p[5];
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       for(int i=0;i<n;i++)
             {
                 scanf("%d %d %d",&a,&b,&c);
                p[i]=q[i]=max(max(a,b),c);
             }
       sort(p,p+n,cmp);
       for(int i=0;i<n;i++)
        if(q[0]==p[i])
          printf("%d",i+1);
       for(int j=1;j<n;j++)
        for(int i=0;i<n;i++)
       if(q[j]==p[i])
       {
           printf(" %d",i+1);
           continue;
       }
       printf("\n");
   }
    return 0;
}
