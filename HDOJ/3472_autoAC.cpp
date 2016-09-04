#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 30;
const int MAXM = 10000;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw = 0)
{
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    edge[tol].flow = 0;
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].next = head[v];
    edge[tol].flow = 0;
    head[v] = tol++;
}
int sap(int start,int end,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            for(int i = pre[u];i != -1;i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u]; i != -1;i = pre[edge[i^1].to])
            {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1;i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
            {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u];  i != -1;i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]] --;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}
int in[30],out[30];
int F[30];
int find(int x)
{
    if(F[x] == -1)return x;
    else return F[x] = find(F[x]);
}
void bing(int u,int v)
{
    int t1 = find(u), t2 = find(v);
    if(t1 != t2)F[t1] = t2;
}
char str[100];
int main()
{
    int T,n;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        memset(F,-1,sizeof(F));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        init();
        int k;
        int s = -1;
        while(n--)
        {
            scanf("%s%d",str,&k);
            int len = strlen(str);
            int u = str[0] - 'a';
            int v = str[len-1] - 'a';
            out[u]++;
            in[v]++;
            s = u;
            if(k == 1)
                addedge(u,v,1);
            bing(u,v);
        }
        bool flag = true;
        int cnt = 0;
        int s1 = -1, s2 = -1;
        for(int i = 0;i < 26;i++)
            if(in[i] || out[i])
            {
                if(find(i) != find(s))
                {
                    flag = false;
                    break;
                }
                if((in[i] + out[i])&1)
                {
                    cnt++;
                    if(s1 == -1)s1 = i;
                    else s2 = i;
                }
            }
        if(cnt != 0 && cnt != 2)flag = false;
        if(!flag)
        {
            printf("Case %d: Poor boy!\n",iCase);
            continue;
        }
        if(cnt == 2)
        {
            out[s1]++;
            in[s2]++;
            addedge(s1,s2,1);
        }
        for(int i = 0;i < 26;i++)
        {
            if(out[i] - in[i] > 0)
                addedge(26,i,(out[i] - in[i])/2);
            else if(in[i] - out[i] > 0)
                addedge(i,27,(in[i] - out[i])/2);
        }
        sap(26,27,28);
        for(int i = head[26];i != -1;i = edge[i].next)
            if(edge[i].cap > 0 && edge[i].cap > edge[i].flow)
            {
                flag = false;
                break;
            }
        if(flag)printf("Case %d: Well done!\n",iCase);
        else printf("Case %d: Poor boy!\n",iCase);
    }
    return 0;
}
