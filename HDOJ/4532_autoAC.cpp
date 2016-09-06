#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1000000007;
long long dp[50][520];  
long long C[520][520];   
long long A[520];       
int a[50];
void Init(){
    C[0][0]=1;
    for(int i=1;i<480;i++){     
        C[i][0]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        C[i][i]=1;
    }
    A[0]=A[1]=1;
    for(int i=2;i<480;i++)
        A[i]=(A[i-1]*i)%mod;
}
int main(){
    Init();
    int t,n,cases=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[1][a[1]-1]=1;    
        long long sum=a[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<sum;j++)  
                for(int k=1;k<=a[i];k++)  
                    for(int u=0;u<=j && u<=k;u++)   
                        dp[i][j-u+a[i]-1-(k-1)]=(dp[i][j-u+a[i]-k]+(((dp[i-1][j]*C[j][u])%mod*C[sum+1-j][k-u])%mod*C[a[i]-1][k-1])%mod)%mod;
            sum+=a[i];
        }
        printf("Case %d: ",++cases);
        long long ans=dp[n][0];
        for(int i=1;i<=n;i++)   
            ans=(ans*A[a[i]])%mod;
        cout<<ans<<endl;
    }
    return 0;
}
