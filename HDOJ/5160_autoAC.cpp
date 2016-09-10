#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define LL __int64
const int N=100005;
const int MOD=1000000007;
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}
LL Inv(LL a,int m){ 
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}
LL Cm(LL n, LL m, LL p){
    LL a=1, b=1;
    if(m>n) return 0;
    while(m){
        a=(a*n)%p;
        b=(b*m)%p;
        m--;
        n--;
    }
    return (LL)a*Inv(b,p)%p;
}
struct Dt{
    LL x;
    int cnt;
    Dt(){}
    Dt(LL _x,int _c){
        x=_x;
        cnt=_c;
    }
};
LL a[N],fro[N],bac[N];
int main(){
    int T;
    int n,cas=0;
    scanf("%d",&T);
    while(T--){
        memset(fro,0,sizeof(fro));
        memset(bac,0,sizeof(bac));
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%I64d",&a[i]);
        sort(a,a+n);
        int len=n,cnt=1;
        fro[0]=1;
        for(int i=1;i<n;++i){
            if(a[i]==a[i-1]){
                ++cnt;
                fro[i]=fro[i-1];
            }
            else{
                fro[i]=fro[i-1]*Cm(len,cnt,MOD)%MOD;
                len-=cnt;
                cnt=1;
            }
        }
        LL pre=1,cnm=1;
        len=cnt=1;
        bac[n-1]=1;
        for(int i=n-2;i>=0;--i){
            ++len;
            if(a[i]==a[i+1]){
                ++cnt;
                cnm=cnm*len%MOD*Inv(cnt,MOD)%MOD;  
                bac[i]=pre*cnm%MOD;
            }
            else{
                cnt=1;
                cnm=len;
                pre=bac[i+1];
                bac[i]=pre*cnm%MOD;
            }
        }
        bac[n]=1;
        LL ans=0;
        for(int i=0;i<n;++i){
            ans=(ans+(fro[i]*bac[i+1]%MOD*a[i]%MOD))%MOD;
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}
