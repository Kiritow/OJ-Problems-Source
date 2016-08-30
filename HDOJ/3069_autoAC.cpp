#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 1005
int head[maxn],tot,u,v,n;
struct Edge
{
    int to,next;
}e[maxn*2];
void addedge(int u,int v)
{
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
int dfs(int u,int pre)
{
    int ans=-1,cnt=0;
    vector<int> check;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to,t;
        if(v==pre) continue;
        t=dfs(v,u);
        check.push_back(t);
        ans=max(ans,t);
    }
    if(check.size()==0) return 1;
    for(int i=0;i<check.size();i++) if(check[i]==ans) cnt++;
    if(cnt>1) return ans+1;
    else return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        int ans=dfs(1,0);
        printf("%d\n",ans);
    }
}
