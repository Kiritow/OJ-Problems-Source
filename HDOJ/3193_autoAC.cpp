#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN =10000+100;
int a[MAXN];
int dmin[MAXN][20];
void initMin(int n,int d[])
{
    for(int i=0; i<=n; i++)dmin[i][0]=d[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
            dmin[i][j] = min(dmin[i][j-1] , dmin[i+(1<<(j-1))][j-1]);
}
int getMin(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1)k++;
    return min(dmin[L][k] , dmin[R-(1<<k)+1][k]);
}
struct node
{
    int p,d;
    bool operator <(const node &b)const
    {
        return p<b.p || (p==b.p && d<b.d);
    }
} node1[MAXN],node2[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i =0; i<=10000+100; i++)
            a[i]=1000000;
        for(int i=1; i<=n; i++)
        {
            int p,d;
            scanf("%d%d",&p,&d);
            p++;
            d++;
            node1[i].p=p;
            node1[i].d=d;
            a[p] = min(a[p],d);
        }
        initMin(MAXN,a);
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            int p,d;
            p = node1[i].p;
            d = node1[i].d;
            if(p==1)
            {
                node2[++cnt]  =node1[i];
            }
            else
            {
                int d_min = getMin(1,p-1);
                if(d<=d_min)
                {
                    node2[++cnt]  =node1[i];
                }
            }
        }
        sort(node2+1,node2+1+cnt);
        printf("%d\n",cnt);
        for(int i=1; i<=cnt; i++)
            printf("%d %d\n",node2[i].p-1,node2[i].d-1);
    }
    return 0;
}
