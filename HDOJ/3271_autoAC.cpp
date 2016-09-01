#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 30
#define inf 1<<29
#define MOD 2007
#define LL long long
using namespace std;
int dp[32][305];
void Init(int b,int m){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<32;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<b&&k+j<=m;k++)
                dp[i][j+k]+=dp[i-1][j];
}
int clac(int n,int b,int m){
    int bit[35],len=0,t=n;
    while(t){
        bit[++len]=t%b;
        t/=b;
    }
    int sum=0,tot=0;
    for(int i=len;i;i--){
        for(int j=0;j<bit[i]&&m-tot-j>=0;j++)
            sum+=dp[i-1][m-tot-j];
        tot+=bit[i];
        if(tot>m) break;
    }
    if(tot==m) sum++;
    return sum;
}
int main(){
    int cas=0,kind,x,y,b,m,k;
    while(scanf("%d%d%d%d%d",&kind,&x,&y,&b,&m)!=EOF){
        Init(b,m);
        if(x>y) swap(x,y);
        printf("Case %d:\n",++cas);
        int cnt=clac(y,b,m)-clac(x-1,b,m);
        if(kind==1){
            printf("%d\n",cnt);
            continue;
        }
        scanf("%d",&k);
        if(k>cnt){
            puts("Could not find the Number!");
            continue;
        }
        int low=x,high=y,mid;
        while(low<high){
            mid=(int)((((LL)low+(LL)high))/2);
            int now=clac(mid,b,m)-clac(x-1,b,m);
            if(now<k)
                low=mid+1;
            else
                high=mid;
        }
        printf("%d\n",low);
    }
    return 0;
}
