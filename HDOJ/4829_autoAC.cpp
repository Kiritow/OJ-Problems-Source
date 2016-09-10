#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctime>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define maxn 1111111
#define mset(a) memset(a,0,sizeof a)
const LL MOD=9999991;
int father[maxn];
int x[maxn],y[maxn];
int v[maxn];
int ve;
int findfather(int xx)
{
    if(father[xx]==xx)
        return xx;
    int fa=findfather(father[xx]);
    x[xx]+=x[father[xx]];
    y[xx]+=y[father[xx]];
    father[xx]=fa;
    return fa;
}
void unit(int aa,int bb,int X,int Y)
{
    int fa=findfather(aa);
    int fb=findfather(bb);
    if(fa!=fb)
    {
        father[fa]=fb;
        x[fa]=x[bb]+X-x[aa];
        y[fa]=y[bb]+Y-y[aa];
    }
    else
    {
        int bax=x[aa]-x[bb];
        int bay=y[aa]-y[bb];
        if(bax!=X||bay!=Y)
            puts("REJECT");
    }
}
bool sf(int a,int b)
{
    int fa=findfather(a);
    int fb=findfather(b);
    return fa==fb;
}
void newv(int a)
{
    v[a]=++ve;
    father[ve]=ve;
    x[ve]=0;
    y[ve]=0;
}
int main()
{
    int t;
    cin>>t;
    int n;
    REP(c,1,t)
    {
        ve=0;
        x[0]=y[0]=v[0]=father[0]=0;
        printf("Case #%d:\n",c);
        scanf("%d",&n);
        REP(i,0,n)
        {newv(i);father[i]=i;v[i]=i;}
        mset(x);
        mset(y);
        int q,a,b,xx,yy;
        REP(i,1,n)
        {
            scanf("%d",&q);
            if(q==1||q==2)
            {
                b=0;
                if(q==1) scanf("%d%d%d%d",&a,&b,&xx,&yy);
                else scanf("%d%d%d",&a,&xx,&yy);
                newv(a);
                unit(v[a],v[b],xx,yy);
            }
            if(q==3||q==4)
            {
                b=0;
                if(q==3) scanf("%d%d%d%d",&a,&b,&xx,&yy);
                else scanf("%d%d%d",&a,&xx,&yy);
                unit(v[a],v[b],xx,yy);
            }
            if(q==5||q==6)
            {
                b=0;
                if(q==5)
                    scanf("%d%d",&a,&b);
                else scanf("%d",&a);
                a=v[a];
                b=v[b];
                if(!sf(a,b))
                    puts("UNKNOWN");
                else printf("%d %d\n",x[a]-x[b],y[a]-y[b]);
            }
        }
    }
}
