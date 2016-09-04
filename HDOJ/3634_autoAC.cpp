#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 205;
#define LL long long
typedef struct
{
    LL x1,y1;
    LL x2,y2;
    LL sum;
    LL v;
}Node;
Node T[N];
LL n;
bool cmp(Node a,Node b)
{
    return a.v<b.v;
}
void Cover(LL x1,LL y1,LL x2,LL y2,LL k,LL c)
{
    while(k<n&&(x1>=T[k].x2||x2<=T[k].x1||y1>=T[k].y2||y2<=T[k].y1)) k++;
    if(k>=n)
    {
        T[c].sum+=(x2-x1)*(y2-y1)*T[c].v;
        return;
    }
    if(x1<T[k].x1)
    {
        Cover(x1,y1,T[k].x1,y2,k+1,c);
        x1=T[k].x1;
    }
    if(x2>T[k].x2)
    {
        Cover(T[k].x2,y1,x2,y2,k+1,c);
        x2=T[k].x2;
    }
    if(y1<T[k].y1)
    {
        Cover(x1,y1,x2,T[k].y1,k+1,c);
        y1=T[k].y1;
    }
    if(y2>T[k].y2)
    {
        Cover(x1,T[k].y2,x2,y2,k+1,c);
        y2=T[k].y2;
    }
}
int main()
{
    LL i,k=1,t;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(T,0,sizeof(T));
        for(i=0;i<n;i++)
        {
            T[i].v=0;
            scanf("%I64d%I64d%I64d%I64d%I64d",&T[i].x1,&T[i].y1,&T[i].x2,&T[i].y2,&T[i].v);
            T[i].sum=0;
        }
        stable_sort(T,T+n,cmp);
        for(i=n-1;i>=0;i--)
            Cover(T[i].x1,T[i].y1,T[i].x2,T[i].y2,i+1,i);
        LL ans=0;
        for(i=0;i<n;i++)
           ans+=T[i].sum;
        printf("Case %I64d: %I64d\n",k++,ans);
    }
    return 0;
}
