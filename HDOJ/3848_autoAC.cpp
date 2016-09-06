#include <iostream>
#include <cstdio>
using namespace std;
const int inf=30000000;
const int maxx=10003;
struct Tree{
    int v,we,next;
};
Tree tree[maxx*2];
int head[maxx*2],pt;
int dp_f[maxx],dp_s[maxx];
void adde(int x,int y,int we){
    tree[pt].v=y;
    tree[pt].we=we;
    tree[pt].next=head[x];
    head[x]=pt++;
}
int min(int a,int b){
    return a<b?a:b;
}
void dfs(int root,int pre){
    bool mark=false;
    for(int i=head[root];i;i=tree[i].next){
        int v=tree[i].v;
        if(pre==v)continue;
        mark=true;
        dfs(v,root);
        if(dp_f[root]>(dp_f[v]+tree[i].we)){
            dp_s[root]=dp_f[root];
            dp_f[root]=dp_f[v]+tree[i].we;
        }else if(dp_f[root]==dp_f[v]+tree[i].we){
            dp_s[root]=dp_f[root];
        }else{
            dp_s[root]=min(dp_s[root],dp_f[v]+tree[i].we);
        }
    }
    if(!mark)dp_f[root]=dp_s[root]=0;
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        pt=1;
        int i,x,y,we,cnt;
        cnt=0;
        for(i=1;i<=n;i++){
            dp_f[i]=dp_s[i]=inf;
        }
        memset(head,0,sizeof(head));
        memset(tree,0,sizeof(tree));
        for(i=2;i<=n;i++){
            scanf("%d%d%d",&x,&y,&we);
            adde(x,y,we);
            adde(y,x,we);
            if(x==1 || y==1)cnt++;
        }
        dfs(1,0);
        int ans=1<<30;
        for(i=1;i<=n;i++){
            if(dp_f[i]==0 || dp_s[i]==0 ||dp_f[i]>20000000 ||dp_s[i]>20000000)continue;
            ans=min(ans,dp_f[i]+dp_s[i]);
        }
        if(cnt==1)ans=min(ans,dp_f[1]);
        printf("%d\n",ans);
    }
    return 0;
}
