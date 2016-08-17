#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef __int64 ss;
struct node
{
    ss k;
    ss t;
    ss v;
};
ss n,m,t,a[50005],sum,flag;
vector<node>vet[10005];
ss vist[10005],dis[10005];
ss spfa(ss num)
{
    ss minx=a[num];
    for(ss i=0; i<=n; i++)
    {
        dis[i]=((ss)1<<25);
        vist[i]=0;
    }
    dis[1]=0;
    vist[1]=1;
    queue<ss>q;
    q.push(1);
    while(!q.empty())
    {
        ss x=q.front();
        q.pop();
        vist[x]=0;
        for(ss i=0; i<vet[x].size(); i++)
        {
            node p=vet[x][i];
            if(p.v>=minx)
            {
                if(dis[p.k]>dis[x]+p.t)
                {
                    dis[p.k]=dis[x]+p.t;
                    if(!vist[p.k])
                        q.push(p.k);
                    vist[p.k]=1;
                }
            }
        }
    }
    if(dis[n]<=t)
        return 1;
    else  return 0;
}
int main()
{
    int text;
    scanf("%d",&text);
    while(text--)
    {
        ss cnt=0;
        scanf("%I64d%I64d%I64d",&n,&m,&t);
        for(ss i=0; i<=n; i++)
            vet[i].clear();
        for(ss i=0; i<m; i++)
        {
            ss v1,v2,tmp,tmp1;
            scanf("%I64d %I64d %I64d %I64d",&v1,&v2,&tmp,&tmp1);
            node p;
            p.k=v2;
            p.t=tmp1;
            p.v=tmp;
            vet[v1].push_back(p);
            p.k=v1;
            vet[v2].push_back(p);
            a[cnt++]=tmp;
        }
        sort(a,a+cnt);
        ss ll=0,rr=cnt-1;
        ss ans=0;
        while(ll<=rr)
        {
            ss mid=(ll+rr)/2;
            if(spfa(mid))
            {
                if(ans<a[mid])
                    ans=a[mid];
                ll=mid+1;
            }
            else  rr=mid-1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
