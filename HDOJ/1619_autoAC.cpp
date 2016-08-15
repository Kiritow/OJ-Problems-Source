#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int NM=205;
const int MAX=0xfffffff;
int d[3][2]={-1,1,0,1,1,1};
int a[NM][NM],dp[NM][NM],path[NM],c[3],n,m,k;
bool flag;
inline int min(int x,int y){
    return x<y?x:y;
}
int DFS(int x,int y)
{
    int x1,y1,i;
    if(dp[x][y]!=MAX) return dp[x][y];
    if(y==m) return dp[x][y]=a[x][y];
    for(i=0;i<3;i++){
        x1=x+d[i][0];y1=y+d[i][1];
        if(!x1) x1=n;if(x1>n) x1=1;
        dp[x][y]=min(dp[x][y],DFS(x1,y1));
    }
    return dp[x][y]=dp[x][y]+a[x][y];
}
void Findp(int x,int y)
{
    int x1,y1,i;
    if(flag) return;
    path[k++]=x;
    if(y==m){
        flag=true;return;
    }
    for(i=0;i<3;i++){
        x1=x+d[i][0];
        if(!x1) x1=n;if(x1>n) x1=1;
        c[i]=x1;
    }
    sort(c,c+3);
    for(i=0;i<3;i++){
        y1=y+d[i][1];
        if(dp[x][y]==dp[c[i]][y1]+a[x][y])
        Findp(c[i],y1);
    }
}
int main()
{
    int i,j,u,mmin;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                dp[i][j]=MAX;
            }
            u=1;mmin=MAX;
            for(i=1;i<=n;i++){
                if(mmin>DFS(i,1)){
                    mmin=dp[i][1],u=i;
                }
            }
            k=0;flag=false;
            memset(path,0,sizeof(path));
            Findp(u,1);
            for(i=0;i<k-1;i++) printf("%d ",path[i]);
            printf("%d\n",path[k-1]);
            printf("%d\n",mmin);
    }
    return 0;
}
