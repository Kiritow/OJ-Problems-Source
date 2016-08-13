#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include<queue>
#include<map>
using namespace std;
#define lson ((root<<1)+1)
#define rson ((root<<1)+2)
#define MID ((l+r)>>1)
typedef long long ll;
typedef pair<int,int> P;
const int maxn=150;
const int base=1000;
const int inf=999999;
int isp[maxn];
int p[maxn];
void mark()
{
    int i,j;
    int len=0;
    isp[0]=isp[1]=1;
    for(i=2;i<maxn;i++)
        if(isp[i]==0)
    {
        p[len++]=i;
        for(j=i+i;j<maxn;j+=i)
        isp[j]=1;
    }
}
int main()
{
    int n,m,i,j,k,t;
    mark();
    int a[maxn],b[maxn];
    int lena,lenb;
    int x,y;
    char op;
    while(1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&x);
        i=0;
        a[i++]=x;
        scanf("%c",&op);
        while(op==',')
        {
            scanf("%d",&x);
            a[i++]=x;
            scanf("%c",&op);
        }
        lena=i;
        scanf("%d",&x);
        i=0;
        b[i++]=x;
        scanf("%c",&op);
        while(op==',')
        {
            scanf("%d",&x);
            b[i++]=x;
            scanf("%c",&op);
        }
        lenb=i;
        reverse(a,a+lena);
        reverse(b,b+lenb);
        if(a[0]==0&&b[0]==0&&lena==1&&lenb==1)break;
        int maxlen=max(lena,lenb);
        int sum[maxn];
        memset(sum,0,sizeof(sum));
        for(i=0,k=0;i<maxlen;i++)
        {
            sum[k++]=a[i]+b[i];
        }
        int lensum=k;
        for(i=0;i<lensum+10;i++)
        {
            int cur=sum[i]%p[i];
            int mod=sum[i]/p[i];
            sum[i]=cur;
            sum[i+1]+=mod;
        }
        for(i=maxn-1;i>=0;i--)if(sum[i]!=0)break;
        j=i;
        printf("%d",sum[j]);
        for(i=j-1;i>=0;i--)
            printf(",%d",sum[i]);
        printf("\n");
    }
    return 0;
}
