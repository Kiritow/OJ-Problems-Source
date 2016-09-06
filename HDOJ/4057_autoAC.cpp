#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N 100005
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
struct Trie{
    int next[4],fail;
    int end;
    void Init(){next[0]=next[1]=next[2]=next[3]=0;fail=end=0;}
}tree[N];
int dp[2][1005][1<<10];
char str[105];
int val[105],tot;
int id(char ch){
    if(ch=='A') return 0;
    if(ch=='T') return 1;
    if(ch=='G') return 2;
    return 3;
}
void Insert(char *s,int len,int k){
    int p=0;
    for(int i=0;i<len;i++){
        int q=id(s[i]);
        if(tree[p].next[q]==0){
            tree[++tot].Init();
            tree[p].next[q]=tot;
        }
        p=tree[p].next[q];
    }
    tree[p].end|=(1<<k);
}
void Bulid_Fail(){
    int que[N];
    int head=0,tail=0;
    que[tail++]=0;
    while(head<tail){
        int p=que[head++];
        for(int i=0;i<4;i++){
            if(tree[p].next[i]==0)
                tree[p].next[i]=tree[tree[p].fail].next[i];
            else{
                int q=tree[p].next[i];
                if(p)
                    tree[q].fail=tree[tree[p].fail].next[i];
                tree[q].end|=tree[tree[q].fail].end;
                que[tail++]=q;
            }
        }
    }
}
int n,m;
int get(int state){
    int ans=0;
    for(int i=0;i<n;i++)
        if(state&(1<<i))
           ans+=val[i];
    return ans;
}
void DP(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(int j=0;j<=tot;j++){
            for(int k=0;k<4;k++){
                for(int r=0;r<(1<<n);r++){
                    if(dp[(i+1)&1][j][r])
                        dp[i&1][tree[j].next[k]][r|tree[tree[j].next[k]].end]=1;
                }
            }
        }
    }
    int ans=-inf;
    for(int j=0;j<(1<<n);j++)
        for(int i=0;i<=tot;i++)
           if(dp[m&1][i][j]){
              ans=max(ans,get(j));
              break;
           }
    if(ans<0) puts("No Rabbit after 2012!");
    else printf("%d\n",ans);
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        tree[0].Init();tot=0;
        for(int i=0;i<n;i++){
            scanf("%s%d",str,&val[i]);
            Insert(str,strlen(str),i);
        }
        Bulid_Fail();
        DP();
    }
    return 0;
}
