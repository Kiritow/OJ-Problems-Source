#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 1ll<<60
typedef long long LL;
using namespace std;
const int MAX=50000+10;
int n,k,index,head,tail,Id;
LL dp[MAX][2],q[MAX];
struct Node{
    LL w,h;
    bool operator<(const Node &a)const{
        return h>a.h;
    }
}s[MAX];
LL GetY(int k,int k2){
    return dp[k][index^1]-dp[k2][index^1];
}
LL GetX(int k,int k2){
    return s[k2+1].h-s[k+1].h;
}
void DP(){
    index=0;
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;++i)dp[i][index]=INF;
    for(int j=1;j<=k;++j){
        index=index^1;
        head=tail=0;
        q[tail++]=0;
        Id=0;
        for(int i=1;i<=n;++i){
            if(s[i].w <= s[Id].w)continue;
            Id=i;
            while(head+1<tail && GetY(q[head+1],q[head])<=GetX(q[head+1],q[head])*s[i].w)++head;
            dp[i][index]=dp[q[head]][index^1]+s[i].w*s[q[head]+1].h;
            while(head+1<tail && GetY(i,q[tail-1])*GetX(q[tail-1],q[tail-2])<=GetY(q[tail-1],q[tail-2])*GetX(i,q[tail-1]))--tail;
            q[tail++]=i;
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        for(int i=1;i<=n;++i)scanf("%I64d%I64d",&s[i].w,&s[i].h);
        sort(s+1,s+n+1);
        DP();
        printf("%I64d\n",dp[Id][index]);
    }
    return 0;
}
