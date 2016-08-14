#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<iostream>
#define INF 1000000000
#define N 1000000+10
using namespace std;
typedef struct
{
    int to;
    int w;
    int next;
}node;
node E[N];
node e[N];
int head[N],dis[N],visit[N],cnt;
int list[N],len[N],tot;
void ADD(int a,int b,int c)
{
    E[++cnt].to=b;
    E[cnt].w=c;
    E[cnt].next=head[a];
    head[a]=cnt;
}
void add(int a,int b,int c)
{
    e[++tot].to=b;
    e[tot].w=c;
    e[tot].next=list[a];
    list[a]=cnt;
}
void spfa(int s,int t)
{
    queue<int>Q;
    for(int i=0;i<N;i++)
    dis[i]=INF;
    memset(visit,0,sizeof(visit));
    dis[s]=0;
    Q.push(s);
    while(!Q.empty())
    {
        int k=Q.front();
        Q.pop();
        visit[k]=0;
        for(int i=head[k];i;i=E[i].next)
        {
            int to=E[i].to;
            int w=E[i].w;
            if(dis[k]+w<dis[to])
            {
                dis[to]=dis[k]+w;
                if(!visit[to])
                {
                    visit[to]=1;
                    Q.push(to);
                }
            }
        }
    }
return ;
}
void SPFA(int s,int t)
{
    for(int i=0;i<N;i++)
    len[i]=INF;
    memset(visit,0,sizeof(visit));
    len[s]=0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int k=Q.front();
        Q.pop();
        visit[k]=0;
        for(int i=list[k];i;i=e[i].next)
        {
            int to=e[i].to;
            int w=e[i].w;
            if(len[k]+w<len[to])
            {
                len[to]=len[k]+w;
                if(!visit[to])
                {
                    visit[to]=1;
                    Q.push(to);
                }
            }
        }
    }
    return;
}   
int main()
{
    int T;
    int n,m;
    int a,b,c;
    int sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head));
        memset(list,0,sizeof(list));
        cnt=1;
        tot=1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            ADD(a,b,c);
            add(b,a,c);
        }
        spfa(1,n);
        SPFA(1,n);
        sum=0;
        for(int i=2;i<=n;i++)
        sum+=dis[i];
        for(int i=2;i<=n;i++)
        sum+=len[i];
        printf("%d\n",sum);
    }
    return 0;
}
