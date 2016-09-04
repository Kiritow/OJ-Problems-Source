#include"iostream"
#include"cstdio"
#include"cmath"
#include"cstring"
using namespace std;
const int N=155;
int n,m,q,s;
int dp[N][N][9][9],le[N][N],rg[N][N],sum[N][N];
int lowbit[N];
inline int max(int a,int b){
    return a>b?a:b;
}
void RMQ()
{
    int j1,j2,row,col;
    int mx=int(log(1.0*n)/log(2.0));
    int my=int(log(1.0*m)/log(2.0));
    for(j1=0;j1<=mx;j1++)
    {
        for(j2=0;j2<=my;j2++)
        {
            if(!j1 && !j2)    continue;
            for(row=1;row+(1<<j1)-1<=n;row++)
            {
                for(col=1;col+(1<<j2)-1<=m;col++)
                {
                    if(!j1)
                        dp[row][col][j1][j2]=max(dp[row][col][j1][j2-1],dp[row][col+(1<<(j2-1))][j1][j2-1]);
                    else
                        dp[row][col][j1][j2]=max(dp[row][col][j1-1][j2],dp[row+(1<<(j1-1))][col][j1-1][j2]);
                }
            }
        }
    }
}
int power[N];
inline int query(int x1,int y1,int x2,int y2)
{
    int kx=power[x2-x1+1];
    int ky=power[y2-y1+1];
    int m1=dp[x1][y1][kx][ky];
    int m2=dp[x2-(1<<kx)+1][y1][kx][ky];
    int m3=dp[x1][y2-(1<<ky)+1][kx][ky];
    int m4=dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
    return max(max(m1,m2),max(m3,m4));
}
void init()
{
    int i,l,temp;
    for(i=0;i<=150;i++) power[i]=log(double(i))/log(2.0);
    for(i=1;i<=n;i++)
    {
        temp=0;
        for(l=1;l<=m;l++)
        {
            scanf("%d",&dp[i][l][0][0]);
            temp+=dp[i][l][0][0];
            sum[i][l]=sum[i-1][l]+temp;
        }
    }
    for(i=1;i<=n;i++)   {le[i][0]=1;rg[i][m+1]=m;}
    for(i=1;i<=n;i++)
    {
        for(l=1;l<=m;l++)
        {
            if(dp[i][l][0][0]==-1)    le[i][l]=l+1;
            else    le[i][l]=le[i][l-1];
        }
        for(l=m;l>=1;l--)
        {
            if(dp[i][l][0][0]==-1)    rg[i][l]=l-1;
            else    rg[i][l]=rg[i][l+1];
        }
    }
    RMQ();
}
int main()
{
    int T,Case;
    int i,l;
    int up;
    int x1,y1,x2,y2,lmax,rmin;
    int t,temp,ans;
    cin>>T;
    for(i=1;i<=150;i++) lowbit[i]=i&(-i);
    for(Case=1;Case<=T;Case++)
    {
        if(Case>1)  printf("\n");
        printf("Case %d:\n",Case);
        scanf("%d%d%d%d",&n,&m,&q,&s);
        init();
        while(q--)
        {
            ans=0;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(l=y1;l<=y2;l++)
            {
                up=x1;
                lmax=y1;
                rmin=y2;
                for(i=x1;i<=x2;i++)
                {
                    if(le[i][l]==l+1)   {up=i+1;lmax=y1;rmin=y2;continue;}
                    if(lmax<le[i][l])   lmax=le[i][l];
                    if(rmin>rg[i][l])   rmin=rg[i][l];
                    temp=query(up,lmax,i,rmin);
                    t=(s-1)*temp+sum[i][rmin]-sum[i][lmax-1]-sum[up-1][rmin]+sum[up-1][lmax-1];
                    if(ans<t)   ans=t;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
