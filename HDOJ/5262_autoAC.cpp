#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
using namespace std;
typedef long long LL;
const int maxn=100010;
const int MOD=1e9+7;
char str[maxn];
int dp[maxn];
int pos[30];
int nxt[maxn][30];
LL cnt[maxn];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int N=strlen(str);
        for(int i=0;i<26;i++)pos[i]=N+1;
        for(int i=N-1;i>=0;i--)
        {
            pos[str[i]-'a']=i+1;
            for(int j=0;j<26;j++)
                nxt[i][j]=pos[j];
        }
        dp[N+1]=0,dp[N]=1;
        for(int i=N-1;i>=0;i--)
        {
            int minv=N+1;
            for(int j=0;j<26;j++)
                minv=min(minv,dp[nxt[i][j]]+1);
            dp[i]=minv;
        }
        memset(cnt,0,sizeof(cnt));
        cnt[N]=26,cnt[N+1]=1;
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                if(dp[i]==dp[nxt[i][j]]+1)
                {
                    cnt[i]+=cnt[nxt[i][j]];
                    if(cnt[i]>=MOD)cnt[i]-=MOD;
                }
        }
        printf("Case #%d:\n%d %I64d\n",cas++,dp[0],cnt[0]);
    }
    return 0;
}
