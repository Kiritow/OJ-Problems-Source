#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define LL long long
#define INF 0x3f3f3f3f
#define msz 405000
#define Max 50000000000000
using namespace std;
typedef struct LinkTree
{
    LL sum[2][2];
}LinkTree;
LinkTree tr[405005];
int n,m;
LinkTree Joint(LinkTree a,LinkTree b)
{
    int i,j;
    LL t;
    LinkTree tmp;
    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < 2; ++j)
        {
            tmp.sum[i][j] = max(a.sum[i][j],b.sum[i][j]);
            t = max(a.sum[i][0]+b.sum[1][j],a.sum[i][1]+b.sum[0][j]);
            tmp.sum[i][j] = max(tmp.sum[i][j],t);
        }
    }
    return tmp;
}
void SetTree(int site,int l,int r)
{
    int i,j,x;
    if(l == r)
    {
        scanf("%d",&x);
        for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
                tr[site].sum[i][j] = -Max;
        tr[site].sum[l&1][r&1] = x;
        return;
    }
    int m = (l+r)>>1;
    SetTree(site<<1,l,m);
    SetTree(site<<1|1,m+1,r);
    tr[site] = Joint(tr[site<<1],tr[site<<1|1]);
}
void Change(int site,int l,int r,int k,int data)
{
    if(l == k && r == k)
    {
        tr[site].sum[l&1][l&1] = data;
        return;
    }
    int m = (l+r)>>1;
    if(m >= k)
        Change(site<<1,l,m,k,data);
    else
        Change(site<<1|1,m+1,r,k,data);
    tr[site] = Joint(tr[site<<1],tr[site<<1|1]);
}
LinkTree MAX(int site,int l,int r,int ll,int rr)
{
    int i,j;
    LinkTree tmp;
    if(l == ll && r == rr)
    {
        return tr[site];
    }
    int m = (l+r)>>1;
    if(m >= rr) return MAX(site<<1,l,m,ll,rr);
    else if(m < ll) return MAX(site<<1|1,m+1,r,ll,rr);
    else
    {
        return Joint(MAX(site<<1,l,m,ll,m),MAX(site<<1|1,m+1,r,m+1,rr));
    }
}
int main()
{
    int i,j,t,x,b,a;
    LL mm;
    LinkTree tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        SetTree(1,1,n);
        while(m--)
        {
            scanf("%d %d %d",&x,&a,&b);
            if(x) Change(1,1,n,a,b);
            else
            {
                tmp = MAX(1,1,n,a,b);
                mm = -Max;
                for(i = 0; i  < 2; ++i)
                {
                    for(j = 0; j < 2; ++j)
                    {
                        mm = max(mm,tmp.sum[i][j]);
                    }
                }
                printf("%lld\n",mm);
            }
        }
    }
    return 0;
}
