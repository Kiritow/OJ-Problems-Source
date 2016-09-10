#include "stdio.h"
#include "string.h"
#include "vector"
using namespace std;
const int inf=0x3f3f3f3f;
vector<int>mark[100010];
int key,cnt;
int du[100010];
struct node
{
    int x,l,r;
}data[400010];
int Min(int a,int b)
{
    if (a<b) return a;
    else return b;
}
void build(int l,int r,int k)
{
    int mid;
    data[k].l=l;
    data[k].r=r;
    if (l==r)
    {
        data[k].x=du[data[k].l];
        return;
    }
    mid=(l+r)/2;
    build(l,mid,k*2);
    build(mid+1,r,k*2+1);
    data[k].x=Min(data[k*2].x,data[k*2+1].x);
}
void updata(int x,int k)
{
    int mid;
    if (data[k].l==data[k].r)
    {
        data[k].x--;
        return;
    }
    mid=(data[k].l+data[k].r)/2;
    if (x<=mid) updata(x,k*2);
    else updata(x,k*2+1);
    data[k].x=Min(data[k*2].x,data[k*2+1].x);
}
void query(int k)
{
    if (data[k].l==data[k].r)
    {
        cnt-=data[k].x;
        key=data[k].l;
        data[k].x=inf;
        return ;
    }
    if (data[k*2+1].x<=cnt)
        query(k*2+1);
    else
        query(k*2);
    data[k].x=Min(data[k*2].x,data[k*2+1].x);
}
int main()
{
    int n,m,i,a,b,x;
    while (scanf("%d%d%d",&n,&m,&cnt)!=EOF)
    {
        memset(du,0,sizeof(du));
        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            mark[a].push_back(b);
            du[b]++;
        }
        build(1,n,1);
        for (a=1;a<=n;a++)
        {
            query(1);
            if (a==1)
                printf("%d",key);
            else
                printf(" %d",key);
            for (i=0;i<mark[key].size();i++)
            {
                x=mark[key][i];
                updata(x,1);
            }
        }
        printf("\n");
    }
    return 0;
}
