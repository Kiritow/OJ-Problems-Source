#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 2005
int fn, gn, hn, en;
int f[maxn], g[maxn], h[maxn], e[maxn];
void input()
{
    scanf("%d", &fn);
    for (int i = fn -1; i >=0; i--)
        scanf("%d", &f[i]);
    scanf("%d", &gn);
    for (int i = gn -1; i >=0; i--)
        scanf("%d", &g[i]);
    scanf("%d", &hn);
    for (int i = hn -1; i >=0; i--)
        scanf("%d", &h[i]);
}
void mul()
{
    memset(e, 0, sizeof(e));
    for (int i =0; i < fn; i++)
        for (int j =0; j < gn; j++)
            e[i + j] ^= f[i] * g[j];
    en = fn + gn;
    while (en >=0&& e[en] ==0)
        en--;
    en++;
}
void mo()
{
    while (en >= hn)
    {
        int d = en - hn;
        for (int i = hn -1; i >=0; i--)
            e[i + d] ^= h[i];
        while (en >=0&& e[en] ==0)
            en--;
        en++;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        mul();
        mo();
        printf("%d", en);
        for (int i = en -1; i >=0; i--)
            printf(" %d", e[i]);
        putchar('\n');
    }
    return 0;
}
