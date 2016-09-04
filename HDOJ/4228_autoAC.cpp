#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<bitset>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson i<<1,l,mid
#define rson i<<1|1,mid+1,r
#define INF 510010
#define maxn 400010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll p[1010];
ll prime[30]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void getartprime(ll cur,int cnt,int limit,int k)
{
    if(cur>(1LL<<60) || cnt>150) return ;
    if(p[cnt]!=0 && p[cnt]>cur)
        p[cnt]=cur;
    if(p[cnt]==0)
        p[cnt]=cur;
    ll temp=cur;
    for(int i=1; i<=limit; i++) 
    {
        temp=temp*prime[k];
        if(temp>(1LL<<60)) return;
        getartprime(temp,cnt*(i+1),i,k+1);
    }
}
int main()
{
    int n;
    getartprime(1,1,75,0);
    for(int i=1; i<=75; i++)
    {
        if(p[i*2-1]!=0 && p[i*2]!=0)
            p[i]=min(p[i*2-1],p[i*2]);
        else if(p[i*2]!=0) p[i]=p[i*2];
        else p[i]=p[i*2-1];
    }
    while(scanf("%d",&n),n)
        printf("%I64d\n",p[n]);
    return 0;
}
