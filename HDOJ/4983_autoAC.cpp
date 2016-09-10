#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#define mod 1000000007
#define LL __int64
using namespace std;
int prim[81000],tot;
int u[1000005];
bool vis[1000005];
void init(void){
    int i;
    for(i=1;i<=1000000;i++) u[i]=i;
    for(i=2;i<=1000000;i++){
        if(!vis[i]){
            for(int j=i;j<=1000000;j+=i){
                u[j]=u[j]/i*(i-1);
                vis[j]=1;
            }
            prim[tot++]=i;
        }
    }
}
int get(int n){
    int i,s,q;
    q=n;
    s=n;
    for(i=0;i<tot&&(LL)prim[i]*prim[i]<=q;i++){
        if(n%prim[i]==0){
            s=s/prim[i]*(prim[i]-1);
            while(n%prim[i]==0) n=n/prim[i];
        }
        if(n==1) break;
    }
    if(n!=1){
        s=s/n*(n-1);
    }
    return s;
}
int main()
{
    int i,k;
    int n;
    LL s=0,q;
    init();
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==1){
            printf("1\n");
            continue;
        }
        s=0;
        if(k>2){ printf("0\n");
            continue;
        }
        if(k==2){
            printf("1\n");
            continue;
        }
        for(i=1;(LL)i*i<=n;i++){
            if(n%i==0){
                if(i<=1000000)
                q=u[i];
                else q=get(i);
                if(n/i<=1000000) q=q*u[n/i];
                else q=q*get(n/i);
                q=q%mod;
                if((LL)i*i!=n)
                q=(q*2)%mod;
                s+=q;
                s%=mod;
            }
        }
        printf("%d\n",s);
    }
}
