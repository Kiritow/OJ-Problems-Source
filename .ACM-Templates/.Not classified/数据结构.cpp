//一维树状数组
//单点修改 + 单点查询 + 区间修改 + 区间查询 + 区间最值
int n;
template<typename T> struct BIT {
  T A[N]; //T B[N]; //区间增减/维护最值
  int lowbit(int x) { return x & -x; }
  void init() { memset(A, 0, sizeof(A)); /*memset(B, 0, sizeof(B));*/ }
  void update(int i, T v) { while (i <= n) { A[i] += v; i += lowbit(i); } }
  T query(int i) { T ret = 0; while (i) { ret += A[i]; i -= lowbit(i); } return ret; }
  T query(int i, int j) { return query(j) - query(i - 1); }
  //区间修改
  T query(int x) {
    if (!x) { return 0; }
    T ret1 = 0, ret2 = 0;
    for (int i = x; i <= n; i += lowbit(i)) { ret1 += A[i]; }
    for (int i = x - 1; i > 0; i -= lowbit(i)) { ret2 += B[i]; }
    return ret1 * x + ret2;
  }
  void update(int x, T v) {
    for (int i = x; i > 0; i -= lowbit(i)) { A[i] += v; }
    for (int i = x; i <= n; i += lowbit(i)) { B[i] += x * v; }
  }
  void update(int i, int j, T v) { update(j, v); if (i > 1) { update(i - 1, -v); } }
  //维护区间最值 O(log^2(n))
  void modify(int x, T v) {
    B[x] = v;
    for (int i = x; i <= n; i += lowbit(i)) {
      A[i] = max(A[i], v);
      for (int j = 1; j < lowbit(i); j <<= 1) {
        A[i] = max(A[i], A[i - j]);
      }
    }
  }
  T query(int l, int r) {
    T ret = B[r];
    while (true) {
      ret = max(ret, B[r]);
      if (l == r) { break; }
      for (r -= 1; r - l >= lowbit(r); r -= lowbit(r)) { ret = max(ret, A[r]); }
    }
    return ret;
  }
  //求区间第K大的下标/值 O(log^2(n))
  int getK(int l, int r, int k) {
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (query(mid) >= k) { r = mid - 1; }
      else { l = mid + 1; }
    }
    return l; //A[l]
  }
};
BIT<int> bit;
//二维树状数组
//单点修改 + 单点查询 + 区域修改 + 区域查询
int n, m;
template<typename T> struct BIT {
  T A[N][N]; //T B[N][N], C[N][N], D[N][N]; //区域求和
  int lowbit(int x) { return x & -x; }
  void init() { memset(A, 0, sizeof(A)); /*memset(B, 0, sizeof(B)); memset(C, 0, sizeof(C)); memset(D, 0, sizeof(D));*/ }
  T get(int x, int y) {
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) { for (int j = y; j > 0; j -= lowbit(j)) { ret += A[i][j]; } }
    return ret;
  }
  T query(int x, int y) { return get(x, y) - get(x, y - 1) - get(x - 1, y) + get(x - 1, y - 1); }
  void update(int x, int y, T v) {
    for (int i = x; i <= n; i += lowbit(i)) { for (int j = y; j <= m; j += lowbit(j)) { A[i][j] += v; } }
  }
  //区域和[x1][y1]-[x2][y2]
  T query(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
  }
  //区域增减
  void update(int x, int y, T v, T a[][N]) {
    for (int i = x; i <= n; i += lowbit(i)) { for (int j = y; j <= m; j += lowbit(j)) { a[i][j] += v; } }
  }
  void update(int x1, int y1, int x2, int y2, T v) {
    update(x1, y1, v, A); update(x2 + 1, y1, -v, A);
    update(x1, y2 + 1, -v, A); update(x2 + 1, y2 + 1, v, A);
    update(x1, y1, v * x1, B); update(x2 + 1, y1, -v * (x2 + 1), B);
    update(x1, y2 + 1, -v * x1, B); update(x2 + 1, y2 + 1, v * (x2 + 1), B);
    update(x1, y1, v * y1, C); update(x2 + 1, y1, -v * y1, C);
    update(x1, y2 + 1, -v * (y2 + 1), C); update(x2 + 1, y2 + 1, v * (y2 + 1), C);
    update(x1, y1, v * x1 * y1, D); update(x2 + 1, y1, -v * (x2 + 1) * y1, D);
    update(x1, y2 + 1, -v * x1 * (y2 + 1), D); update(x2 + 1, y2 + 1, v * (x2 + 1) * (y2 + 1), D);
  }
};
BIT<int> bit;
//线段树 单点修改 + 区间查询
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
template<typename T> struct SegmentTree {
  T data[N << 2];
  T calc(const T &x, const T &y)const { return x + y; }
  void push_up(int rt) { data[rt] = calc(data[rt << 1], data[rt << 1 | 1]); }
  void build(int l, int r, int rt) {
    if (l == r) { scanf("%d", &data[rt]); return; }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
  }
  void update(int p, T val, int l, int r, int rt) {
    if (l == r) { data[rt] += val; return; }
    int m = (l + r) >> 1;
    if (p <= m) { update(p, val, lson); }
    else { update(p, val, rson); }
    push_up(rt);
  }
  T query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) { return data[rt]; }
    int m = (l + r) >> 1; T ret = 0;
    if (L <= m) { ret = calc(ret, query(L, R, lson)); }
    if (m < R) { ret = calc(ret, query(L, R, rson)); }
    return ret;
  }
};
SegmentTree<int> st;
//线段树 区间查询/修改 + 延迟标记
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
template<typename T> struct SegmentTree {
  T data[N << 2], lazy[N << 2];
  T calc(const T &x, const T &y)const { return x + y; }
  void push_up(int rt) { data[rt] = calc(data[rt << 1], data[rt << 1 | 1]); }
  void push_down(int rt, int len) {
    if (lazy[rt]) {
      data[rt << 1] += lazy[rt] * (len - (len >> 1)); lazy[rt << 1] += lazy[rt];
      data[rt << 1 | 1] += lazy[rt] * (len >> 1); lazy[rt << 1 | 1] += lazy[rt];
      lazy[rt] = 0;
    }
  }
  void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r) { scanf("%d", &data[rt]); return; }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
  }
  void update(int L, int R, T val, int l, int r, int rt) {
    if (L <= l && r <= R) {
      data[rt] += val * (r - l + 1);
      lazy[rt] += val;
      return;
    }
    push_down(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) { update(L, R, val, lson); }
    if (m < R) { update(L, R, val, rson); }
    push_up(rt);
  }
  T query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) { return data[rt]; }
    push_down(rt, r - l + 1);
    int m = (l + r) >> 1; T ret = 0;
    if (L <= m) { ret = calc(ret, query(L, R, lson)); }
    if (m < R) { ret = calc(ret, query(L, R, rson)); }
    return ret;
  }
};
SegmentTree<int> st;
//非递归版线段树 单点修改 + 区间查询
const int N = ((131072 << 1) + 10); //节点个数->不小于区间长度+2的最小2的正整数次幂*2+10
#define l(x) ((x)<<1) //x的左儿子
#define r(x) (((x)<<1)|1) //x的右儿子
template<typename T> struct zkwSegmentTree {
  int m; //底层节点数
  T sum[N]; //区间和
  void build(int n) {
    for (m = 1; m < n + 2; m <<= 1);
    for (int i = 1; i <= n; i++) { scanf("%d", &sum[m + i]); }
    for (int i = m - 1; i; i--) { sum[i] = sum[l(i)] + sum[r(i)]; }
  }
  void update(int p, T val) {
    for (sum[p += m] += val, p >>= 1; p; p >>= 1) {
      sum[p] = sum[l(p)] + sum[r(p)];
    }
  }
  T query(int l, int r) {
    T ret = 0;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) { ret += sum[l ^ 1]; }
      if (r & 1) { ret += sum[r ^ 1]; }
    }
    return ret;
  }
};
zkwSegmentTree<int> st;
//非递归版线段树 区间查询/修改 + 延迟标记
const int N = ((131072 << 1) + 10); //节点个数->不小于区间长度+2的最小2的正整数次幂*2+10
#define l(x) ((x)<<1) //x的左儿子
#define r(x) (((x)<<1)|1) //x的右儿子
template<typename T> struct zkwSegmentTree {
  int m, h; //底层节点数 高度
  T sum[N], add[N]; //区间和 延迟标记
  void pushdown(int rt) {
    for (int i = h, p; i; i--) { //自顶向下
      if (add[p = rt >> i]) {
        add[p] >>= 1; //add[p]为节点增加总量, 子节点增加一半
        sum[l(p)] += add[p]; add[l(p)] += add[p];
        sum[r(p)] += add[p]; add[r(p)] += add[p];
        add[p] = 0;
      }
    }
  }
  void build(int n) {
    for (m = 1, h = 0; m < n + 2; m <<= 1, h++);
    for (int i = 1; i <= n; i++) { scanf("%d", &sum[m + i]); }
    for (int i = m - 1; i; i--) { sum[i] = sum[l(i)] + sum[r(i)]; }
  }
  void update(int l, int r, T val) {
    l += m - 1, r += m + 1; int ll = l >> 1, rr = r >> 1;
    for (pushdown(l), pushdown(r); l ^ r ^ 1; l >>= 1, r >>= 1, val <<= 1) {
      if (~l & 1) { sum[l ^ 1] += val; add[l ^ 1] += val; }
      if (r & 1) { sum[r ^ 1] += val; add[r ^ 1] += val; }
    }
    for (; ll; ll >>= 1) { sum[ll] = sum[l(ll)] + sum[r(ll)]; }
    for (; rr; rr >>= 1) { sum[rr] = sum[l(rr)] + sum[r(rr)]; }
  }
  T query(int l, int r) {
    T ret = 0; l += m - 1, r += m + 1;
    for (pushdown(l), pushdown(r); l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) { ret += sum[l ^ 1]; }
      if (r & 1) { ret += sum[r ^ 1]; }
    }
    return ret;
  }
};
zkwSegmentTree<int> st;
//可持久化线段树
const int N = 100005;
const int M = 2500005;
const int INF = 0x3f3f3f3f;
int n, m, nn; //离散化后大小
#define lson l,m,ls[rt]
#define rson m+1,r,rs[rt]
template<typename T> struct SegmentTree {
  int ls[M], rs[M], root[N], tot; T data[M];
  int new_node() { return ++tot; }
  void build(int l, int r, int &rt) {
    rt = new_node(); data[rt] = 0;
    if (l == r) { return; }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
  }
  void update(int p, T val, int lst, int l, int r, int &rt) {
    rt = new_node(); ls[rt] = ls[lst]; rs[rt] = rs[lst]; data[rt] = data[lst] + val;
    if (l == r) { return; }
    int m = (l + r) >> 1;
    if (p <= m) { update(p, val, ls[lst], lson); }
    else { update(p, val, rs[lst], rson); }
  }
  //带修改区间第k小
  int tree[N], use[N];
  int lowbit(int x) { return x & -x; }
  void modify(int x, int p, T val) { //x为原数列中的下标, p为值
    for (int i = x; i <= n; i += lowbit(i)) { update(p, val, tree[i], 1, nn, tree[i]); }
  }
  T query(int x) {
    T ret = 0;
    for (int i = x; i; i -= lowbit(i)) { ret += data[ls[use[i]]]; }
    return ret;
  }
  int query(int L, int R, int k, int l, int r) {
    for (int i = L; i; i -= lowbit(i)) { use[i] = tree[i]; }
    for (int i = R; i; i -= lowbit(i)) { use[i] = tree[i]; }
    int lr = root[L], rr = root[R];
    while (l < r) {
      int m = (l + r) >> 1; T tmp = query(R) - query(L) + data[ls[rr]] - data[ls[lr]];
      if (k <= tmp) {
        r = m;
        for (int i = L; i; i -= lowbit(i)) { use[i] = ls[use[i]]; }
        for (int i = R; i; i -= lowbit(i)) { use[i] = ls[use[i]]; }
        lr = ls[lr]; rr = ls[rr];
      } else {
        l = m + 1; k -= tmp;
        for (int i = L; i; i -= lowbit(i)) { use[i] = rs[use[i]]; }
        for (int i = R; i; i -= lowbit(i)) { use[i] = rs[use[i]]; }
        lr = rs[lr]; rr = rs[rr];
      }
    }
    return l;
  }
};
SegmentTree<int> st;
//ZOJ 2112
int a[N], hs[N], l[N], r[N], k[N];
char op[N];
int main() {
  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    nn = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]); hs[++nn] = a[i];
    }
    for (int i = 0; i < m; i++) {
      scanf(" %c%d%d", &op[i], &l[i], &r[i]);
      switch (op[i]) {
        case 'Q': scanf("%d", &k[i]); break;
        case 'C': hs[++nn] = r[i]; break;
      }
    }
    sort(hs + 1, hs + nn + 1);
    nn = unique(hs + 1, hs + nn + 1) - hs - 1;
    for (int i = 1; i <= n; ++i) {
      a[i] = lower_bound(hs + 1, hs + nn + 1, a[i]) - hs;
    }
    st.tot = 0;
    st.build(1, nn, st.root[0]);
    for (int i = 1; i <= n; i++) {
      st.update(a[i], 1, st.root[i - 1], 1, nn, st.root[i]);
    }
    for (int i = 1; i <= n; i++) { st.tree[i] = st.root[0]; }
    for (int i = 0; i < m; i++) {
      switch (op[i]) {
        case 'Q':
          printf("%d\n", hs[st.query(l[i] - 1, r[i], k[i], 1, nn)]);
          break;
        case 'C':
          st.modify(l[i], a[l[i]], -1);
          a[l[i]] = lower_bound(hs + 1, hs + nn + 1, r[i]) - hs;
          st.modify(l[i], a[l[i]], 1);
          break;
      }
    }
  }
}
//实时开节点的权值线段树 (无需离散化) O(logV)
const int N = 60005;
const int M = 2500005;
const int INF = 0x3f3f3f3f;
int n, a[N];
#define lson l,m,ls[rt]
#define rson m+1,r,rs[rt]
struct SegmentTree {
  int ls[M], rs[M], cnt[M], root[N], tot;
  void init() {
    tot = 0; memset(cnt, 0, sizeof(cnt)); memset(root, 0, sizeof(root));
    memset(ls, 0, sizeof(ls)); memset(rs, 0, sizeof(rs));
  }
  int new_node() { return ++tot; }
  void update(int p, int val, int l, int r, int &rt) {
    if (!rt) { rt = new_node(); }
    if (l == r) { cnt[rt] += val; return; }
    int m = (l + r) >> 1;
    if (p <= m) { update(p, val, lson); }
    else { update(p, val, rson); }
    cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
  }
  int use[N];
  int lowbit(int x) { return x & -x; }
  //单点修改
  void modify(int x, int p, int val) {
    for (int i = x; i <= n; i += lowbit(i)) { update(p, val, 0, INF, root[i]); }
  }
  int query(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) { ret += cnt[ls[use[i]]]; }
    return ret;
  }
  //查询区间第k小
  int query(int L, int R, int k, int l, int r) {
    for (int i = L; i; i -= lowbit(i)) { use[i] = root[i]; }
    for (int i = R; i; i -= lowbit(i)) { use[i] = root[i]; }
    while (l < r) {
      int m = (l + r) >> 1, tmp = query(R) - query(L);
      if (k <= tmp) {
        r = m;
        for (int i = L; i; i -= lowbit(i)) { use[i] = ls[use[i]]; }
        for (int i = R; i; i -= lowbit(i)) { use[i] = ls[use[i]]; }
      } else {
        l = m + 1; k -= tmp;
        for (int i = L; i; i -= lowbit(i)) { use[i] = rs[use[i]]; }
        for (int i = R; i; i -= lowbit(i)) { use[i] = rs[use[i]]; }
      }
    }
    return l;
  }
} st;
//BZOJ1901 区间第k小
int main() {
  int m, l, r, k; char op[5];
  while (~scanf("%d%d", &n, &m)) {
    st.init();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      st.modify(i, a[i], 1);
    }
    while (m--) {
      scanf("%s%d%d", op, &l, &r);
      switch (op[0]) {
        case 'Q':
          scanf("%d", &k);
          printf("%d\n", st.query(l - 1, r, k, 0, INF));
          break;
        case 'C':
          st.modify(l, a[l], -1);
          a[l] = r;
          st.modify(l, a[l], 1);
          break;
      }
    }
  }
}
//平衡二叉树 常用操作
//注意这些操作适用于不允许重复值的平衡二叉树(set而非multiset)
//对于允许重复值(拥有cnt域)的实现, 只要在一些+1的地方稍作修改(改成cnt[x])即可
bool find(int v) {
  for (int x = root; x; x = ch[x][key[x] < v]) {
    if (key[x] == v) { return true; }
  }
  return false;
}
int getKth(int k) {
  int x = root;
  while (size[ch[x][0]] + 1 != k) {
    if (k < size[ch[x][0]] + 1) { x = ch[x][0]; }
    else { k -= size[ch[x][0]] + 1; x = ch[x][1]; }
  }
  return key[x];
}
int getRank(int v) {
  int ret = 0, x = root;
  while (x) {
    if (v < key[x]) { x = ch[x][0]; }
    else { ret += size[ch[x][0]] + 1; x = ch[x][1]; }
  }
  return ret;
}
int getPre(int v) {
  int x = root, y = 0;
  while (x) {
    if (v < key[x]) { x = ch[x][0]; }
    else { y = x; x = ch[x][1]; }
  }
  return y;
}
int getNext(int v) {
  int x = root, y = 0;
  while (x) {
    if (v > key[x]) { x = ch[x][1]; }
    else { y = x; x = ch[x][0]; }
  }
  return y;
}
int getMin() {
  if (size[root] == 0) { return -1; }
  int x = root;
  while (ch[x][0]) { x = ch[x][0]; }
  return x;
}
int getMax() {
  if (size[root] == 0) { return -1; }
  int x = root;
  while (ch[x][1]) { x = ch[x][1]; }
  return x;
}
//Debug遍历
void treaval(int x) {
  if (x != 0) {
    treaval(ch[x][0]);
    printf("Node%2d:lson %2d rson %2d size = %2d ,val = %2d\n", x, ch[x][0], ch[x][1], size[x], key[x]);
    treaval(ch[x][1]);
  }
}
void debug() {
  printf("root:%d\n", root);
  treaval(root);
  putchar('\n');
}
//基于旋转的Treap 允许重复值
//维护序列的有序性和堆的性质, 依靠堆值的随机化,
//将树的高度维护在期望下平衡的程度,从而实现了各种操作期望O(logn)的复杂度.
//它的性价比高在只有两种旋转(而且可以合并地写), 比红黑树和AVL短小
struct Treap {
  int tot, root;
  int ch[N][2], key[N], pt[N], cnt[N], size[N];
  void init() { tot = root = 0; pt[0] = INF; }
  void push_up(int x) { size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x]; }
  void new_node(int &x, int v) {
    x = ++tot;
    ch[x][0] = ch[x][1] = 0;
    size[x] = cnt[x] = 1;
    pt[x] = rand();
    key[x] = v;
  }
  void rotate(int &x, int f) {
    int y = ch[x][f];
    ch[x][f] = ch[y][f ^ 1];
    ch[y][f ^ 1] = x;
    push_up(x);
    push_up(y);
    x = y;
  }
  void insert(int &x, int v) {
    if (!x) { new_node(x, v); return; }
    if (key[x] == v) {
      ++cnt[x];
    } else {
      int f = key[x] < v;
      insert(ch[x][f], v);
      if (pt[ch[x][f]] < pt[x]) {
        rotate(x, f);
      }
    }
    push_up(x);
  }
  void erase(int &x, int v) {
    if (!x) { return; }
    if (key[x] == v) {
      if (cnt[x] > 1) {
        --cnt[x];
      } else {
        if (!ch[x][0] && !ch[x][1]) {
          x = 0;
        } else {
          rotate(x, pt[ch[x][0]] > pt[ch[x][1]]);
          erase(x, v);
        }
      }
    } else {
      erase(ch[x][key[x] < v], v);
    }
    push_up(x);
  }
  void insert(int v) { insert(root, v); }
  void erase(int v) { erase(root, v); }
} treap;
//Size Balanced Tree 不允许重复值
//独特的平摊时间O(1)的Maintain操作, 具有仅次于红黑树的优秀的时间效率
struct SBT {
  int root, tot;
  int ch[N][2], key[N], size[N];
  void init() { tot = root = 0; size[0] = 0; }
  void rotate(int &x, int f) {
    int y = ch[x][f];
    ch[x][f] = ch[y][f ^ 1];
    ch[y][f ^ 1] = x;
    size[y] = size[x];
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    x = y;
  }
  void maintain(int &x, int f) {
    if (size[ch[ch[x][f]][f]] > size[ch[x][f ^ 1]]) {
      rotate(x, f);
    } else if (size[ch[ch[x][f]][f ^ 1]] > size[ch[x][f ^ 1]]) {
      rotate(ch[x][f], f ^ 1); rotate(x, f);
    } else {
      return;
    }
    maintain(ch[x][0], 0);
    maintain(ch[x][1], 1);
    maintain(x, 0);
    maintain(x, 1);
  }
  void insert(int &x, int v) {
    if (!x) {
      x = ++tot;
      ch[x][0] = ch[x][1] = 0;
      size[x] = 1;
      key[x] = v;
    } else {
      ++size[x];
      insert(ch[x][key[x] < v], v);
      maintain(x, key[x] < v);
    }
  }
  int erase(int &x, int v) {
    if (!x) { return 0; }
    --size[x];
    if (key[x] == v || (key[x] > v && !ch[x][0]) || (key[x] < v && !ch[x][1])) {
      int ret = key[x];
      if (ch[x][0] && ch[x][1]) {
        key[x] = erase(ch[x][0], v + 1);
      } else {
        x = ch[x][0] + ch[x][1];
      }
      return ret;
    }
    return erase(ch[x][key[x] < v], v);
  }
  void insert(int v) { insert(root, v); }
  void erase(int v) { erase(root, v); }
} sbt;
//Splay
//可以实现很多其它平衡树无法实现的操作(如区间翻转), 既可以维护集合信息,
//也可以维护序列信息, 可以用它来做Treap的题, 也可以用它来做线段树的题.
//更重要的是, Splay可以实现split(将某棵子树从原树中分离)和merge操作(将某棵子树插入另一棵树),
//这也使得区间插入删除成为可能. 它的美中不足是常数稍大, 约是Treap的1.5～3倍, 线段树的2～5倍.
//Splay有单旋和双旋两种实现, 其中只有双旋保证了均摊O(logn)的单次操作复杂度,
//但因为很多人认为zigzag太长不好敲(大多是OI选手有此困扰), 选择了单旋.
//其实完全可以稍微损失一点常数, 合并成一个rotate函数来完成双旋.
//此外一个良好的实现通常要在序列一首一尾增加两个哨兵节点, 这样可以减少很多边界特判.
//有必要进行的扩展性说明是, 对于一棵树, 如果想要维护子树信息, 我们可以用Splay维护这棵树的括号序列(dfs序),
//这样便可以轻易split出任意子树所属的区间；而用Splay维护dfs序的结构, 就是Euler-Tour Tree.
//同样的, 如果想要维护链上信息, 可以先树链剖分然后用Splay维护每条重链,
//根据杨哲在07年国家集训队作业的计算, 因其势能分析得到的复杂度依然是单次操作均摊O(logn)复杂度;
//而类似的思想做些转化, 就变成了后面会提到的Link-Cut Tree(以下简称LCT).
//ver.1
#define keyTree (ch[ch[root][1]][0])
const int N = 200005;
const int INF = 0x3f3f3f3f;
int num[N];
struct Splay {
  int root, tot1, tot2;
  int ch[N][2], pre[N], size[N];
  int gc[N], que[N];
  int key[N], vmin[N], add[N], rev[N];
  void rotate(int x, int f) {
    int y = pre[x];
    ch[y][f ^ 1] = ch[x][f];
    pre[ch[x][f]] = y;
    pre[x] = pre[y];
    if (pre[x]) {
      ch[pre[y]][ch[pre[y]][1] == y] = x;
    }
    ch[x][f] = y;
    pre[y] = x;
    push_up(y);
  }
  void splay(int x, int goal) {
    push_down(x);
    while (pre[x] != goal) {
      int y = pre[x], z = pre[y];
      if (z == goal) {
        push_down(y);
        push_down(x);
        rotate(x, ch[y][0] == x);
      } else {
        push_down(z);
        push_down(y);
        push_down(x);
        int f = ch[z][0] == y;
        if (ch[y][f] == x) {
          rotate(x, f ^ 1);
        } else {
          rotate(y, f);
        }
        rotate(x, f);
      }
    }
    push_up(x);
    if (goal == 0) {
      root = x;
    }
  }
  void rotate_to(int k, int goal) {
    int x = root;
    push_down(x);
    while (size[ch[x][0]] != k) {
      if (k < size[ch[x][0]]) {
        x = ch[x][0];
      } else {
        k -= size[ch[x][0]] + 1;
        x = ch[x][1];
      }
      push_down(x);
    }
    splay(x, goal);
  }
  void erase(int x) {
    int fa = pre[x], head = 0, tail = 0;
    for (que[tail++] = x; head < tail; ++head) {
      gc[tot2++] = que[head];
      if (ch[que[head]][0]) {
        que[tail++] = ch[que[head]][0];
      }
      if (ch[que[head]][1]) {
        que[tail++] = ch[que[head]][1];
      }
    }
    ch[fa][ch[fa][1] == x] = 0;
    push_up(fa);
  }
  void new_node(int &x, int v, int fa) {
    if (tot2) {
      x = gc[--tot2];
    } else {
      x = ++tot1;
    }
    ch[x][0] = ch[x][1] = 0;
    pre[x] = fa;
    size[x] = 1;
    key[x] = vmin[x] = v;
    add[x] = rev[x] = 0;
  }
  void update_add(int x, int d) {
    if (x) {
      key[x] += d;
      add[x] += d;
      vmin[x] += d;
    }
  }
  void update_rev(int x) {
    if (x) {
      swap(ch[x][0], ch[x][1]);
      rev[x] ^= 1;
    }
  }
  void push_up(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    vmin[x] = min(key[x], min(vmin[ch[x][0]], vmin[ch[x][1]]));
  }
  void push_down(int x) {
    if (add[x]) {
      update_add(ch[x][0], add[x]);
      update_add(ch[x][1], add[x]);
      add[x] = 0;
    }
    if (rev[x]) {
      update_rev(ch[x][0]);
      update_rev(ch[x][1]);
      rev[x] = 0;
    }
  }
  void build(int &x, int l, int r, int f) {
    int m = l + r >> 1;
    new_node(x, num[m], f);
    if (l < m) {
      build(ch[x][0], l, m - 1, x);
    }
    if (r > m) {
      build(ch[x][1], m + 1, r, x);
    }
    push_up(x);
  }
  void init(int n) {
    root = tot1 = tot2 = 0;
    ch[0][0] = ch[0][1] = pre[0] = size[0] = 0;
    add[0] = rev[0] = 0;
    key[0] = vmin[0] = INF;
    new_node(root, -1, 0);
    new_node(ch[root][1], -1, root);
    size[root] = 2;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &num[i]);
    }
    build(keyTree, 1, n, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
  }
  void plus(int l, int r, int v) {
    rotate_to(l - 1, 0);
    rotate_to(r + 1, root);
    update_add(keyTree, v);
  }
  void reverse(int l, int r) {
    rotate_to(l - 1, 0);
    rotate_to(r + 1, root);
    update_rev(keyTree);
  }
  void revolve(int l, int r, int k) {
    k %= r - l + 1;
    if (!k) {
      return;
    }
    rotate_to(r - k, 0);
    rotate_to(r + 1, root);
    int tmp = keyTree;
    keyTree = 0;
    push_up(ch[root][1]);
    push_up(root);
    rotate_to(l - 1, 0);
    rotate_to(l, root);
    keyTree = tmp;
    pre[tmp] = ch[root][1];
    push_up(ch[root][1]);
    push_up(root);
  }
  void insert(int k, int v) {
    rotate_to(k, 0);
    rotate_to(k + 1, root);
    new_node(keyTree, v, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
  }
  void del(int k) {
    rotate_to(k - 1, 0);
    rotate_to(k + 1, root);
    erase(keyTree);
    push_up(ch[root][1]);
    push_up(root);
  }
  int query(int l, int r) {
    rotate_to(l - 1, 0);
    rotate_to(r + 1, root);
    return vmin[keyTree];
  }
} splay;
int main() {
  int n, m, x, y, v;
  char op[10];
  while (~scanf("%d", &n)) {
    splay.init(n);
    scanf("%d", &m);
    while (m--) {
      scanf("%s", op);
      switch (op[0]) {
        case 'A':
          scanf("%d%d%d", &x, &y, &v);
          splay.plus(x, y, v);
          break;
        case 'R':
          scanf("%d%d", &x, &y);
          if (op[3] == 'E') {
            splay.reverse(x, y);
          } else {
            scanf("%d", &v);
            splay.revolve(x, y, v);
          }
          break;
        case 'I':
          scanf("%d%d", &x, &v);
          splay.insert(x, v);
          break;
        case 'D':
          scanf("%d", &x);
          splay.del(x);
          break;
        case 'M':
          scanf("%d%d", &x, &y);
          printf("%d\n", splay.query(x, y));
          break;
      }
    }
  }
}
//ver.2
int k1, k2, num[N];
struct Splay {
  int root, tot, point;
  int ch[N][2], pre[N], size[N];
  int key[N], add[N], rev[N];
  bool isroot(int x) { return !pre[x] || ch[pre[x]][0] != x && ch[pre[x]][1] != x; }
  void rotate(int x) {
    int y = pre[x], f = ch[y][1] == x;
    ch[y][f] = ch[x][f ^ 1];
    pre[ch[y][f]] = y;
    if (!isroot(y)) { ch[pre[y]][ch[pre[y]][1] == y] = x; }
    pre[x] = pre[y];
    ch[x][f ^ 1] = y;
    pre[y] = x;
    push_up(y);
  }
  void splay(int x) {
    push_down(x);
    while (!isroot(x)) {
      int y = pre[x], z = pre[y];
      if (isroot(y)) {
        push_down(y);
        push_down(x);
        rotate(x);
      } else {
        push_down(z);
        push_down(y);
        push_down(x);
        rotate((ch[z][1] == y) == (ch[y][1] == x) ? y : x);
        rotate(x);
      }
    }
    push_up(x);
  }
  void new_node(int &x, int v, int fa) {
    x = ++tot;
    ch[x][0] = ch[x][1] = 0;
    pre[x] = fa;
    size[x] = 1;
    key[x] = v;
    add[x] = rev[x] = 0;
  }
  void update_add(int x, int v) {
    if (x) { key[x] += v; add[x] += v; }
  }
  void update_rev(int x) {
    if (x) { rev[x] ^= 1; swap(ch[x][0], ch[x][1]); }
  }
  void push_down(int x) {
    if (add[x]) {
      update_add(ch[x][0], add[x]);
      update_add(ch[x][1], add[x]);
      add[x] = 0;
    }
    if (rev[x]) {
      update_rev(ch[x][0]);
      update_rev(ch[x][1]);
      rev[x] = 0;
    }
  }
  void push_up(int x) { size[x] = size[ch[x][0]] + size[ch[x][1]] + 1; }
  void build(int &x, int l, int r, int fa) {
    int m = l + r >> 1;
    new_node(x, num[m], fa);
    if (l < m) { build(ch[x][0], l, m - 1, x); }
    if (r > m) { build(ch[x][1], m + 1, r, x); }
    push_up(x);
  }
  void init(int n) {
    root = tot = size[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &num[i]);
    }
    build(root, 1, n, 0);
    point = 1;
  }
  int find(int rt, int k) {
    int x = rt;
    while (size[ch[x][0]] + 1 != k) {
      push_down(x);
      if (k <= size[ch[x][0]]) {
        x = ch[x][0];
      } else {
        k -= size[ch[x][0]] + 1;
        x = ch[x][1];
      }
    }
    return x;
  }
  void split(int &x, int &y, int sz) {
    if (!sz) { y = x; x = 0; return; }
    y = find(x, sz + 1);
    splay(y);
    x = ch[y][0];
    ch[y][0] = 0;
    push_up(y);
  }
  void split3(int &x, int &y, int &z, int l, int r) {
    split(x, z, r); split(x, y, l - 1);
  }
  void join(int &x, int &y) {
    if (!x || !y) { x |= y; return; }
    x = find(x, size[x]);
    splay(x);
    ch[x][1] = y;
    pre[y] = x;
    push_up(x);
  }
  void join3(int &x, int y, int z) {
    join(y, z); join(x, y);
  }
  void evert() {
    if (point > 1) {
      int x;
      split(root, x, point - 1);
      swap(root, x);
      join(root, x);
      point = 1;
    }
  }
  void plus(int v) {
    evert();
    int x, y;
    split3(root, x, y, point, point + k2 - 1);
    update_add(x, v);
    join3(root, x, y);
  }
  void reverse() {
    evert();
    int x, y;
    split3(root, x, y, point, point + k1 - 1);
    update_rev(x);
    join3(root, x, y);
  }
  void insert(int v) {
    evert();
    int x, y;
    split(root, x, point);
    new_node(y, v, 0);
    join3(root, y, x);
  }
  void erase() {
    evert();
    int x, y;
    split3(root, x, y, point, point);
    join(root, y);
  }
  void move(int tag) {
    switch (tag) {
      case 1:
        if (--point == 0) { point = size[root]; }
        break;
      case 2:
        if (++point == size[root] + 1) { point = 1; }
        break;
    }
  }
  void query() {
    evert();
    int x, y;
    split3(root, x, y, point, point);
    printf("%d\n", key[x]);
    join3(root, x, y);
  }
} splay;
//HDU4453
int main() {
  int n, m, v, cas = 0;
  char op[10];
  while (~scanf("%d%d%d%d", &n, &m, &k1, &k2) && (n || m || k1 || k2)) {
    splay.init(n);
    printf("Case #%d:\n", ++cas);
    while (m--) {
      scanf("%s", op);
      switch (op[0]) {
        case 'a':
          scanf("%d", &v);
          splay.plus(v);
          break;
        case 'r':
          splay.reverse();
          break;
        case 'i':
          scanf("%d", &v);
          splay.insert(v);
          break;
        case 'd':
          splay.erase();
          break;
        case 'm':
          scanf("%d", &v);
          splay.move(v);
          break;
        case 'q':
          splay.query();
          break;
      }
    }
  }
}
//ver.3
const int N = 500005;
const int INF = 0x3f3f3f3f;
int n, q;
struct Splay {
  int pre[N], ch[N][2], key[N], size[N];
  int root, tot1;
  int sum[N], rev[N], same[N];
  int lx[N], rx[N], mx[N];
  int s[N], tot2; //内存池和容量
  int a[N];
  void NewNode(int &r, int father, int k) {
    if (tot2) { r = s[tot2--]; } //取的时候是tot2--,存的时候就是++tot2
    else { r = ++tot1; }
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    key[r] = k;
    sum[r] = k;
    rev[r] = same[r] = 0;
    lx[r] = rx[r] = mx[r] = k;
    size[r] = 1;
  }
  void Update_Rev(int r) {
    if (!r) { return; }
    swap(ch[r][0], ch[r][1]);
    swap(lx[r], rx[r]);
    rev[r] ^= 1;
  }
  void Update_Same(int r, int v) {
    if (!r) { return; }
    key[r] = v;
    sum[r] = v * size[r];
    lx[r] = rx[r] = mx[r] = max(v, v * size[r]);
    same[r] = 1;
  }
  void push_up(int r) {
    int lson = ch[r][0], rson = ch[r][1];
    size[r] = size[lson] + size[rson] + 1;
    sum[r] = sum[lson] + sum[rson] + key[r];
    lx[r] = max(lx[lson], sum[lson] + key[r] + max(0, lx[rson]));
    rx[r] = max(rx[rson], sum[rson] + key[r] + max(0, rx[lson]));
    mx[r] = max(0, rx[lson]) + key[r] + max(0, lx[rson]);
    mx[r] = max(mx[r], max(mx[lson], mx[rson]));
  }
  void push_down(int r) {
    if (same[r]) {
      Update_Same(ch[r][0], key[r]);
      Update_Same(ch[r][1], key[r]);
      same[r] = 0;
    }
    if (rev[r]) {
      Update_Rev(ch[r][0]);
      Update_Rev(ch[r][1]);
      rev[r] = 0;
    }
  }
  void Build(int &x, int l, int r, int father) {
    if (l > r) { return; }
    int mid = (l + r) / 2;
    NewNode(x, father, a[mid]);
    Build(ch[x][0], l, mid - 1, x);
    Build(ch[x][1], mid + 1, r, x);
    push_up(x);
  }
  void Init() {
    root = tot1 = tot2 = 0;
    ch[root][0] = ch[root][1] = size[root] = pre[root] = 0;
    same[root] = rev[root] = sum[root] = key[root] = 0;
    lx[root] = rx[root] = mx[root] = -INF;
    NewNode(root, 0, -1);
    NewNode(ch[root][1], root, -1);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    Build(ch[ch[root][1]][0], 0, n - 1, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
  }
  //旋转,0为左旋, 1为右旋
  void Rotate(int x, int kind) {
    int y = pre[x];
    push_down(y);
    push_down(x);
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if (pre[y]) { ch[pre[y]][ch[pre[y]][1] == y] = x; }
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    push_up(y);
  }
  //Splay调整, 将r结点调整到goal下面
  void Splay(int r, int goal) {
    push_down(r);
    while (pre[r] != goal) {
      if (pre[pre[r]] == goal) {
        push_down(pre[r]);
        push_down(r);
        Rotate(r, ch[pre[r]][0] == r);
      } else {
        push_down(pre[pre[r]]);
        push_down(pre[r]);
        push_down(r);
        int y = pre[r];
        int kind = ch[pre[y]][0] == y;
        if (ch[y][kind] == r) {
          Rotate(r, !kind);
          Rotate(r, kind);
        } else {
          Rotate(y, kind);
          Rotate(r, kind);
        }
      }
    }
    push_up(r);
    if (goal == 0) { root = r; }
  }
  int Get_kth(int r, int k) {
    push_down(r);
    int t = size[ch[r][0]] + 1;
    if (t == k) { return r; }
    if (t > k) { return Get_kth(ch[r][0], k); }
    else { return Get_kth(ch[r][1], k - t); }
  }
  //在第pos个数后面插入tot个数
  void Insert(int pos, int tot) {
    for (int i = 0; i < tot; i++) { scanf("%d", &a[i]); }
    Splay(Get_kth(root, pos + 1), 0);
    Splay(Get_kth(root, pos + 2), root);
    Build(ch[ch[root][1]][0], 0, tot - 1, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
  }
  //删除子树
  void erase(int r) {
    if (!r) { return; }
    s[++tot2] = r;
    erase(ch[r][0]);
    erase(ch[r][1]);
  }
  //从第pos个数开始连续删除tot个数
  void Delete(int pos, int tot) {
    Splay(Get_kth(root, pos), 0);
    Splay(Get_kth(root, pos + tot + 1), root);
    erase(ch[ch[root][1]][0]);
    pre[ch[ch[root][1]][0]] = 0;
    ch[ch[root][1]][0] = 0;
    push_up(ch[root][1]);
    push_up(root);
  }
  //将从第pos个数开始的连续的tot个数修改为c
  void Make_Same(int pos, int tot, int c) {
    Splay(Get_kth(root, pos), 0);
    Splay(Get_kth(root, pos + tot + 1), root);
    Update_Same(ch[ch[root][1]][0], c);
    push_up(ch[root][1]);
    push_up(root);
  }
  //将第pos个数开始的连续tot个数进行反转
  void Reverse(int pos, int tot) {
    Splay(Get_kth(root, pos), 0);
    Splay(Get_kth(root, pos + tot + 1), root);
    Update_Rev(ch[ch[root][1]][0]);
    push_up(ch[root][1]);
    push_up(root);
  }
  //得到第pos个数开始的tot个数的和
  int Get_Sum(int pos, int tot) {
    Splay(Get_kth(root, pos), 0);
    Splay(Get_kth(root, pos + tot + 1), root);
    return sum[ch[ch[root][1]][0]];
  }
  //得到第pos个数开始的tot个数中最大的子段和
  int Get_MaxSum(int pos, int tot) {
    Splay(Get_kth(root, pos), 0);
    Splay(Get_kth(root, pos + tot + 1), root);
    return mx[ch[ch[root][1]][0]];
  }
  void InOrder(int r) {
    if (!r) { return; }
    push_down(r);
    InOrder(ch[r][0]);
    printf("%d ", key[r]);
    InOrder(ch[r][1]);
  }
} splay;
int main() {
  while (scanf("%d%d", &n, &q) == 2) {
    splay.Init();
    char op[20];
    int x, y, z;
    while (q--) {
      scanf("%s", op);
      if (strcmp(op, "INSERT") == 0) {
        scanf("%d%d", &x, &y);
        splay.Insert(x, y);
      } else if (strcmp(op, "DELETE") == 0) {
        scanf("%d%d", &x, &y);
        splay.Delete(x, y);
      } else if (strcmp(op, "MAKE-SAME") == 0) {
        scanf("%d%d%d", &x, &y, &z);
        splay.Make_Same(x, y, z);
      } else if (strcmp(op, "REVERSE") == 0) {
        scanf("%d%d", &x, &y);
        splay.Reverse(x, y);
      } else if (strcmp(op, "GET-SUM") == 0) {
        scanf("%d%d", &x, &y);
        printf("%d\n", splay.Get_Sum(x, y));
      } else if (strcmp(op, "MAX-SUM") == 0) {
        printf("%d\n", splay.Get_MaxSum(1, splay.size[root] - 2));
      }
    }
  }
}
//Link-Cut Tree 动态树
//维护多棵树(森林)的形态, 并在O(logn)的时间复杂度内维护链上信息; 但LCT处理子树信息将会非常麻烦.
//它的核心操作是access函数, 可以把某个节点到根的路径上所有点按照深度用Splay维护起来,
//从而结合evert函数(换跟操作)和splay操作可以实现对链的信息维护.
//LCT几乎可以实现除维护子树信息外以上的所有操作, 同时有着优越的理论复杂度,
//但实际常数较大, 很多不改变树形态的题用O(logn)的LCT并不比O(log^2n)的树链剖分套线段树更优越
struct LCT {
  int ch[N][2], pre[N], key[N], rev[N];
  int add[N], vmax[N];
  bool isroot(int x) { return !pre[x] || ch[pre[x]][0] != x && ch[pre[x]][1] != x; }
  void rotate(int x) {
    int y = pre[x], f = ch[y][1] == x;
    ch[y][f] = ch[x][f ^ 1];
    pre[ch[y][f]] = y;
    if (!isroot(y)) { ch[pre[y]][ch[pre[y]][1] == y] = x; }
    pre[x] = pre[y];
    ch[x][f ^ 1] = y;
    pre[y] = x;
    push_up(y);
  }
  void splay(int x) {
    push_down(x);
    while (!isroot(x)) {
      int y = pre[x], z = pre[y];
      if (isroot(y)) {
        push_down(y);
        push_down(x);
        rotate(x);
      } else {
        push_down(z);
        push_down(y);
        push_down(x);
        rotate((ch[z][1] == y) == (ch[y][1] == x) ? y : x);
        rotate(x);
      }
    }
    push_up(x);
  }
  int access(int x) {
    int y = 0;
    for (; x; x = pre[x]) {
      splay(x);
      ch[x][1] = y;
      push_up(x);
      y = x;
    }
    return y;
  }
  void evert(int x) {
    rev[access(x)] ^= 1;
    splay(x);
  }
  void push_up(int x) { vmax[x] = max(max(vmax[ch[x][0]], vmax[ch[x][1]]), key[x]); }
  void push_down(int x) {
    if (add[x]) {
      key[x] += add[x];
      if (ch[x][0]) {
        add[ch[x][0]] += add[x];
        vmax[ch[x][0]] += add[x];
      }
      if (ch[x][1]) {
        add[ch[x][1]] += add[x];
        vmax[ch[x][1]] += add[x];
      }
      add[x] = 0;
    }
    if (rev[x]) {
      if (ch[x][0]) { rev[ch[x][0]] ^= 1; }
      if (ch[x][1]) { rev[ch[x][1]] ^= 1; }
      swap(ch[x][0], ch[x][1]);
      rev[x] = 0;
    }
  }
  int find_root(int x) {
    while (pre[x]) { x = pre[x]; }
    return x;
  }
  //如果u,v不在同一颗子树中,则通过在u,v之间连边的方式,连接这两颗子树
  void link(int u, int v) {
    if (find_root(u) == find_root(v)) { puts("-1"); return; }
    evert(u);
    pre[u] = v;
  }
  //如果u,v在同一颗子树中,且u!=v,则将u视为这颗子树的根以后,切断v与其父亲结点的连接
  void cut(int u, int v) {
    if (u == v || find_root(u) != find_root(v)) { puts("-1"); return; }
    evert(u);
    access(v);
    splay(v);
    pre[ch[v][0]] = 0;
    ch[v][0] = 0;
    push_up(v);
  }
  //如果u,v在同一颗子树中,则将u,v之间路径上所有点的点权增加w
  void update(int u, int v, int w) {
    if (find_root(u) != find_root(v)) { puts("-1"); return; }
    evert(u);
    access(v);
    splay(v);
    add[v] += w;
    vmax[v] += w;
    push_down(v);
  }
  //如果u,v在同一颗子树中, 返回u,v之间路径上点权的最大值
  void query(int u, int v) {
    if (find_root(u) != find_root(v)) { puts("-1"); return; }
    evert(u);
    access(v);
    splay(v);
    printf("%d\n", vmax[v]);
  }
  struct graph {
    int head[N], to[N << 1], next[N << 1];
    int tot;
    void init() { tot = 0; memset(head, 0xff, sizeof(head)); }
    void add(int u, int v) {
      to[tot] = v;
      next[tot] = head[u];
      head[u] = tot++;
    }
  } g;
  void dfs(int u, int fa) {
    for (int i = g.head[u]; ~i; i = g.next[i]) {
      int v = g.to[i];
      if (v != fa) {
        dfs(v, u);
        pre[v] = u;
      }
    }
  }
  void init(int n) {
    int m, x, y;
    g.init();
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &x, &y);
      g.add(x, y); g.add(y, x);
    }
    memset(ch, 0, sizeof(ch));
    memset(pre, 0, sizeof(pre));
    memset(rev, 0, sizeof(rev));
    memset(add, 0, sizeof(add));
    vmax[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &key[i]);
      vmax[i] = key[i];
    }
    dfs(1, 0);
  }
} lct;
//HDU4010
int main() {
  int n, q, op, x, y, w;
  while (~scanf("%d", &n)) {
    lct.init(n);
    scanf("%d", &q);
    while (q--) {
      scanf("%d", &op);
      switch (op) {
        case 1:
          scanf("%d%d", &x, &y);
          lct.link(x, y);
          break;
        case 2:
          scanf("%d%d", &x, &y);
          lct.cut(x, y);
          break;
        case 3:
          scanf("%d%d%d", &w, &x, &y);
          lct.update(x, y, w);
          break;
        case 4:
          scanf("%d%d", &x, &y);
          lct.query(x, y);
          break;
      }
    }
    putchar('\n');
  }
}
//不基于旋转的Treap
int num[N];
struct Treap {
  int tot, root;
  int ch[N][2], pt[N], size[N];
  int key[N], vmin[N], add[N], rev[N];
  void init() { tot = 0; }
  void new_node(int &x, int v) {
    x = ++tot;
    ch[x][0] = ch[x][1] = 0;
    size[x] = 1;
    pt[x] = rand();
    key[x] = vmin[x] = v;
    add[x] = rev[x] = 0;
  }
  void merge(int &p, int x, int y) {
    if (!x || !y) { p = x | y; return; }
    if (pt[x] < pt[y]) {
      push_down(x);
      merge(ch[x][1], ch[x][1], y);
      p = x;
    } else {
      push_down(y);
      merge(ch[y][0], x, ch[y][0]);
      p = y;
    }
    push_up(p);
  }
  void split(int p, int sz, int &x, int &y) {
    if (!sz) { x = 0; y = p; return; }
    push_down(p);
    if (size[ch[p][0]] >= sz) {
      y = p;
      split(ch[p][0], sz, x, ch[y][0]);
    } else {
      x = p;
      split(ch[p][1], sz - size[ch[p][0]] - 1, ch[x][1], y);
    }
    push_up(p);
  }
  void update_add(int x, int v) {
    if (x) { key[x] += v; add[x] += v; vmin[x] += v; }
  }
  void update_rev(int x) {
    if (x) { swap(ch[x][0], ch[x][1]); rev[x] ^= 1; }
  }
  void push_down(int x) {
    if (add[x]) {
      update_add(ch[x][0], add[x]);
      update_add(ch[x][1], add[x]);
      add[x] = 0;
    }
    if (rev[x]) {
      update_rev(ch[x][0]);
      update_rev(ch[x][1]);
      rev[x] = 0;
    }
  }
  void push_up(int x) {
    size[x] = 1;
    vmin[x] = key[x];
    if (ch[x][0]) {
      size[x] += size[ch[x][0]];
      vmin[x] = min(vmin[x], vmin[ch[x][0]]);
    }
    if (ch[x][1]) {
      size[x] += size[ch[x][1]];
      vmin[x] = min(vmin[x], vmin[ch[x][1]]);
    }
  }
  int build(int &x, int l, int r) {
    int m = l + r >> 1;
    new_node(x, num[m]);
    if (l < m) { build(ch[x][0], l, m - 1); }
    if (r > m) { build(ch[x][1], m + 1, r); }
    push_up(x);
  }
  void plus(int l, int r, int v) {
    int x, y;
    split(root, l - 1, root, x);
    split(x, r - l + 1, x, y);
    update_add(x, v);
    merge(x, x, y);
    merge(root, root, x);
  }
  void reverse(int l, int r) {
    int x, y;
    split(root, l - 1, root, x);
    split(x, r - l + 1, x, y);
    update_rev(x);
    merge(x, x, y);
    merge(root, root, x);
  }
  void revolve(int l, int r, int k) {
    int x, y, p, q;
    k %= r - l + 1;
    if (!k) { return; }
    split(root, l - 1, root, x);
    split(x, r - l + 1, x, y);
    split(x, r - l + 1 - k, p, q);
    merge(x, q, p);
    merge(x, x, y);
    merge(root, root, x);
  }
  void insert(int k, int v) {
    int x, y;
    new_node(x, v);
    split(root, k, root, y);
    merge(root, root, x);
    merge(root, root, y);
  }
  void erase(int k) {
    int x, y;
    split(root, k - 1, root, x);
    split(x, 1, x, y);
    merge(root, root, y);
  }
  int query(int l, int r) {
    int x, y, ret;
    split(root, l - 1, root, x);
    split(x, r - l + 1, x, y);
    ret = vmin[x];
    merge(x, x, y);
    merge(root, root, x);
    return ret;
  }
} treap;
//POJ3580
int main() {
  int n, m, x, y, v;
  char op[10];
  while (~scanf("%d", &n)) {
    treap.init();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &num[i]);
    }
    treap.build(treap.root, 1, n);
    scanf("%d", &m);
    while (m--) {
      scanf("%s", op);
      switch (op[0]) {
        case 'A':
          scanf("%d%d%d", &x, &y, &v);
          treap.plus(x, y, v);
          break;
        case 'R':
          scanf("%d%d", &x, &y);
          if (op[3] == 'E') {
            treap.reverse(x, y);
          } else {
            scanf("%d", &v);
            treap.revolve(x, y, v);
          }
          break;
        case 'I':
          scanf("%d%d", &x, &v);
          treap.insert(x, v);
          break;
        case 'D':
          scanf("%d", &x);
          treap.erase(x);
          break;
        case 'M':
          scanf("%d%d", &x, &y);
          printf("%d\n", treap.query(x, y));
          break;
      }
    }
  }
}
//可持久化Treap
const int N = 50005;
const int M = 5000005;
int root[N], vs, d;
struct Treap {
  int tot;
  int ch[M][2], size[M];
  char key[M];
  bool hey(int x, int y) { return (ll)rand() * (size[x] + size[y]) < (ll)size[x] * RAND_MAX; }
  void init() { tot = 0; }
  void new_node(int &x, char v) {
    x = ++tot;
    ch[x][0] = ch[x][1] = 0;
    size[x] = 1;
    key[x] = v;
  }
  void copy_node(int &x, int y) {
    if (!y) { x = 0; return; }
    x = ++tot;
    ch[x][0] = ch[y][0];
    ch[x][1] = ch[y][1];
    size[x] = size[y];
    key[x] = key[y];
  }
  void merge(int &p, int x, int y) {
    if (!x || !y) {
      p = 0;
      if (x) { copy_node(p, x); }
      if (y) { copy_node(p, y); }
      return;
    }
    if (hey(x, y)) {
      copy_node(p, x);
      merge(ch[p][1], ch[x][1], y);
    } else {
      copy_node(p, y);
      merge(ch[p][0], x, ch[y][0]);
    }
    push_up(p);
  }
  void split(int p, int sz, int &x, int &y) {
    if (!sz) { x = 0; copy_node(y, p); return; }
    if (size[ch[p][0]] >= sz) {
      copy_node(y, p);
      split(ch[p][0], sz, x, ch[y][0]);
      push_up(y);
    } else {
      copy_node(x, p);
      split(ch[p][1], sz - size[ch[p][0]] - 1, ch[x][1], y);
      push_up(x);
    }
  }
  void push_up(int x) {
    size[x] = 1;
    if (ch[x][0]) { size[x] += size[ch[x][0]]; }
    if (ch[x][1]) { size[x] += size[ch[x][1]]; }
  }
  void build(char str[], int &x, int l, int r) {
    int m = l + r >> 1;
    new_node(x, str[m]);
    if (l < m) { build(str, ch[x][0], l, m - 1); }
    if (r > m) { build(str, ch[x][1], m + 1, r); }
    push_up(x);
  }
  void insert(int k, char str[]) {
    int x, y, z;
    build(str, x, 0, strlen(str) - 1);
    split(root[vs], k, y, z);
    merge(y, y, x);
    merge(root[++vs], y, z);
  }
  void erase(int k, int sz) {
    int x, y, z;
    split(root[vs], k - 1, x, y);
    split(y, sz, y, z);
    merge(root[++vs], x, z);
  }
  void output(int x) {
    if (ch[x][0]) { output(ch[x][0]); }
    putchar(key[x]);
    d += key[x] == 'c';
    if (ch[x][1]) { output(ch[x][1]); }
  }
  void output(int v, int k, int sz) {
    int x, y, z;
    split(root[v], k - 1, x, y);
    split(y, sz, y, z);
    output(y);
    putchar('\n');
  }
} treap;
//UVa12538
int main() {
  int n, op, p, c, v;
  char s[105];
  treap.init();
  vs = d = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &op);
    switch (op) {
      case 1:
        scanf("%d%s", &p, s);
        treap.insert(p - d, s);
        break;
      case 2:
        scanf("%d%d", &p, &c);
        treap.erase(p - d, c - d);
        break;
      case 3:
        scanf("%d%d%d", &v, &p, &c);
        treap.output(v - d, p - d, c - d);
        break;
    }
  }
}
//树链剖分
//轻重链剖分将一棵树划分成至多logn条重链和若干条轻边, 满足每个节点属于一条重链,
//从而将树上路径修改转化为至多logn次线性修改, 非常利于套用树状数组、线段树等各类数据结构.
//树链剖分的常数很小, 且因着树链剖分的性质, 我们发现越是退化的树(极端情况下成为一条链),
//树链剖分的效果越是好(极端情况下甚至是O(1)级的, 因为只有很少的重链),
//以至于一些不涉及形态修改的树上路径维护题目, 可以用树链剖分套线段树以O(logn^2)的单次操作复杂度水过,
//且实际表现不输于单次操作O(logn)但常数很大的LCT.
//常见轻重链剖分的初始化实现是两次dfs的, 但dfs有两个问题,
//一是递归调用使得时间稍慢, 二是有些题目有爆栈风险; 所以我抄了bfs实现的很好用的交大板.
//需要稍作说明的是, 对于点权修改直接维护即可, 对于边权修改, 常规做法是选定一个根,
//将边权下垂到深度更大的节点上; 换言之, 每个点储存的权值是它与它的父节点之间的边权, 根节点上没有权值.
int top[N];    //top[p]表示编号为p的路径的顶端节点
int len[N];    //len[p]表示路径p的长度
int belong[N]; //belong[v]表示节点v所属的路径编号
int idx[N];    //idx[v]表示节点v在其路径中的编号, 按深度由深到浅依次标号
int dep[N];    //dep[v]表示节点v的深度
int fa[N];     //fa[v]表示节点v的父亲节点
int size[N];   //size[v]表示以节点v为根的子树的节点个数
int que[N];
bool vis[N];
int n, cnt;       //n是点数, 标号从1到n
void split() {
  memset(dep, 0xff, sizeof(dep));
  int l = 0, r = 0;
  que[++r] = 1; dep[1] = 0; fa[1] = -1;
  while (l < r) {
    int u = que[++l];
    vis[u] = false;
    for (int i = g.head[u]; ~i; i = g.next[i]) {
      int v = g.to[i];
      if (!~dep[v]) { que[++r] = v; dep[v] = dep[u] + 1; fa[v] = u; }
    }
  }
  cnt = 0;
  for (int i = n; i > 0; --i) {
    int u = que[i], p = -1;
    size[u] = 1;
    for (int j = g.head[u]; ~j; j = g.next[j]) {
      int v = g.to[j];
      if (vis[v]) {
        size[u] += size[v];
        if (!~p || size[v] > size[p]) { p = v; }
      }
    }
    if (!~p) {
      idx[u] = len[++cnt] = 1;
      belong[u] = cnt;
      top[cnt] = u;
    } else {
      belong[u] = belong[p];
      idx[u] = ++len[belong[u]];
      top[belong[u]] = u;
    }
    vis[u] = true;
  }
}
int fi[N], cid[N], rank[N];
void getcid() {
  fi[1] = 1;
  for (int i = 2; i <= cnt; ++i) { fi[i] = fi[i - 1] + len[i - 1]; }
  for (int i = 1; i <= n; ++i) {
    cid[i] = fi[belong[i]] + len[belong[i]] - idx[i];
    rank[cid[i]] = i;
  }
}
// 路径修改和查询依下面修改
int query(int x, int y) {
  int ret = 0;
  while (belong[x] != belong[y]) {
    if (dep[top[belong[x]]] < dep[top[belong[y]]]) { swap(x, y); }
    ret = max(ret, query(cid[top[belong[x]]], cid[x], 1, n, 1));
    x = fa[top[belong[x]]];
  }
  if (dep[x] > dep[y]) { swap(x, y); }
  ret = max(ret, query(cid[x], cid[y], 1, n, 1));
  /*边权如下
  if(x!=y)
      ret=max(ret,query(cid[x]+1,cid[y],1,n,1));
  */
  return ret;
}
//第一次dfs和倍增LCA的dfs部分几乎一致; 所以稍作修改就可以无缝衔接LCA.
//第二次dfs对节点的新位置进行了标号(对应bfs的getcid函数),
//我们可以发现无论它以怎样的顺序进行dfs(先dfs重儿子再dfs其它子节点), 得到的依旧是这棵树的一个dfs序.
//换句话说, 这里处理出的剖分标号, 同时也是dfs序标号.
//我们知道每棵子树的节点在dfs序中都是连续的一段,
//这样我们就可以同时维护树上路径信息(剖分部分复杂度O(logn))和子树信息(剖分部分复杂度O(1))了.
//BZOJ3083 树链剖分套线段树
const int N = 100005;
const int maxd = 18;
const int INF = 0x7fffffff;
struct graph {
  int head[N], tot;
  int to[N << 1], next[N << 1];
  void init() {
    tot = 0; memset(head, 0xff, sizeof(head));
  }
  void add(int u, int v) {
    to[tot] = v; next[tot] = head[u]; head[u] = tot++;
  }
} g;
int top[N], son[N];
int dep[N], fa[N][maxd], size[N];
int cid[N], rank[N], cnt;
void dfs1(int u) {
  size[u] = 1; son[u] = -1;
  for (int i = 1; i < maxd; ++i) { fa[u][i] = fa[fa[u][i - 1]][i - 1]; }
  for (int i = g.head[u]; ~i; i = g.next[i]) {
    int v = g.to[i];
    if (v != fa[u][0]) {
      dep[v] = dep[u] + 1; fa[v][0] = u;
      dfs1(v);
      size[u] += size[v];
      if (!~son[u] || size[v] > size[son[u]]) { son[u] = v; }
    }
  }
}
void dfs2(int u, int tp) {
  top[u] = tp; cid[u] = ++cnt; rank[cid[u]] = u;
  if (~son[u]) { dfs2(son[u], tp); }
  for (int i = g.head[u]; ~i; i = g.next[i]) {
    int v = g.to[i];
    if (v != son[u] && v != fa[u][0]) { dfs2(v, v); }
  }
}
void split() {
  dfs1(1); cnt = 0; dfs2(1, 1);
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) { swap(u, v); }
  int k = dep[u] - dep[v];
  for (int i = 0; i < maxd; ++i) {
    if ((1 << i)&k) { u = fa[u][i]; }
  }
  if (u == v) { return u; }
  for (int i = maxd - 1; i >= 0; --i) {
    if (fa[u][i] != fa[v][i]) { u = fa[u][i]; v = fa[v][i]; }
  }
  return fa[u][0];
}
int n, root, a[N];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int vmin[N << 2], col[N << 2];
void push_up(int rt) {
  vmin[rt] = min(vmin[rt << 1], vmin[rt << 1 | 1]);
}
void push_down(int rt) {
  if (col[rt]) {
    col[rt << 1] = col[rt << 1 | 1] = vmin[rt << 1] = vmin[rt << 1 | 1] = col[rt];
    col[rt] = 0;
  }
}
void build(int l, int r, int rt) {
  col[rt] = 0;
  if (l == r) { vmin[rt] = a[rank[l]]; return; }
  int m = l + r >> 1;
  build(lson);
  build(rson);
  push_up(rt);
}
void update(int L, int R, int val, int l, int r, int rt) {
  if (L <= l && r <= R) { col[rt] = vmin[rt] = val; return; }
  push_down(rt);
  int m = l + r >> 1;
  if (L <= m) { update(L, R, val, lson); }
  if (m < R) { update(L, R, val, rson); }
  push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) { return vmin[rt]; }
  push_down(rt);
  int m = l + r >> 1;
  int ret = INF;
  if (L <= m) { ret = min(ret, query(L, R, lson)); }
  if (m < R) { ret = min(ret, query(L, R, rson)); }
  return ret;
}
void modify(int x, int y, int d) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) { swap(x, y); }
    update(cid[top[x]], cid[x], d, 1, n, 1);
    x = fa[top[x]][0];
  }
  if (dep[x] > dep[y]) { swap(x, y); }
  update(cid[x], cid[y], d, 1, n, 1);
}
int query(int rt) {
  if (rt == root) { return query(1, n, 1, n, 1); }
  int pre = lca(root, rt);
  if (pre != rt) { return query(cid[rt], cid[rt] + size[rt] - 1, 1, n, 1); }
  int depth = dep[root] - dep[rt] - 1, tmp = root;
  for (int i = maxd - 1; i >= 0; --i) {
    if (depth & (1 << i)) { tmp = fa[tmp][i]; }
  }
  return min(query(1, cid[tmp] - 1, 1, n, 1), query(cid[tmp] + size[tmp], n, 1, n, 1));
}
int main() {
  int m, u, v, opt, id;
  while (~scanf("%d%d", &n, &m)) {
    g.init();
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &u, &v);
      g.add(u, v); g.add(v, u);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    split();
    build(1, n, 1);
    scanf("%d", &root);
    while (m--) {
      scanf("%d", &opt);
      switch (opt) {
        case 1: scanf("%d", &root); break;
        case 2: scanf("%d%d%d", &u, &v, &id); modify(u, v, id); break;
        case 3: scanf("%d", &id); printf("%d\n", query(id)); break;
      }
    }
  }
}
//KD-Tree
//用来维护多维第K近点对距离一类的信息.
//在每一维上依次用一个超平面进行空间划分, 将点集比较均匀地分割在各个区域内,
//结构上则是一棵二叉树, 且与线段树的形态和构造方法都有些类似.
//经过改造的KD-Tree一般可以做到O(logn)的单点插入, 以及O(n^(1-1/D))的询问操作, 其中D是维数, 可见维数越大KD-Tree越慢
//询问距离一个点的前K近点一般需要用一个优先队列进行询问时的维护
//HDU4347 O(n) 不支持点的插入和删除
const int N = 50005;
const int INF = ~0U >> 1;
const int DIM = 5;
#define lson l,m-1,dep+1
#define rson m+1,r,dep+1
int cur, K;
struct point {
  int x[DIM];
  bool operator<(const point &oth)const { return x[cur] < oth.x[cur]; }
  void output() {
    for (int i = 0; i < K; ++i) {
      printf("%d%c", x[i], i < K - 1 ? ' ' : '\n');
    }
  }
} vec[N], origin[N], pt, ans[10];
inline int sqr(int x) { return x * x; }
int dist(const point &a, const point &b) {
  int ret = 0;
  for (int i = 0; i < K; ++i) { ret += sqr(a.x[i] - b.x[i]); }
  return ret;
}
void build(int l, int r, int dep = 0) {
  if (l >= r) { return; }
  int m = l + r >> 1;
  cur = dep % K;
  nth_element(vec + l, vec + m, vec + r + 1);
  build(lson);
  build(rson);
}
priority_queue<pair<int, point>> pq;
void query(const point &x, int k, int l, int r, int dep = 0) {
  if (l > r) { return; }
  int m = l + r >> 1, cur = dep % K;
  pair<int, point> tmp(dist(x, vec[m]), vec[m]);
  if (pq.size() < k) {
    pq.push(tmp);
  } else if (pq.top().first > tmp.first) {
    pq.pop(); pq.push(tmp);
  }
  if (x.x[cur] < vec[m].x[cur]) {
    query(x, k, lson);
    if (pq.top().first > sqr(x.x[cur] - vec[m].x[cur])) { query(x, k, rson); }
  } else {
    query(x, k, rson);
    if (pq.top().first > sqr(x.x[cur] - vec[m].x[cur])) { query(x, k, lson); }
  }
}
int main() {
  int n, t, m;
  while (~scanf("%d%d", &n, &K)) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < K; ++j) {
        scanf("%d", &origin[i].x[j]);
      }
      vec[i] = origin[i];
    }
    build(1, n);
    scanf("%d", &t);
    while (t--) {
      for (int i = 0; i < K; ++i) {
        scanf("%d", &pt.x[i]);
      }
      scanf("%d", &m);
      query(pt, m, 1, n);
      for (int i = 0; i < m; ++i) {
        ans[i] = pq.top().second; pq.pop();
      }
      printf("the closest %d points are:\n", m);
      for (int i = m - 1; i >= 0; --i) { ans[i].output(); }
    }
  }
}
//支持点的插入和删除
#define lson kdt[rt].ls,dep+1
#define rson kdt[rt].rs,dep+1
struct kdnode {
  int ls, rs, x[DIM]; bool flag; //删点标记
} kdt[N];
inline ll sqr(int x) { return (ll)x * x; }
ll dist(const kdnode &a, const kdnode &b) {
  ll ret = 0;
  for (int i = 0; i < DIM; ++i) { ret += sqr(a.x[i] - b.x[i]); }
  return ret;
}
int root, tot;
void init() { tot = 0; root = -1; }
int add(int pt[]) {
  kdt[tot].flag = false;
  kdt[tot].ls = kdt[tot].rs = -1;
  for (int i = 0; i < DIM; ++i) { kdt[tot].x[i] = pt[i]; }
  return tot++;
}
void insert(int pt[], int rt, int dep = 0) {
  dep %= DIM;
  if (pt[dep] < kdt[rt].x[dep]) {
    if (!~kdt[rt].ls) { kdt[rt].ls = add(pt); }
    else { insert(pt, lson); }
  } else {
    if (!~kdt[rt].rs) { kdt[rt].rs = add(pt); }
    else { insert(pt, rson); }
  }
}
//求最近点距离
ll query(const kdnode &pt, int rt, int dep = 0) {
  if (!~rt) { return INF; }
  dep %= DIM;
  ll ret = INF, tmp = sqr(kdt[rt].x[dep] - pt.x[dep]);
  if (!kdt[rt].flag) { ret = dist(kdt[rt], pt); }
  if (pt.x[dep] <= kdt[rt].x[dep]) {
    ret = min(ret, query(pt, lson));
    if (tmp < ret) { ret = min(ret, query(pt, rson)); }
  }
  if (pt.x[dep] >= kdt[rt].x[dep]) {
    ret = min(ret, query(pt, rson));
    if (tmp < ret) { ret = min(ret, query(pt, lson)); }
  }
  return ret;
}
//查询区间内有多少个点
int query(int pt1[], int pt2[], int rt, int dep = 0) {
  if (!~rt) { return 0; }
  dep %= DIM;
  int ret = 0, cur;
  for (cur = 0; cur < DIM; ++cur) {
    if (kdt[rt].x[cur] < pt1[cur] || kdt[rt].x[cur] > pt2[cur]) { break; }
  }
  if (cur == DIM) { ++ret; }
  if (pt2[dep] < kdt[rt].x[dep]) {
    ret += query(pt1, pt2, lson);
  } else if (pt1[dep] >= kdt[rt].x[dep]) {
    ret += query(pt1, pt2, rson);
  } else {
    ret += query(pt1, pt2, lson);
    ret += query(pt1, pt2, rson);
  }
  return ret;
}
//划分树
int part[20][N]; //表示每层每个位置的值
int sorted[N]; //已经排序好的数
int tol[20][N]; //tol[p][i] 表示第i层从1到i有数分入左边
void build(int l, int r, int dep) {
  if (l == r) { return; }
  int m = l + r >> 1, cnt = m - l + 1; //表示等于中间值而且被分入左边的个数
  for (int i = l; i <= r; ++i) {
    if (part[dep][i] < sorted[m]) { --cnt; }
  }
  int lpos = l, rpos = m + 1;
  for (int i = l; i <= r; ++i) {
    if (part[dep][i] < sorted[m]) {
      part[dep + 1][lpos++] = part[dep][i];
    } else if (part[dep][i] == sorted[m] && cnt > 0) {
      part[dep + 1][lpos++] = part[dep][i];
      --cnt;
    } else {
      part[dep + 1][rpos++] = part[dep][i];
    }
    tol[dep][i] = tol[dep][l - 1] + lpos - l;
  }
  build(l, m, dep + 1);
  build(m + 1, r, dep + 1);
}
//离线查询区间第k大的数, [L, R]是要查询的小区间, [l, r]是大区间
int query(int L, int R, int k, int l, int r, int dep) {
  if (L == R) { return part[dep][L]; }
  int m = l + r >> 1, cnt = tol[dep][R] - tol[dep][L - 1];
  if (cnt >= k) {
    int tl = l + tol[dep][L - 1] - tol[dep][l - 1], tr = tl + cnt - 1;
    return query(tl, tr, k, l, m, dep + 1);
  } else {
    int tr = R + tol[dep][r] - tol[dep][R], tl = tr - (R - L - cnt);
    return query(tl, tr, k - cnt, m + 1, r, dep + 1);
  }
}
//左偏树
//可并堆的一种实现, 可以在O(logn)的时间内实现堆的push、pop和两个堆的合并操作, 以及O(1)时间的取堆顶操作
int val[N], ls[N], rs[N], dep[N], fa[N];
void init(int n) {
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &val[i]); ls[i] = rs[i] = dep[i] = 0; fa[i] = i;
  }
}
int find(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }
int merge(int x, int y) {
  if (!x || !y) { return x | y; }
  if (val[x] < val[y]) { swap(x, y); }
  rs[x] = merge(rs[x], y); fa[rs[x]] = x;
  if (dep[ls[x]] < dep[rs[x]]) { swap(ls[x], rs[x]); }
  dep[x] = dep[rs[x]] + 1;
  return x;
}
int push(int x, int y) { return merge(x, y); }
int pop(int x) {
  int a = ls[x], b = rs[x];
  ls[x] = rs[x] = dep[x] = 0;
  fa[x] = x; fa[a] = a; fa[b] = b;
  return merge(a, b);
}
//POJ 2201
int main() {
  int n, m, x, y;
  while (~scanf("%d", &n)) {
    init(n);
    scanf("%d", &m);
    while (m--) {
      scanf("%d%d", &x, &y);
      int a = find(x), b = find(y);
      if (a == b) {
        puts("-1");
      } else {
        val[a] >>= 1; val[b] >>= 1;
        a = push(pop(a), a); b = push(pop(b), b);
        printf("%d\n", val[merge(a, b)]);
      }
    }
  }
}
//笛卡尔树
//考虑一个键值对的序列, 当键与键, 值与值之间互不相同时, 它们可以唯一地构成这样一棵二叉树：
//key在中序遍历时呈升序, 满足二叉查找树性质; 父节点的value大于子节点的value, 满足堆的性质.
//一个键值对序列的笛卡儿树可以O(n)时间内构造出来
//POJ2201
const int N = 50005;
int idx[N], n;
struct Cartesian_Tree {
  int root, key[N], val[N], ch[N][2], pre[N];
  void init() {
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &key[i], &val[i]);
      ch[i][0] = ch[i][1] = pre[i] = 0;
    }
  }
  void build() {
    static int st[N];
    int top = -1;
    for (int i = 1; i <= n; ++i) {
      int k = top;
      while (k >= 0 && val[st[k]] > val[idx[i]]) {
        --k;
      }
      if (~k) {
        pre[idx[i]] = st[k];
        ch[st[k]][1] = idx[i];
      }
      if (k < top) {
        pre[st[k + 1]] = idx[i];
        ch[idx[i]][0] = st[k + 1];
      }
      st[++k] = idx[i];
      top = k;
    }
    root = st[0];
  }
} ct;
bool cmp(int x, int y) {
  return ct.key[x] < ct.key[y];
}
int main() {
  while (~scanf("%d", &n)) {
    ct.init();
    for (int i = 1; i <= n; ++i) { idx[i] = i; }
    sort(idx + 1, idx + n + 1, cmp);
    ct.build();
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      printf("%d %d %d\n", ct.pre[i], ct.ch[i][0], ct.ch[i][1]);
    }
  }
}
