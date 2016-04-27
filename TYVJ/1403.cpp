#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXM 100000
#define MAXN 20000
struct ppk
{
    int a,b,c;
};
bool cmp(const ppk& a,const ppk& b)
{
    return a.c>b.c;
}
int f[MAXN*2];
ppk X[MAXM];

int get(int x)
{
    if(x==f[x]) return x;
    else
    {
        f[x]=get(f[x]);
        return f[x];
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*2;i++)
    {
        f[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&X[i].a,&X[i].b,&X[i].c);
    }
    sort(X,X+m,cmp);
    for(int s=0;s<m;s++)
    {
        int x=get(X[s].a);
        int y=get(X[s].b);
        if(x==y)
        {
            printf("%d\n",X[s].c);
            return 0;
        }
        int w=get(X[s].a+n);
        int t=get(X[s].b+n);
        f[x]=t;
        f[y]=w;
    }
    printf("0\n");
    return 0;
}
