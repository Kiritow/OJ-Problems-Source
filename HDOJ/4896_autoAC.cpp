#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 
#include <string>
#include <map>
#define eps 1e-9
#define LL long long
#define mod 2333333
using namespace std;
map <int , int> ma;
int pos[100];
int clo,p,ed;
struct node
{
    int x,y,w;
}a[250000];
int f[500];
LL te[200];
int cmp(node a,node b)
{
    return (a.w<b.w);
}
int getf(int x)
{
    if (x==f[x]) return x;
    else return (f[x]=getf(f[x]));
}
int unite(int x,int y)
{
    if (getf(x)!=getf(y)) f[getf(x)]=getf(y);
}
LL kru()
{
    LL ans=0;
    for (int i=1;i<=ed;i++)
        if (getf(a[i].x)!=getf(a[i].y)) {
            ans+=a[i].w;
            unite(a[i].x,a[i].y);
        }
    return ans;
}
int main()
{
    LL n,seed;
    while (~scanf("%I64d%I64d",&n,&seed))
    {
        ma.clear();
        int cur=seed;
        int t=0;
        while (ma[cur]==0)
        {
            t++;
            pos[t]=cur;
            pos[0]=cur;
            ma[cur]=1;
            cur=cur*907%mod;
        }
        for (int k=1;k<=108;k++)
        {
            for (int i=1;i<=k;i++)
                f[i]=i;
            clo=ed=0;
            for (int i=1;i<=k;i++)
            {
                clo++;
                clo%=54;
                p=pos[clo];
                for (int j=max(1,i-5);j<i;j++)
                {
                    clo++;
                    clo%=54;
                    ed++;
                    a[ed].x=i;
                    a[ed].y=j;
                    a[ed].w=pos[clo]^p;
                }
            }
        sort(a+1,a+1+ed,cmp);
        te[k]=kru();
        }
        if (n<=108) printf("%I64d\n",te[n]);
        else printf("%I64d\n",te[54+n%54]+(n/54-1)*(te[108]-te[54]));
    }
    return 0;
}
