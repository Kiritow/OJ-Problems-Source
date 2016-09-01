#include<stdio.h>
#include<string.h>
#define inf 99999999
int flag[500];
int D[500];
int map[505][505];
int n,i,j;
int prime()
{
    int v,k;
    int ret=0,mi;
    for(i=1;i<=n;i++){
        flag[i]=0;
        D[i]=inf;
    }D[1]=0;flag[1]=1;v=1;
    for(k=1;k<n;k++){
        for(i=1;i<=n;i++)if(!flag[i]){
            if(map[v][i]<D[i])
                D[i]=map[v][i];
        }
        mi=inf;
        for(i=1;i<=n;i++)
            if(!flag[i]&&D[i]<mi)
                mi=D[v=i];
            flag[v]=1;
            ret+=mi;
    }
    return ret;
}
int num[505];
int main()
{
    int t,m,k,x,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,w;
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;i++)
        {
            map[i][i]=0;
            for(j=i+1;j<=n;j++)
                map[i][j]=map[j][i]=inf;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            if(w<map[a][b])
            map[a][b]=map[b][a]=w;
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
                scanf("%d",&num[j]);
            for(j=0;j<m;j++)
                for(x=j+1;x<m;x++)
                    map[num[j]][num[x]]=map[num[x]][num[j]]=0;
        }
        int ans=prime();
        if(ans>=inf)
            printf("-1\n");
        else printf("%d\n",ans);    
    }
    return 0;
}
