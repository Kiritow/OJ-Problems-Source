#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#pragma comment (linker,"/STACK:102400000,102400000")
#define maxn 70
#define MAXN 31290
#define OO (1<<31)-1
#define mod 100000000
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-6
typedef long long ll;
using namespace std;
int n,m,ans,cnt,tot,flag;
int a[2005],dp[30][2005],w[2005][2005];
int main()
{
    int i,j,k,t,num1,num2,sum;
    while(scanf("%d%d",&n,&m),n|m)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            priority_queue<int>lower;
            priority_queue<int,vector<int>,greater<int> >upper;
            sum=0;
            for(j=i;j<=n;j++)
            {
                if(upper.empty()||a[j]>=upper.top())
                {
                    upper.push(a[j]);
                    sum+=a[j];
                }
                else
                {
                    lower.push(a[j]);
                    sum-=a[j];
                }
                num1=(j-i+1)/2; num2=j-i+1-num1;  
                if(lower.size()>num1)
                {
                    upper.push(lower.top());
                    sum+=2*lower.top();
                    lower.pop();
                }
                else if(upper.size()>num2)
                {
                    lower.push(upper.top());
                    sum-=2*upper.top();
                    upper.pop();
                }
                if(num2>num1) w[i][j]=sum-upper.top();
                else w[i][j]=sum;
            }
        }
        for(i=0;i<=m;i++) for(j=0;j<=n;j++) dp[i][j]=INF;
        dp[0][0]=0;
        for(i=1;i<=m;i++)
        {
            for(j=i;j<=n;j++)
            {
                for(k=0;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+w[k+1][j]);
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
