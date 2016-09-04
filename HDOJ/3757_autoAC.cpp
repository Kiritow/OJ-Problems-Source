#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long inf=(1LL)<<60;
short path[4010][4010];
long long f[4010];
struct node
{
    long long d;
    int num;
    int sh;
}x[4010],y[4010];
int n,m;
bool cmpd(node a,node b)
{
    return a.d<b.d;
}
bool cmpnum(node a,node b)
{
    return a.num<b.num;
}
void solve(int i,int j)
{
    if(i!=1) solve(i-1,path[i][j]);
    x[i].sh=y[j].num;
}
int main()
{
    int sec;
    scanf("%d",&sec);
    for(int z=1;z<=sec;z++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&x[i].d);
            x[i].num=i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%I64d",&y[i].d);
            y[i].num=i;
        }
        sort(x+1,x+1+n,cmpd);
        sort(y+1,y+1+m,cmpd);
        for(int i=0;i<=max(n,m);i++)
        f[i]=inf;
        f[1]=abs(x[1].d-y[1].d);
        for(int i=2;i<=n;i++)
         for(int j=min(i,m);j>=1;j--)
        {
            if(f[j]<f[j-1])
            {
                f[j]=f[j]+abs(x[i].d-y[j].d);
                path[i][j]=j;
            }
            else
            {
                f[j]=f[j-1]+abs(x[i].d-y[j].d);
                path[i][j]=j-1;
            }
        }
        printf("%I64d\n",f[m]);
        solve(n,m);
        sort(x+1,x+1+n,cmpnum);
        for(int i=1;i<=n-1;i++)
        printf("%d ",x[i].sh);
        printf("%d\n",x[n].sh);
    }
    return 0;
}
