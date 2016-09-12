#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#define N 110000  
#define pr pair<int,int>  
#define lson l,mid,no<<1  
#define rson mid+1,r,no<<1|1  
#define mod 1000000007ll  
using namespace std;  
typedef long long ll;  
int dis[N<<1],len;  
pr L[N];  
ll sum[N<<3],cov[N<<3];  
ll P[N],S[N];  
void Pushdown(int no,int len)  
{  
    if(cov[no])  
    {  
        cov[no<<1]+=cov[no];  
        cov[no<<1|1]+=cov[no];  
        sum[no<<1]+=cov[no]*(len-(len>>1));  
        sum[no<<1|1]+=cov[no]*(len>>1);  
        cov[no]=0;  
    }  
}  
void Pushup(int no)  
{  
    sum[no]=sum[no<<1]+sum[no<<1|1];  
}  
void update(int l,int r,int no,int st,int en)  
{  
    if(st<=l&&r<=en)  
    {  
        cov[no]++;  
        sum[no]+=r-l+1;  
    }  
    else  
    {  
        int mid=l+r>>1;  
        Pushdown(no,r-l+1);  
        if(en<=mid)        update(lson,st,en);  
        else if(st>mid)    update(rson,st,en);  
        else update(lson,st,en),update(rson,st,en);  
        Pushup(no);  
    }  
}  
int query(int l,int r,int no,int k)  
{  
    if(l==r)  
        return sum[no];  
    else  
    {  
        int mid=l+r>>1;  
        Pushdown(no,r-l+1);  
        if(k<=mid)    return query(lson,k);  
        else        return query(rson,k);  
    }  
}  
int main()  
{  
    int c,T;  
    int n,i,l,r;  
    scanf("%d",&T);  
    P[1]=1;  
    for(i=2;i<N;i++)  
        P[i]=P[i-1]*2%mod;  
    for(i=1;i<N;i++)  
        S[i]=(S[i-1]+P[i])%mod;  
    for(c=1;c<=T;c++)  
    {  
        memset(sum,0,sizeof(sum));  
        memset(cov,0,sizeof(cov));  
        scanf("%d",&n);  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d%d",&L[i].first,&L[i].second);  
            dis[i+i-1]=L[i].first;  
            dis[i+i]=L[i].second;  
        }  
        sort(dis+1,dis+n+n+1);  
        len=unique(dis+1,dis+n+n+1)-dis-1;  
        for(i=1;i<=n;i++)  
        {  
            l=lower_bound(dis+1,dis+len+1,L[i].first)-dis;  
            r=lower_bound(dis+1,dis+len+1,L[i].second)-dis;  
            if(l<=r-1)  
            update(1,len-1,1,l,r-1);  
        }  
        ll ans=0;  
        for(i=1;i<len;i++)  
        {  
            ans=(ans+(S[n]-S[n-query(1,len-1,1,i)]+mod)%mod*(((ll)dis[i+1]-dis[i]+mod)%mod)%mod)%mod;  
        }  
        printf("%I64d\n",ans);  
    }  
    return 0;  
}
