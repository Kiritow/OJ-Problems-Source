#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int v[105],num[105];
int dp[100010];
int main()
{
    int i,j,k,n,m,tmp,sum;
    while(cin>>n>>m,(m+n))
    {
        sum=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;i<=n;i++)
        {
            cin>>v[i];
        }
        for(i=1;i<=n;i++)
        {
            cin>>num[i];
        }
        for(i=1;i<=n;i++)
        {
            tmp=num[i];
            for(j=1;j<=tmp;j*=2)
            {
                for(k=m;k>=j*v[i];k--)
                {
                   dp[k]+=dp[k-j*v[i]];
                }
                tmp-=j;
            }
            if(tmp)
            {
                for(k=m;k>=tmp*v[i];k--)
                {
                    dp[k]+=dp[k-tmp*v[i]];
                }
            }
        }
        for(j=1;j<=m;j++)
        {
            if(dp[j])
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
}
