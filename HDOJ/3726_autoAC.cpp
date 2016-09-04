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
#define Key_value ch[ch[root][1]][0]
const int MAXN = 20010;
int pre[MAXN],ch[MAXN][2],key[MAXN],size[MAXN];
int root;
void NewNode(int &r,int father,int loc,int k)
{
    r = loc;
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    key[r] = k;
    size[r] = 1;
}
void push_up(int r)
{
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
}
void Init()
{
    root = 0;
    ch[root][0] = ch[root][1] = key[root] = size[root] = 0;
    pre[root] = 0;
}
void Rotate(int x,int kind)
{
    int y = pre[x];
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    push_up(y);
}
void Splay(int r,int goal)
{
    while(pre[r] != goal)
    {
        if(pre[pre[r]] == goal)
            Rotate(r,ch[pre[r]][0] == r);
        else
        {
            int y = pre[r];
            int kind = ch[pre[y]][0]==y;
            if(ch[y][kind] == r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    push_up(r);
    if(goal == 0) root = r;
}
int Get_kth(int r,int k)
{
    int t = size[ch[r][0]] + 1;
    if(t == k)return r;
    if(t > k)return Get_kth(ch[r][0],k);
    else return Get_kth(ch[r][1],k-t);
}
void Insert(int loc,int k)
{
    int r = root;
    if(r == 0)
    {
        NewNode(root,0,loc,k);
        return;
    }
    while(ch[r][key[r]<k])
        r = ch[r][key[r]<k];
    NewNode(ch[r][key[r]<k],r,loc,k);
    Splay(ch[r][key[r]<k],0);
}
struct Edge
{
    int u,v;
}edge[60010];
bool used[60010];
int to[400010];
int ne[400010];
int head[20010];
int tot;
void add_value(int x,int v)
{
    to[tot] = v;
    ne[tot] = head[x];
    head[x] = tot++;
}
struct Query
{
    char op[5];
    int x,y;
}query[400010];
int q_num;
int F[20010];
int find(int x)
{
    if(F[x] == -1)return x;
    else return F[x] = find(F[x]);
}
void erase(int r)
{
    if(!r)return;
    erase(ch[r][0]);
    erase(ch[r][1]);
    Insert(r,to[head[r]]);
}
int Get_Min(int r)
{
    while(ch[r][0])
    {
        r = ch[r][0];
    }
    return r;
}
void Delete()
{
    if(ch[root][0] == 0 || ch[root][1] == 0)
    {
        root = ch[root][0] + ch[root][1];
        pre[root] = 0;
        return;
    }
    int k = Get_Min(ch[root][1]);
    Splay(k,root);
    Key_value = ch[root][0];
    root = ch[root][1];
    pre[ch[root][0]] = root;
    pre[root] = 0;
    push_up(root);
}
void bing(int x,int y)
{
    int t1 = find(x),t2 = find(y);
    if(t1 == t2)return;
    F[t1] = t2;
    Splay(t1,0);
    Splay(t2,0);
    if(size[t1] > size[t2])
        swap(t1,t2);
    root = t2;
    erase(t1);
}
int main()
{
    int N,M;
    int iCase = 0;
    while(scanf("%d%d",&N,&M) == 2 )
    {
        if(N == 0 && M == 0) break;
        iCase++;
        memset(head,-1,sizeof(head));
        tot = 0;
        int v;
        for(int i = 1;i <= N;i++)
        {
            scanf("%d",&v);
            add_value(i,v);
        }
        for(int i = 1;i <= M;i++)
        {
            scanf("%d%d",&edge[i].u,&edge[i].v);
        }
        q_num = 0;
        memset(used,false,sizeof(used));
        while(scanf("%s",&query[q_num].op) == 1)
        {
            if(query[q_num].op[0] == 'E')break;
            if(query[q_num].op[0] == 'D')
            {
                scanf("%d",&query[q_num].x);
                used[query[q_num].x] = true;
            }
            else if(query[q_num].op[0] == 'Q')
                scanf("%d%d",&query[q_num].x,&query[q_num].y);
            else if(query[q_num].op[0] == 'C')
            {
                scanf("%d%d",&query[q_num].x,&query[q_num].y);
                add_value(query[q_num].x,query[q_num].y);
            }
            q_num++;
        }
        memset(F,-1,sizeof(F));
        for(int i = 1;i <= N;i++)
            NewNode(root,0,i,to[head[i]]);
        for(int i = 1;i <= M;i++)
            if(!used[i])
                bing(edge[i].u,edge[i].v);
        double ans = 0;
        int cnt = 0;
        for(int i = q_num-1; i>= 0 ;i--)
        {
            if(query[i].op[0] == 'Q')
            {
                Splay(query[i].x,0);
                if(size[root] < query[i].y || query[i].y <= 0)
                {
                    cnt++;
                    continue;
                }
                ans += key[Get_kth(root,size[root] - query[i].y + 1)];
                cnt++;
            }
            else if(query[i].op[0] == 'D')
            {
                int tmp = query[i].x;
                bing(edge[tmp].u,edge[tmp].v);
            }
            else if(query[i].op[0] == 'C')
            {
                Splay(query[i].x,0);
                Delete();
                head[query[i].x] = ne[head[query[i].x]];
                Insert(query[i].x,to[head[query[i].x]]);
            }
        }    
        if(cnt == 0)cnt = 1;
        printf("Case %d: %.6lf\n",iCase,ans/cnt);
    }
    return 0;
}
