#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=998244353;
struct atom{
    int x,y;
};
atom operator - (const atom k1,const atom k2){
    return (atom){(k1.x-k2.x+mo)%mo,(k1.y-k2.y+mo)%mo};
}
atom operator * (const atom k1,const int k2){
    return (atom){1ll*k1.x*k2%mo,1ll*k1.y*k2%mo};
}
int x[20][20],n,m,A[20][20],dp[1<<16][17],f[1<<16],pd[20];
int gauss(int n){
    int pd=1; n--;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) x[i][j]=(x[i][j]+mo)%mo;
    for (int i=1;i<=n;i++){
        int r=0;
        for (int j=i;j<=n;j++) if (x[j][i]){r=j; break;}
        for (int j=1;j<=n;j++) swap(x[i][j],x[r][j]);
        if (r!=i) pd=-pd;
        for (int j=i+1;j<=n;j++){
            int k1=x[i][i],k2=x[j][i];
            atom xx=(atom){1,0},y=(atom){0,1};
            while (k2){
                int k4=k1/k2;
                atom z=y; y=xx-y*k4; xx=z;
                k4=k2; k2=k1%k2; k1=k4; pd=-pd;
            }
            for (int k=1;k<=n;k++){
                int k3=x[i][k],k4=x[j][k];
                x[i][k]=(1ll*xx.x*k3+1ll*xx.y*k4)%mo;
                x[j][k]=(1ll*y.x*k3+1ll*y.y*k4)%mo;
            }
        }
    }
    for (int i=1;i<=n;i++) pd=1ll*pd*x[i][i]%mo;
    return (pd+mo)%mo;
}
int solve(){
    memset(A,0x00,sizeof A);
    for (;m;m--){
        int k1,k2; scanf("%d%d",&k1,&k2); A[k1][k2]=1; A[k2][k1]=1;
    }
    memset(f,0x00,sizeof f);
    for (int s=1;s<=n;s++){
        memset(dp,0x00,sizeof dp);
        dp[(1<<s-1)][s]=1;
        for (int i=1;i<(1<<n);i++)
            for (int j=1;j<=n;j++)
                if (dp[i][j]){
                    for (int k=s+1;k<=n;k++)
                        if ((i&(1<<k-1))==0&&A[j][k])
                            dp[i|(1<<k-1)][k]=(dp[i|(1<<k-1)][k]+dp[i][j])%mo;
                    if (A[j][s]) f[i]=(f[i]+dp[i][j])%mo;
                }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (A[i][j]) f[(1<<i-1)|(1<<j-1)]=(f[(1<<i-1)|(1<<j-1)]-1+mo)%mo;
    int inv2=(mo+1)/2;
    for (int i=0;i<(1<<n);i++) f[i]=1ll*f[i]*inv2%mo;
    for (int now=0;now<(1<<n);now++) if (f[now]){
        for (int i=1;i<=n;i++) pd[i]=0;
        for (int i=1;i<=n;i++) if (now&(1<<i-1)) pd[i]=1;
        int sign=1;
        for (int i=1;i<=n;i++) if (pd[i]==0) pd[i]=++sign;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) x[i][j]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (A[i][j]&&pd[i]!=pd[j]){
                    x[pd[i]][pd[j]]--; x[pd[i]][pd[i]]++;
                }
        ans=(ans+1ll*f[now]*gauss(sign))%mo;
    }
    return ans;
}
int main(){
    while (scanf("%d%d",&n,&m)!=EOF) printf("%d\n",solve());
    return 0;
}
