#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
const int mod=1000000007;  
const int maxn=110005;  
typedef long long LL;  
LL jie[maxn],jie2[maxn];  
int mm(int n,int m){  
    LL s=1,k=n;  
    while(m>0){  
        if(m&1){  
            s=s*k;  
            s%=mod;  
        }  
        k=k*k;  
        k%=mod;  
        m>>=1;  
    }  
    return s;  
}  
int zuhe(int n,int m){  
    LL s;  
    s=jie[n];  
    s=s*jie2[m];  
    s%=mod;  
    s=s*jie2[n-m];  
    s%=mod;  
    return s;  
}  
void init(void){  
    int i;  
    jie[0]=1;  
    jie2[0]=1;  
    for(i=1;i<=110000;i++){  
        jie[i]=jie[i-1]*i;  
        jie[i]%=mod;  
        jie2[i]=mm(jie[i],mod-2);  
    }  
}  
LL dp[1005];  
int main()  
{  
    int i,j,n,m,t,N=0;  
    cin>>t;  
    init();  
    while(t--){  
        cin>>n>>m;  
        memset(dp,0,sizeof(dp));  
        dp[0]=1;  
        for(i=1;i<=n;i++){  
            for(j=1;j<=i;j++){  
                dp[i]+=zuhe(i-1,j-1)*((dp[i-j]*zuhe(j+m-1,m-1))%mod);  
                dp[i]%=mod;  
            }  
        }  
        printf("Case #%d: %d\n",++N,dp[n]);  
    }  
}
