#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
 
using namespace std;
 
#define MAXN  505
#define MAXM  500150
 
struct edges
{
    int to;
    int next;
}edge[MAXM];
 
int nx,ny,n,m,en,k;
int first[MAXN];
int cx[MAXN],cy[MAXN],distx[MAXN],disty[MAXN];
int que[MAXN],head,tail;
int ans;
int color[MAXN],cnt1,cnt2;
int w[550][550];
 
void init()
{
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    memset(first,-1,sizeof(first));
    memset(w,0x3f3f3f3f,sizeof(w));
    en=0;ans=0;
}
 
void add(int a, int b)
{
    edge[en].to=b;
    edge[en].next=first[a];
    first[a]=en++;
}
 
bool bfs()
{
    int i,j,k;
    bool flag(0);
    int h,t;
    memset(distx,0,sizeof(distx));
    memset(disty,0,sizeof(disty));
    head=tail=0;
    for(i=1;i<=nx;i++)
        if (cx[i]==-1&&color[i]==1) que[tail++]=i;
    while(head!=tail)
    {
        for(h=head,t=tail;h!=t;h=(h+1)%MAXN)
        {
            i=que[h];
            if(color[i]!=1) continue;
            for(k=first[i];k!=-1;k=edge[k].next)
            {
                j=edge[k].to;
                if(color[j]!=-1) continue;
                if(!disty[j])
                {
                    disty[j]=distx[i]+1;
                    if (cy[j]==-1) flag=1;
                    else
                    {
                        distx[cy[j]]=disty[j]+1;
                        que[tail]=cy[j];
                        tail=(tail+1)%MAXN;
                    }
                }
            }
        }
        head=t;
    }
    return flag;
}
 
bool dfs(int i)
{
    int j, k;
    if(color[i]!=1) return 0;
    for(k=first[i];k!=-1;k=edge[k].next)
    {
        j=edge[k].to;
        if(color[j]!=-1) continue;
        if(disty[j]==distx[i]+1)
        {
            disty[j]=0;
            if(cy[j]==-1||dfs(cy[j]))
            {
                cx[i]=j,cy[j]=i;
                return 1;
            }
        }
    }
    return 0;
}
 
int Hopcroft_Karp()
{
    int i,j;
    while(bfs())
          for(i=1; i<=nx;i++)
            if(color[i]==1&&cx[i]==-1&&dfs(i)) ans++;
    return ans;
}
 
bool bipartite(int u,int c)
{
    color[u]=c;
    if(c==1) cnt1++;
    else cnt2++;
    for(int i=first[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(color[v]==0)
        {
            if(!bipartite(v,-c))
                return false;
        }
        else
            if(color[v]==color[u])
                return false;
    }
    return true;
}
 
void Floyd(int n)
{
    for (int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(w[i][j]>(w[i][k]+w[k][j]))
                {
                    w[i][j]=w[i][k]+w[k][j];
                }
    }
}
int main(){
    //freopen("indata","r",stdin);
    //freopen("outdata","w",stdout);
    int t;
    int a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        init();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            w[a][b] = w[b][a] = c;
        }
       // printf("notdone\n");
        Floyd(n);
        //printf("fdone\n");
        int knum = 0;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(i == j) continue;
                if(w[i][j] <= k) {
                    add(i,j);
                    knum ++;
                }
            }
        }
        knum/=2;
        if(n == 0&& knum == 0){
            printf("0\n");
            continue;
        }
        memset(color,0,sizeof(color));
        bool ok=1;
        for(int i=1;i<=n;i++)
            if(color[i]==0)
            {
                cnt1=cnt2=0;
                if(!bipartite(i,1))
                    ok=0;
                if(cnt1!=cnt2) ok=0;
            }
        if(!ok || n%2==1)
        {
           // printf("%d %d\n",ok,n%2 );
            printf("Impossible\n");
            continue;
        }
        nx=ny=n;
        if(Hopcroft_Karp()!=n/2)
        {
            //printf("hk\n");
            printf("Impossible\n");
            continue;
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                printf("%d",i);
            else if(color[i]==color[1])
                printf(" %d",i );
        }
        printf("\n");
    }
    return 0;
}
