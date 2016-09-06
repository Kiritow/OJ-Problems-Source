#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[105];
int a[15];
int b[15];
int c[15];
long long dp[10][2];
int main()
{
    int i,j,n,tag,t,aup,bup,cup,cnt=1,x,y,z,p,q,r;
    while(scanf("%s",str)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        n=strlen(str);
        tag=0;
        aup=bup=cup=0;
        for (i=n-1;i>=0;i--)
        {
            if (str[i]=='=' || str[i]=='+') tag++;
            else
            {
                t=str[i]=='?'?-1:(str[i]-'0');
                if (tag==0) c[cup++]=t;
                if (tag==1) b[bup++]=t;
                if (tag==2) a[aup++]=t;
            }
        }
        if (cup<max(aup,bup))
        {
            printf("Case %d: 0\n",cnt++);
            continue;
        }
        for (i=aup;i<=cup;i++)
        {
            a[i]=0;
        }
        for (i=bup;i<=cup;i++)
        {
            b[i]=0;
        }
        for (i=0;i<cup;i++)
        {
            for (x=0;x<=9;x++)
            {
                if (i==aup-1 && aup!=1 && x==0 && a[i]==-1) continue;
                if (a[i]!=-1 && x>=1) continue;
                for (y=0;y<=9;y++)
                {
                    if (i==bup-1 && bup!=1 && y==0 && b[i]==-1) continue;
                    if (b[i]!=-1 && y>=1) continue;
                    for (z=0;z<=9;z++)
                    {
                        if (i==cup-1 && cup!=1 && z==0 && c[i]==-1) continue;
                        if (c[i]!=-1 && z>=1) continue;
                        p=a[i]==-1?x:a[i];
                        q=b[i]==-1?y:b[i];
                        r=c[i]==-1?z:c[i];
                        if (p+q==r)
                        {
                            if (i==0) dp[i][0]++;
                            else dp[i][0]+=dp[i-1][0];
                        }
                        if (p+q==10+r)
                        {
                            if (i==0) dp[i][1]++;
                            else dp[i][1]+=dp[i-1][0];
                        }
                        if (p+q+1==r && i!=0)
                        {
                            dp[i][0]+=dp[i-1][1];
                        }
                        if (p+q+1==r+10 && i!=0)
                        {
                            dp[i][1]+=dp[i-1][1];
                        }
                    }
                }
            }
         }
        printf("Case %d: %I64d\n",cnt++,dp[cup-1][0]);
    }
    return 0;
}
