#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <list>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iostream>
#include <stack>
using namespace std;
int n,m,q;
struct Node
{
    int e,xia,val;
}e1[20001];
struct Node2
{
    int e,xia;
}e2[2000001];
int d1,d2,head1[10001],head2[10001];
bool vis[10001];
int fat[10001],dis[10001],ans[1000001];
void add1(int s,int e,int val)
{
    e1[d1].e=e,e1[d1].val=val,e1[d1].xia=head1[s];
    head1[s]=d1++;
}
void add2(int s,int e)
{
    e2[d2].e=e,e2[d2].xia=head2[s];
    head2[s]=d2++;
}
int find(int num)
{
    if(fat[num] == num)return num;
    return fat[num]=find(fat[num]);
}
void Union(int s,int e)
{
    fat[e]=s;
}
void tarjan(int s)
{
    int i;
    vis[s]=true;
    fat[s]=s;
    for(i=head1[s];i != -1;i=e1[i].xia)
    {
        if(!vis[e1[i].e])
        {
            dis[e1[i].e]=dis[s]+e1[i].val;
            tarjan(e1[i].e);
            Union(s,e1[i].e);
        }
    }
    for(i=head2[s];i != -1 ;i=e2[i].xia)
    {
        if(vis[e2[i].e])
        {
            if(dis[e2[i].e] != -1)
            {
                ans[i/2]=dis[s]+dis[e2[i].e]-2*dis[find(e2[i].e)];
            }
            else ans[i/2]=-1;
        }
    }
}
int main()
{
    int i,j,ji1,ji2,ji3;
    while(~scanf("%d %d %d",&n,&m,&q))
    {
        d1=d2=0;
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&ji1,&ji2,&ji3);
            add1(ji1,ji2,ji3);
            ji1^=ji2,ji2^=ji1,ji1^=ji2;
            add1(ji1,ji2,ji3);
        }
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&ji1,&ji2);
            add2(ji1,ji2);
            ji1^=ji2,ji2^=ji1,ji1^=ji2;
            add2(ji1,ji2);
        }
        memset(vis,false,sizeof(vis));
        for(i=1;i<=n;i++)fat[i]=i;
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                memset(dis,-1,sizeof(dis));
                dis[i]=0;
                tarjan(i);
            }
        }
        for(i=0;i<q;i++)
        {
            if(ans[i] == -1)puts("Not connected");
            else printf("%d\n",ans[i]);
        }
    }
    return 0;
}
