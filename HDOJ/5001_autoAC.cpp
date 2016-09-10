#include <iostream>             
#include <stdio.h>             
#include <cmath>             
#include <algorithm>             
#include <iomanip>             
#include <cstdlib>             
#include <string>             
#include <memory.h>             
#include <vector>             
#include <queue>             
#include <stack>             
#include <map>           
#include <set>           
#include <ctype.h>           
#define INF 1000000000000000010LL        
#define ll long long         
#define max3(a,b,c) max(a,max(b,c))         
using namespace std;
vector<int> way[55];
int cnt[55];
double dp[10010][55];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(way,0,sizeof(way));
        memset(cnt,0,sizeof(cnt));
        int n,m,d;
        cin>>n>>m>>d;
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            way[u].push_back(v);
            way[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }
        for(int i=1;i<=n;i++){
            dp[0][i]=(1.0/n);  
        }
        for(int l=1;l<=n;l++){
            for(int i=1;i<=d;i++){
                for(int j=0;j<=n;j++)dp[i][j]=0.0;
            }
            for(int i=1;i<=d;i++){            
                for(int j=1;j<=n;j++){
                    if(j==l)continue;
                    for(int k=0;k<cnt[j];k++){
                        if(way[j][k]==l)continue;
                        dp[i][way[j][k]]+=dp[i-1][j]/cnt[j];
                    }
                }
            }
            double ans=0;
            for(int i=1;i<=n;i++){
                ans+=dp[d][i];
            }
            printf("%.10lf\n",ans);
        }
    }
    return 0;
}
