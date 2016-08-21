#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;
const int MAX=1597+10;
int n,nowsize,size;
int dp[MAX],temp[MAX],ans[MAX],now[MAX];
int w[16][16],head[MAX];
char s[MAX];
struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*MAX/2];
void Init(int N){
    n=N;
    memset(dp,0,sizeof dp);
    memset(temp,0,sizeof temp);
    memset(head,-1,sizeof head);
    size=nowsize=0;
}
void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++;
}
void dfs(int k,int p){
    if(k>=n){now[++nowsize]=p;return;}
    dfs(k+2,p|(1<<k));
    dfs(k+1,p);
}
int cal(int k,int p){
    int sum=0;
    for(int i=0;i<15;++i){
        if(p & (1<<i))sum+=w[k][i];
    }
    return sum;
}
void DP(){
    dfs(0,0);
    for(int i=1;i<=nowsize;++i){
        for(int j=i+1;j<=nowsize;++j){
            if(now[i] & now[j])continue;
            if(now[i] & (now[j]<<1))continue;
            if(now[i] & (now[j]>>1))continue;
            InsertEdge(i,j);
            InsertEdge(j,i);
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=nowsize;++i){
            ans[i]=cal(k,now[i]);
            for(int j=head[i];j != -1;j=edge[j].next){
                dp[i]=max(dp[i],temp[edge[j].v]+ans[i]);
            }
        }
        for(int i=1;i<=nowsize;++i)temp[i]=dp[i],dp[i]=0;
    }
}
int main(){
    int k;
    while(gets(s)){
        k=1;
        do{
            n=0;
            stringstream ss(s);
            while(ss>>w[k][n])++n;
            gets(s);
            if(s[0] == '\0')break;
            ++k;
        }while(true);
        Init(k);
        DP();
        int sum=0;
        for(int i=1;i<=nowsize;++i)sum=max(sum,temp[i]);
        printf("%d\n",sum);
    }
    return 0;
}
