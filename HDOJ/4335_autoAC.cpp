#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL unsigned long long
#define eps 1e-6
#define zero(a)  fabs(a)<eps
using namespace std;
LL get_eular(LL m){
    LL ret=1;
    for(LL i=2;i*i<=m;i++)
        if(m%i==0){
            ret*=i-1;
            m/=i;
            while(m%i==0){
                m/=i;
                ret*=i;
            }
        }
    if(m>1)
        ret*=m-1;
    return ret;
}
LL PowMod(LL a,LL b,LL MOD){
    LL ret=1;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
LL b,p,m,ring[100005];
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%I64u%I64u%I64u",&b,&p,&m);
        printf("Case #%d: ",++cas);
        if(p==1){
            if(m==18446744073709551615ULL)
                printf("18446744073709551616\n");       
            else                 
                printf("%I64u\n",m+1);
            continue;
        }
        LL i=0,phi=get_eular(p),fac=1,ans=0;
        for(i=0;i<=m&&fac<=phi;i++){
            if(PowMod(i,fac,p)==b)
                ans++;
            fac*=i+1;
        }
        fac=fac%phi;
        for(;i<=m&&fac;i++){
            if(PowMod(i,fac+phi,p)==b)
                ans++;
            fac=(fac*(i+1))%phi;
        }
        if(i<=m){
            LL cnt=0;
            for(int j=0;j<p;j++){
                ring[j]=PowMod(i+j,phi,p);
                if(ring[j]==b)
                    cnt++;
            }
            LL idx=(m-i+1)/p;
            ans+=cnt*idx;
            LL remain=(m-i+1)%p;
            for(int j=0;j<remain;j++)
                if(ring[j]==b)
                    ans++;
        }
        printf("%I64u\n",ans);
    }
    return 0;
}
