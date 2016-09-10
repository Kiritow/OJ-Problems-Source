#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
long long n,w,h;
long long sums[300600];
long long sumout[350560];
long long mins=50000*50000;
int main()
{
    while(~scanf("%I64d%I64d%I64d",&n,&w,&h))
    {
        int aa;
        long long sum=0;
        long long sout=0;
        for(int i=0;i<=n+w+w+1;i++)
        {
            sums[i]=sumout[i]=0;
        }
        mins=1234567891234;
        for(int i=w;i<w+n;i++)
         {
             scanf("%d",&aa);
             if(aa>h)
                sout=sout+aa-h;
            sumout[i]=sout;
             sum=sum+aa;
             sums[i]=sum;
         }
         for(int i=n+w;i<=n+w+w+1;i++)  //娉ㄦ涓涓㈢sum涔瑕存
         {
             sums[i]=sums[i-1];
             sumout[i]=sumout[i-1];
         }
         if(sum<w*h)
         {
             printf("-1\n");
             continue;
         }
         for(int i=1;i<=n+w-1;i++)
         {
             int tt=i+w-1;
             int ss=i-1;
            long long allout=sumout[tt]-sumout[ss];
             long long allsum=sums[tt]-sums[ss];
             if(allsum>=w*h)
             {
                 if(allout<mins)mins=allout;
             }
             else
             {
                 if(allout+w*h-allsum<mins)mins=allout+w*h-allsum;
             }
         }
        printf("%I64d\n",mins);
    }
    return 0;
}
