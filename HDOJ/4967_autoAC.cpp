#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct info{
    int s;
    int x;
    int t;
};
const int MAX = 50010;
int N,x,t;
char str[20];
info a[MAX];
int b[MAX];
int ans;
struct interval{
    int left, right;
    int sum, rsum;
};
struct SegmentTree{
    static const int MAX = 50010;
    interval node[MAX<<3];
    #define ls(o) (o<<1)
    #define rs(o) (o<<1|1)
    void build(int l, int r, int o){
        node[o].left = l;
        node[o].right = r;
        node[o].sum = node[o].rsum = 0;
        if(l == r) return;
        int mid = (l + r)>>1;
        build(l,mid,ls(o));
        build(mid+1,r,rs(o));
    }
    void pushup(int o){
        node[o].sum = node[rs(o)].sum + node[ls(o)].sum;
        node[o].rsum = max(node[rs(o)].rsum,node[ls(o)].rsum + node[rs(o)].sum);
    }
    void update(int value,int pos,int o){
        if(node[o].left == node[o].right &&
           node[o].left == pos){
            node[o].sum = node[o].rsum = value;
            return ;
           }
        int mid = (node[o].left + node[o].right) >> 1;
        if(pos <= mid) update(value,pos,ls(o));
        else update(value,pos,rs(o));
        pushup(o);
    }
    void getans(int v,int o){
        if(node[o].left == node[o].right){
            ans = b[node[o].left];
            return;
        }
        if(v + node[rs(o)].rsum > 0)
            getans(v,rs(o));
        else
            getans(v + node[rs(o)].sum,ls(o));
    }
    void query(int &v,int L, int R, int o){
        if(~ans) return;
        if(L <= node[o].left && R >= node[o].right){
            if(v + node[o].rsum <= 0) v += node[o].sum;
            else getans(v,o);
            return;
        }
        int mid = (node[o].left + node[o].right) >> 1;
        if(R > mid) query(v,L,R,rs(o));
        if(L <= mid) query(v,L,R,ls(o));
    }
};
SegmentTree tree;
int main(void)
{
    int cas = 1;
    while(scanf("%d", &N),N){
        for(int i = 0 ; i < N; ++i){
            scanf("%s",str);
            if(str[1] == 'u'){
                a[i].s = 1;
                scanf("%d", &a[i].x);
            }
            else if(str[1] == 'o')
                a[i].s = 2;
            else
                a[i].s = 3;
            scanf("%d", &a[i].t);
            b[i] = a[i].t;
        }
        sort(b,b + N);
        for(int i = 0 ; i < N; ++i)
            a[i].t = lower_bound(b, b + N, a[i].t) - b + 1;
        memset(b,0,sizeof(b));
        for(int i = 0 ; i < N; ++i)
            if(a[i].s == 1)
                b[a[i].t] = a[i].x;
        printf("Case #%d:\n",cas++);
        tree.build(1,N,1);
        for(int i = 0 ; i < N; ++i){
            if(a[i].s == 1)
                tree.update(1,a[i].t,1);
            else if(a[i].s == 2)
                tree.update(-1,a[i].t,1);
            else{
                int v =0;
                ans = -1;
                tree.query(v,1,a[i].t,1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
