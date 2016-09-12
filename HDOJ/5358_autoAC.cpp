#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define lowbit(x) x&(-x)
using namespace std;
typedef long long LL;
const int N=1e5+10;
long long inf=1e15;
const int MOD=1e9+7;
int T,n,m,k,x,y,z,l,tot;
long long cnt;
int a[N];
long long sum[N];
long long solve(long long L,long long R){    
    long long ans=0;
    int l,r;
    r=0;l=1;
    for(int i=1;i<=n;i++){
        if(l<i) l=i;
        if(r<i-1) r=i-1;
        while(l<=n && sum[l]-sum[i-1]<L) l++;
        while(r+1<=n && sum[r+1]-sum[i-1]<R) r++;
        if(l>r) continue;
        if(sum[r]-sum[i-1]<L || sum[r]-sum[i-1]>=R) continue;
        if(sum[l]-sum[i-1]<L || sum[l]-sum[i-1]>=R) continue;
        ans+=(long long)(r-l+1)*i+(long long)(l+r)*(r-l+1)/2;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        sum[0]=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        long long ans=0;
        for(int k=1;k<=34;k++){
            ans+=(long long)k*solve(pow(2,k-1),pow(2,k));
        }
         ans+=solve(0,1);
         printf("%I64d\n",ans);
    }
    return 0;
}
