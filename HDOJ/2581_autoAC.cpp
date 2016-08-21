#include<iostream>
#include<math.h>
using namespace std;
int t, w, l, b;
struct POINT
{
    double x, y, r;
} node[12];
int parent[12];
int bomb[12][12];
int visit[12];
int isbomb[2][12];
double dist(POINT a, POINT b)
{
    return sqrt(1.0 * ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
void UFset()
{
    int i;
    for(i = 0; i < b; i++)
        parent[i] = -1;
}
int Find(int x)
{
    int s;
    for(s = x; parent[s] >= 0; s = parent[s]);
    while(s != x)
    {
        int tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}
void Union(int r1, int r2)
{
    if(parent[r1] > parent[r2])
    {
        parent[r2] += parent[r1];
        parent[r1] = r2;
    }
    else
    {
        parent[r1] += parent[r2];
        parent[r2] = r1;
    }
}
void kruskal()
{
    int i, j, k;
    double s;
    UFset();
    for(i = 0; i < b; i++)
    {
        for(j = 0; j < b; j++)
        {
            if(i != j)
            {
                s = dist(node[i], node[j]) - node[i].r - node[j].r;
                if(s <= 0 && Find(i) != Find(j))
                    Union(Find(i), Find(j));
            }
        }
    }
}
int main()
{
    int i, j, k, r, wa, wb;
    double ab;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &w, &l, &b);
        for(i = 0; i < b; i++)
            scanf("%lf%lf%lf", &node[i].x, &node[i].y, &node[i].r);
        kruskal();
        r = k = 0;
        memset(bomb, -1, 12 * 12 * sizeof(int));
        memset(isbomb, -1, 2 * 12 * sizeof(int));
        memset(visit, 0, sizeof(visit));
        for(i = 0; i < b; i++)
        {
            if(visit[i]) continue;
            visit[i] = 1;
            bomb[k][r++] = i;
            for(j = 0; j < b; j++)
            {
                if(i == j) continue;
                if(Find(i) == Find(j))
                {
                    bomb[k][r++] = j;
                    visit[j] = 1;
                }
            }
            k++;
            r = 0;
        }
        wa = wb = 0;
        for(i = 0; i < k; i++)
        {
            r = 0;
            for(j = 0; bomb[i][j] >= 0; j++)
            {
                if(node[bomb[i][j]].r - node[bomb[i][j]].x >= 0)
                {
                    r = 1;
                    break;
                }
            }
            if(r == 1)
            {
                for(j = 0; bomb[i][j] >= 0; wa++, j++)
                    isbomb[0][wa] = bomb[i][j];
            }
            r = 0;
            for(j = 0; bomb[i][j] >= 0; j++)
            {
                if(w - node[bomb[i][j]].r - node[bomb[i][j]].x <= 0)
                {
                    r = 1;
                    break;
                }
            }
            if(r == 1)
            {
                for(j = 0; bomb[i][j] >= 0; wb++, j++)
                    isbomb[1][wb] = bomb[i][j];
            }
        }
        ab = w;
        for(i = 0; isbomb[0][i] >= 0; i++)
        {
            if(w - node[isbomb[0][i]].r - node[isbomb[0][i]].x < ab)
                ab = w - node[isbomb[0][i]].r - node[isbomb[0][i]].x;
            for(j = 0; isbomb[1][j] >= 0; j++)
            {
                double s = dist(node[isbomb[0][i]], node[isbomb[1][j]]) - node[isbomb[0][i]].r
                           - node[isbomb[1][j]].r;
                if(s < ab)
                    ab = s;
            }
        }
        for(i = 0; isbomb[1][i] >= 0; i++)
        {
            if(node[isbomb[1][i]].x - node[isbomb[1][i]].r < ab)
                ab = node[isbomb[1][i]].x - node[isbomb[1][i]].r;
        }
        ab = 0.5 * ab;
        if(ab < 0) ab = 0;
        r = ceil(ab);
        printf("%d\n", r);
    }
    return 0;
}
