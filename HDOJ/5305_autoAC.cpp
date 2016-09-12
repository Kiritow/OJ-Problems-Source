#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int ans;
int n,m;
int cnt[10];
struct node{
    int x,y;
    void in(){
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        cnt[x]++;
        cnt[y]++;
    }
    friend bool operator < (node a,node b){
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    }
}p[30];
void dfs(int t,int on[],int off[]){
    if(t==m){
        ans++;
        return ;
    }
    int x=p[t].x;
    int y=p[t].y;
    on[x]++ , on[y]++;
    if(on[x]<=cnt[x]/2 && off[x]<=cnt[x]/2 && on[y]<=cnt[y]/2 && off[y]<=cnt[y]/2 ){
        dfs(t+1,on,off);
    }
    on[x]-- , on[y]--;
    off[x]++ , off[y]++;
    if(on[x]<=cnt[x]/2 && off[x]<=cnt[x]/2 && on[y]<=cnt[y]/2 && off[y]<=cnt[y]/2 ){
        dfs(t+1,on,off);
    }
    off[x]-- , off[y]-- ;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int on[10];
        int off[10];
        memset(cnt,0,sizeof cnt);
        memset(on,0,sizeof on);
        memset(off,0,sizeof off);
        for(int i=0;i<m;i++){
            p[i].in();
        }
        bool ok=false;
        for(int i=1;i<=n;i++){
            if(cnt[i]&1){
                ok=true;
                break;
            }
        }
        if(ok){
            printf("0\n");
            continue;
        }
        sort(p,p+m);
        ans=0;
        dfs(0,on,off);
        printf("%d\n",ans);
    }
    return 0;
}
