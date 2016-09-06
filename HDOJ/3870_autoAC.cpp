#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#define N 400*400
using namespace std;
int t,n,a[405][405];
int v,e,low[N],p[N],q[N],adj[N];
bool f[N];
struct Edge
{
    int v,w,next;
}edge[4*N];
void insert(int u,int v,int w)
{
    edge[e].v=v;edge[e].w=w;
    edge[e].next=adj[u];
    adj[u]=e++;
}
int spfa(int s)
{
    memset(f,0,sizeof(f));
    memset(low,0x7f,sizeof(low));
    int i,j,k,x,h=0,t=1;
    v=n*n+1;
    q[t]=s;
    low[s]=0;
    while(h!=t)
    {
        h=(h+1)%(v+1);
        x=q[h];
        f[x]=0;
        for(k=adj[x];k!=-1;k=edge[k].next)
        {
            i=edge[k].v;
            j=edge[k].w;
            if(j+low[x]<low[i])
            {
                low[i]=low[x]+j;
                if(!f[i])
                {
                    f[i]=1;
                    t=(t+1)%(v+1);
                    q[t]=i;
                }
            }
        }
    }
    return low[n*n+1];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(adj,-1,sizeof(adj));
        int i,j;
        e=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        n--;
        for(i=0;i<n;i++)
        {
            insert(0,i*n+1,a[i][0]);
            insert(0,(n-1)*n+i+1,a[n][i]);
            insert(i+1,n*n+1,a[0][i]);
            insert(i*n+n,n*n+1,a[i][n]);
            for(j=0;j<n;j++)
            {
                if(j+1<n)
                {
                    insert(i*n+j+1,i*n+j+2,a[i][j+1]);
                    insert(i*n+j+2,i*n+j+1,a[i][j+1]);
                }
                if(i+1<n)
                {
                    insert(i*n+j+1,(i+1)*n+j+1,a[i+1][j]);
                    insert((i+1)*n+j+1,i*n+j+1,a[i+1][j]);
                }
            }
        }
        printf("%d\n",spfa(0));
    }
}
