#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define maxn 100005
#define ll __int64
ll x[maxn],y[maxn];
ll sumx[maxn],sumy[maxn];
int main(){
    ll i,j,k,T,n,C=1;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d",&n);
        memset(sumx,0,sizeof(sumx));
        memset(sumy,0,sizeof(sumy));
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&x[i],&y[i]);
            sumx[i]=sumx[i-1]+x[i];
            sumy[i]=sumy[i-1]+y[i];
        }
        ll sum=0;
        for(i=1;i<=n;i++){
            sum+=sumx[i-1]*y[i]+sumy[i-1]*x[i];
        }
        printf("Case %I64d: %I64d\n",C++,sum);
    }
    return 0;
}
