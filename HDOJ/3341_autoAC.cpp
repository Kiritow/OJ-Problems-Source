#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Trie
{
    int next[510][4],fail[510];
    int end[510];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 4;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    int getch(char ch)
    {
        if(ch == 'A')return 0;
        else if(ch == 'C')return 1;
        else if(ch == 'G')return 2;
        else return 3;
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][getch(buf[i])] == -1)
                next[now][getch(buf[i])] = newnode();
            now = next[now][getch(buf[i])];
        }
        end[now] ++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 4;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            end[now] += end[fail[now]];/********/
            for(int i = 0;i < 4;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int dp[510][11*11*11*11+5];
    int bit[4];
    int num[4];
    int solve(char buf[])
    {
        int len = strlen(buf);
        memset(num,0,sizeof(num));
        for(int i = 0;i < len;i++)
            num[getch(buf[i])]++;
        bit[0] = (num[1]+1)*(num[2]+1)*(num[3]+1);
        bit[1] = (num[2]+1)*(num[3]+1);
        bit[2] = (num[3]+1);
        bit[3] = 1;
        memset(dp,-1,sizeof(dp));
        dp[root][0] = 0;
        for(int A = 0;A <= num[0];A++)
            for(int B = 0;B <= num[1];B++)
                for(int C = 0;C <= num[2];C++)
                    for(int D = 0;D <= num[3];D++)
                    {
                        int s = A*bit[0] + B*bit[1] + C*bit[2] + D*bit[3];
                        for(int i = 0;i < L;i++)
                            if(dp[i][s] >= 0)
                            {
                                for(int k = 0;k < 4;k++)
                                {
                                    if(k == 0 && A == num[0])continue;
                                    if(k == 1 && B == num[1])continue;
                                    if(k == 2 && C == num[2])continue;
                                    if(k == 3 && D == num[3])continue;
                                    dp[next[i][k]][s+bit[k]] = max(dp[next[i][k]][s+bit[k]],dp[i][s]+end[next[i][k]]);
                                }
                            }
                    }
        int ans = 0;
        int status = num[0]*bit[0] + num[1]*bit[1] + num[2]*bit[2] + num[3]*bit[3];
        for(int i = 0;i < L;i++)
            ans = max(ans,dp[i][status]);
        return ans;
    }
};
char buf[50];
Trie ac;
int main()
{
    int n;
    int iCase = 0;
    while( scanf("%d",&n) == 1 && n)
    {
        iCase++;
        ac.init();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("Case %d: %d\n",iCase,ac.solve(buf));
    }
    return 0;
}
