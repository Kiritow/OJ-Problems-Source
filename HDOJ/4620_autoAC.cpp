#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct node
{
    int t,p[15],c,id;
}cut[35];
bool cmp(node x,node y)
{
    return x.t<y.t;
}
int T,longe,ans[35],tmpa[35],tmpl,n,w,m,vis[205],num;
void dfs(int pos,int lastt)
{
    if(n-pos+tmpl<=longe) return;
    int num,i,j,tmp;
    for(i=pos+1;i<=n;i++)
    {
        for(j=1,num=0;j<=cut[i].c;j++)
        {
            tmp=cut[i].p[j];
            if(vis[tmp]==0)
                num++;
            vis[tmp]++;
        }
        if((cut[i].t-lastt<=w||!tmpl)&&num>=3)
        {
            tmpl++;
            tmpa[tmpl]=cut[i].id;
            dfs(i,cut[i].t);
            tmpl--;
        }
        for(j=1;j<=cut[i].c;j++)
        {
            tmp=cut[i].p[j];
            vis[tmp]--;
        }
    }
    if(longe<tmpl)
    {
        longe=tmpl;
        for(j=0;j<longe;j++)
            ans[j]=tmpa[j+1];
    }
}
int main()
{
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&cut[i].c,&cut[i].t);
            for(j=1;j<=cut[i].c;j++)
                scanf("%d",&cut[i].p[j]);
            cut[i].id=i;
        }
        sort(cut+1,cut+n+1,cmp);
        memset(vis,0,sizeof vis);
        longe=0;tmpl=0;
        dfs(0,cut[1].t);
        sort(ans,ans+longe);
        printf("%d\n",longe);
        for(i=0;i<longe-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[longe-1]);
    }
    return 0;
}
