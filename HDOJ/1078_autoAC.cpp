#include <iostream>
#include <utility>
using namespace std;
const int N = 102;
int graph[N][N];
int collect[N][N];
int n, k, ans;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isBound(int x, int y)
{
    if(x < 0 || y < 0)
        return false;
    if(x >= n || y >= n)
        return false;
    return true;
}
int memory(pair<int, int> p )
{
    int i, j, maxb = 0, tmax;
    pair<int , int> cs;
    if(collect[p.first][p.second] > 0)
        return collect[p.first][p.second];
    for(i = 0; i < 4; i++)
    {
        cs = p;
        for(j = 0; j < k; j++)
        {
            cs.first += dir[i][0];
            cs.second += dir[i][1];
            if(!isBound(cs.first, cs.second))
                break;
            if(graph[cs.first][cs.second] > graph[p.first][p.second])
            {
                tmax = memory(cs);
                if(tmax > maxb)
                    maxb = tmax;
            }
        }
    }
    collect[p.first][p.second] = maxb + graph[p.first][p.second];
    return collect[p.first][p.second];
}
int main()
{
    pair<int, int> p;
    int i, j;
    while(scanf("%d%d", &n, &k))
    {
        if(n == -1 && k == -1)
            break;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%d", &graph[i][j]);
                collect[i][j] = 0;
            }
        p.first = p.second = 0;
        printf("%d\n", memory(p));
    }
    return 0;
}
