#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=300000;
const int MAXM=600000;
struct node
{
    int u,v;
};
node edge[MAXM];
int first[MAXN],ne[MAXM],cc;
int dfn[MAXN],low[MAXN],belong[MAXN];
int ti,id,top;
int stack[MAXN];
int arc[MAXM]; 
int arcid;       
inline void add_edge(int u,int v)
{
    edge[cc].u=u;
    edge[cc].v=v;
    ne[cc]=first[u];
    first[u]=cc;
    cc++;
}
void tardfs(int u,int p)
{
    dfn[u]=low[u]=ti++;
    stack[top++]=u;
    int i;
    int ff=1;
    for(i=first[u];i!=-1;i=ne[i])
    {
        int v=edge[i].v;
        if(v==p&&ff)       
        {
            ff=0;
            continue;
        }
        if(dfn[v]==-1)
        {
            tardfs(v,u);
            if(low[u]>low[v])
                low[u]=low[v];
            else if(low[v]>dfn[u])
            {
                arc[arcid]=i;   
                arcid++;
                id++;
                for(stack[top]=-1;stack[top]!=v;)
                {
                    top--;
                    belong[stack[top]]=id;
                }
            }
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
}
int tarjan(int n)
{
    ti=1;               
    id=0;               
    top=0;         
    arcid=0;            
    memset(dfn,-1,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    tardfs(1,-1);
    return id;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(first,-1,sizeof(first));
        memset(ne,-1,sizeof(ne));
        cc=0;
        int n,m;
        scanf("%d%d",&n,&m);
        map<string,int> mp1;
        map<int,string> mp2;
        int cnt=1;
        int i;
        char str1[150],str2[150];
        for(i=0;i<m;i++)
        {
            scanf("%s%s",str1,str2);
            if(mp1[str1]==0)
            {
                mp1[str1]=cnt;
                mp2[cnt]=str1;
                cnt++;
            }
            if(mp1[str2]==0)
            {
                mp1[str2]=cnt;
                mp2[cnt]=str2;
                cnt++;
            }
            int u=mp1[str1];
            int v=mp1[str2];
            add_edge(u,v);
            add_edge(v,u);
        }
        tarjan(n);
        int flag=0;
        for(i=1;i<=n;i++)
        {
            if(dfn[i]==-1)
                flag=1;
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        sort(arc,arc+arcid);
        printf("%d\n",arcid);
        for(i=0;i<arcid;i++)
        {
            int x=arc[i];
            x=min(x,x^1);
            printf("%s %s\n",mp2[edge[x].u].c_str(),mp2[edge[x].v].c_str());
        }
    }
    return 0;
}
