#include<stdio.h>
#include<math.h>
#include <string.h>
#define INF 1<<29
int map[9][9],sum[9][9];
int d[15][9][9][9][9];
inline int Min(int a,int b){return a>b?b:a;}
int s(int x1,int y1,int x2,int y2){
    int temp=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]; return temp*temp;
}
int dp(int k,int x1,int y1,int x2,int y2){
    if(d[k][x1][y1][x2][y2]!=-1)return d[k][x1][y1][x2][y2];
    if(k==1)return s(x1,y1,x2,y2);
    int ans=INF,i;
    for(i=x1;i<x2;i++)
    {
        ans=Min(dp(k-1,x1,y1,i,y2)+s(i+1,y1,x2,y2),ans);
        ans=Min(dp(k-1,i+1,y1,x2,y2)+s(x1,y1,i,y2),ans);
    }
    for(i=y1;i<y2;i++)
    {
        ans=Min(dp(k-1,x1,y1,x2,i)+s(x1,i+1,x2,y2),ans);
        ans=Min(dp(k-1,x1,i+1,x2,y2)+s(x1,y1,x2,i),ans);
    }
    return d[k][x1][y1][x2][y2]=ans;
}
int main()
{
    int n,i,j,k;
    while(~scanf("%d",&n)){
        memset(map,0,sizeof(map));
        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                scanf("%d",&map[i][j]);
        memset(sum,0,sizeof(sum));
        for(i=1;i<=8;i++)  
            for(j=1;j<=8;j++)   
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];  
            memset(d,-1,sizeof(d));
            int ans=dp(n,1,1,8,8);
            double aver=(double)sum[8][8]/(double)n;
            double last=sqrt((double)ans/(double)n-aver*aver);
            printf("%.3lf\n",last);
    }
    return 0;
}
