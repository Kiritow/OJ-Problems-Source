#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=200010;
int N;
int maxvid,maxvsum;
LL R;
int height[maxn];
struct IntervalTree
{
    LL sum[maxn<<2];
    int id[maxn<<2];
    void build(int o,int l,int r)
    {
        if(l==r)
        {
            sum[o]=R*(l-1)+height[l];
            id[o]=l;
            return ;
        }
        int mid=(l+r)>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        pushup(o);
    }
    void pushup(int o)
    {
        if(sum[o<<1]<sum[o<<1|1])
        {
            sum[o]=sum[o<<1|1];
            id[o]=id[o<<1|1];
        }
        else
        {
            sum[o]=sum[o<<1];
            id[o]=id[o<<1];
        }
    }
    void query(int o,int l,int r,int q1,int q2)
    {
        if(q1<=l&&r<=q2)
        {
            if(sum[o]>maxvsum)
            {
                maxvsum=sum[o];
                maxvid=id[o];
            }
            return ;
        }
        int mid=(l+r)>>1;
        if(q1<=mid)query(o<<1,l,mid,q1,q2);
        if(q2>mid)query(o<<1|1,mid+1,r,q1,q2);
    }
}tree;
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%I64d",&N,&R);
        for(int i=1;i<=N;i++)
            scanf("%d",&height[i]);
        for(int i=1;i<=N;i++)
            height[i+N]=height[i];
        tree.build(1,1,N*2);
        LL anssum=0;
        int x,y,p;
        pair<int,int> ans=make_pair(N,N),tmp;
        for(int i=1;i<=N*2;i++)
        {
            int r=i+N/2,l=i-N/2;
            if(r>N*2||l<1)continue;
            maxvid=maxvsum=0;
            tree.query(1,1,N*2,i+1,r);
            x=maxvid;
            maxvid=maxvsum=0;
            tree.query(1,1,N*2,l,i-1);
            y=maxvid;
            if((i-y)*R+height[i]+height[y]>anssum)
            {
                anssum=(i-y)*R+height[i]+height[y];
                if(y>N)y-=N;
                p=i;
                if(p>N)p-=N;
                tmp=make_pair(min(y,p),max(y,p));
                ans=tmp;
            }
            else if((i-y)*R+height[i]+height[y]==anssum)
            {
                if(y>N)y-=N;
                p=i;
                if(p>N)p-=N;
                tmp=make_pair(min(y,p),max(y,p));
                if(tmp<ans)ans=tmp;
            }
            if((x-i)*R+height[x]+height[i]>anssum)
            {
                anssum=(x-i)*R+height[x]+height[i];
                if(x>N)x-=N;
                p=i;
                if(p>N)p-=N;
                tmp=make_pair(min(x,p),max(x,p));
                ans=tmp;
            }
            else if((x-i)*R+height[x]+height[i]==anssum)
            {
                if(x>N)x-=N;
                p=i;
                if(p>N)p-=N;
                tmp=make_pair(min(x,p),max(x,p));
                if(tmp<ans)ans=tmp;
            }
        }
        printf("Case #%d:\n",cas++);
        printf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}
