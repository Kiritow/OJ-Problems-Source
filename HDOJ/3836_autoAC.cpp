#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"stack"
#define N 30000
using namespace std;
int n,m;
int index_s;
int instack[N],DFN[N],LOW[N];
int belong[N],indegree[N],outdegree[N];
struct Eage
{
    int from,to,next;
}eage[2*N];
int tot,head[N];
void add(int a,int b)
{
    eage[tot].from=a;
    eage[tot].to=b;
    eage[tot].next=head[a];
    head[a]=tot++;
}
void getmap()
{
    int i,l;
    int a,b;
    tot=0;
    memset(head,-1,sizeof(head));
    while(m--)  {scanf("%d%d",&a,&b);add(a,b);}
}
stack<int>st;
void Tarjan(int k)
{
    int j,v;
    st.push(k);
    instack[k]=1;
    DFN[k]=LOW[k]=++index_s;
    for(j=head[k];j!=-1;j=eage[j].next)
    {
        v=eage[j].to;
        if(instack[v])  LOW[k]=LOW[k]>DFN[v]?DFN[v]:LOW[k];
        else if(DFN[v]==-1)
        {
            Tarjan(v);
            LOW[k]=LOW[k]>LOW[v]?LOW[v]:LOW[k];
        }
    }
    if(DFN[k]==LOW[k])
    {
        do
        {
            j=st.top();
            st.pop();
            instack[j]=0;
            belong[j]=k;
        }while(j!=k);
    }
}
void getdegree()
{
    int i,l;
    memset(indegree,0,sizeof(indegree));
    memset(outdegree,0,sizeof(outdegree));
    for(i=0;i<tot;i++)
    {
        if(belong[eage[i].from]==belong[eage[i].to])    continue;
        indegree[belong[eage[i].to]]++;
        outdegree[belong[eage[i].from]]++;
    }
}
int main()
{
    int i;
    int temp,t1,t2,ans;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        getmap();
        index_s=0;
        memset(DFN,-1,sizeof(DFN));
        memset(LOW,-1,sizeof(LOW));
        memset(instack,0,sizeof(instack));
        for(i=1;i<=n;i++)   if(DFN[i]==-1) Tarjan(i);
        getdegree();
        temp=t1=t2=0;
        for(i=1;i<=n;i++)
        {
            if(belong[i]!=i)    continue;
            temp++;
            if(indegree[i]==0)  t1++;
            if(outdegree[i]==0) t2++;
        }
        ans=t1>t2?t1:t2;
        if(n<1 || temp==1) ans=0;
        printf("%d\n",ans);
   }
    return 0;
}
