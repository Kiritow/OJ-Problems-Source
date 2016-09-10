#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    int next,to;
    int step;
} a[100005];
int head[100005];
int n,d,len,ans;
void add(int x,int y)
{
    a[len].to = y;
    a[len].next = head[x];
    head[x] = len++;
}
void dfs(int x,int step)
{
    int i,j,k;
    if(-1 == head[x])
        return ;
    for(i = head[x]; i!=-1; i = a[i].next)
    {
        k = a[i].to;
        a[i].step = step+1;
        if(a[i].step>d)
            ans++;
        dfs(k,a[i].step);
    }
}
int main()
{
    int T,i,j,x,y;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof(head));
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&d);
        len = 0;
        for(i = 1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        ans = 0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
