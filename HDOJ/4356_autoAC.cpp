#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007
#define N 2010
using namespace std;
int n,ans;
int a[N],w[N];
int f[N][N];
int fac[N];
void init(){
    fac[0]=1;
    int i,j;
    for (i=1;i<=n;i++)
        fac[i]=(1ll*fac[i-1]*i)%MOD;
    for (i=0;i<=n;i++) f[1][i]=n-i;
    for (i=1;i<=n;i++){
        for (j=0;j<w[i];j++) f[i+1][j]=f[i][j]-1;
        for (j=w[i];j<=n;j++) f[i+1][j]=f[i][j];
    }
}
int dfs(int k){
    if (k==n) return 0;
    int tp=(1ll*fac[n-k]*f[k][w[k]])%MOD;
    int tp1=dfs(k+1);
    if (w[k]>=a[k]) ans=(1ll*ans+tp1)%MOD;
    return (1ll*tp1+tp)%MOD;
}
void work(){
    int i,j,k;
    for (i=1;i<=n;i++){
        if (a[i]>w[i]) ans=(1ll*ans+1ll*f[i][a[i]-1]*fac[n-i])%MOD;
        else ans=(1ll*ans+1ll*f[i][w[i]]*fac[n-i])%MOD;
        for (j=i+1;j<=n;j++){
            k=f[i][w[i]]*f[i][a[j]-1]-min(f[i][w[i]],f[i][a[j]-1]);
            ans=(1ll*ans+1ll*k*fac[n-i-1])%MOD;
        }
    }
}
int main(){
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++){
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=0;
        init();
        work();
        dfs(1);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
