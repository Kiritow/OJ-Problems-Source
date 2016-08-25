#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#define LL long long
#define eps 1e-7
using namespace std;
int prime[100005][20];
int cnt[100005]={0};
void Init(){
    for(int i=2;i<=100000;i++){
        if(cnt[i]) continue;
        prime[i][0]=i;
        cnt[i]=1;
        for(int j=2;j*i<=100000;j++)
            prime[i*j][cnt[i*j]++]=i;
    }
}
LL dfs(int m,int n,int idx){
    LL ret=0;
    for(int i=idx;i<cnt[m];i++)
        ret+=n/prime[m][i]-dfs(m,n/prime[m][i],i+1);
    return ret;
}
int main(){
    Init();
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        LL ans=n;
        for(int i=2;i<=m;i++)
            ans+=n-dfs(i,n,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
