#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct
{
    int l,r,sum;
    int lsum,rsum,midsum;
}Tree;
Tree tree[500005];
int a[100005];
int c[2000][2000];
int ans,rans;
int Count(int t)
{
    if (t==0) return 0;
    int s=0;
    while(t)
    {
        s+=t%10;
        t/=10;
    }
    s%=9;
    if (s==0) return 9;
    return s;
}
int Pre()
{
    int i,j,x,y;
    for (i=0;i<1024;i++)
    {
        for (j=i;j<1024;j++)
        {
            c[i][j]=0;
            for (x=0;x<10;x++)
            {
                if ((i & (1<<x))==0) continue;
                for (y=0;y<10;y++)
                {
                    if ((j & (1<<y))==0) continue;
                    c[i][j]=(c[i][j]|(1<<Count(x+y)));
                }
            }
            c[j][i]=c[i][j];
        }
    }
}
void Build(int t,int l,int r)
{
    tree[t].l=l;
    tree[t].r=r;
    if (l==r)
    {
        tree[t].sum=a[l];
        tree[t].lsum=(1<<a[l]);
        tree[t].rsum=(1<<a[l]);
        tree[t].midsum=(1<<a[l]);
        return;
    }
    int mid=(l+r)/2;
    Build(2*t+1,l,mid);
    Build(2*t+2,mid+1,r);
    tree[t].sum=Count(tree[2*t+1].sum+tree[2*t+2].sum);
    tree[t].lsum=(tree[2*t+1].lsum | c[1<<tree[2*t+1].sum][tree[2*t+2].lsum]);
    tree[t].rsum=(tree[2*t+2].rsum | c[tree[2*t+1].rsum][1<<tree[2*t+2].sum]);
    tree[t].midsum=(tree[2*t+1].midsum | tree[2*t+2].midsum | c[tree[2*t+1].rsum][tree[2*t+2].lsum]);
}
void Query(int t,int x,int y)
{
    int l,r;
    l=tree[t].l;
    r=tree[t].r;
    if (l==x && r==y)
    {
        ans=(ans | tree[t].midsum | c[rans][tree[t].lsum]);
        rans=(c[rans][1<<tree[t].sum] | tree[t].rsum);
        return;
    }
    int mid=(l+r)/2;
    if (mid>=x) Query(2*t+1,x,min(y,mid));
    if (mid<y) Query(2*t+2,max(x,mid+1),y);
}
int main()
{
    int T,i,j,n,x,y,m,s,cnt=1;
    Pre();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=Count(a[i]);
        }
        Build(0,0,n-1);
        scanf("%d",&m);
        printf("Case #%d:\n",cnt++);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            ans=rans=0;
            Query(0,x-1,y-1);
            s=0;
            for (i=9;i>=0;i--)
            {
                if (ans>=(1<<i))
                {
                    ans-=(1<<i);
                    if (s==0) printf("%d",i);
                    else printf(" %d",i);
                    s++;
                    if (s==5) break;
                }
            }
            for (i=s;i<5;i++)
            {
                printf(" -1");
            }
            printf("\n");
        }
        if (T>0) printf("\n");
    }
    return 0;
}
