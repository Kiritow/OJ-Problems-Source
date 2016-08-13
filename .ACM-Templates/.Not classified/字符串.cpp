//hash_fun.h
inline size_t __stl_hash_string(const char *s) {
  size_t h = 0;
  for (; *s; ++s) { h = 5 * h + *s; }
  return h;
}
//for hash_map<string, XXX>
struct str_hash {
  size_t operator()(const string &str)const {
    return __stl_hash_string(str.c_str());
  }
};
//BKDR Hash Function
inline size_t BKDRHash(const char *str) {
  size_t h = 0, seed = 131; //31 131 1313 13131 131313 etc..
  while (*str) { h = h * seed + (*str++); }
  return h & 0x7FFFFFFF;
}
//字符串hash
const int N = 20005, P = 31, D = 1000173169;
int n, pp[N] = {1}, hs[N]; char s[N];
int get(int l, int r) { return ((hs[r] - (ll)hs[l - 1] * pp[r - l + 1]) % D + D) % D; }
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) { pp[i] = pp[i - 1] * P % D; }
  for (int i = 1; i <= n; i++) { hs[i] = ((ll)hs[i - 1] * P + s[i]) % D; }
}
//手写hash_map
const int P = 13131;
char key[N][M];
typedef struct Node { int id, val; } etype;
template<size_t(*Hash)(const char *)> struct hashmap {
  vector<etype> hs[P];
  void init() { for (int i = 0; i < P; i++) { hs[i].clear(); } }
  void insert(int id, int val) {
    int h = Hash(key[id]) % P; hs[h].push_back((etype) {id, val});
  }
  bool erase(char *buf) {
    int h = Hash(buf) % P;
    for (size_t i = 0; i < n; i++) { if (!strcmp(buf, key[hs[h][i].id])) { hs[h].erase(hs[h].begin() + i); return true; } }
    return false;
  }
  int query(char *buf) {
    int h = Hash(buf) % P;
    for (size_t i = 0; i < n; i++) { if (!strcmp(buf, key[hs[h][i].id])) { return hs[h][i].val; } }
    return false;
  }
};
hashmap<BKDRHash> mp;
//Manacher 最长回文子串
//最长回文子串对应原串T中的位置: l = (i - R[i]) / 2; r = (i + R[i]) / 2 - 2;
char s[N], tmp[N << 1];
int dp[N << 1];
void Manacher(char *s, int len) {
  int l = 0, mx = 0, id = 0; tmp[l++] = '$'; tmp[l++] = '#';
  for (int i = 0; i < len; i++) { tmp[l++] = s[i]; tmp[l++] = '#'; }
  tmp[l] = 0;
  for (int i = 0; i < l; i++) {
    dp[i] = mx > i ? min(dp[(id << 1) - i], mx - i) : 1;
    while (tmp[i + dp[i]] == tmp[i - dp[i]]) { dp[i]++; }
    if (i + dp[i] > mx) { mx = i + dp[i]; id = i; }
  }
}
int main() {
  while (~scanf("%s", s)) {
    int len = strlen(s), mlen = (len << 1) + 2, mxlen = 0, mxpos = 0;
    Manacher(s, len);
    for (int i = 0; i < mlen; i++) {
      if (mxlen < dp[i]) { mxlen = dp[i]; mxpos = i; }
    }
    printf("%d\n", mxlen - 1); //s.substr((mxpos - mxlen) >> 1, mxlen - 1);
  }
}
//字符串最小表示
int minString(char *s) {
  int m = strlen(s), i, j, k;
  char ss[m << 1]; strcpy(ss, s); strcpy(ss + m, s);
  for (i = k = 0, j = 1; k < m && i < m && j < m;) {
    for (k = 0; k < m && ss[i + k] == ss[j + k]; k++);
    if (k < m) {
      if (ss[i + k] > ss[j + k]) { i += k + 1; } //最大则改为<
      else { j += k + 1; }
      if (i == j) { j++; }
    }
  }
  return min(i, j);
}
//strstr 在str1中查找str2的第一次出现 无则返回NULL
char *strstr(const char *str1, const char *str2);
//KMP O(M + N)
//nxt[]的含义：x[i-nxt[i]...i-1]=x[0...nxt[i]-1]
//nxt[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值(就是x的自身匹配)
char x[N], y[N];
int nxt[N];
void getnxt(char *x, int m, int nxt[]) {
  int i = 0, j = -1; nxt[0] = -1;
  while (i < m) {
    while (j != -1 && x[i] != x[j]) { j = nxt[j]; }
    nxt[++i] = ++j;
  }
}
//改进版
void getnxt(char *x, int m, int nxt[]) {
  int i = 0, j = -1; nxt[0] = -1;
  while (i < m) {
    while (j != -1 && x[i] != x[j]) { j = nxt[j]; }
    if (x[++i] == x[++j]) { nxt[i] = nxt[j]; }
    else { nxt[i] = j; }
  }
}
//返回x在y中出现的次数, 可以重叠
//x是模式串, y是主串
int KMPCount(char *x, int m, char *y, int n, int nxt[]/*, int &longest, int &lp*/) {
  int i = 0, j = 0, ans = 0; //longest = 0; lp = 0;
  while (i < n) {
    while (j != -1 && y[i] != x[j]) { j = nxt[j]; }
    i++; j++;
    //if (j > longest) { longest = j; lp = i - j; }
    if (j >= m) { j = nxt[j]; ans++; }
  }
  return ans;
}
//扩展KMP
//nxt[i]:x[i...m-1]与x[0...m-1]的最长公共前缀
//ext[i]:y[i...n-1]与x[0...m-1]的最长公共前缀
int nxt[N], ext[N];
void getnxt(char *x, int m, int nxt[]) {
  int i = 2, j = 0, k = 1;
  while (j + 1 < m && x[j] == x[j + 1]) { j++; }
  nxt[0] = m; nxt[1] = j;
  for (; i < m; i++) {
    int p = nxt[k] + k - 1, l = nxt[i - k];
    if (i + l < p + 1) { nxt[i] = l; }
    else {
      j = max(0, p - i + 1);
      while (i + j < m && x[i + j] == x[j]) { j++; }
      nxt[i] = j; k = i;
    }
  }
}
void getext(char *x, int m, char *y, int n, int nxt[], int ext[]) {
  getnxt(x, m);
  int i = 1, j = 0, k = 0;
  while (j < n && j < m && x[j] == y[j]) { j++; }
  ext[0] = j;
  for (; i < n; i++) {
    int p = ext[k] + k - 1, l = nxt[i - k];
    if (i + l < p + 1) { ext[i] = l; }
    else {
      j = max(0, p - i + 1);
      while (i + j < n && j < m && y[i + j] == x[j]) { j++; }
      ext[i] = j; k = i;
    }
  }
}
//Sunday
int Sunday(char *x, int m, char *y, int n) {
  int nxt[26] = {0};
  for (int j = 0; j < 26; j++) { nxt[j] = m + 1; }
  for (int j = 0; j < m; j++) { nxt[x[j] - 'a'] = m - j; }
  for (int pos = 0, i, j; pos <= n - m;) {
    for (i = pos, j = 0; j < m; i++, j++) {
      if (y[i] != x[j]) { pos += nxt[y[pos + m] - 'a']; break; }
    }
    if (j == m) { return pos; }
  }
  return -1;
}
//Rabin-Karp
#define UNSIGNED(x) ((unsigned char)x)
const int d = 257;
int hashMatch(char *s, int m, char *p, int n) {
  if (m > n || m == 0 || n == 0) { return -1; }
  //sv为s子串的hash结果, pv为p的hash结果, base为d的m-1次方
  unsigned sv = UNSIGNED(s[0]), pv = UNSIGNED(p[0]), base = 1;
  int i, j;
  //初始化sv, pv, base
  for (i = 1; i < m; i++) {
    pv = pv * d + UNSIGNED(p[i]);
    sv = sv * d + UNSIGNED(s[i]);
    base *= d;
  }
  i = m - 1;
  do {
    if (!(sv ^ pv)) {
      for (j = 0; j < m && s[i - m + 1 + j] == p[j]; j++);
      if (j == m) { return i - m + 1; }
    }
    if (++i >= n) { break; }
    //O(1)时间内更新sv, sv + UNSIGNED(s[i - m]) * (~base + 1)等价于sv - UNSIGNED(s[i - m]) * base
    sv = (sv + UNSIGNED(s[i - m]) * (~base + 1)) * d + UNSIGNED(s[i]);
  } while (i < n);
  return -1;
}
//Trie
//数组实现
struct Trie {
  int nxt[N * 20][26], val[N * 20], root, tot;
  void init() { memset(nxt, 0, sizeof(nxt)); memset(val, 0, sizeof(val)); root = tot = 1; }
  void insert(char *buf, int id) {
    int len = strlen(buf), now = root;
    for (int i = 0, c; i < len; i++) {
      if (!nxt[now][c = buf[i] - 'a']) { nxt[now][c] = ++tot; }
      now = nxt[now][c];
    }
    val[now] = id;
  }
  int query(char *buf) {
    int len = strlen(buf), now = root;
    for (int i = 0, c; i < len; i++) {
      if (!nxt[now][c = buf[i] - 'a']) { return -1; }
      now = nxt[now][c];
    }
    return val[now];
  }
} tr;
//指针实现
struct Node { Node *nxt[26]; int val; };
struct Trie {
  Node *root;
  void init() { erase(root); root = new Node(); }
  void insert(char *buf, int id) {
    int len = strlen(buf); Node *now = root;
    for (int i = 0, c; i < len; i++) {
      if (!now->nxt[c = buf[i] - 'a']) { now->nxt[c] = new Node(); }
      now = now->nxt[c];
    }
    now->val = id;
  }
  void erase(Node *p) {
    if (p) { for (int i = 0; i < 26; i++) { erase(p->nxt[i]); } delete p; }
  }
  int query(char *buf) {
    int len = strlen(buf); Node *now = root;
    for (int i = 0, c; i < len; i++) {
      if (!now->nxt[c = buf[i] - 'a']) { return -1; }
      now = now->nxt[c];
    }
    return now->val;
  }
} tr;
//AC自动机
struct AC {
  int nxt[N * 20][26], fail[N * 20], val[N * 20], root, tot;
  void init() { memset(nxt, 0, sizeof(nxt)); memset(val, 0, sizeof(val)); root = tot = 1; }
  void insert(char *buf, int id) {
    int len = strlen(buf), now = root;
    for (int i = 0, c; i < len; i++) {
      if (!nxt[now][c = buf[i] - 'a']) { nxt[now][c] = ++tot; }
      now = nxt[now][c];
    }
    val[now] = id;
  }
  void build() {
    queue<int> que; fail[root] = root;
    for (int i = 0; i < 26; i++) {
      if (!nxt[root][i]) { nxt[root][i] = root; }
      else { fail[nxt[root][i]] = root; que.push(nxt[root][i]); }
    }
    while (!que.empty()) {
      int now = que.front(); que.pop();
      for (int i = 0; i < 26; i++) {
        if (!nxt[now][i]) { nxt[now][i] = nxt[fail[now]][i]; }
        else { fail[nxt[now][i]] = nxt[fail[now]][i]; que.push(nxt[now][i]); }
      }
    }
  }
  int query(char *buf) {
    int len = strlen(buf), now = root, res = 0;
    for (int i = 0, c; i < len; i++) {
      for (int tmp = now = nxt[now][c = buf[i] - 'a']; tmp != root; tmp = fail[tmp]) {
        res += val[tmp]; //val[tmp] = 0;
      }
    }
    return res;
  }
} ac;
//后缀数组
//n：串长
//m：字符集大小
//s[0..n - 1]：字符串
//sa[1..n]：字典序第 i 小的是哪个后缀
//rnk[0..n - 1]：后缀 i 的排名
//height[i]：lcp(sa[i], sa[i - 1])
int rnk[N], sa[N], height[N], tmp[N], cnt[N];
void SA(char *s, int n, int m) {
  int i, j, k; n++;
  memset(rnk, 0, sizeof(rnk)); memset(sa, 0, sizeof(sa)); memset(height, 0, sizeof(height));
  memset(tmp, 0, sizeof(tmp)); memset(cnt, 0, sizeof(cnt));
  for (i = 0; i < n; i++) { cnt[rnk[i] = s[i]]++; }
  for (i = 1; i < m; i++) { cnt[i] += cnt[i - 1]; }
  for (i = 0; i < n; i++) { sa[--cnt[rnk[i]]] = i; }
  for (k = 1; k <= n; k <<= 1) {
    for (i = 0; i < n; i++) {
      j = sa[i] - k;
      if (j < 0) { j += n; }
      tmp[cnt[rnk[j]]++] = j;
    }
    sa[tmp[cnt[0] = 0]] = j = 0;
    for (i = 1; i < n; i++) {
      if (rnk[tmp[i]] != rnk[tmp[i - 1]] || rnk[tmp[i] + k] != rnk[tmp[i - 1] + k]) { cnt[++j] = i; }
      sa[tmp[i]] = j;
    }
    memcpy(rnk, sa, n * sizeof(int));
    memcpy(sa, tmp, n * sizeof(int));
    if (j >= n - 1) { break; }
  }
  for (j = rnk[height[i = k = 0] = 0]; i < n - 1; i++, k++) {
    while (k >= 0 && s[i] != s[sa[j - 1] + k]) { height[j] = k--, j = rnk[sa[j] + 1]; }
  }
}
//后缀自动机
const int N = 1000005;
const int N_CHAR = 26;
struct SuffixAutomaton {
  struct Node { Node *fail, *next[N_CHAR]; int val, right; };
  Node mempool[N << 1]; int n_node;
  Node *new_node(int v) {
    Node *p = &mempool[n_node++]; memset(p->next, 0, sizeof(p->next));
    p->fail = 0; p->right = 0; p->val = v; return p;
  }
  Node *root, *last;
  SuffixAutomaton() { clear(); }
  void clear() { root = last = new_node(n_node = 0); }
  void add(int c) {
    Node *p = last, *np = new_node(p->val + 1);
    while (p && !p->next[c]) { p->next[c] = np; p = p->fail; }
    if (!p) { np->fail = root; }
    else {
      Node *q = p->next[c];
      if (p->val + 1 == q->val) { np->fail = q; }
      else {
        Node *nq = new_node(p->val + 1);
        for (int i = 0; i < N_CHAR; i++) { nq->next[i] = q->next[i]; }
        nq->fail = q->fail; q->fail = np->fail = nq;
        while (p && p->next[c] == q) { p->next[c] = nq; p = p->fail; }
      }
    }
    last = np; np->right = 1;
  }
  Node *go(const char *s) {
    Node *p = root; int cL = 0; //与s匹配的长度
    for (int i = 0; s[i]; i++) {
      int c = s[i] - 'a';
      if (p->next[c]) { p = p->next[c], ++cL; }
      else {
        while (p && !p->next[c]) { p = p->fail; }
        if (!p) { cL = 0; p = root; }
        else { cL = p->val + 1; p = p->next[c]; }
      }
    }
    return p;
  }
  int d[N << 1]; Node *b[N << 1];
  void toposort() {
    for (int i = 0; i <= n_node; i++) { d[i] = 0; }
    int mx_val = 0;
    for (int i = 0; i < n_node; i++) { mx_val = max(mx_val, mempool[i].val); d[mempool[i].val]++; }
    for (int i = 1; i <= mx_val; i++) { d[i] += d[i - 1]; }
    for (int i = 0; i < n_node; i++) { b[--d[mempool[i].val]] = &mempool[i]; }
  }
  void updateright() {
    toposort();
    for (int i = n_node - 1; i; i--) { b[i]->fail->right += b[i]->right; }
  }
} sa;
//回文树
struct PalindromicTree {
  int nxt[N][26]; //指向的串为当前串两端加上同一个字符构成
  int fail[N]; //表示失配后跳转到长度小于该串且以该节点表示回文串的最后一个字符结尾的最长回文串表示的节点
  int cnt[N]; //表示节点表示的本质不同的串的个数(建树时求出的不是完全的, 最后count函数跑一遍以后才是正确的)
  int num[N]; //表示以节点表示的最长回文串的最右端点为回文串结尾的回文串个数
  int len[N]; //表示节点表示的回文串长度
  int S[N]; //表示第i次添加的字符(S[0] = -1(任意一个在串中不会出现的字符))
  int last; //指向新添加一个字母后所形成的最长回文串表示的节点
  int n; //表示添加的字符个数
  int tot; //表示节点个数
  int newnode(int l) { len[tot] = l; return tot++; }
  void init() {
    memset(nxt, 0, sizeof(nxt)); memset(cnt, 0, sizeof(cnt)); memset(len, 0, sizeof(len));
    newnode(0); newnode(-1); tot = last = n = 0; S[n] = -1; fail[0] = 1;
  }
  int getfail(int x) { //失配后找一个尽量最长的
    while (S[n - len[x] - 1] != S[n]) { x = fail[x]; }
    return x;
  }
  void add(int c) {
    c -= 'a'; S[++n] = c;
    int cur = getfail(last); //通过上一个回文串找这个回文串的匹配位置
    if (!nxt[cur][c]) { //如果这个回文串没有出现过, 说明出现了一个新的本质不同的回文串
      int now = newnode(len[cur] + 2); //新建节点
      fail[now] = nxt[getfail(fail[cur])][c]; //和AC自动机一样建立fail指针, 以便失配后跳转
      nxt[cur][c] = now; num[now] = num[fail[now]] + 1;
    }
    cnt[last = nxt[cur][c]]++;
  }
  void count() {
    for (int i = tot - 1; i >= 0; i--) { cnt[fail[i]] += cnt[i]; }
    //父亲累加儿子的cnt, 因为如果fail[v] = u, 则u一定是v的子回文串
  }
} pat;
