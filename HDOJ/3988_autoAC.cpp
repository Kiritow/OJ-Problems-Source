#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define MOD 9973
#define LL unsigned long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
bool flag[10000005];
int cnt=0,prime[10000005];
void Init(){
    for(int i=2;i<=sqrt(10000000.0)+1;i++){
        if(flag[i])
            continue;
        for(int j=2;j*i<=10000000;j++)
            flag[i*j]=true;
    }
    for(int i=2;i<=10000000;i++)
        if(!flag[i])
            prime[cnt++]=i;
}
LL get_sum(LL n,LL p){
    LL ret=0;
    while(n){
        n/=p;
        ret+=n;
    }
    return ret;
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    Init();
    while(t--){
        LL n,k;
        scanf("%I64u%I64u",&n,&k);
        if(k==1){
            printf("Case %d: inf\n",++cas);
            continue;
        }
        LL mmax=-1;
        for(int i=0;i<cnt&&prime[i]<=k;i++){
            if(k%prime[i]==0){
                int c=0;
                while(k%prime[i]==0){
                    c++;
                    k/=prime[i];
                }
                LL tmp=get_sum(n,prime[i])/c;
                if(mmax==-1)
                    mmax=tmp;
                else
                    mmax=min(mmax,tmp);
            }
        }
        if(k>1){
            LL tmp=get_sum(n,k);
            if(mmax==-1)
                mmax=tmp;
            else
                mmax=min(mmax,tmp);
        }
        printf("Case %d: %I64u\n",++cas,mmax);
    }
    return 0;
}
