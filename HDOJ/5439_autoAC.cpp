#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int MAXN = 438744;
int a[MAXN+5];
int b[MAXN+5];
int sum[MAXN+5];
int dp[MAXN+5];
int pre[MAXN+5];
int sz,val;
int add(int x,int y){
    x+=y;
    if(x>=MOD)x-=MOD;
    return x;
}
int po(int x,int n){
    int ans=1;
    int temp=x;
    while(n){
        if(n&1)ans=(ll)ans*temp%MOD;
        temp=(ll)temp*temp%MOD;
        n>>=1;
    }
    return ans;
}
int main()
{
    val=po(2,MOD-2);
    a[1]=1;
    a[2]=2;
    a[3]=2;
    int sz=3;
    for(int i=3;;i++){
        int cnt=a[i];
        while(cnt){
        a[++sz]=i;
        cnt--;
        if(sz>=MAXN)break;
        }
        if(sz>=MAXN)break;
    }
    for(int i=1;i<=MAXN;i++){
        sum[i]=sum[i-1]+a[i];
        if(sum[i]>=INF)break;
    }
    for(int i=1;i<=MAXN;i++){
        dp[i]=add(dp[i-1],(ll)( add(add(add(pre[i-1],1),pre[i-1]),a[i]) )*a[i]%MOD*i%MOD*val%MOD);
        pre[i]=add(pre[i-1],a[i]);
    }
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        int l=1,r=MAXN;
        int pos;
        while(l<=r){
            int mid=l+r>>1;
            if(n<=sum[mid]){
                pos=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        int x=n-sum[pos-1];
        int ans=add(dp[pos-1],(ll)( add(add(add(pre[pos-1],1),pre[pos-1]),x) )*x%MOD*pos%MOD*val%MOD);
        printf("%d\n",ans);
    }
    return 0;
}
