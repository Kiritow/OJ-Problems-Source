#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define INF 2000002
int hash[2000002];
int lowcost[601];
int e[601][601];
int used[601];
int w[601];
int n,i,j;
void sushubiao()
{
    int i;
    memset(hash,0,sizeof(hash));
    int num=0;
    hash[1]=1;
    hash[0]=1;
    int M=2000002;
    for(i=2; i<=M; i++)
    {
        if(!hash[i])
        {
            for(j=i+i;j<M;j+=i)
            {
                hash[j]=1;
            }
        }
    }
}
int yxc(int a,int b)
{
    if(a>=b)return b;
    else return a;
}
void prim()
{
    int sum=0;
    int min;
    int v;
    for(i=0; i<n; i++)
    {
        lowcost[i]=e[0][i];
        used[i]=0;
    }
    used[0]=-1;
    for(i=1; i<n; i++)
    {
        min=INF;
        for(j=0; j<n; j++)
        {
            if(used[j]==0&&lowcost[j]<min)
            {
                min=lowcost[j];
                v=j;
            }
        }
        if(min==INF) break;
        sum+=min;
        used[v]=-1;
        for(j=0; j<n; j++)
        {
            if(used[j]==0&&e[v][j]<lowcost[j])
            {
                lowcost[j]=e[v][j];
            }
        }
    }
    int   flag=0;
    for(j=0; j<n; j++)
    {
        if(used[j]==0)
        {
            flag=1;
            break;
        }
    }
    if(flag)   printf("-1\n");
    else
        printf("%d\n",sum);
}
int main()
{
    int T;
    sushubiao();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&w[i]);
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(hash[w[i]]==0||hash[w[j]]==0||hash[w[i]+w[j]]==0)
                    e[i][j]=e[j][i]=yxc(yxc(w[i],w[j]),abs(w[i]-w[j]));
                    else   e[i][j]=e[j][i]=INF;
            }
        prim();
    }
    return 0;
}
