#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn = 1e6 + 5;
const int max_pos = 20 ;

struct Q{ int l,r; } quary[maxn];

int N,Q;
int weight[maxn];
int rmq[maxn][max_pos];

void init(){
    memset(rmq,0x5f,sizeof(rmq));
}

void input(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&weight[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++) scanf("%d%d",&quary[i].l,&quary[i].r);
}
/*
int get_mi(int x){
    int ret=0;
    for(int i=1;i<=x;i*=2) ret++;
    return ret-1;
}
*/

void RMQ_ST(){
    for(int i=1;i<=N;i++) rmq[i][0]=weight[i];
    //int l=get_mi(N);
    int l=(int)((log(N))/(log(2.0)));
    for(int j=1;j<=l;j++){
        for(int i=1;i+(1<<j)-1<=N;i++){
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
        }
    }
}

void solve(){
    RMQ_ST();
    for(int i=1;i<=Q;i++){
        int l=quary[i].l;
        int r=quary[i].r;
        //int mi=get_mi(v-u+1);
        int mi=(int)((log(r-l+1))/(log(2.0)));
        printf("%d\n",min(rmq[l][mi],rmq[r-(1<<mi)+1][mi]));
    }
}

int main(){
    init();
    input();
    solve();
    return 0;
}

