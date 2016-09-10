#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;
const int maxn=44;
const int maxm=(1<<20)+10;
const int INF=1e9;
char a[maxn];
int c[maxn],b[maxn],x,y,xx,yy,sx,sy,t,f[maxn],g[maxm],len[maxn];
struct node{
    int id,w,flag;
    bool operator <(const node &a)const{
        if(id==a.id)return w<a.w;
        return id<a.id;
    }
}e[maxm*2];
int bitcount(int i)
{
    int x=0;
    while(i)
    {
        x+=(i&1);
        i=i>>1;
    }
    return x;
}
void init()
{
    for(int i=0;i<=22;i++)
    {
        f[i]=(1<<i)-1;
        len[i]=i*10000000;
    }
    for(int i=0;i<(1<<20);i++)
    {
        g[i]=bitcount(i);
    }
}
void judge()
{
    int i,j,k;
    if((y>>(yy-xx))^x)return ;
    e[t].flag=0;
    e[t].id=len[yy-xx]+(y&f[yy-xx]);
    e[t++].w=sy-sx;
}
void judge2()
{
    int i,j,k,p;
    if(x^(y&f[xx]))return ;
    e[t].flag=1;
    e[t].id=len[yy-xx]+(y>>xx);
    e[t++].w=sy-sx;
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int i,j,k=0,ans=INF;
        scanf("%s",a);
        for(i=0;i<2*n;i++)
        {
            b[i]=a[i]-'a';
            k+=b[i];
        }
        for(i=0;i<n*2;i++)
            scanf("%d",&c[i]);
        if(k%2){printf("-1\n");continue;}
        t=0;
        for(i=0;i<(1<<n);i++)
        {
            if(g[i]>n-g[i])continue;
            x=y=xx=yy=sx=sy=0;
            for(j=n-1;j>=0;j--)
            {
                if((1<<j)&i)
                {
                    x=(x<<1)|b[n-1-j];
                    sx+=c[n-1-j];
                    xx++;
                }
                else
                {
                    y=(y<<1)|b[n-1-j];
                    sy+=c[n-1-j];
                    yy++;
                }
            }
            if(xx<=yy)judge();
        }
        for(i=0;i<(1<<n);i++)
        {
            if(g[i]>n-g[i])continue;
            x=y=xx=yy=sx=sy=0;
            for(j=n-1;j>=0;j--)
            {
                if((1<<j)&i)
                {
                    x=(x<<1)|b[2*n-1-j];
                    sx+=c[2*n-1-j];
                    xx++;
                }
                else
                {
                    y=(y<<1)|b[2*n-1-j];
                    sy+=c[2*n-1-j];
                    yy++;
                }
            }
            if(xx<=yy)judge2();
        }
        sort(e,e+t);
        int p=-1,q=-1;
        for(i=0;i<t;i++)
        {
            if(e[i].flag==0)p=i;
            else q=i;
            if(p==-1||q==-1)continue;
            if(e[p].id==e[q].id)ans=min(ans,abs(e[p].w-e[q].w));
        }
        if(ans==INF)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
