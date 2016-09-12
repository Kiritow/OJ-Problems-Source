#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLL;
PLL x[5],y[5];
bool cmp1(const PLL &x,const PLL &y) {return x.first>y.first;}
bool cmp2(const PLL &x,const PLL &y) {return x.first<y.first;}
int main()
{
    int T;
    scanf("%d",&T);
    int n,a,b;
    LL z;
    for(int k=1;k<=T;k++)
    {
        scanf("%d%d%d",&n,&a,&b);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&z);
            x[4]=make_pair(z*z,i);
            y[4]=make_pair(z,i);
            if(i<=4)
            {
                x[i]=x[4];
                y[i]=y[4];
            }else
            {
                if(a>0)
                    sort(x,x+5,cmp1);
                else sort(x,x+5,cmp2);
                if(b>0)
                    sort(y,y+5,cmp1);
                else sort(y,y+5,cmp2);
            }
        }
        LL ans=-1e20;
        for(int i=0;i<min(n,2);i++)
            for(int j=0;j<min(n,2);j++)
        if(x[i].second!=y[j].second)
            ans=max(ans,x[i].first*a+b*y[j].first);
        printf("Case #%d: %lld\n",k,ans);
    }
    return 0;
}
