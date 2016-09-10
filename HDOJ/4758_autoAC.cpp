#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MOD = 1e9+7;
int dp[110][110][220][4];
int n,m;
    int ne[420][2],fail[420],en[420];
    int root,L;
    inline int change(char ch)
    {
        if(ch == 'R')return 0;
        else return 1;
    }
    inline int newnode()
    {
        for(int i = 0;i < 2;i++)
            ne[L][i] = -1;
        en[L++] = 0;
        return L-1;
    }
    inline void init()
    {
        L = 0;
        root = newnode();
    }
    inline void insert(char buf[],int id)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(ne[now][change(buf[i])] == -1)
                ne[now][change(buf[i])] = newnode();
            now = ne[now][change(buf[i])];
        }
        en[now] |= (1<<id);
    }
    inline void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 2;i++)
            if(ne[root][i] == -1)
                ne[root][i] = root;
            else
            {
                fail[ne[root][i]] = root;
                Q.push(ne[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            en[now] |= en[fail[now]];
            for(int i = 0;i < 2;i++)
                if(ne[now][i] == -1)
                    ne[now][i] = ne[fail[now]][i];
                else
                {
                    fail[ne[now][i]]=ne[fail[now]][i];
                    Q.push(ne[now][i]);
                }
        }
    }
    inline int solve()
    {
        dp[0][0][0][0] = 1;
        int ret = 0;
            for(int x = 0;x <= n;x++)
                for(int y = 0;y <= m;y++)
                    for(int i = 0;i < L;i++)
                    for(int k = 0;k < 4;k++)
                    {
                        if(dp[x][y][i][k] == 0)continue;
                        if(x < n)
                        {
                            int nxt = ne[i][0];
                            dp[x+1][y][nxt][k|en[nxt]] += dp[x][y][i][k];
                            if(dp[x+1][y][nxt][k|en[nxt]] >= MOD)
                                dp[x+1][y][nxt][k|en[nxt]] -= MOD;
                        }
                        if(y < m)
                        {
                            int nxt = ne[i][1];
                            dp[x][y+1][nxt][k|en[nxt]] += dp[x][y][i][k];
                            if(dp[x][y+1][nxt][k|en[nxt]] >= MOD)
                                dp[x][y+1][nxt][k|en[nxt]] -= MOD;
                        }
                    }
        for(int i = 0;i < L;i++)
        {
            ret += dp[n][m][i][3];
            if(ret >= MOD)ret -= MOD;
        }
        return ret;
    }
char str[210];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0;i < 2;i++)
        {
            scanf("%s",str);
            insert(str,i);
        }
        build();
        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= m;j++)
                for(int x = 0; x < L;x++)
                    for(int y = 0;y < 4;y++)
                        dp[i][j][x][y] = 0;
        printf("%d\n",solve());
    }
    return 0;
}
