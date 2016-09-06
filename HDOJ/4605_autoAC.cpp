#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 100005
struct list
{
    int l,r;
    int w;
}node[maxn];
int fs[maxn*2];
int fss[maxn*2];
struct qq
{
    int x;
    int id;
}xx;
vector<qq>num[maxn];
int ans[maxn][2];
int sum[maxn][2];
int w[maxn];
int n,m,q,len;
int lowbit(int x)
{
     return (x&(-x));
}
int search(int l,int r,int w)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(fs[mid]==w)return mid;
        if(fs[mid]<w)l=mid+1;
        else r=mid;
    }
}
void add(int x,int bs,int num)
{
    for(;x<len;x+=lowbit(x))
    {
        sum[x][bs]+=num;
    }
}
int allsum(int s,int bs)
{
    int ss;
    ss=0;
    while(s>0)
    {
        ss+=sum[s][bs];
        s=s-lowbit(s);
    }
    return ss;
}
void dfs(int x)
{
    int s;
    s=num[x].size();
    for(int i=0;i<s;i++)
    {
        xx=num[x][i];
        int z,id;
        z=search(1,len,xx.x);
        id=xx.id;
        if(allsum(z,0)-allsum(z-1,0)+allsum(z,1)-allsum(z-1,1)>0)
        {
            ans[id][0]=-1;
            continue;
        }
        int ll,lr,rl,rr;
        ll=allsum(len-1,0)-allsum(z,0);
        rl=allsum(z,0);
        lr=allsum(len-1,1)-allsum(z,1);
        rr=allsum(z,1);
        ans[id][0]=rr;
        ans[id][1]=(rl+rr)*3+ll+lr;
    }
    s=search(1,len,node[x].w);
    if(node[x].l!=-1)
    {
        add(s,0,1);
        dfs(node[x].l);
        add(s,0,-1);
    }
    if(node[x].r!=-1)
    {
        add(s,1,1);
        dfs(node[x].r);
        add(s,1,-1);
    }
}
int main()
{
    int T,a,b,c,i;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ll=1;
        memset(fs,0,sizeof(fs));
        memset(ans,0,sizeof(ans));
        memset(fss,0,sizeof(fss));
        for (i = 1; i <= n; ++i) node[i].l = node[i].r = node[i].w = -1;
        for(i=1;i<=n;i++)
        {
            num[i].clear();
            scanf("%d",&w[i]);
            node[i].w=w[i];
            fss[ll++]=w[i];
        }
        cin>>m;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            node[a].l=b;
            node[a].r=c;
        }
        cin>>q;
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b);
            fss[ll++]=b;
            xx.id=i;
            xx.x=b;
            num[a].push_back(xx);
        }
        len=1;
        sort(fss,fss+ll);
        for(i=1;i<ll;i++)
            if(fss[i]!=fss[i-1])fs[len++]=fss[i];
        dfs(1);
        for(i=1;i<=q;i++)
        {
            if(ans[i][0]==-1)printf("0\n");
            else printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
    return 0;
}
