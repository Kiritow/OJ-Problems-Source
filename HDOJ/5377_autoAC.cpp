#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <tr1/unordered_map>
#define clr(x, y) memset(x, y, sizeof x)
using namespace std;
typedef long long LL;
const double eps=1e-8;
const int maxn=100100;
const int mod=1e6+10;
LL prime[maxn];
LL X[maxn],Y[maxn];
LL A[maxn],B[maxn];
LL ans[maxn];
LL M;
LL get_prime(LL n)
{
    LL cnt=0;
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime[cnt++]=i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        prime[cnt++]=n;
    return cnt;
}
LL pow_mod(LL a,LL p,LL n)
{
    LL ans=1;
    while(p)
    {
        if(p&1)
            ans=(ans*a)%n;
        p>>=1;
        a=(a*a)%n;
    }
    return ans;
}
vector<LL>a;
bool g_test(LL g,LL p)
{
    for(LL i=0;i<a.size();i++)
    {
        if(pow_mod(g,(p-1)/a[i],p)==1)
            return 0;
    }
    return 1;
}
LL primitive_root(LL p)
{
    LL tmp=p-1;
    a.clear();
    for(LL i=2;i<=tmp/i;i++)
    {
        if(tmp%i==0)
        {
            a.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    }
    if(tmp!=1)
        a.push_back(tmp);
    LL g=1;
    while(true)
    {
        if(g_test(g,p))
            return g;
        g++;
    }
}
void gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b) {  d=a;  x=1;  y=0;}
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
LL inv(LL a,LL n)
{
    LL d,x,y;
    gcd(a,n,d,x,y);
    return d==1 ? (x+n)%n : -1;
}
struct HashTable
{
    int top,head[mod];
    struct Node
    {
        int x,y,next;
    }node[mod];
    void init()
    {
        top=0;
        memset(head,0,sizeof(head));
    }
    void insert(LL x,LL y)
    {
        node[top].x=x;
        node[top].y=y;
        node[top].next=head[x%mod];
        head[x%mod]=top++;
    }
    LL query(LL x)
    {
        for(int tx=head[x%mod];tx;tx=node[tx].next)
        {
            if(node[tx].x==x)
                return node[tx].y;
        }
        return -1;
    }
}hs;
void log_mod(LL a,LL n)
{
    LL m,v,e=1;
    m=mod;
    v=inv(pow_mod(a,m,n),n);
    hs.init();
    for(int i=0;i<m;i++)
    {
        hs.insert(e,i);
        e=e*a%n;
    }
    for(int j=0;j<M;j++)
    {
        LL b=X[j]%n;
        for(int i=0;i<m;i++)
        {
            LL s=hs.query(b);
            if(s!=-1)
            {
                A[j]=i*m+s;
                break;
            }
            b=b*v%n;
        }
        b=Y[j]%n;
        for(int i=0;i<=n/m;i++)
        {
            LL s=hs.query(b);
            if(s!=-1)
            {
                B[j]=i*m+s;
                break;
            }
            b=b*v%n;
        }
    }
}
LL get_K(LL a,LL b,LL c)
{
    LL d,x,y;
    gcd(a,b,d,x,y);
    if(c%d!=0)
        return -1;
    x=x*c/d;
    b=b/d;
    x=x-(x/b*b);
    if(x<0)
        x+=b;
    return x;
}
int main()
{
    int T;
    LL sum;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        memset(ans,-1,sizeof(ans));
        scanf("%I64d %I64d",&sum,&M);
        printf("Case #%d:\n",t);
        for(int i=0;i<M;i++)
        {
            scanf("%I64d %I64d",&X[i],&Y[i]);
        }
        LL cnt=get_prime(sum);
        LL temp;
        for(int j=0;j<cnt;j++)
        {
            LL d=primitive_root(prime[j]);
            log_mod(d,prime[j]);
            for(int i=0;i<M;i++)
            {
                temp=get_K(A[i],prime[j]-1,B[i]);
                if(temp!=-1)
                {
                    if(ans[i]==-1)
                        ans[i]=temp;
                    else
                        ans[i]=min(temp,ans[i]);
                }
            }
        }
        for(int i=0;i<M;i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
