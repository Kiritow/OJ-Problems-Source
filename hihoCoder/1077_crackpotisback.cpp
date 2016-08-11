#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#include <stack>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1000010;
struct node {
    int lt,rt,minv;
};
node tree[maxn<<2];
void build(int lt,int rt,int v) {
    tree[v].lt = lt;
    tree[v].rt = rt;
    if(lt == rt) {
        scanf("%d",&tree[v].minv);
        return;
    }
    int mid = (lt + rt)>>1;
    build(lt,mid,v<<1);
    build(mid+1,rt,v<<1|1);
    tree[v].minv = min(tree[v<<1].minv,tree[v<<1|1].minv);
}
void update(int p,int val,int v) {
    if(tree[v].lt == tree[v].rt) {
        tree[v].minv = val;
        return;
    }
    if(p <= tree[v<<1].rt) update(p,val,v<<1);
    if(p >= tree[v<<1|1].lt) update(p,val,v<<1|1);
    tree[v].minv = min(tree[v<<1].minv,tree[v<<1|1].minv);
}
int query(int lt,int rt,int v) {
    if(tree[v].lt >= lt && tree[v].rt <= rt)
        return tree[v].minv;
    int a = INF,b = INF;
    if(lt <= tree[v<<1].rt) a = query(lt,rt,v<<1);
    if(rt >= tree[v<<1|1].lt) b = query(lt,rt,v<<1|1);
    return min(a,b);
}
int main() {
    int n,q,u,v,op;
    while(~scanf("%d",&n)) {
        build(1,n,1);
        scanf("%d",&q);
        while(q--) {
            scanf("%d %d %d",&op,&u,&v);
            if(op) update(u,v,1);
            else printf("%d\n",query(u,v,1));
        }
    }
    return 0;
}
