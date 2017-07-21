#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<list>
//#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
long long dp[1005][1005];
long long dp2[505][505];
char mp[1005][1005];
//n*m的图，计算以（1，1）为起点到所有曼哈顿距离和
long long get(long long n,long long m)
{
    return m*(m-1)*n/2+n*(n-1)*m/2;
}
//n*m的图，计算任意点到所有点的曼哈顿距离和
long long get2(long long x,long long y)
{
    return get(x,y)+get(n-x+1,y)+get(x,m-y+1)+get(n-x+1,m-y+1)-(get(1,x)+get(1,y)+get(1,n-x+1)+get(1,m-y+1));
}
int xx[1005],yy[1005],cnt2;
int pr[1005],pc[1005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt2=0;
        scanf("%d%d",&n,&m);
        long long up=(long long)m*n*(m*n-1)*(m+n)/3,down=0;
        int cnt=0;
        memset(pr,-1,sizeof pr);
        memset(pc,-1,sizeof pc);
        getchar();
        for(int i=0;i<n;i++)
        {

            gets(mp[i]);
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='G')
                {
                    pr[i]=j;
                    pc[j]=i;
                    up-=4ll*j*(m-j-1);//同行被阻断会在后面重复计算
                    up-=4ll*i*(n-i-1);//同列类似
                    up-=2*get2(i+1,j+1),cnt++;
                    xx[cnt2]=i;
                    yy[cnt2]=j;
                    cnt2++;
                }
            }
        }
        //计算绕行路径和
        int suml=0,sumr=0;
        for(int i=0;i<n;i++)
        {
            if(pr[i]!=-1)
            {
                if(i==0||pr[i]>pr[i-1]) suml+=pr[i];
                else suml=pr[i];
                up+=4ll*suml*(m-pr[i]-1);
            }
            else suml=0;
            if(pr[i]!=-1)
            {
                if(i==0||pr[i]<pr[i-1]) sumr+=m-pr[i]-1;
                else sumr=m-pr[i]-1;
                up+=4ll*sumr*pr[i];
            }
            else sumr=0;
        }
        int sumu=0,sumd=0;
        for(int i=0;i<m;i++)
        {
            if(pc[i]!=-1)
            {
                if(i==0||pc[i]>pc[i-1]) sumu+=pc[i];
                else sumu=pc[i];
                up+=4ll*sumu*(n-pc[i]-1);
            }
            else sumu=0;
            if(
               pc[i]!=-1)
            {
                if(i==0||pc[i]<pc[i-1]) sumd+=n-pc[i]-1;
                else sumd=n-pc[i]-1;
                up+=4ll*sumd*pc[i];
            }
            else sumd=0;
        }

        for(int i=0;i<cnt2;i++)
        {
            for(int j=0;j<cnt2;j++)
            {
                up+=abs(xx[i]-xx[j])+abs(yy[i]-yy[j]);
            }
        }
        down=(long long)(n*m-cnt)*(n*m-cnt);
        double ans=(long double)up/down;
        printf("%.4llf\n",ans);
    }
    return 0;
}
