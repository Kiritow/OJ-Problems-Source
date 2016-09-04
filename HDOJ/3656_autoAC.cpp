#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
const int MAX=120;
const int head=0;
int up[MAX*MAX],down[MAX*MAX],left[MAX*MAX],right[MAX*MAX];
int cnt[MAX],h[MAX],col[MAX*MAX];
int K,ans;
int nc;
void remove(const int& c){
    for(int i=down[c];i!=c;i=down[i]){
        left[right[i]]=left[i];
        right[left[i]]=right[i];
        cnt[col[i]]--;
    }
}
void resume(const int& c){
    for(int i=up[c];i!=c;i=up[i]){
        left[right[i]]=i;
        right[left[i]]=i;
        cnt[col[i]]++;
    }
}
int evalute(){
    bool vis[MAX]={0};
    int ret=0;
    for(int i=right[head];i!=head;i=right[i]){
        if(!vis[i]){
            ret++;
            vis[i]=true;
            for(int j=down[i];j!=i;j=down[j]){
                for(int k=right[j];k!=j;k=right[k]){
                    vis[col[k]]=true;
                }
            }
        }
    }
    return ret;
}
bool dfs(const int& k){
    if(k+evalute()>ans){
        return false;
    }
    if(right[head]==head){
        return true;
    }
    int s=oo,c=0;
    for(int i=right[head];i!=head;i=right[i]){
        if(cnt[i]<s){
            s=cnt[i];
            c=i;
            if(cnt[i]<=1){
                break;
            }
        }
    }
    for(int i=down[c];i!=c;i=down[i]){
        remove(i);
        for(int j=right[i];j!=i;j=right[j]){
            remove(j);
        }
        if(dfs(k+1)){
            return true;
        }
        for(int j=left[i];j!=i;j=left[j]){
            resume(j);
        }
        resume(i);
    }
    return false;
}
void init(){
    for(int i=0;i<=nc;i++){
        h[i]=-1;
        left[i]=i-1;
        right[i]=i+1;
        up[i]=down[i]=i;
        cnt[i]=0;
        col[i]=i;
    }
    left[head]=nc;
    right[nc]=head;
    K=nc;
    for(int i=1;i<=nc;i++){
        h[i]=-1;
    }
}
void add(const int& r,const int& c){
    K++;
    col[K]=c;
    up[K]=c;
    down[K]=down[c];
    if(h[r]==-1){
        h[r]=right[K]=K;
    }
    left[K]=h[r];
    right[K]=right[h[r]];
    left[right[K]]=K;
    right[left[K]]=K;
    up[down[K]]=K;
    down[up[K]]=K;
}
struct Node{
    int x,y;
}city[MAX];
int dis[MAX][MAX];
int que[MAX*MAX],top;
int sqr(int x){
    return x*x;
}
int operator*(const Node& a,const Node& b){
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
void build(const int& mid){
    init();
    for(int i=1;i<=nc;i++){
        for(int j=1;j<=nc;j++){
            if(dis[i][j]<=mid){
                add(i,j);
            }
        }
    }
}
void run(){
    int l=0,r=top;
    int mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        build(que[mid]);
        if(dfs(0)){
            ans=que[mid];
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%.6f\n",sqrt((double)ans));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&nc,&ans);
        for(int i=1;i<=nc;i++){
            scanf("%d%d",&city[i].x,&city[i].y);
        }
        top=0;
        for(int i=1;i<=nc;i++){
            for(int j=1;j<=nc;j++){
                que[top++]=dis[i][j]=city[i]*city[j];
            }
        }
        int tmp=top;
        sort(que,que+top);
        top=1;
        for(int i=1;i<tmp;i++){
            if(que[i]!=que[i-1]){
                que[top++]=que[i];
            }
        }
        run();
    }
    return 0;
}
