#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct Node
{
    long long s,t;
}node[11000];
int cmp(const void *a,const void *b)
{
    return ((Node *)b)->s-((Node *)a)->s;
}
long long S[11000],T[11000],N;
int ff(int s,int t)
{
    if(N==1)
        return 1;
    if(N==2)
    {
        if((T[1]-t)*(S[2]-s)<(S[1]-s)*(T[2]-t))
            return 1;
        return 2;
    }
    int l=2,r=N-1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if((T[mid]-t)*(S[mid-1]-s)<=(T[mid-1]-t)*(S[mid]-s)&&(T[mid]-t)*(S[mid+1]-s)<=(T[mid+1]-t)*(S[mid]-s))
            l=r=mid;
        else if((T[mid]-t)*(S[mid-1]-s)<(T[mid-1]-t)*(S[mid]-s)&&(T[mid]-t)*(S[mid+1]-s)>=(T[mid+1]-t)*(S[mid]-s))
            l=mid+1;
        else
            r=mid-1;
    }
    if((T[1]-t)*(S[r]-s)<(T[r]-t)*(S[1]-s))
        r=1;
    if((T[N]-t)*(S[r]-s)<(T[r]-t)*(S[N]-s))
        r=N;
    return r;
}
int q[11000],f,r,qq[11000];
int main()
{
    long long n,s,w,d,L,j;
    int i,t;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d%I64d",&n,&d,&L,&w);
        for(i=1,s=0;i<=n;i++)
            scanf("%I64d%I64d",&node[i].s,&node[i].t),s+=d*node[i].t,w-=node[i].s*d;
        L-=d*n;
        if(L<0||w<0)
        {
            printf("No solution\n");
            continue;
        }
        qsort(node+1,n,sizeof(Node),cmp);
        for(i=1,f=1,r=0;i<=n;i++)
        {
            while(f<=r&&node[i].t<node[q[r]].t)
                r--;
            q[++r]=i;
        }
        n=r;
        for(i=1;i<=n&&L*node[q[i]].s>w;i++);
        if(i>n)
        {
            printf("No solution\n");
            continue;
        }
        else if(L*(node[q[1]].s)<=w)
        {
            printf("%.2f\n",s+L*node[q[1]].t+0.0);
            continue;
        }
        r=i;
        S[1]=node[q[1]].s,T[1]=node[q[1]].t;
        for(i=2,N=1,qq[1]=q[1];i<r;i++)
        {
            while(N>1&&((node[qq[N-1]].t-node[qq[N]].t)*(node[qq[N]].s-node[q[i]].s)<=(node[qq[N]].t-node[q[i]].t)*(node[qq[N-1]].s-node[qq[N]].s)))
                N--;
            qq[++N]=q[i];
        }
        for(i=1;i<=N;i++)
            S[i]=node[qq[i]].s,T[i]=node[qq[i]].t;
        for(ans=4000000000,i=r;i<=n;i++)
        {
            j=ff(node[q[i]].s,node[q[i]].t);
            j=qq[j];
            double tt=L*node[q[i]].t+(w-L*node[q[i]].s)*((node[q[i]].t-node[j].t+0.0)/(node[q[i]].s-node[j].s+0.0));
            if(tt<ans)
                ans=tt;
        }
        printf("%.2f\n",ans+s);
    }
}
