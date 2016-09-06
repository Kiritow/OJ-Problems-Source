#include<iostream>
#include<string.h>
const int N=110;
using namespace std;
int dp[N*N*10];
struct Node{
    int a,b;
}node[N];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&node[i].a,&node[i].b);
        }
        int m;
        scanf("%d",&m);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                if(j<node[i].b)continue;
                dp[j]=max(dp[j],dp[j-node[i].b]+node[i].a);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
