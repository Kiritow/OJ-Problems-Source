#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int N=210;
const int M=41000;
const int MOD=1000000007;
const double eps=1e-8;
const double PI=acos(-1.0);
const double PI2=PI*2;
struct Point
{
    double x,y;
    LL index;
    double angle;
    inline void input()
    {
        scanf("%lf%lf",&x,&y);
    }
}point[N],temp[N];
int n;
bool visit[M];
LL fib[M];
LL fk[M];
int num[N][N];
int left[N][N];
int right[N][N];
inline Point operator-(const Point &a, const Point &b)
{
    Point c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}
inline double operator*(const Point &a, const Point &b)
{
    return a.x*b.y-a.y*b.x;
}
inline bool operator==(const Point &a, const Point &b)
{
    return a.x==b.x&&a.y==b.y;
}
inline int cross(const Point &a, const Point &b, const Point &o)
{
    return (a-o)*(b-o)>0? 1:-1;
}
inline int cross(const int &a, const int &b, const int &o)
{
    return cross(point[a],point[b],point[o]);
}
inline double positiveAtan(const Point &a, const Point &o)
{
    double res=atan2(a.y-o.y,a.x-o.x);
    if(res<0)
        res+=PI2;
    return res;
}
bool operator<(const Point &a, const Point &b)
{
    return a.angle<b.angle;
}
int abs1(int x)
{
    return x<0? -x:x;
}
int getAngleNumber(int a,int b,int c)
{
    if(point[c].y<point[b].y&&point[a].y>=point[b].y)
        return n-abs1(right[b][c]-right[b][a]+2)+3;
    return abs1(right[b][a]-right[b][c])+2;
}
int getTriangleNumber(int a, int b, int c)
{
    return n-left[a][b]-left[b][c]-left[c][a]+getAngleNumber(a,b,c)+getAngleNumber(b,c,a)+getAngleNumber(c,a,b)-6;
}
LL quick_mod(LL a,LL b)
{
    LL ans=1;
    a%=MOD;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%MOD;
            b--;
        }
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}
LL solve(int x)
{
    if(visit[x])
        return fk[x];
    visit[x]=true;
    fib[0]=x;
    fib[1]=x;
    for(int i=2;i<=x;++i)
        fib[i]=(fib[i-1]*fib[i-2])%MOD;
    return fk[x]=fib[x]+1;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            point[i].input();
            temp[i]=point[i];
            temp[i].index=i;
        }
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(k!=i&&k!=j)
                    {
                        if(cross(k,j,i)<0)
                            ++left[i][j];
                        else if(cross(k,i,j)<0)
                            ++left[j][i];
                    }
                }
            }
            for(int j=0;j<n;++j)
            {
                if(temp[j].index==i)
                    temp[j].angle=-1e100;
                else
                    temp[j].angle=positiveAtan(temp[j],point[i]);
            }
            sort(temp,temp+n);
            int cnt=0;
            for(int j=0;j<n;++j)
                right[i][temp[j].index]=++cnt;
        }
        memset(num,0,sizeof(num));
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(k==i||k==j) continue;
                    if(cross(point[k], point[j], point[i]) < 0)
                        num[i][j]+=getAngleNumber(j,k,i)-getTriangleNumber(i,j,k);
                }
            }
        }
        LL ans=1;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                ans=(ans*solve(num[i][j]))%MOD;
        printf("%I64d\n", ans);
    }
    return 0;
}
