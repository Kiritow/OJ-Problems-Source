#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 35
int n, m;
int d[maxn];
int dir[2] = {-1, 1};
bool vis[maxn];
void input()
{
    char st[5];
    scanf("%d", &m);
    m--;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", st);
        if (st[0] == 'R')
            d[i] = 1;
        else
            d[i] = 0;
    }
}
int unify(int a)
{
    return (a + n) % n;
}
void work()
{
    int s = m;
    int t = unify(0 + dir[d[m]]);
    if (t == m)
        t = unify(t + dir[d[m]]);
    int cnt = 1;
    int ret = 1;
    vis[m] = true;
    memset(vis, 0, sizeof(vis));
    while (cnt < n)
    {
        vis[s] = true;
        d[s] = 1 - d[s];
        ret++;
        if (!vis[t])
            cnt++;
        int temp = unify(s + dir[d[t]]);
        if (temp == t)
            temp = unify(temp + dir[d[t]]);
        s = t;
        t = temp;
    } 
    printf("Classmate %d got the ball last after %d tosses.\n", s + 1, ret);
}
int main()
{
    while (scanf("%d", &n), n)
    {
        input();
        work();
    }
    return 0;
}
