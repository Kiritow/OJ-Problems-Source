#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lz 2*u,l,mid
#define rz 2*u+1,mid+1,r
const int maxn=2222;
typedef long long lld;
int flag[4*maxn];
lld sum1[4*maxn], sum2[4*maxn], sum3[4*maxn];
int X[maxn], Z[maxn];
struct Node
{
    int lx, rx, y, z1, z2, s;
    Node() {}
    Node(int lx_, int rx_ , int y_, int zm_, int zl_, int s_)
    {
        lx=lx_, rx=rx_, y=y_, z1=zm_, z2=zl_, s=s_;
    }
    bool operator<(const Node &S) const
    {
        if(y==S.y) return s>S.s;
        else return y<S.y;
    }
} line[maxn], tmp[maxn];
void push_up(int u, int l, int r)
{
    if(flag[u]>=3)   
    {
        sum3[u]=sum2[u]=sum1[u]=X[r+1]-X[l];
    }
    else if(flag[u]==2)
    {
        sum2[u]=sum1[u]=X[r+1]-X[l];
        if(l==r)sum3[u]=0;
        else
            sum3[u]=sum1[2*u]+sum1[2*u+1];
    }
    else if(flag[u]==1)
    {
        sum1[u]=X[r+1]-X[l];
        if(l==r)sum2[u]=sum3[u]=0;
        else
        {
            sum2[u]=sum1[2*u]+sum1[2*u+1];
            sum3[u]=sum2[2*u]+sum2[2*u+1];
        }
    }
    else
    {
        if(l==r)sum1[u]=sum2[u]=sum3[u]=0;
        else
        {
            sum1[u]=sum1[2*u]+sum1[2*u+1];
            sum2[u]=sum2[2*u]+sum2[2*u+1];
            sum3[u]=sum3[2*u]+sum3[2*u+1];
        }
    }
}
void Update(int u, int l, int r, int tl, int tr, int c)
{
    if(tl>tr) return ;
    if(tl<=l&&r<=tr)
    {
        flag[u]+=c;
        push_up(u,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(tr<=mid) Update(lz,tl,tr,c);
    else if(tl>mid) Update(rz,tl,tr,c);
    else
    {
        Update(lz,tl,mid,c);
        Update(rz,mid+1,tr,c);
    }
    push_up(u,l,r);
}
int find(int tmp, int n)
{
    int l=1, r=n, mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(X[mid]==tmp) return mid;
        else if(X[mid]<tmp) l=mid+1;
        else r=mid-1;
    }
}
int main()
{
    int T, n, tcase=0;
    cin >> T;
    while(T--)
    {
        cin >> n ;
        int num=0;
        for(int i=0; i<n; i++)
        {
            int x1, y1, x2, y2, z1, z2;
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            line[++num]=Node(x1,x2,y1,z1,z2,1);
            X[num]=x1, Z[num]=z1;
            line[++num]=Node(x1,x2,y2,z1,z2,-1);
            X[num]=x2, Z[num]=z2;
        }
        sort(line+1,line+num+1);
        sort(X+1,X+num+1);
        sort(Z+1,Z+num+1);
        int ep=1, m=1;
        for(int i=2; i<=num; i++)
            if(X[i]!=X[ep]) X[++ep]=X[i];
        for(int i=2; i<=num; i++)
            if(Z[i]!=Z[m]) Z[++m]=Z[i];
        lld ans=0;
        for(int j=1; j<m; j++)
        {
            memset(flag,0,sizeof(flag));
            memset(sum1,0,sizeof(sum1));
            memset(sum2,0,sizeof(sum2));
            memset(sum3,0,sizeof(sum3));
            lld tp=0, cnt=0;
            for(int i=1; i<=num; i++)
            {
                if(line[i].z1<=Z[j]&&Z[j]<line[i].z2)
                    tmp[++cnt]=line[i];
            }
            for(int i=1; i<cnt; i++)
            {
                int l=find(tmp[i].lx,ep);
                int r=find(tmp[i].rx,ep)-1;
                Update(1,1,ep-1,l,r,tmp[i].s);
                tp+=(lld)sum3[1]*(lld)(tmp[i+1].y-tmp[i].y);
            }
            ans+=(lld)tp*(lld)(Z[j+1]-Z[j]);
        }
        printf("Case %d: %I64d\n",++tcase,ans);
    }
    return 0;
}
