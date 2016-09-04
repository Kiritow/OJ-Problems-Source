#include <cstdio>
#include <cstring>
const int MAXN = 200005;
struct SAMNode {
    SAMNode *f, *ch[26];
    int len;
    bool *d;
    int pos; 
    int v;
};
SAMNode *root, *last;
int p_cnt, d_cnt, seq_len, v_id;
SAMNode pool[MAXN*2];
bool is_d[MAXN*2];
char str[MAXN];
SAMNode *seq[MAXN];
bool is_del(SAMNode *x) {
    return x == NULL || *x->d;
}
void append(char ch) {
    int c = ch - 'a';
    SAMNode *p = last, *np = pool + p_cnt++;
    memset(np, 0, sizeof(*np));
    np->pos = np->len = p->len + 1;
    np->d = is_d + d_cnt++;
    *np->d = false;
    seq[seq_len = np->len] = np;
    last = np;
    for (; NULL != p && is_del(p->ch[c]); p = p->f) p->ch[c] = np;
    if (NULL == p) {
        np->f = root;
    } else {
        if (p->ch[c]->len == p->len + 1) {
            np->f = p->ch[c];
        } else {
            SAMNode *q = p->ch[c], *nq = pool + p_cnt++;
            *nq = *q;
            nq->len = p->len + 1;
            q->f = np->f = nq;
            for (; NULL != p && p->ch[c] == q; p = p->f) p->ch[c] = nq;
        }
    }
}
void del(int len) {
    while (len--) *seq[seq_len--]->d = true;
    last = seq[seq_len];
}
int dfs_len;
int dfs(SAMNode *x, int l) {
    if (l == dfs_len) return x->pos - l  + 1;
    if (x->v == v_id) return seq_len - l + 1;
    for (int i = 0; i < 26; ++i) {
        if (!is_del(x->ch[i])) {
            return dfs(x->ch[i], l+1);
        }
    }
    return x->len - l + 1;
}
int query(int len) {
    ++v_id;
    for (SAMNode *p = last; p != root; p = p->f) p->v = v_id;
    dfs_len = len;
    int ret = dfs(root, 0);
    return ret;
}
int main() {
    while (EOF != scanf("%s", str)) {
        root = last = pool;
        memset(root, 0, sizeof(*root));
        root->d = is_d;
        is_d[0] = false;
        p_cnt = 1;
        d_cnt = 1;
        v_id = 0;
        seq[0] = root;
        for (char *c = str; *c; ++c) append(*c);
        int m, q, len;
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &q);
            if (1 == q) {
                scanf("%s", str);
                for (char *c = str; *c; ++c) append(*c);
            } else if (2 == q) {
                scanf("%d", &len);
                printf("%d\n", query(len));
            } else if (3 == q) {
                scanf("%d", &len);
                del(len);
            } else {
                for(;;);
                fprintf(stderr, "error cmd %d\n", q);
            }
        }
    }
    return 0;
}
