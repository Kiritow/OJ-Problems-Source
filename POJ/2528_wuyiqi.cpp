#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL rt<<1
#define RR rt<<1|1
#define lson l,m,LL
#define rson m+1,r,RR
#define bug puts("bugbug");
const int maxn = 11111;
bool hash[10010];
int col[maxn<<4];
struct node{
    int l,r;
}q[10010];
int ans;
int x[maxn<<2];
void pushdown(int rt){
    if(col[rt]!=-1){
        col[LL]=col[RR]=col[rt];
        col[rt]=-1;
    }
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L<=l&&r<=R){
        col[rt]=c;
        return ;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m)  update(L,R,c,rson);
}
void query(int l,int r,int rt){
    if(col[rt]!=-1){
        if(!hash[col[rt]]) ans++;
        hash[col[rt]]=true;
        return;
    }
    if(l==r) return;
    int m=(l+r)>>1;
    query(lson);
    query(rson);
}
int main(){
    int n,i,j,t;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            x[cnt++]=q[i].l;x[cnt++]=q[i].r;
        }
        sort(x,x+cnt);
        int m=1;
        for(i=1;i<cnt;i++)   if(x[i]!=x[i-1]) x[m++]=x[i];
        for(i=m-1;i>=1;i--)  if(x[i]!=x[i-1]+1) x[m++]=x[i-1]+1;
        sort(x,x+m);
        memset(col,-1,sizeof(col));
        for(i=0;i<n;i++){
            int l=lower_bound(x,x+m,q[i].l)-x;
            int r=lower_bound(x,x+m,q[i].r)-x;
            update(l,r,i,0,m,1);
        }
        memset(hash,false,sizeof(hash));
        ans=0;
        query(0,m,1);
        printf("%d\n",ans);
    }
    return 0;
}
