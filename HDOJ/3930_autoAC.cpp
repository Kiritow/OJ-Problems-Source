#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;
typedef long long LL;
const int N=1000005;
int p[N];
bool prime[N];
int num,cnt;
LL k,m,newx,g;
LL a[65],b[65];
void isprime()
{
    num=0;
    int i,j;
    memset(prime,true,sizeof(prime));
    for(i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[num++]=i;
            for(j=i+i;j<N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
LL multi(LL a,LL b,LL m)
{
    LL ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}
LL quick_mod(LL a,LL b,LL m)
{
    LL ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}
void factor(LL n)
{
    cnt=0;
    for(int i=0;(LL)p[i]*p[i]<=n;i++)
    {
        if(n%p[i]==0)
        {
            a[cnt]=p[i];
            int c=0;
            while(n%p[i]==0)
            {
                c++;
                n/=p[i];
            }
            b[cnt++]=c;
        }
    }
    if(n>1)
    {
        a[cnt]=n;
        b[cnt++]=1;
    }
}
LL extend_Euclid(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL gd=extend_Euclid(b,a%b,x,y);
    LL temp=x;
    x=y;
    y=temp-(a/b)*y;
    return gd;
}
LL Inv(LL n,LL p)
{
    return quick_mod(n,p-2,p);
}
bool dfs(int dept,LL t)
{
    if(dept==cnt)
    {
        LL ans=quick_mod(g,t,m);
        if(ans==1&&t!=m-1) return false;
        return true;
    }
    LL tmp=1;
    for(int i=0;i<=b[dept];i++)
    {
        if(!dfs(dept+1,t*tmp)) return false;
        tmp*=a[dept];
    }
    return true;
}
void find()
{
    factor(m-1);
    for(g=2;;g++)
        if(dfs(0,1)) break;
}
LL log_x(LL a,LL b,LL p)
{
    map<LL,int>x;
    LL z=(LL)ceil(sqrt(p*1.0));
    LL v=Inv(quick_mod(a,z,p),p);
    LL e=1;
    x[1]=0;
    for(int i=1;i<z;i++)
    {
        e=multi(e,a,p);
        if(!x.count(e))
            x[e]=i;
    }
    for(int i=0;i<z;i++)
    {
        if(x.count(b))
            return i*z+x[b];
        b=multi(b,v,p);
    }
    return -1;
}
LL sol[1005];
void Solve(LL a,LL b,LL n)
{
    LL d,x,y;
    d=extend_Euclid(a,n,x,y);
    if(b%d) puts("-1");
    else
    {
        n/=d;b/=d;
        sol[0]=(x*b%n+n)%n;
        for(int i=1;i<d;i++)
            sol[i]=sol[i-1]+n;
        for(int i=0;i<d;i++)
            sol[i]=quick_mod(g,sol[i],m);
        sort(sol,sol+d);
        for(int i=0;i<d;i++)
            cout<<sol[i]<<endl;
    }
}
int main()
{
    int t=1;
    isprime();
    while(cin>>k>>m>>newx)
    {
        find();
        LL t1=log_x(g,newx,m);
        LL t2=m-1;
        cout<<"case"<<t++<<":"<<endl;
        Solve(k,t1,t2);
    }
    return 0;
}
