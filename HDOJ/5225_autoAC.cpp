#include <stdio.h>
#include <iostream>
using namespace std;
#define mod 1000000007
#define llt long long
llt cal[110],a[110],A[110];
llt tree[330];
template<class T>
inline char read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' | c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return c;
}
template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n) {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
void create(llt l,llt r,llt rt)
{
    tree[rt]=0;
    if(l==r) return;
    llt mid=(l+r)>>1;
    create(l,mid,rt<<1);
    create(mid+1,r,rt<<1|1);
}
llt query(llt ll,llt rr,llt l,llt r,llt rt)
{
    if(l==ll&&r==rr) return tree[rt];
    llt mid=(l+r)>>1;
    if(rr<=mid) return query(ll,rr,l,mid,rt<<1);
    else if(ll>mid) return query(ll,rr,mid+1,r,rt<<1|1);
    else
    {
        llt ans=query(ll,mid,l,mid,rt<<1);
        ans+=query(mid+1,rr,mid+1,r,rt<<1|1);
        return ans;
    }
}
void update(llt l,llt r,llt rt,llt x)
{
    if(l==x&&r==x)
    {
        tree[rt]++;
        return;
    }
    llt mid=(l+r)>>1;
    if(x<=mid) update(l,mid,rt<<1,x);
    else update(mid+1,r,rt<<1|1,x);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void init()
{
    cal[0]=0,cal[1]=0,cal[2]=1;
    A[1]=1;A[0]=1;
    for(int i=2;i<=100;i++)
    {A[i]=(A[i-1]*i)%mod;
    }
    for(int i=3;i<=100;i++)
    {
        cal[i]=((i*cal[i-1])%mod+(i*(i-1)*A[i-1]/2)%mod)%mod;
    }
}
llt sum(llt x)
{
    return ((x-1)*x)/2;
}
int main()
{
    init();llt n;
    while(scanf("%I64d",&n)!=EOF)
    {
        llt ans=0;
        llt i,j,pre=0,tmp=0;
        llt k;
        create(1,100,1);
        for(i=1;i<=n;i++)
        {
            read(a[i]);
            tmp=query(a[i]+1>100?100:a[i]+1,100,1,100,1);
            j=n-i-(n-a[i]-tmp);  
            if(j<=0) continue;
            k=A[n-i];llt p=cal[n-i];
            ans=(ans+((p*j)%mod+(pre*k*j)%mod+(sum(j)*k)%mod)%mod)%mod;
            update(1,100,1,a[i]);
            pre+=j;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
