#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
#define for if(0); else for
const int N=65537*2;
struct SegTree{
    int a[N<<1],mi[N<<1],mx[N<<1];
    int Q;
    void init(int n,int c[]){
        for(Q=1;Q<=n+2;Q<<=1);
        memset(a,0,sizeof(a));
        for(int i=Q+0;i<Q+n;i++) a[i]=mi[i]=mx[i]=c[i-Q];
        for(int i=Q-1;i>=1;i--) pushup(i);
    }
    void pushup(int rt) {
        a[rt]=a[rt<<1]==a[rt<<1|1]?a[rt<<1]:-1;
        mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
        mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    }
    void update_one(int rt,int x) {
        a[rt]=mi[rt]=mx[rt]=x;
    }
    void pushdown(int rt) {
        if(a[rt]!=-1) {
            update_one(rt<<1,a[rt]);
            update_one(rt<<1|1,a[rt]);
        }
    }
    void update(int L,int R,int l,int r,int rt,int c) {
        if(a[rt]==c) return;
        if(L<=l && r<=R) {
            update_one(rt,c);
            return;
        }
        pushdown(rt);
        if(rt>=Q) return;
        int m=(l+r)>>1;
        if(L<=m) update(L,R,l,m,rt<<1,c);
        if(m<R) update(L,R,m+1,r,rt<<1|1,c);
        pushup(rt);
    }
    int query(int L,int R,int l,int r,int rt,int c) {
        int ret=0;
        if(L<=l && r<=R) {
            if(c>=mi[rt]&&c<=mx[rt]){
                int m=(l+r)>>1;
                if(a[rt]!=-1) return (a[rt]==c)?r-l+1:0;
                else return query(L,R,l,m,rt<<1,c)+query(L,R,m+1,r,rt<<1|1,c);
            }else return 0;
        }
        if(rt>=Q) return ret;
        pushdown(rt);
        int m=(l+r)>>1;
        if(L<=m) ret+=query(L,R,l,m,rt<<1,c);
        if(m<R) ret+=query(L,R,m+1,r,rt<<1|1,c);
        return ret;
    }
}st;
int a[N];
int n,m;
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        st.init(n,a);
        for(int i=0;i<m;i++) {
            int cmd,l,r,c;
            scanf("%d%d%d%d",&cmd,&l,&r,&c);
            if(cmd==1){
                st.update(l,r,0,st.Q-1,1,c);
            }else {
                printf("%d\n",st.query(l,r,0,st.Q-1,1,c));
            }
        }
    }
    return 0;
}
