#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 258280327
int n;
struct s
{
    int a[1050];
    void set()
    {
        memset(a,0,sizeof(a));
    }
}f[1050];
s ss;
s operator +(s const &m,s const &n)
{
    s temp;
    temp.set();
    for(int i=0;i<1050;i++)
    {
        temp.a[i]+=m.a[i]+n.a[i];
        if(temp.a[i]>9)
        {
            temp.a[i+1]++;
            temp.a[i]-=10;
        }
    }
    return temp;
}
s operator -(s const &m,s const &n)
{
    s tem;
    tem.set();
    for(int i=0;i<1050;i++)
    {
        tem.a[i]=m.a[i];
    }
    for(int i=0;i<1050;i++)
    {
        tem.a[i]-=n.a[i];
        if(tem.a[i]<0)
        {
            tem.a[i]=10+tem.a[i];
            tem.a[i+1]--;
        }
    }
    return tem;
}
bool operator >(s const &m,s const &n)
{
    int lm,ln;
    for(lm=1000;m.a[lm]==0;lm--);
    for(ln=1000;n.a[ln]==0;ln--);
    if(lm>ln)
        return true;
    else if(lm<ln)
        return false;
    for(int i=lm;i>=0;i--)
    {
        if(m.a[i]>n.a[i])
            return true;
        else if(m.a[i]<n.a[i])
            return false;
    }
    return false;
}
void init(int n)
{
    for(int i=1;i<=n;i++)
        f[i].set();
    f[1].a[0]=1;
    f[2].a[0]=1;
    for(int i=3;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
}
void change(string m)
{
    ss.set();
    for(int i=0;i<m.length();i++)
    {
        ss.a[m.length()-1-i]=m[i]-'0';
    }
    s k;
    k.set();
    k.a[0]=1;
    while(f[n]>ss+k)
    {
        n--;
    }
}
long long g()
{
    long long ans=0;
    int i;
    s temp=ss-f[n-1];
    for(i=1000;temp.a[i]==0;i--);
    for(int j=i;j>=0;j--)
        ans=((ans*10)%MOD+temp.a[j]%MOD)%MOD;
    return ans;
}
int main()
{
    int t;
    string m;
    long long ans;
    init(1001);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin >> m;
        if(m.length()==1&&(m[0]=='1'))
        {
            puts("1");
            continue;
        }
        int i;
        change(m);
        ans=g();
        printf("%lld\n",ans);
    }
    return 0;
}
