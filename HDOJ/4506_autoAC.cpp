#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
long long n,t,k;
long long num[10010],res[10010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&n,&t,&k);
        long long tmpt=t,tmpk=1;
        while(tmpt){
            if(tmpt&1)
                tmpk=(tmpk*k)%mod;
            tmpt>>=1;
            k=(k*k)%mod;
        }
        for(int i=0;i<n;i++){
            scanf("%I64d",&num[i]);
            num[i]=(num[i]*tmpk)%mod;
        }
        t=t%n;
        for(int i=0;i<n;i++)
            res[(i+t)%n]=num[i];
        for(int i=0;i<n-1;i++)
            printf("%I64d ",res[i]);
        printf("%I64d\n",res[n-1]);
    }
    return 0;
}
