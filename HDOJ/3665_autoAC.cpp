#include<stdio.h>
#define INF 99999999
int n,dis[15][15];
int mark[15];
void Floyed(){
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j)
                    dis[i][j]=0;
                else
                    dis[i][j]=INF;
        int m;
        int s,l;
        for(i=0;i<n;i++){
            scanf("%d%d",&m,&mark[i]);
            for(j=0;j<m;j++){
                scanf("%d%d",&s,&l);
                dis[i][s]=l;
            }
        }
        Floyed();
        int min=INF;
        for(i=0;i<n;i++)
            if(mark[i])
                if(min>dis[0][i])
                    min=dis[0][i];
        printf("%d\n",min);
    }
    return 0;
}
