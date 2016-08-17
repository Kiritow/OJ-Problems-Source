#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const double eps=1e-6;
const int maxn=2100;
int xL,xR,yL,yR,Value;
int Max[220<<2][maxn<<2];
int N,M;
int maxv;
void pushup(int xrt,int rt)
{
    Max[xrt][rt]=max(Max[xrt][rt<<1],Max[xrt][rt<<1|1]);
}
void updateY(int xrt,int x,int l,int r,int rt)
{
    if(l==r)
    {
        if(x==-1)
        {
            Max[xrt][rt]=max(Max[xrt<<1][rt],Max[xrt<<1|1][rt]);
        }
        else
        {
            Max[xrt][rt]=max(Max[xrt][rt],Value);
        }
        return ;
    }
    int m=(l+r)/2;
    if(yL<=m) updateY(xrt,x,lson);
    else updateY(xrt,x,rson);
    pushup(xrt,rt);
}
void updateX(int l,int r,int rt)
{
    if(l==r)
    {
        updateY(rt,l,1,M,1);
        return ;
    }
    int m=(l+r)/2;
    if(xL<=m) updateX(lson);
    else updateX(rson);
    updateY(rt,-1,1,M,1);
}
void queryY(int xrt,int l,int r,int rt)
{
    if(yL<=l&&r<=yR)
    {
        maxv=max(maxv,Max[xrt][rt]);
        return ;
    }
    int m=(l+r)/2;
    if(yL<=m) queryY(xrt,lson);
    if(yR>m) queryY(xrt,rson);
}
void queryX(int l,int r,int rt)
{
    if(xL<=l&&r<=xR)
    {
        queryY(rt,1,M,1);
        return ;
    }
    int m=(l+r)/2;
    if(xL<=m) queryX(lson);
    if(xR>m) queryX(rson);
}
int main()
{
    int op;char cmd[20];
    N=200;M=2100;
    while(scanf("%d",&op)!=EOF&&op)
    {
        memset(Max,-1,sizeof(Max));
        while(op--)
        {
            scanf("%s",cmd);
            if(cmd[0]=='I')
            {
                int H;
                double a,l;
                scanf("%d%lf%lf",&H,&a,&l);
                H-=99;
                int A=(int)((a+eps)*10);
                int L=(int)((l+eps)*10);
                xL=H;yL=A;Value=L;
                updateX(1,N,1);
            }
            else if(cmd[0]=='Q')
            {
                int H1,H2;
                double a1,a2;
                scanf("%d%d%lf%lf",&H1,&H2,&a1,&a2);
                int A1=(int)((a1+eps)*10);
                int A2=(int)((a2+eps)*10);
                xL=min(H1,H2)-99,xR=max(H1,H2)-99;
                yL=min(A1,A2),yR=max(A1,A2);
                maxv=-(1<<30);
                queryX(1,N,1);
                if(maxv==-1) printf("-1\n");
                else printf("%.1lf\n",maxv/10.);
            }
        }
    }
    return 0;
}
