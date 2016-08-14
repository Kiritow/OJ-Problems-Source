#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const int N = 600;
const int M = 800000;
const int inf = 0x3f3f3f3f;
int n,m,k,sum,num;
struct node
{
    int to,c,next,pre;
}arc[M];
int head[N],sta[N],que[N],cnt[N],dis[N],rpath[N];
map<string,int>mp1,mp2;
void build(int s,int e,int cap)
{
    arc[num].to = e;
    arc[num].c = cap;
    arc[num].next = head[s];
    head[s] = num ++;
    arc[num - 1].pre = num;
    arc[num].pre = num - 1;
    arc[num].to = s;
    arc[num].next = head[e];
    arc[num].c = 0;
    head[e] = num ++;
}
void init()
{
    memset(head,-1,sizeof(head));
    num = 0;
    int i;
    string s1,s2;
    mp1.clear();
    mp2.clear();
    scanf("%d",&n);
    for(i = 2;i < n + 2;i ++)
    {
        cin>>s1;
        mp2[s1] = i;
        build(i,1,1);
    }
    scanf("%d",&m);
    sum = m + n + 2;
    for(i = n + 2;i <= m + 1 + n;i ++)
    {
        cin>>s1>>s2;
        mp1[s1] = i;
        build(0,i,1);
        if(mp2[s2] == 0)
        {
            mp2[s2] = sum ++;
        }
        build(i,mp2[s2],1);
    }
    scanf("%d",&k);
    for(i = 1;i <= k;i ++)
    {
        cin>>s1>>s2;
        if(mp2[s1] == 0)
        {
            mp2[s1] = sum ++;
        }
        if(mp2[s2] == 0)
        {
            mp2[s2] = sum ++;
        }
        build(mp2[s1],mp2[s2],inf);
    }
    sum --;
}
void re_Bfs()
{
    int i,front,rear;
    for(i = 0;i <= sum;i ++)
    {
        cnt[i] = 0;
        dis[i] = inf;
    }
    front = rear = 0;
    que[rear ++] = 1;
    cnt[0] ++;
    dis[1] = 0;
    while(front != rear)
    {
        int u = que[front ++];
        for(i = head[u];i != -1;i = arc[i].next)
        {
            if(arc[arc[i].pre].c == 0 || dis[arc[i].to] < inf)
                continue;
            dis[arc[i].to] = dis[u] + 1;
            cnt[dis[arc[i].to]] ++;
            que[rear ++] = arc[i].to;
        }
    }
}
void ISAP()
{
    re_Bfs();
    int i,u,v,maxflow = 0;
    for(i = 0;i <= sum;i ++)
        sta[i] = head[i];
    u = 0;
    while(dis[0] < sum)
    {
        if(u == 1)
        {
            int curflow = inf;
            for(i = 0;i != 1;i = arc[sta[i]].to)
                curflow = min(curflow,arc[sta[i]].c);
            for(i = 0;i != 1;i = arc[sta[i]].to)
            {
                arc[sta[i]].c -= curflow;
                arc[arc[sta[i]].pre].c += curflow;
            }
            maxflow += curflow;
            u = 0;
        }
        for(i = sta[u];i != -1;i = arc[i].next)
            if(arc[i].c > 0 && dis[u] == dis[arc[i].to] + 1)
                break;
        if(i != -1)
        {
            sta[u] = i;
            rpath[arc[i].to] = arc[i].pre;
            u = arc[i].to;
        }
        else
        {
            if((-- cnt[dis[u]]) == 0)
                break;
            sta[u] = head[u];
            int Min = sum;
            for(i = sta[u];i != -1;i = arc[i].next)
                if(arc[i].c > 0)
                    Min = min(Min,dis[arc[i].to]);
            dis[u] = Min + 1;
            cnt[dis[u]] ++;
            if(u != 0)
                u = arc[rpath[u]].to;
        }
    }
    printf("%d\n",m - maxflow);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --)
    {
        init();
        ISAP();
        if(t)
            puts("");
    }
    return 0;
}
