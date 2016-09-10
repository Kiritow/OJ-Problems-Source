#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define lson l, mid, root<<1
#define rson mid+1, r, root<<1|1
const int N = 1e6 + 5;
set <int> s;
set <int> ::iterator it;
struct Node {
    int color;
    int left;
    int right;
    int mid;
} a[N<<2];
void Push_Down(int root) {
    if(a[root].color) {
        a[root<<1].color = a[root].color;
        a[root<<1|1].color = a[root].color;
        a[root].color = 0;
    }
}
void Build_Tree(int l, int r, int root) {
    int mid = (l + r) >> 1;
    a[root].left = l;
    a[root].right = r;
    a[root].mid = mid;
    a[root].color = 2;
    if(l == r) return;
    Build_Tree(lson);
    Build_Tree(rson);
}
void Update(int l, int r, int c, int root) {
    if(a[root].left == l && a[root].right == r) {
        a[root].color = c;
        return;
    }
    if(a[root].color == c) return;
    Push_Down(root);
    if(l > a[root].mid) Update(l, r, c, root<<1|1);
    else if(r <= a[root].mid) Update(l, r, c, root<<1);
    else {
        Update(l, a[root].mid, c, root<<1);
        Update(a[root].mid+1, r, c, root<<1|1);
    }
}
void Query(int l, int r, int root) {
    if(a[root].color) {
        s.insert(a[root].color);
        return ;
    }
    if(l > a[root].mid) Query(l, r, root<<1|1);
    else if(r <= a[root].mid) Query(l, r, root<<1);
    else {
        Query(l, a[root].mid, root<<1);
        Query(a[root].mid+1, r, root<<1|1);
    }
}
int main() {
    int n, m;
    int l, r, c;
    char op[10];
    while(~scanf("%d%d", &n, &m) && (n + m)) {
        Build_Tree(1, n, 1);
        for(int i = 0; i < m; i++) {
            scanf("%s%d%d", op, &l, &r);
            if(op[0] == 'P') {
                scanf("%d", &c);
                Update(l, r, c, 1);
            }
            else {
                s.clear();
                Query(l, r, 1);
                int ss = s.size();
                for(it = s.begin(); it != s.end(); it++) {
                    printf("%d", *it);
                    if(ss > 1) printf(" ");
                    ss--;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
