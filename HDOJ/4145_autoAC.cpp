#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
struct enemy
{
    int x, y, da, db;
}p[N], c1, c2;
bool cmp(enemy a, enemy b)
{
    return a.da < b.da;
}
int dist(enemy a, enemy b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    int ncase;
    int num;
    int ans, res, onlyb;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d%d%d%d", &c1.x, &c1.y, &c2.x, &c2.y);
        scanf("%d", &num);
        for(int i = 0; i < num; ++i)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].da = dist(c1, p[i]);
            p[i].db = dist(c2, p[i]);
        }
        sort(p, p + num, cmp);
        res = p[num - 1].da; 
        ans = 0;
        for(int i = num - 2; i >= 0; --i)
        {
            ans = max(ans, p[i + 1].db);
            res = min(res, ans + p[i].da);
        }
        ans = max(ans, p[0].db);
        res = min(res, ans); 
        printf("%d\n", res);
    }
    return 0;
}
