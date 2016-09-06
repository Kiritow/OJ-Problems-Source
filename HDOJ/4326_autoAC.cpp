#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define maxn 102
#define eps 1e-10
double g[maxn][maxn];
double x[maxn];
int n,m,k;
void add(int cnt,int i,int j,double val)
{
    int t=i*n+j;
    if(i==m)
    {
        if(j==1)    
            g[cnt][m*n+1]+=-1.0*val;  
        return;
    }
    g[cnt][t]+=val;
}
void gauss(int n,int m)
{
    int row,col,i,j,k;
    for(row=1,col=1;row<n,col<m;row++,col++)
    {
        k=row;
        for(i=row+1;i<=n;i++)  
            if(fabs(g[i][col])>fabs(g[k][col]))
                k=i;
        if(k!=row)  
        {
            for(i=col; i<=m; i++)
                swap(g[k][i],g[row][i]);
        }
        for(i=row+1; i<=n; i++)  
        {
            if(fabs(g[i][col])<eps)
                continue;
            double t=g[i][col]/g[row][col];
            g[i][col]=0.0;
            for(j=col+1;j<=m;j++)
                g[i][j]-=t*g[row][j];
        }
    }
    for(i=n;i>=1;i--)  
    {
        x[i]=g[i][m];
        for(j=i+1;j<=n;j++)
            x[i]-=x[j]*g[i][j];
        x[i]/=g[i][i];
    }
}
int main()
{
    int i,j,cs,nn=0;
    scanf("%d",&cs);
    while(cs--){
        scanf("%d%d%d",&n,&m,&k);
        memset(g,0,sizeof(g));
        int cnt=0;
        for(i=0;i<m;i++)
            for(j=1;j<=n;j++)
            {
                cnt++;
                add(cnt,i,j,1.0);
                if(j==1)
                {
                    add(cnt,i+1,j,-0.25);
                    add(cnt,1,n-2,-0.75);
                }
                else if(j==2)
                {
                    add(cnt,i+1,n-2,-0.25);
                    add(cnt,1,1,-0.25);
                    add(cnt,1,n-1,-0.5);
                }
                else if(j==3)
                {
                    add(cnt,i+1,n-1,-0.25);
                    add(cnt,1,1,-0.25);
                    add(cnt,1,n-1,-0.25);
                    add(cnt,1,n,-0.25);
                }
                else if(j==4)
                {
                    add(cnt,i+1,n,-0.25);
                    add(cnt,1,n,-0.5);
                    add(cnt,1,1,-0.25);
                }
                else
                {
                    add(cnt,i+1,j-3,-0.25);
                    add(cnt,1,j-3,-0.75);
                }
            }
        gauss(cnt,cnt+1);
        printf("Case #%d: %.6lf\n",++nn,x[k]);
    }
    return 0;
}
