#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node
{
    int v;
    int next;
}Edge[500010*2];
int pre[100010];
void add(int u,int v,int index)
{
    Edge[index].v=v;
    Edge[index].next=pre[u];
    pre[u]=index;
}
int flag[100010];
int c[100010];
int bfs(int v)
{
    queue <int> q;
    flag[v]=1;
    q.push(v);
    while(!q.empty())
    {
        int b=q.front();
        q.pop();
        for(int i=pre[b];i!=-1;i=Edge[i].next)
        {
            int e=Edge[i].v;
            if(flag[e]==flag[b])
                return 0;
            if(!flag[e])
            {
                flag[e]=flag[b]==1?2:1;
                q.push(e);
            }
        }
    }
    return 1;
}
int main()
{
    int n,m,q,cnt=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        int a,b,index=1;
        memset(flag,0,sizeof(flag));
        memset(pre,-1,sizeof(pre));
        memset(c,0,sizeof(c));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b,index++);
            add(b,a,index++);
            c[a]++,c[b]++;
        }
        int state=0;
        for(int i=1;i<=n;i++)
        {
            if(!flag[i]&&c[i])
            {
                if(!bfs(i))
                {
                    state=1;
                    break;
                }
            }
        }
        printf("Case %d: ",cnt++);
        if(state)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
