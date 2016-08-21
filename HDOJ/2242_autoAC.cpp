#include<stdio.h>
#include<string.h>
#include<stack>
#include<math.h>
using namespace std;
#define N 10005
#define M 20005
struct node{
    int from,to,next;
}edge[2*M],edge1[2*M];
int head[N],tol,n,m,cnt,dfn[N],low[N],visit[N],Belong[N],tol1,head1[N],val[N],val1[N],SUM,Min,count;
stack<int>S;
void add(int a,int b)
{
    edge[tol].from=a;edge[tol].to=b;edge[tol].next=head[a];head[a]=tol++;
}
void add1(int a,int b)
{
    edge1[tol1].from=a;edge1[tol1].to=b;edge1[tol1].next=head1[a];head1[a]=tol1++;
}
int min(int a,int b)
{
    return a<b?a:b;
}
void tarjan(int u,int father)
{
    int j,v,flag;
    dfn[u]=low[u]=cnt++;
    visit[u]=1;
    S.push(u);
    flag=0;
    for(j=head[u];j!=-1;j=edge[j].next)
    {
        v=edge[j].to;
        if(v==father && !flag) {flag=1;continue;}
        if(!visit[v]) tarjan(v,u);
        low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u])
    {
        count++;
        do{
            v=S.top();
            S.pop();
            Belong[v]=count;
            val[count]+=val1[v];
        }while(v!=u);
    }
}
int dfs(int u,int father)
{
    int j,v,sum;
    sum=val[u];
    for(j=head1[u];j!=-1;j=edge1[j].next)
    {
        v=edge1[j].to;
        if(v==father) continue;
        sum+=dfs(v,u);
    }
    Min=min(Min,abs(SUM-2*sum));
    return sum;
}
int main()
{
    int i,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tol=cnt=0;
        SUM=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&val1[i]);
            SUM+=val1[i];
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        memset(visit,0,sizeof(visit));
        memset(val,0,sizeof(val));
        count=0;
        tarjan(0,0);
        if(count==1) {printf("impossible\n");continue;}
        tol1=0;
        memset(head1,-1,sizeof(head1));
        for(i=0;i<tol;i++)
        {
            a=edge[i].from;
            b=edge[i].to;
            if(Belong[a]!=Belong[b]) add1(Belong[a],Belong[b]);
        }
        Min=0xfffffff;
        dfs(1,0);
        printf("%d\n",Min);
    }
    return 0;
}
