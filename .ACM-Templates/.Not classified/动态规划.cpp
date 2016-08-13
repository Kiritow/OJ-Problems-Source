//最大子段和 O(n)
ll maxSum(int a[], int n, int &st, int &ed) {
  ll mx = a[0], mxc = 0; st = ed = 0;
  for (int i = 1; i < n; i++) {
    if (mxc > 0) { mxc += a[i]; }
    else { mxc = a[i]; s = i; }
    if (mxc > mx) { mx = mxc; st = s; ed = i; }
  }
  return mx;
}
//循环数组最大子段和 O(n)
const ll INF = 0x7f7f7f7f7f7fLL;
ll maxSum_adj(int a[], int n) {
  ll mx = -INF, mxc = 0, mn = INF, mnc = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    mxc = a[i] + (mxc > 0 ? mxc : 0);
    if (mx < mxc) { mx = mxc; }
    mnc = a[i] + (mnc > 0 ? 0 : mnc);
    if (mn > mnc) { mn = mnc; }
    sum += a[i];
  }
  return mx < 0 || mx > sum - mn ? mx : sum - mn;
}
//最大M子段和 O(nm)
ll dp[N], mxsum[N];
ll mxMSum(int a[], int n, int m) {
  ll mx;
  for (int i = 1; i <= m; i++) {
    mx = 0x8f8f8f8f8f8f8f8fLL;
    for (int j = i; j <= n; j++) {
      dp[j] = max(dp[j - 1], mxsum[j - 1]) + a[j];
      mxsum[j - 1] = mx; mx = max(mx, dp[j]);
    }
  }
  return mx;
}
//最大子阵和 O(n^3)
ll presum[N][N];
ll maxSum(int a[][N], int h, int w, int &x1, int &y1, int &x2, int &y2) {
  ll ret = a[0][0], sum; x1 = y1 = x2 = y2 = 0;
  for (int i = 0; i < h; i++) {
    presum[i][0] = 0;
    for (int j = 0; j < w; j++) { presum[i][j + 1] = presum[i][j] + a[i][j]; }
  }
  for (int j = 0; j < w; j++) {
    for (int k = j, s; k < w; k++) {
      sum = s = 0;
      for (int i = 0; i < h; i++, s = sum > 0 ? s : i) {
        if ((sum = (sum > 0 ? sum : 0) + presum[i][k + 1] - presum[i][j]) > ret) {
          ret = sum; x1 = s; y1 = j; x2 = i; y2 = k;
        }
      }
    }
  }
  return ret;
}
//最长上升子序列 Longest Increasing Subsequence O(nlogn)
int b[N];
int LIS(int a[], int n) {
  int len = 1; b[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[a[i] > b[len - 1] ? len++ : lower_bound(b, b + len, a[i]) - b] = a[i]; //非降换为>=和upper_bound
  }
  return len;
}
//最长上升子序列数量 O(nlogn)?
int b[N], l[N]; ll cnt[N];
vector<int> v[N];
ll LIS(int a[], int n) {
  int len = 1; b[0] = a[0]; l[0] = 1; v[1].push_back(0);
  for (int i = 1; i < n; i++) {
    int pos = a[i] > b[len - 1] ? len++ : lower_bound(b, b + len, a[i]) - b;
    b[pos] = a[i]; l[i] = pos + 1;
    v[l[i]].push_back(i);
  }
  ll ret = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] == 1) { cnt[i] = 1; continue; }
    for (int j = 0, ll = l[i] - 1; j < (int)v[ll].size() && v[ll][j] <= i; j++) {
      if (a[v[ll][j]] < a[i]) { cnt[i] += cnt[v[ll][j]]; }
    }
    if (l[i] == len) { ret += cnt[i]; }
  }
  return ret;
}
//长度为k的上升子序列个数 O(knlogn)
int n, k;
ll bit[M][N];
inline int lowbit(int x) { return x & -x; }
void add(int id, int i, ll val) { while (i <= n) { bit[id][i] += val; i += lowbit(i); } }
ll sum(int id, int i) { ll ret = 0; while (i) { ret += bit[id][i]; i -= lowbit(i); } return ret; }
int main() {
  scanf("%d%d", &n, &k);
  add(0, 1, 1);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 1; j <= k; j++) { add(j, x, sum(j - 1, x - 1)); } //非降改为x
  }
  printf("%I64d\n", sum(k, n)); //n为元素最大值
}
//最长公共子序列 Longest Common Subsequence O(n^2)
int dp[N][N];
int LCS(char *a, char *b) {
  int m = strlen(a), n = strlen(b);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
      else { dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); }
    }
  }
  return dp[m][n];
}
void printLCS(char *a, char *b) {
  char s[N] = {0};
  for (int i = strlen(a), j = strlen(b), k = dp[i][j]; i && j;) {
    if (a[i - 1] == b[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) { s[--k] = a[--i]; --j; }
    else if (dp[i - 1][j] > dp[i][j - 1]) { i--; }
    else { j--; }
  }
  puts(s);
}
//最长公共子串 Longest Common Substring
//DP O(n^2)
int dp[2][N];
int LCS_dp(char *a, char *b, int &st1, int &st2) {
  int m = strlen(a), n = strlen(b), ret = 0, cur = 0; st1 = st2 = -1;
  for (int i = 0; i < m; i++, cur ^= 1) {
    for (int j = 0; j < n; j++) {
      if (a[i] == b[j]) {
        dp[cur][j] = i == 0 || j == 0 ? 1 : dp[cur ^ 1][j - 1] + 1;
        if (dp[cur][j] > ret) { ret = dp[cur][j]; st1 = i + 1 - ret; st2 = j + 1 - ret; }
      }
    }
  }
  //outputLCS(a, ret, st1);
  return ret;
}
//后缀数组 O(nlogn)
char *suf[N];
int pstrcmp(const void *p, const void *q) {
  return strcmp(*(char **)p, *(char **)q);
}
int comlen_suf(const char *p, const char *q) {
  for (int len = 0; *p && *q && *p++ == *q++;) {
    len++;
    if (*p == '#' || *q == '#') { return len; }
  }
  return 0;
}
int LCS_suffix(char *a, char *b) {
  int m = strlen(a), n = strlen(b), ret = 0, suf_index = 0, len_suf = m + n + 1;
  char *arr = new char[len_suf + 1];
  strcpy(arr, a); arr[m] = '#'; strcpy(arr + m + 1, b);
  for (int i = 0; i < len_suf; i++) { suf[i] = &arr[i]; }
  qsort(suf, len_suf, sizeof(char *), pstrcmp);
  for (int i = 0; i < len_suf - 1; i++) {
    int len = comlen_suf(suf[i], suf[i + 1]);
    if (len > ret) { ret = len; suf_index = i; }
  }
  //outputLCS(suf[suf_index], ret);
  delete[] arr; return ret;
}
void outputLCS(char *s, int len, int i = 0) {
  for (; len--; i++) { putchar(s[i]); } puts("");
}
//DP 下界O(nlogn) 上界O(nmlog(nm))
int c[N * N], d[N * N];
int LCS_dp(char *a, char *b) {
  vector<int> pos[26]; int k = 0, len = 1; d[0] = c[0];
  for (int i = strlen(b) - 1; i >= 0; i--) { pos[b[i] - 'a'].push_back(i); }
  for (int i = 0; a[i]; i++) {
    for (int j = 0; j < (int)pos[a[i] - 'a'].size(); j++) { c[k++] = pos[a[i] - 'a'][j]; }
  }
  for (int i = 1; i < k; i++) {
    d[c[i] > d[len - 1] ? len++ : lower_bound(d, d + len, c[i]) - d] = c[i];
  }
  return len;
}
//最长公共递增子序列 GCIS O(n^2)
int dp[N], f[N][N];
int GCIS(int a[], int la, int b[], int lb, int ans[]) {
  //a[1...la], b[1...lb]
  int mx = 0;
  memset(f, 0, sizeof(f));
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= la; i++) {
    memcpy(f[i], f[i - 1], sizeof(f[0]));
    for (int j = 1, k = 0; j <= lb; j++) {
      if (a[j - 1] > b[i - 1] && dp[k] < dp[j]) { k = j; }
      if (b[j - 1] == a[i - 1] && dp[k] + 1 > dp[j]) { dp[j] = dp[k] + 1; f[i][j] = i * (lb + 1) + k; }
    }
  }
  for (int i = 1; i <= lb; i++) { if (dp[i] > dp[mx]) { mx = i; } }
  for (int i = la * lb + la + mx, j = dp[mx]; j; i = f[i / (lb + 1)][i % (lb + 1)], j--) {
    ans[j - 1] = b[i % (lb + 1) - 1];
  }
  return dp[mx];
}
//字符串编辑距离 (Levenshtein距离)
//操作包括将替换一个字符, 插入一个字符, 删除一个字符
int dp[N][N];
int LevDist(char *a, char *b) {
  int n = strlen(a), m = strlen(b);
  for (int i = 0; i <= n; i++) { dp[i][0] = i; }
  for (int i = 0; i <= m; i++) { dp[0][i] = i; }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
      if (a[i - 1] == b[j - 1]) { dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); }
      else { dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); }
    }
  }
  return dp[n][m];
}
//字符串距离
//非空格字符的距离定义为它们的ASCII码的差的绝对值, 空格字符与其它任意字符之间的距离为已知的定值k
int dp[N][N];
int dist(char *a, char *b, int k) {
  int n = strlen(a), m = strlen(b);
  for (int i = 0; i <= n; i++) { dp[i][0] = i * k; }
  for (int i = 1; i <= m; i++) { dp[0][i] = i * k; }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]), min(dp[i - 1][j], dp[i][j - 1]) + k);
    }
  }
  return dp[n][m];
}
//TSP问题 O(V^2*2^V)
int n, mp[N][N], dp[1 << N][N];
int TSP() {
  memset(dp, 0x1f, sizeof(dp));
  dp[1][0] = 0;
  for (int s = 0; s < 1 << n; s++) {
    for (int v = 0; v < n; v++) {
      if (dp[s][v] == 0x1f1f1f1f) { continue; }
      for (int u = 0; u < n; u++) {
        if (s & 1 << u) { continue; }
        dp[s | 1 << u][u] = min(dp[s | 1 << u][u], dp[s][v] + mp[v][u]);
      }
    }
  }
  int ans = 0x1f1f1f1f;
  for (int i = 0; i < n; i++) { ans = min(ans, dp[(1 << n) - 1][i] + mp[i][0]); }
  return ans;
}
//mTSP问题 O(V^2*2^V)
int n, mp[N][N], dp[1 << N][N], best[1 << N];
bool ok[1 << N]; //该集合状态是否可行
int mTSP() {
  memset(dp, 0x1f, sizeof(dp));
  memset(best, 0x1f, sizeof(best));
  dp[1][0] = 0;
  for (int s = 0; s < 1 << n; s++) {
    if (!ok[s]) { continue; }
    for (int v = 0; v < n; v++) {
      if (!(s & (1 << v)) || dp[s][v] == 0x1f1f1f1f) { continue; }
      best[s] = min(best[s], dp[s][v] + mp[v][0]);
      for (int u = 0; u < n; u++) {
        if (s & (1 << u)) { continue; }
        dp[s | 1 << u][u] = min(dp[s | 1 << u][u], dp[s][v] + mp[v][u]);
      }
    }
  }
  for (int s = 0; s < 1 << n; s++) {
    if (!(s & 1)) { continue; }
    for (int i = s & (s - 1); i; i = s & (i - 1)) {
      best[s] = min(best[s], best[i] + best[(s ^ i) | 1]);
    }
  }
  return best[(1 << n) - 1];
}
