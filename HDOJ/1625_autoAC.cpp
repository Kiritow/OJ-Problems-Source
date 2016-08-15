#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 55
int path[MAXN][MAXN];
int m,n;
void floyd(){
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                path[i][j]+=path[i][k]*path[k][j];
            }
        }
    }
    for(int i=0;i<=n;i++)if(path[i][i]){
        path[i][i]=-1;
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(path[j][i]&&path[i][k]){
                    path[j][k]=-1;
                }
            }
        }
    }
}
int main(){
    int u,v,t=0;
    while(~scanf("%d",&m)){
        memset(path,0,sizeof(path));
        n=0;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            path[u][v]=1;
            n=max(n,max(u,v));
        }
        printf("matrix for city %d\n",t++);
        floyd();
        for(int i=0;i<=n;i++){
            for(int j=0;j<n;j++){
                printf(" %d",path[i][j]);
            }
            printf(" %d\n",path[i][n]);
        }
    }
    return 0;
}
