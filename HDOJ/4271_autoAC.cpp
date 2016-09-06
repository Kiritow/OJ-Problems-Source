#include <iostream>
#include <cstdio>
#include <string.h>
#define MIN(a , b) ((a) < (b) ? (a) : (b))
using namespace std;
const int inf = 1 << 29;
const int maxn = 100002;
const int maxm = 12;
char str[maxn],dtr[maxn + maxm],dic[maxm][maxm],huan[maxm];
int dp[maxn + maxm][maxm];
int m,len,llen;
int CompareString(char *s1,char *s2,int l1,int l2) 
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=l2;i++)
    {
        dp[0][i] = i;
    }
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            dp[i][j] = MIN(dp[i-1][j-1] + cost , MIN(dp[i-1][j] + 1 , dp[i][j-1] + 1));
        }
    }
    int res = inf;
    for(int i=0;i<=l1;i++)
    {
        res = MIN(res , dp[i][l2]);
    }
    return res;
}
void solve()
{
    len = strlen(str);
    strcpy(dtr , str);
    for(int i=0;i<maxm;i++)
    {
        dtr[i+len] = str[i];
    }
    llen = len + maxm;
    dtr[llen] = '\0';
    scanf("%d",&m);
    getchar();
    int pos = -1,ans = inf;
    for(int i=0;i<m;i++)
    {
        scanf("%s",dic[i]);
        int l = strlen(dic[i]);
        if((l << 1) < len)
        {
            int tmp = CompareString(dtr , dic[i] , llen , l);
            if(tmp < ans || (tmp == ans && strcmp(dic[pos] , dic[i]) > 0))
            {
                ans = tmp;
                pos = i;
            }
        }
        else
        {
            for(int s=0;s<len;s++)
            {
                for(int j=0;j<len;j++)
                {
                    huan[j] = str[(s+j) % len];
                }
                huan[len] = '\0';
                int tmp = CompareString(huan , dic[i] , len , l);
                if(tmp < ans || (tmp == ans && strcmp(dic[pos] , dic[i]) > 0))
                {
                    ans = tmp;
                    pos = i;
                }
            }
        }
    }
    printf("%s %d\n",dic[pos],ans);
    return;
}
int main()
{
    while(~scanf("%s",str))
    {
        solve();
    }
    return 0;
}
