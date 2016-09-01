#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N=10006;
struct Edge
{
    int st, en;
    Edge() {}
    Edge(int a, int b)
    {
        st=a, en=b;
    }
};
stack <Edge> palm;
vector <int> arc[N];
vector <Edge> block[N];
int dfn[N], low[N];
bool vs[N];
int n, m, ind, T, sum1, sum2;
void tarjan(int u, int pre)
{
    dfn[u]=low[u]=T++;
    int len=(int)arc[u].size();
    for(int i=0; i<len; i++)
    {
        int v=arc[u][i];
        if(dfn[v]==-1)
        {
            palm.push(Edge(u, v));
            tarjan(v, u);
            if(low[u]>low[v]) low[u]=low[v];
            if(dfn[u]<=low[v])
            {
                for(Edge temp; !palm.empty(); )
                {
                    temp=palm.top();
                    if(dfn[temp.st]<dfn[v]) break;
                    block[ind].push_back(temp), palm.pop();
                }
                block[ind++].push_back(Edge(u, v));
                palm.pop();
                if(dfn[u]<low[v]) sum1++;
            }
        }
        else if(v!=pre && dfn[v]<dfn[u])
        {
            palm.push(Edge(u, v));
            if(low[u]>dfn[v]) low[u]=dfn[v];
        }
    }
}
int main()
{
    while(scanf("%d%d", &n, &m), n!=0 || m!=0)
    {
        for(int i=0; i<n; i++) arc[i].clear();
        for(int i=0, a, b; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            arc[a].push_back(b);
            arc[b].push_back(a);
        }
        for(int i=0; i<n; i++) dfn[i]=-1, block[i].clear();
        while(!palm.empty()) palm.pop();
        ind=T=sum1=sum2=0;
        for(int i=0; i<n; i++) if(dfn[i]==-1) tarjan(i, -1);
        for(int i=0; i<ind; i++)
        {
            for(int j=0; j<n; j++) vs[j]=0;
            int len=(int)block[i].size(), tot=0;
            for(int j=0; j<len; j++)
            {
                if(!vs[block[i][j].st]) vs[block[i][j].st]=1, tot++;
                if(!vs[block[i][j].en]) vs[block[i][j].en]=1, tot++;
            }
            if(len>tot) sum2+=len;
        }
        printf("%d %d\n", sum1, sum2);
    }
    return 0;
}
