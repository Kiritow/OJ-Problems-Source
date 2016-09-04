#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <algorithm> 
#include <stdlib.h> 
using namespace std;
#define N 1010
#define inf 2000000010
struct node{
    int x,li,id;
}w[N];
bool cmp(const node &a,const node &b){
    if(a.x!=b.x) return a.x<b.x;
    return a.li>b.li;
}
int dp[N][N];
int main(){
    int T,n,id;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int Min=-inf;
        for(int i=0;i<n;++i){
            scanf("%d%d",&w[i].x,&w[i].li);
            w[i].id=i;
        }
        sort(w,w+n,cmp);
        for(int i=0;i<n;++i){
            if(!w[i].id) id=i;
            for(int j=0;j<=n;++j)
                dp[i][j]=inf;
        }
        if(id){
            dp[0][0]=Min;
            dp[0][1]=w[0].x;
        }
        else dp[0][1]=w[0].x+(w[0].li+1>>1); 
        for(int i=1;i<n;++i){
            if(i==id){
                int l=w[i].x-(w[i].li+1>>1);
                int r=w[i].x+(w[i].li+1>>1);
                for(int j=0;j<=i;++j)
                    if(dp[i-1][j]<=l)
                        dp[i][j+1]=r;
                continue;
            }
            for(int j=0;j<=i;++j){
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(dp[i-1][j]!=inf){
                    if(dp[i-1][j]<=w[i].x){
                        int temp=max(dp[i-1][j]+w[i].li,w[i].x);
                        dp[i][j+1]=min(dp[i][j+1],temp);
                    }
                }
            }
        }
        for(int i=n;i;--i)
            if(dp[n-1][i]!=inf){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
