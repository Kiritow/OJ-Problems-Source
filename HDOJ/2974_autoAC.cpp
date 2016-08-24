#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int MAX = 510000;
int pre[MAX], cnt[MAX];
int isleaf[MAX];
queue<int> q;
long long n, mod;
int prime[MAX], num_prime, cprime[MAX], isprime[MAX];
void init()
{
    scanf("%d%d", &n, &mod);
    pre[1] = -1;
    memset(isleaf, 0, sizeof(isleaf));
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &pre[i]);
        isleaf[pre[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (!isleaf[i])
            q.push(i);
}
void bfs()
{
    for (int i = 1; i <= n; i++)
        cnt[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == 1)
            continue;
        cnt[pre[u]] += cnt[u];
        isleaf[pre[u]]--;
        if (!isleaf[pre[u]])
            q.push(pre[u]);
    }
}
void prime_init()
{
    memset(isprime, 1, sizeof(isprime));
    int cnt = 0;
    isprime[0] = isprime[1] = -1;
    for (int i = 2; i < MAX; i++)
        if (isprime[i] != -1)
        {
            isprime[i] = cnt++;
            for (int j = 2; j * i < MAX; j++)
                isprime[i * j] = -1;
        }
    num_prime = 0;
    for (int i = 2; i <= MAX; i++)
        if (isprime[i] != -1)
            prime[num_prime++] = i;
}
void fac(int a, int v)
{
    for (int i = 0; a != 1; i++)
    {
        while (a % prime[i] == 0)
            cprime[i] += v, a /= prime[i];
        if (isprime[a] != -1)
            cprime[isprime[a]] += v, a = 1;
    }
}
long long pow(int a, int b)
{
    long long x = a, r = 1;
    while (b)
    {
        if (b & 1)
            r = (r * x) % mod;
        x = (x * x) % mod;
        b >>= 1;
    }
    return r;
}
long long solve()
{
    memset(cprime, 0, sizeof(cprime));
    for (int i = 2; i < n; i++)
        fac(i, 1);
    for (int i = 2; i <= n; i++)
        fac(cnt[i], -1);
    long long res = 1;
    for (int i = 0; i <= n && res != 0; i++)
        if (cprime[i])
            res = (res * pow(prime[i], cprime[i])) % mod;
    return res;
}
int main()
{
    prime_init();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        bfs();
        cout << solve() << endl;
    }
    return 0;
}
