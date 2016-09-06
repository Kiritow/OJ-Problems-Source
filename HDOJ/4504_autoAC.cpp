#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
__int64 d[100][300];
int main()
{
    __int64 A,B,t;
    while(scanf("%I64d%I64d%I64d",&A,&B,&t)!=-1)
    {
        t/=15;
        B+=t/2;
        t=(t+1)/2;
        d[0][0]=1;
        for(__int64 j=1;j<=3*t;j++)
        {
            d[0][j]=0;
        }
        for(__int64 i=1;i<=t;i++)
        {
            d[i][0]=0;
            d[i][1]=d[i-1][0];
            d[i][2]=d[i-1][0]+d[i-1][1];
            for(__int64 j=3;j<=3*t;j++)
            {
                d[i][j]=d[i-1][j-1]+d[i-1][j-2]+d[i-1][j-3];
            }
        }
        __int64 ans=0;
        __int64 j=B-A+1;
        if(j<0)
        {
            j=0;
        }
        for(;j<=3*t;j++)
        {
            ans+=d[t][j];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
