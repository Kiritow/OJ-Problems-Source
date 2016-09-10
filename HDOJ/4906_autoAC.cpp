#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define maxn  1<<21
#define mod 1000000007
#define ll long long
ll dp[2][maxn];
void add(ll&a,ll b){
    a+=b;
    if(a >= mod) a-=mod;
}
int main(){
    int t,n,l,k,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&l);
        int p=0,q=1,f=min(l,k),s=1<<(k-1),s1,s2,s3=(1<<k)-1;
        memset(dp[0],0,sizeof(dp[0]));
        dp[0][0] = 1;
        for( i = 0;i < n; i++){
            if(k>16)memset(dp[q],0,sizeof(dp[q]));
            else for(j=0;j<=s;j++)dp[q][j]=0;
            for(j = 0;j <= s;j++){
                if(dp[p][j] == 0) continue;
                dp[q][j] = (dp[q][j]+dp[p][j]*(l-f))%mod;
                add(dp[q][j],dp[p][j]);
                for(s1=1;s1<=f;s1++){
                    s2 = (1<<(s1-1))|j|(j<<s1);
                    if(s2&s)add(dp[q][s],dp[p][j]);
                    else add(dp[q][s2&s3],dp[p][j]);
                }
            }
            swap(p,q);
        }
        cout<<dp[p][s]<<endl;
    }
    return 0;
}
