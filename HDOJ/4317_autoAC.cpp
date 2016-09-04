#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
const int M=1<<11;
const int MAX=0x1f1f1f1f;
int s[25],dp[25][M];
int t[M];
int a[11];
int main()
{
    int N,i,j,k,len,tmp,r;
    for(i=0;i<M;i++)
    {
        tmp=0;
        j=i;
        while(j!=0)
        {
            tmp+=(j&1);
            j=j>>1;
        }
        t[i]=tmp;
    }
    while(scanf("%d",&N)!=EOF)
    {
        memset(s,0,sizeof(s));;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        if(N<2)
        {
            printf("impossible\n");
            continue;
        }
        for(i=1;i<=22;i++)
        {
            for(j=0;j<N;j++)
            {
                if(a[j]&(1<<(i-1)))
                {
                    s[i]|=(1<<j);
                }
            }
            if(s[i]!=0)
            len=i+1;
        }
        memset(dp,MAX,sizeof(dp));
        dp[0][0]=0;
        for(r=1;r<=len;r++)
        {
            for(j=0;j<(1<<N);j++)
            {
                if(dp[r-1][j]<MAX)
                {
                    tmp=j&s[r];
                    for(k=tmp;k<(1<<N);k++)
                    {
                        if((k&tmp)==tmp&&
                           ((s[r]^j)&(k^tmp))==(k^tmp)&&
                           ((t[(s[r]^j)^(k^tmp)]&1)==0||t[(s[r]^j)^(k^tmp)]<N))
                           {
                               dp[r][k]=min(dp[r][k],dp[r-1][j]+(t[k^tmp]+(t[(s[r]^j)^(k^tmp)]&1))*(1<<(r-1)));
                           }
                    }
                }
            }
        }
        int Min=MAX;
        for(j=0;j<(1<<N);j++)
        {
            if((s[j]&1)==0)
                Min=min(Min,dp[len][j]);
        }
        printf("%d\n",Min);
    }
    return 0;
}
