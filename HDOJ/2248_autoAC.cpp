#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define LL long long
const int N=6500010;
const int M=20010;
const int MOD=1000000007ll;
const int INF=0x7fffffff;
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const double eps=1e-8;
const double PI=acos(-1.0);
inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
char str[12];
bool f[N];
int tot,prime[N];
int a[M],r[M];
void fun()
{
    int i,j,s;
    memset(f,true,sizeof(f));
    f[1]=false;
    tot=0;
    prime[tot++]=2;
    for(i=4;i<=N;i+=2)
        f[i]=false;
    for(i=3;i*i<=N;i+=2)
    {
        if(!f[i])
            continue;
        prime[tot++]=i;
        for(s=2*i,j=i*i;j<=N;j+=s)
            f[j]=false;
    }
    for(;i<=N;i++)
        if(f[i])
            prime[tot++]=i;
}
void Swords()
{
    char ss[110];
    scanf("%s",ss);
    int len=(int)strlen(ss);
    if(f[len])
        printf("Yes.\n");
    else
        printf("No.\n");
}
void Stones()
{
    int n,sign,p=0,len=INF;
    memset(r,-1,sizeof(r));
    r[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        p=(p+a[i])%n;
        if(r[p] != -1)
        {
            if(i-r[p] < len)
            {
                len=i-r[p];
                sign=r[p]+1;
            }
        }
        r[p]=i;
    }
    if(len == INF)
        printf("浜绾疯!\n");
    else
    {
        for(int i=sign;i<sign+len;i++)
        {
            if(i!=sign)
                printf(" ");
            printf("%d",i);
        }
        printf("\n");
    }
}
void Search()
{
    int x,k,i=0;
    scanf("%d%d",&x,&k);
    while(x > 1)
    {
        while(x%prime[i] == 0)
        {
            x/=prime[i];
            k--;
            if(k == 0)
            {
                printf("%d\n",prime[i]);
                return ;
            }
        }
        i++;
    }
    printf("no\n");
}
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4
class BigNum
{
private:
    int a[1510];   
    int len;       
public:
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }  
    BigNum(const int);       
    BigNum operator*(const BigNum &) const;   
    BigNum operator^(const int  &) const;    
    void print();       
};
BigNum::BigNum(const int b)     
{
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum BigNum::operator*(const BigNum & T) const   
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0 ; i < len ; i++)
    {
        up = 0;
        for(j = 0 ; j < T.len ; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigNum BigNum::operator^(const int & n) const    
{
    BigNum t,ret(1);
    int i;
    if(n<0)
        exit(-1);
    if(n==0)
        return 1;
    if(n==1)
        return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for(i=1;i<<1<=m;i<<=1)
            t=t*t;
        m-=i;
        ret=ret*t;
        if(m==1)
            ret=ret*(*this);
    }
    return ret;
}
void BigNum::print()    
{
    int i;
    printf("%d",a[len-1]);
    for(i = len - 2 ; i >= 0 ; i--)
        printf("%04d",a[i]);
    printf("\n");
}
void See()
{
    int n;
    scanf("%d",&n);
    BigNum t(2);
    BigNum ans=t^n;
    ans.print();
}
void solve()
{
    if(!strcmp(str,"Swords"))
        Swords();
    else if(!strcmp(str,"Stones"))
        Stones();
    else if(!strcmp(str,"Search"))
        Search();
    else
        See();
}
int main()
{
   fun();
   while(scanf("%s",str)!=EOF)
       solve();
   return 0;
}
