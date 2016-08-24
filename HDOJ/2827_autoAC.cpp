#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define LL long long
using namespace std;
 LL n,m,A[105][105],p[10000],pos,d[105],r[105],len,B[105][105];
 bool vd[10005]={0};
 void prime()
{
    pos=0;
    for(int i=2;i<10005;i++)
    {
        if(!vd[i])
        {
           if(i>1000) p[pos++]=i;
            for(int j=(i<<1);j<10005;j+=i)
                vd[i]=1;
        }
    }
}
void deal(LL k)
{
    len=0;
    for(int i=0;i<pos&&k!=1;i++)
    {
        if(k%p[i]==0)
        {
            while(k%p[i]==0)
            {
                d[len++]=p[i];
                k/=p[i];
            }
        }
    }
}
LL exp(LL a,LL b,LL mod)
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ans;
}
void ex_gcd(LL a,LL b,LL &dd,LL &x,LL &y)
{
    if(b==0)
        x=1,y=0,dd=a;
    else
    {
        ex_gcd(b,a%b,dd,y,x);
        y-=x*(a/b);
    }
}
LL gauss(LL mod)
{
    bool flag=0;
    LL ans=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];
    for(int k=0;k<n-1;k++)
    {
        LL max_b=B[k][k];int bin=k;
        for(int i=k+1;i<n;i++)
            if(B[i][k]>max_b)
                max_b=B[i][k],bin=i;
        if(bin!=k)
        {
            for(int i=k;i<n;i++)
                swap(B[bin][i],B[k][i]);
            flag^=1;
        }
        if(B[k][k]<0)B[k][k]+=mod;
        LL Ni,y,dd;
        ex_gcd(B[k][k],mod,dd,Ni,y);
        Ni%=mod;
        if(Ni<0)Ni+=mod;
        for(int j=k+1;j<n;j++)
        {
            B[k][j]=B[k][j]*Ni%mod;
            if(B[k][j]<0)B[k][j]+=mod;
            for(int i=k+1;i<n;i++)
            {
                B[i][j]=(B[i][j]-(B[k][j]*B[i][k])%mod)%mod;
                if(B[i][j]<0)B[i][j]+=mod;
            }
        }
        ans*=B[k][k];
        ans%=mod;
        if(ans<0)ans+=mod;
    }
    ans*=B[n-1][n-1];
    ans%=mod;
    if(flag)ans=-ans;
    if(ans<0)ans+=mod;
    return ans;
}
LL china_remain()
{
    LL a,b,c,c1,c2,x,y,dd,N;
    a=d[0],c1=r[0];
    if(c1==0)c1=d[0];
    for(int i=1;i<len;i++)
    {
        b=d[i],c2=r[i];
        ex_gcd(a,b,dd,x,y);
        c=c2-c1;
        LL b1=b/dd;
        x=((c/dd*x)%b1+b1)%b1;
        c1=a*x+c1;
        a=a*b1;
    }
    return c1%m;
}
int main()
{
    prime();
    while(cin>>n>>m)
    {
        deal(m);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>A[i][j];
        if(m==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<len;i++)
        {
            r[i]=gauss(d[i]);
        }
        cout<<china_remain()<<endl;
    }
    return 0;
}
