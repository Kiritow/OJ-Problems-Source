#include <iostream>
#include <algorithm>
#define MAXN 200050
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r
using namespace std;
int h, w, n, m;
class Segment_Tree{
private:
    int node[MAXN << 2];
    void push_up(int rt){
        node[rt] = min(node[rt << 1], node[rt << 1 | 1]);
    }
public:
    void build(){
        memset(node, 0, sizeof(node));
    }
    int update(int val, int rt = 1, int l = 1, int r = n){
        if (l == r){
            if (node[rt] + val <= w){
                node[rt] += val;
                return l;
            }
            else return 0;
        }
        int m = (l + r) >> 1, ret = 0;
        if (node[rt << 1] + val <= w) ret += update(val, lchild);
        else ret += update(val, rchild);
        push_up(rt);
        return ret;
    }
    int query(){
        return node[1];
    }
}st;
int main(){
    int wi;
    while (scanf("%d %d %d", &h, &w, &m) != EOF){
        st.build();
        n = min(h, m);
        while (m--){
            scanf("%d", &wi);
            if (st.query() + wi <= w){
                printf("%d\n", st.update(wi));
            }
            else printf("-1\n");
        }
    }
    return 0;
}
