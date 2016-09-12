#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define maxn 1005
int n1, m1, k1;
int n2, m2, k2;
bool tar1[maxn];
bool tar2[maxn];
int go1[maxn][26];
int go2[maxn][26];
int prestate[maxn*maxn];
char prechar[maxn*maxn];
bool vis[maxn*maxn];
bool check(int x)
{
    return tar1[x / n2] != tar2[x%n2];
}
int nextState(int x, int c)
{
    return go1[x / n2][c] * n2 + go2[x%n2][c];
}
int main()
{
    int T; cin >> T; int ca = 0;
    while (T--)
    {
        memset(go1, -1, sizeof(go1));
        memset(go2, -1, sizeof(go2));
        memset(tar1, 0, sizeof(tar1));
        memset(tar2, 0, sizeof(tar2));
        int accept;
        int ui, vi;
        char ci[3];
        scanf("%d%d%d", &n1, &m1, &k1);
        for (int i = 0; i < k1; ++i){
            scanf("%d", &accept);
            tar1[accept] = true;
        }
        for (int i = 0; i < m1; ++i){
            scanf("%d%d%s", &ui, &vi, ci);
            go1[ui][ci[0] - 'a'] = vi;
        }
        for (int i = 0; i <= n1; ++i){
            for (int k = 0; k < 26; ++k){
                if (go1[i][k] == -1) go1[i][k] = n1;
            }
        }
        scanf("%d%d%d", &n2, &m2, &k2);
        for (int i = 0; i < k2; ++i){
            scanf("%d", &accept);
            tar2[accept] = true;
        }
        for (int i = 0; i < m2; ++i){
            scanf("%d%d%s", &ui, &vi, ci);
            go2[ui][ci[0] - 'a'] = vi;
        }
        for (int i = 0; i <= n2; ++i){
            for (int k = 0; k < 26; ++k){
                if (go2[i][k] == -1) go2[i][k] = n2;
            }
        }
        ++n1; ++n2;
        int ans = -1;
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(0);
        vis[0] = true;
        while (!Q.empty())
        {
            int state = Q.front(); Q.pop();
            if (check(state)){
                ans = state;
                break;
            }
            for (int k = 0; k < 26; ++k){
                int nstate = nextState(state, k);
                if (!vis[nstate]){
                    Q.push(nstate);
                    vis[nstate] = true;
                    prestate[nstate] = state;
                    prechar[nstate] = k;
                }
            }
        }
        if (-1 == ans){
            printf("Case #%d: 0\n", ++ca);
            continue;
        }
        string ts;
        while (ans != 0){
            ts.push_back(char('a' + prechar[ans]));
            ans = prestate[ans];
        }
        reverse(ts.begin(), ts.end());
        printf("Case #%d: %s\n", ++ca, ts.c_str());
    }
    return 0;
}
