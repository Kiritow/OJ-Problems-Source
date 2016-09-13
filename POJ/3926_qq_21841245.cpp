#include <cstdio>
#include <iostream>

using namespace std;

const int Nmax = 105;
const int Mmax = 10005;

int N, M, K;
int w[Nmax][Mmax], t[Nmax][Mmax];
int dp[3][Mmax];

namespace queue {
    int q[Mmax], head, tail;
    
    inline void init() { head = 0, tail = -1; q[0] = 0; }
    inline void push_back(int x) { q[++tail] = x; }
    inline void pop_back() { --tail; }
    inline void pop_front() { ++head; }
    inline int front() { return q[head]; }
    inline int back() { return q[tail]; }
    inline int size() { return tail - head + 1; }
}

int main()
{
    while (~scanf("%d%d%d", &N, &M, &K) && (N || M || K))
    {
        for (int i = 0; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            scanf("%d", &w[i][j]);
            w[i][j] += w[i][j - 1];
        }
        for (int i = 0; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            scanf("%d", &t[i][j]);
            t[i][j] += t[i][j - 1];
        }
        
        using namespace queue; memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N + 1; ++i)
        {
            int nw = i & 1, pr = nw ^ 1;
            
            init(); for (int j = 0; j <= M; ++j)
            {
                while (size() > 0 && t[i - 1][j] - t[i - 1][front()] > K) pop_front();
                dp[nw][j] = !size() ? dp[pr][j] : max(dp[pr][j], dp[pr][front()] + w[i - 1][j] - w[i - 1][front()]);
                while (size() > 0 && dp[pr][back()] - w[i - 1][back()] < dp[pr][j] - w[i - 1][j]) pop_back();
                push_back(j);
            }
            init(); for (int j = M; ~j; --j)
            {
                while (size() > 0 && t[i - 1][front()] - t[i - 1][j] > K) pop_front();
                dp[nw][j] = !size() ? dp[nw][j] : max(dp[nw][j], dp[pr][front()] + w[i - 1][front()] - w[i - 1][j]);
                while (size() > 0 && dp[pr][back()] + w[i - 1][back()] < dp[pr][j] + w[i - 1][j]) pop_back();
                push_back(j);
            }
        }
        int ans = 0;
        for (int i = 0; i <= M; ++i) ans = max(ans, dp[(N & 1) ^ 1][i]);
        printf("%d\n", ans);
    }
    return 0;
}
