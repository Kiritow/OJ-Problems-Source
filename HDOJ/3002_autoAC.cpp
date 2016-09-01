#include<stdio.h>
#include<string.h>
const int N=105;
const int INF=1<<30;
int map[N][N];
int wet[N];
int vis[N];
int combine[N];
int S,T,mincut,n;
void search()
{
    int i,j,max,tmp;
    memset(vis,0,sizeof(vis));
    memset(wet,0,sizeof(wet));
    S=T=-1;
    for(i=0;i<n;i++)
    {
        max=-INF;
        for(j=0;j<n;j++)
        {
            if(!combine[j]&&!vis[j]&&wet[j]>max)
            {
                tmp=j;
                max=wet[j];
            }
        }
        if(T==tmp) return;
        S=T;T=tmp;
        mincut=max;
        vis[tmp]=1;
        for(j=0;j<n;j++)
        {
            if(!combine[j]&&!vis[j])
                wet[j]+=map[tmp][j];
        }
    }
}
int Stoer_Wagner()
{
    int i,j;
    memset(combine,0,sizeof(combine));
    int ans=INF;
    for(i=0;i<n-1;i++)
    {
        search();
        if(mincut<ans) ans=mincut;
        if(ans==0) return 0;   //杩
        combine[T]=1;
        for(j=0;j<n;j++)
        {
            if(!combine[j])
            {
                map[S][j]+=map[T][j];
                map[j][S]+=map[j][T];
            }
        }
    }
    return ans;
}
int main()
{
    int a,b,c,m,i;
    while(~scanf("%d%d",&n,&m))
    {
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++)
        {
           scanf("%d%d%d",&a,&b,&c);
           map[a][b]+=c;
           map[b][a]+=c;
        }
        printf("%d\n",Stoer_Wagner());
    }
    return 0;
}
