#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define lz 2*u,l,mid
#define rz 2*u+1,mid+1,r
const int maxn=50005;
int maxx[4*maxn], flag[4*maxn];
int a[maxn];
int pre[maxn];
int n, m, T;
vector<int>vt;
struct node
{
    int l, r, id;
    int ans;
    friend bool operator<(const node A, const node B)
    {
        return A.r<B.r;
    }
}f[maxn];
bool cmp(node A, node B)
{
    return A.id<B.id;
}
void push_down(int u, int l, int r)
{
    if(flag[u])
    {
        flag[2*u]=max(flag[2*u],flag[u]);
        flag[2*u+1]=max(flag[2*u+1],flag[u]);
        maxx[2*u]=max(maxx[2*u],flag[u]);
        maxx[2*u+1]=max(maxx[2*u+1],flag[u]);
        flag[u]=0;
    }
}
void Update(int u, int l, int r, int tl, int tr, int val)
{
    maxx[u]=max(maxx[u],val);
    if(tl<=l&&r<=tr)
    {
        flag[u]=max(flag[u],val);
        maxx[u]=max(maxx[u],val);
        return ;
    }
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) Update(lz,tl,tr,val);
    else if(tl>mid) Update(rz,tl,tr,val);
    else
    {
        Update(lz,tl,mid,val);
        Update(rz,mid+1,tr,val);
    }
}
int Query(int u, int l, int r, int tl, int tr)
{
    if(tl<=l&&r<=tr) return maxx[u];
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) return Query(lz,tl,tr);
    else if(tl>mid) return Query(rz,tl,tr);
    else
    {
        int t1=Query(lz,tl,mid);
        int t2=Query(rz,mid+1,tr);
        return max(t1,t2);
    }
}
void Solve(int x, int r)
{
    vt.clear();
    vt.push_back(x);
    for(int i=2; i*i<=x; i++)
        if(x%i==0)
        {
            vt.push_back(i);
            vt.push_back(x/i);
        }
    for(int i=0; i<vt.size(); i++)
    {
        int l=pre[ vt[i] ];
        pre[ vt[i] ]=r;
        if(l==-1||l==r) continue;
        Update(1,1,n,l,l,vt[i]);
    }
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=1; i<=n; i++) scanf("%d", a+i), pre[i]=-1;
        cin >> m;
        for(int i=1; i<=m; i++) f[i].id=i, scanf("%d%d",&f[i].l,&f[i].r);
        sort(f+1,f+m+1);
        for(int i=1; i<=4*n; i++) maxx[i]=1, flag[i]=0;
        int i=1, j=1;
        while(j<=m)
        {
            if(i<=f[j].r&&i<=n)
            {
                Solve(a[i],i);
                i++;
            }
            else
            {
                if(f[j].l!=f[j].r)f[j].ans=Query(1,1,n,f[j].l,f[j].r);
                else f[j].ans=0;
                j++;
            }
        }
        sort(f+1,f+m+1,cmp);
        for(int i=1; i<=m; i++)
            printf("%d\n",f[i].ans);
    }
    return 0;
}
