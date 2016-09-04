#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 100010;
__int64 num[N],dis[N],num1 = 0,head[N];
struct edge
{
    int rp,value,next;
}ee[N];
void init()
{
    num1 = 0;
    memset(num,0,sizeof(num));
    memset(dis,0,sizeof(dis));
    memset(head,-1,sizeof(head));
}
void addedge(int x,int y,int v)
{
    ee[num1].rp = y;
    ee[num1].value = v;
    ee[num1].next = head[x];
    head[x] = num1++;
}
void bfs(int x)
{
    queue<int> qq;
    qq.push(x);
    while(!qq.empty())
    {
        int y = qq.front();
        qq.pop();
        for(int i = head[y];i != -1;i = ee[i].next)
        {
            int k = ee[i].rp;
            dis[k] = dis[y] + ee[i].value;
            qq.push(k);
        }
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 0;i <= n;++i)
        {
            scanf("%I64d",&num[i]);
        }
        int x,y,value;
        __int64 sum = 0;
        for(int i = 1;i <= n;++i)
        {
            scanf("%d%d%d",&x,&y,&value);
            addedge(x,y,value);
            sum += value;
        }
        bfs(0);
        __int64 mmin = 2000000000;
        __int64 ss = 0;
        for(int i = 0;i <= n;++i)
        {
            ss = (sum - dis[i]) * 2 + num[i] + dis[i];
             if(ss < mmin)
            {
                mmin = ss;
            }
        }
        printf("%I64d\n",mmin);
    }
    return 0;
}
