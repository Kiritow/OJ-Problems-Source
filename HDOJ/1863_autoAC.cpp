#include<stdio.h>
#include<string.h>
#define Max 10000000
int map[110][110],cost[110],vit[110],m,n;
void prim(int x)
{
    int i,j,min,k,sum=0;
    memset(vit,0,sizeof(vit));
    for(i=1;i<=m;i++)
        cost[i]=map[x][i];
    cost[x]=0;
    vit[x]=1;
    for(i=1;i<m;i++)
    {
        min=Max;k=-1;
        for(j=1;j<=m;j++)
            if(!vit[j]&&cost[j]<min)
                min=cost[k=j];
            if(min==Max)
            {
                printf("?\n");
                return ;
            }
            vit[k]=1;
            sum+=min;
            for(j=1;j<=m;j++)
                if(!vit[j]&&cost[j]>map[k][j])
                    cost[j]=map[k][j];
    }
    printf("%d\n",sum);    
}
int main()
{
    int i,j,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF&&n)  
    {
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
            {
                if(i==j)
                    map[i][j]=0;
                map[i][j]=Max;
            }
            for(i=0;i<n;i++)
            {
                scanf("%d%d%d",&a,&b,&c);
                map[a][b]=map[b][a]=c;
            }
            prim(1);
    }
    return 0;
}
