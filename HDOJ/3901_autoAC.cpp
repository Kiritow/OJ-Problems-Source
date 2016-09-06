#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
typedef pair <int, int> pt;
const int BUF_SIZE = 100000, SON = 26;
char s[BUF_SIZE + 1], t[BUF_SIZE + 1];
int lens, lent;
vector <pt> vec;
bool fir, las;
struct node_t {
    node_t *son[SON], *fail;
    vector <int> lis;
} node_pool[BUF_SIZE + 1], *node_idx, *root;
node_t *node_alloc() {
    node_t *ret = node_idx ++;
    memset(ret -> son, 0, sizeof(ret -> son));
    ret -> fail = NULL;
    ret -> lis.clear();
    return ret;
}
void init() {
    node_idx = node_pool;
    root = node_alloc();
}
void ins(char *st, char *ed, int p) {
    node_t *pos = root;
    while (st != ed) {
        int t = *(st ++) - 'a';
        if (!pos -> son[t]) pos -> son[t] = node_alloc();
        pos = pos -> son[t];
    }
    pos -> lis.pb(p);
}
void build() {
    static queue <node_t *> q;
    for (int i = 0; i < SON; i ++)
        if (root -> son[i]) {
            root -> son[i] -> fail = root;
            q.push(root -> son[i]);
        }
        else root -> son[i] = root;
    while (q.size()) {
        node_t *u = q.front();
        q.pop();
        for (int i = 0; i < SON; i ++)
            if (u -> son[i]) {
                u -> son[i] -> fail = u -> fail -> son[i];
                for (vector <int>::iterator it = u -> fail -> son[i] -> lis.begin(); it != u -> fail -> son[i] -> lis.end(); it ++)
                    u -> son[i] -> lis.pb(*it);
                q.push(u -> son[i]);
            }
            else u -> son[i] = u -> fail -> son[i];
    }
}
bool solve(int lb, int rb, bool st, bool ed) { 
    init();
    int pat = 0;
    static int cnt[BUF_SIZE];
    memset(cnt, 0, sizeof(cnt));
    for (int i = lb; i < rb; )
        if (t[i] == '?') i ++;
        else {
            int j = i;
            while (j < rb && t[j] != '?') j ++;
            ins(t + i, t + j, j - 1 - lb);
            i = j;
            pat ++;
        }
    build();
    node_t *pos = root;
    for (int i = 0; i < lens; i ++) {
        int p = s[i] - 'a';
        pos = pos -> son[p];
        node_t *tmp = pos;
        for (vector <int>::iterator it = tmp -> lis.begin(); it != tmp -> lis.end(); it ++) {
            int q = *it;
            if (i - q >= 0)
                cnt[i - q] ++;
        }
    }
    for (int i = 0; i < lens; i ++)
        if (cnt[i] == pat) {
            if (vec.empty()) {
                if (!fir && st && i != 0) continue;
                if (!las && ed && i + rb - lb != lens) continue;
                vec.pb(make_pair(i, i + rb - lb));
                return 1;
            }
            else {
                vector <pair <int, int> >::reverse_iterator it = vec.rbegin();
                if (i >= it -> second) {
                    if (ed && !las && i + rb - lb != lens) continue;
                    vec.pb(make_pair(i, i + rb - lb));
                    return 1;
                }
            }
        }
    return 0;
}
int main() {
    while (scanf("%s%s", s, t) != EOF) {
        lens = strlen(s), lent = strlen(t);
        fir = (t[0] == '*'), las = (t[lent - 1] == '*');
        vec.clear();
        bool fail = 0;
        int split = 0;
        int real_end = lent;
        while (real_end && t[real_end - 1] == '*') real_end --;
        for (int i = 0; i < lent; )
            if (t[i] == '*') i ++;
            else {
                int j = i;
                while (j < lent && t[j] != '*') j ++;
                if (!solve(i, j, split == 0, j == real_end)) {
                    fail = 1;
                    split ++;
                    break;
                }
                i = j;
                split ++;
            }
        if (split == 0) printf("YES\n");
        else if (fail) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
