#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef __int64 ll;
const int N=100010;
const int M=500010;
const ll inf=1LL<<60;
struct node
{
    int to;
    ll dis;
    node *next;
}E[M<<1],*G1[N],*G2[N],*head;
int n,m,num;
ll d1[N],d2[N];
bool inq[N];
map<string,int> dict;
inline void add(int a,int b,ll c,node *G[])
{
    head->to=b;
    head->dis=c;
    head->next=G[a];
    G[a]=head++;
}
inline int change(char *s)
{
    if(dict.count(s)) return dict[s];
    else return dict[s]=num++;
}
void SPFA(int s,ll d[],node *G[])
{
    deque<int> Q;
    Q.push_back(s);
    memset(inq,false,sizeof(inq));
    fill(d,d+N,inf);
    d[s]=0;
    int to;
    ll dis;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop_front();
        inq[u]=false;
        for(node *p=G[u];p;p=p->next)
        {
            to=p->to;
            dis=p->dis;
            if(d[to]>d[u]+dis)
            {
                d[to]=d[u]+dis;
                if(!inq[to])
                {
                    inq[to]=true;
                    if(!Q.empty() && d[to]<=d[Q.front()]) Q.push_front(to);
                    else Q.push_back(to);
                }
            }
        }
    }
}
int main()
{
    char s1[20],s2[20];
    while(~scanf("%d%d",&n,&m))
    {
        num=0;
        dict.clear();
        memset(G1,NULL,sizeof(G1));
        memset(G2,NULL,sizeof(G2));
        head=E;
        int s,t;
        ll dis;
        for(int i=0;i<m;i++)
        {
            scanf("%s %s %I64d",s1,s2,&dis);
            s=change(s1),t=change(s2);
            add(s,t,dis,G1);
            add(t,s,dis,G2);
        }
        scanf("%s %s",s1,s2);
        s=dict[s1],t=dict[s2];
        SPFA(s,d1,G1);
        SPFA(t,d2,G2);
        ll ans=inf;
        for(int i=0;i<n;i++)
        {
            for(node *p=G1[i];p;p=p->next)
            {
                int j=p->to;
                if(d1[i]<inf && d2[j]<inf) ans=min(ans,d1[i]+d2[j]+(p->dis)/2);
            }
        }
        if(ans==inf) printf("-1\n");
        else printf("%I64d\n",ans);
    }
    return 0;
}
