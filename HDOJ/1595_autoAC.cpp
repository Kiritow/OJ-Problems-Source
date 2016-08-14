#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int map[1005][1005];
int pre[1005];
int dis[1005];
bool s[1005];
class path
{
public:
    int start, end;
};
vector<path>p;
void dijkstra(int n)
{
    memset(s,false,sizeof(s));
    int i, j, k;
    for (i = 2; i <= n; i++)          
    {
        dis[i] = map[1][i];         
        if (map[1][i] != -1)
        {
            pre[i] = 1;
        }
        else
        {
            pre[i] = -1;
        }
    }
    pre[1] = -1;
    dis[1] = 0;
    s[1] = true;        
    for (j = 2; j <= n; j++)
    {
        int min = 100000;
        int u;
        for (i = 1; i <= n; i++)         
        {
            if (!s[i] && dis[i] != -1)
            {
                if (min > dis[i])
                {
                    min = dis[i];
                    u = i;
                }
            }
        }
        s[u] = true;
        for (k = 1; k <= n;k++)
        {
            if (!s[k] && map[u][k]!=-1)
            {            
                    if ((dis[k] > dis[u] + map[u][k])||dis[k]==-1)
                    {
                        dis[k] = dis[u] + map[u][k];
                        pre[k] = u;
                    }        
            }
        }
    }
}
void findpath(int n)
{
    p.clear();
    int i = n;
    while (pre[i]!=-1)
    {
        path tmp;
        tmp.start = pre[i];
        tmp.end = i;
        p.push_back(tmp);
        i=pre[i];
    }
}
int main()
{
    int n, m;
    while (cin>>n>>m)
    {
        int i,k;
        int start, end, weight;
        for (i = 1; i <= n;i++)
        for (k = 1; k <= n; k++)
        {
            map[i][k] = -1;
        }
        for (i = 0; i < m; i++)
        {
            cin >> start >> end >> weight;
            map[start][end] = weight;
            map[end][start] = weight;
        }
        dijkstra(n);
        findpath(n);
        int num,max=-1;
        for (num = 0; num < p.size(); num++)
        {
            path tmp = p[num];
            int t;
            t = map[tmp.start][tmp.end];
            map[tmp.start][tmp.end] = -1;
            map[tmp.end][tmp.start] = -1;
            dijkstra(n);
            if (dis[n]>max)
                max = dis[n];
            map[tmp.start][tmp.end] = t;
            map[tmp.end][tmp.start] = t;
        }
        cout << max << endl;
    }
    return 0;
}
