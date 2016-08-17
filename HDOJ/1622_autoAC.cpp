#include<algorithm>
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
using std::queue;
using std::vector;
const int Max_N = 260;
struct Node {
    int v, vis;
    Node *ch[2];
    inline void set(int _v, Node *p) {
        vis = 0, v = _v;
        ch[0] = ch[1] = p;
    }
};
struct BinTree {
    int fail;
    char buf[Max_N];
    Node *tail, *root, stack[Max_N];
    void init() {
        fail = 0;
        tail = &stack[0];
    }
    inline Node *newNode(int v = 0) {
        Node *p = tail++;
        p->set(v, NULL);
        return p;
    }
    inline void insert(const char *src, const int v) {
        int n = strlen(src);
        Node *x = root;
        for (int i = 0; i < n; i++) {
            if (src[i] == 'L') {
                if (!x->ch[0]) x->ch[0] = newNode();
                x = x->ch[0];
            } else if (src[i] == 'R') {
                if (!x->ch[1]) x->ch[1] = newNode();
                x = x->ch[1];
            }
        }
        if (x->vis) fail = 1;
        x->v = v;
        x->vis = 1;
    }
    inline void bfs() {
        vector<int> ans;
        queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            Node *u = que.front(); que.pop();
            if (!u->vis) {
                fail = 1;
                break;
            }
            ans.push_back(u->v);
            if (u->ch[0]) que.push(u->ch[0]);
            if (u->ch[1]) que.push(u->ch[1]);
        }
        if (fail) {
            puts("not complete");
            return;
        }
        int n = ans.size();
        for (int i = 0; i < n; i++) {
            printf("%d%c", ans[i], i < n - 1 ? ' ' : '\n');
        }
    }
    inline int gogo() {
        init();
        int v = 0;
        root = newNode();
        for (;;) {
            if (scanf("%s", buf) != 1) return 0;
            if (!strcmp(buf, "()")) break;
            sscanf(&buf[1], "%d", &v);
            insert(strchr(buf, ',') + 1, v);
        }
        bfs();
        return 1;
    }
}tree;
int main() {
    while (tree.gogo());
    return 0;
}
