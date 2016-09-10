#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=101000;
typedef long long LL;
LL fac[maxn],ans[maxn];
LL N;
int cnt;
int cas;
void init()
{
    LL tmp=sqrt(N);
    cnt=0;
    for(LL i=1;i<=tmp;i++)
        if(N%i==0)
        {
            fac[cnt++]=i;
            if(i*i!=N){fac[cnt++]=N/i;}
        }
}
LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void solve()
{
    int num=0;
    for(int i=0;i<cnt;i++)
        if((gcd(N,N^fac[i])==fac[i])&&((N^fac[i])<=N)&&((N^fac[i])!=0)&&(fac[i]!=N))
        ans[num++]=(N^fac[i]);
    sort(ans,ans+num);
    bool first=true;
    printf("Case #%d:\n%d\n",cas++,num);
    for(int i=0;i<num;i++)
    {
        if(first)first=false;
        else printf(" ");
        printf("%I64d",ans[i]);
    }
    printf("\n");
}
int main()
{
    cas=1;
    while(scanf("%I64d",&N)!=EOF)
    {
        init();
        solve();
    }
    return 0;
}
