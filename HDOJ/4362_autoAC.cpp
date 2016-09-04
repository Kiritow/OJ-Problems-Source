#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
const int Ni = 1005;
const int inf=1<<27;
struct node{
    int x,w;
    bool operator < (const node &a) const
    {
        return x<a.x;
    }
}arr[52][Ni];
struct qnode{
    int val,x;
    bool operator < (const qnode &a) const
    {
        if(val>a.val) return 1;
        if(val==a.val&&x>a.x) return 1;
        return 0;
    }
};
int dp[52][Ni];
int n,m;
inline void cInit()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j].x);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j].w);
        }
    }
    for(i=0;i<n;i++)
    {
        sort(arr[i],arr[i]+m);
    }
}
int main()
{
    int cs,x,i,j,ans;
    cin>>cs;
    while(cs--)
    {
        scanf("%d%d%d",&n,&m,&x);
        cInit();
        for(j=0;j<m;j++)
        {
            dp[0][j]=x-arr[0][j].x;
            if(dp[0][j]<0) dp[0][j]=-dp[0][j];
            dp[0][j]+=arr[0][j].w;
        }
        for(i=1;i<n;i++)
        {
            priority_queue<qnode> ql,qr;
            qnode qn;
            for(j=0;j<m;j++)
            {
                qn.val=dp[i-1][j]+arr[i-1][j].x;
                qn.x=arr[i-1][j].x;
                qr.push(qn);
            }
            int k=0;
            for(j=0;j<m;j++)
            {
                dp[i][j]=inf;
                while(k<m&&arr[i-1][k].x<=arr[i][j].x)
                {
                    qn.val=dp[i-1][k]-arr[i-1][k].x;
                    qn.x=arr[i-1][k].x;
                    ql.push(qn);
                    k++;
                }
                if(!ql.empty())
                {
                    qn=ql.top();
                    dp[i][j]=min(dp[i][j],qn.val+arr[i][j].x+arr[i][j].w);
                }
                if(!qr.empty())
                {
                    qn=qr.top();
                    while(!qr.empty()&&qn.x<arr[i][j].x)
                    {
                        qr.pop();
                        qn=qr.top();
                    }
                    if(qn.x>=arr[i][j].x)
                    dp[i][j]=min(dp[i][j],qn.val-arr[i][j].x+arr[i][j].w);
                }
            }
        }
        ans=inf;
        for(i=0;i<m;i++)
        {
            if(ans>dp[n-1][i])
                ans=dp[n-1][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
