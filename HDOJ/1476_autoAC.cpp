#include<cstdio>
#include<iostream>
using namespace std;
int C;
int DI(int t)
{
     if(t==0) return 0;
     else if(t>=1&&t<=10) return -C;
     else return (t-10)*(t-10);
}
int main()
{
   int n,L,count=0,i,j;
   int t[1010],lecture[1010],DP[1010];
   while(scanf("%d",&n),n)
   {
       count++;
       if(count>1)
           printf("\n");
       scanf("%d %d",&L,&C);
       for(i=1;i<=n;i++)
           scanf("%d",&t[i]);
       lecture[0]=DP[0]=0;
       lecture[1]=1;DP[1]=DI(L-t[1]);
       for(i=2;i<=n;i++)
       {
           lecture[i]=lecture[i-1]+1;
           DP[i]=DP[i-1]+DI(L-t[i]);
           int sum=t[i];
           for(j=i-1;j>0;j--)
           {
               sum+=t[j];
               if(sum<=L)
               {
                   int a=DP[j-1]+DI(L-sum);
                   if(lecture[i]>lecture[j-1]+1)
                   {
                       lecture[i]=lecture[j-1]+1;
                           DP[i]=a;
                   }
                   else if(lecture[i]==lecture[j-1]+1)
                       DP[i]=DP[i]>a?a:DP[i];
               }
               else
                   break;
           }
       }
       printf("Case %d:\n\nMinimum number of lectures: %d\nTotal dissatisfaction index: %d\n",count,lecture[n],DP[n]);
   }
   return 0;
}
