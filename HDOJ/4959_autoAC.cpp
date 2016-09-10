#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long 
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define eps 1e-10
#define mod 1000000007
using namespace std;
int cnt=0;
typedef pair <LL,LL> qf;
qf operator + (qf a,qf b)
{
    return make_pair((a.first+b.first)%mod,(a.second+b.second)%mod);
}
qf operator * (qf a,qf b)
{
    if (a.first<0) a.first+=mod;
    if (b.first<0) b.first+=mod;
    if (a.second<0) a.second+=mod;
    if (b.second<0) b.second+=mod;
    return make_pair((((LL)a.first*(LL)b.first)%mod+((LL)a.second*(LL)b.second)%mod*5ll)%mod,
    (((LL)a.first*(LL)b.second)%mod+((LL)a.second*(LL)b.first)%mod)%mod);
}
qf pow(qf a, LL x)
{
    qf res(1,0);
    qf multi=a;
    while (x)
    {
        if (x&1)
        {
            res=res*multi;
        }
        multi=multi*multi;
        x/=2;
    }
    return res;
}
LL pow(LL a,LL b)
{
    LL res=1;
    LL multi=a;
    while (b)
    {
        if (b&1)
        {
            res=res*multi%mod;
        }
        multi=multi*multi%mod;
        b/=2;
    }
    return res;
}
qf acce(qf a,LL b)
{  
    qf ans=make_pair(1,0);
       qf powe=a;
    qf sum=a;
    qf multi=make_pair(1,0); 
    while (b)
    {  
        if (b&1)  
        {  
            ans=ans+(multi*sum);
            multi=multi*powe;  
        }  
        sum=sum*(powe+make_pair(1,0));  
        powe=powe*powe;
        b/=2;
    }  
    return ans;
}
LL inv[100005];
qf r1[100005],r2[100005];
void egcd (LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1,y=0;
        return ;
    }
    egcd(b,a%b,x,y);
    LL t=x;
    x=y;y=t-a/b*y;
}
int main()
{
    LL x,y;
    for (LL i=1;i<=100000;i++)
    {
        egcd(i,mod,x,y);
        x=(x+mod)%mod;
        inv[i]=x;
    }
    r1[0]=make_pair(1,0);
    r2[0]=make_pair(1,0);
    for (int i=1;i<=100000;i++)
    {
        r1[i]=r1[i-1]*make_pair(1,1);
        r2[i]=r2[i-1]*make_pair(1,-1);
    }
    int T;
    scanf("%d",&T);
    while (T--)    
    {
        cnt=0;
        LL n,m;
        scanf("%I64d%I64d",&n,&m);
        qf ans=make_pair(0,0);
        LL Ca=1;
        LL v=pow(inv[2],m);
        for (LL i=0;i<=m;i++)
        {
            qf p(Ca,0);
            qf tmp=r1[i]*r2[m-i]*make_pair(v,0);
            tmp=acce(tmp,n);
            tmp=tmp*p;
            ans=ans+tmp;
            Ca=Ca*(m-i)%mod;
            Ca=Ca*inv[i+1]%mod;
        }
        LL aa=(LL)ans.first;
        printf("%I64d\n",aa);
    }
    return 0;
}
