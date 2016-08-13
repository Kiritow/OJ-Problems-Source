//快速幂
ll powMod(ll a, ll b, ll m) {
  ll r = 1;
  for (a %= m; b; b >>= 1) { if (b & 1) { r = r * a % m; } a = a * a % m; }
  return r;
}
//素数筛
//Eratosthenes O(nloglogn)
const int N = 10000000; //~110ms
bitset<N> isprime;
void getPrime() {
  isprime.set(); isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) {
      for (ll j = (ll)i * i; j < N; j += i) { isprime[j] = false; }
    }
  }
}
//Euler O(n) prime[0]为个数
const int N = 10000000; //~110ms
int prime[N]; //3711111 for [2, 10^9)
void getPrime() {
  for (int i = 2; i < N; i++) {
    if (!prime[i]) { prime[++prime[0]] = i; }
    for (int j = 1; j <= prime[0] && prime[j] * i < N; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) { break; }
    }
  }
}
//Euler O(n)
const int N = 10000000; //~95ms
int prime[N >> 3]; bitset<N> isprime;
void getPrime() {
  isprime.set(); isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) { prime[++prime[0]] = i; }
    for (int j = 1; j <= prime[0] && prime[j] * i < N; j++) {
      isprime[prime[j] * i] = false;
      if (i % prime[j] == 0) { break; }
    }
  }
}
//[a, b]区间内素数个数
bitset<N> isprime, isprimesmall;
ll segPrime(ll a, ll b) {
  ll ret = 0; isprime.set(); isprimesmall.set();
  for (int i = 2; (ll)i * i <= b; i++) {
    if (isprimesmall[i]) {
      for (ll j = (ll)i * i; (ll)j * j <= b; j += i) { isprimesmall[j] = false; }
      for (ll j = max(2ll, (a + i - 1) / i)) * i; j <= b; j += i) { isprime[j - a] = false; }
    }
  }
  for (ll i = 0; i <= r - l; i++) { ret += isprime[i]; }
  return ret;
}
//分解质因数
ll factor[100], facCnt;
void getFactors(ll x) {
  facCnt = 0;
  for (int i = 2, xx = sqrt(x + 0.5); i <= xx; i++) {
    if (x % i == 0) {
      factor[facCnt++] = i;
      while (x % i == 0) { x /= i; }
    }
  }
  if (x != 1) { factor[facCnt++] = x; }
}
//分解质因数及个数 预处理素数表
ll factor[100][2], facCnt;
void getFactors(ll x) {
  facCnt = 0;
  for (int i = 1; prime[i] <= x / prime[i]; i++) {
    factor[facCnt][1] = 0;
    if (x % prime[i] == 0) {
      factor[facCnt][0] = prime[i];
      while (x % prime[i] == 0) { factor[facCnt][1]++; x /= prime[i]; }
      facCnt++;
    }
  }
  if (x != 1) { factor[facCnt][0] = x; factor[facCnt++][1] = 1; }
}
//Miller-Rabin素性测试 素数返回true 错误(伪素数)概率为1/4^Times
const int Times = 7;
int WIT[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}; //7 bases for n < 2^64
ll mulMod(ll a, ll b, ll m) {
  ll r = 0;
  for (a %= m, b %= m; b; b >>= 1) { if (b & 1) { r = (r + a) % m; } a = (a << 1) % m; }
  return r;
}
ll powMod(ll a, ll b, ll m) {
  ll r = 1;
  for (a %= m; b; b >>= 1) { if (b & 1) { r = mulMod(r, a, m); } a = mulMod(a, a, m); }
  return r;
}
bool Miller_Rabin(ll n) {
  if (n == 2) { return true; }
  if (n < 2 || (n & 1) == 0) { return false; }
  ll m = n - 1; int k = 0;
  while ((m & 1) == 0) { k++; m >>= 1; }
  for (int i = 0; i < Times; i++) {
    ll a = WIT[i], x = powMod(a, m, n), y = 0;
    //ll a = rand() % (n - 1) + 1;
    for (int j = 0; j < k; j++, x = y) {
      y = mulMod(x, x, n);
      if (y == 1 && x != 1 && x != n - 1) { return false; }
    }
    if (y != 1) { return false; }
  }
  return true;
}
//pollard rho质因素分解
//对n进行素因子分解, 存入factor, k设置为107左右即可
ll factor[100], facCnt; //质因素分解结果(无序)
ll pollard_rho(ll x, ll c) {
  ll i = 1, k = 2, x0 = rand() % (x - 1) + 1, y = x0;
  while (true) {
    x0 = (mulMod(x0, x0, x) + c) % x;
    ll d = llabs(__gcd(y - x0, x));
    if (d != 1 && d != x) { return d; }
    if (y == x0) { return x; }
    if (++i == k) { y = x0; k <<= 1; }
  }
}
void findfac(ll n, int k = 107) {
  if (n == 1) { return; }
  if (Miller_Rabin(n)) { factor[facCnt++] = n; return; }
  ll p = n; int c = k;
  while (p >= n) { p = pollard_rho(p, c--); } //k值变化, 防止死循环
  findfac(p, k); findfac(n / p, k);
}
//求单个数的欧拉函数
ll eular(ll n) {
  ll ret = 1;
  while ((n & 1) == 0) { n >>= 1; ret <<= 1; }
  for (ll i = 3; i * i <= n; i += 2) {
    if (n % i == 0) { n /= i; ret *= i - 1; while (n % i == 0) { n /= i; t *= i; } }
  }
  return n > 1 ? ret * (n - 1) : ret;
}
//欧拉函数筛 O(nloglogn)
const int N = 10000000; //~400ms
int phi[N] = {0, 1};
void getPhi() {
  for (int i = 2; i < N; i++) {
    if (!phi[i]) {
      for (int j = i; j < N; j += i) {
        if (!phi[j]) { phi[j] = j; } phi[j] -= phi[j] / i;
      }
    }
  }
}
//素数 + 欧拉函数筛 O(n)
const int N = 10000000; //~150ms
int prime[N >> 3], phi[N] = {0, 1}; bitset<N> isprime;
void getPrimePhi() {
  isprime.set(); isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) { prime[++prime[0]] = i; phi[i] = i - 1; }
    for (int j = 1, k; j <= prime[0] && prime[j] * i < N; j++) {
      isprime[k = prime[j] * i] = false;
      if (i % prime[j] == 0) { phi[k] = phi[i] * prime[j]; break; }
      phi[k] = phi[i] * (prime[j] - 1);
    }
  }
}
//素数 + 莫比乌斯函数筛 O(n)
const int N = 10000000; //150ms
int prime[N >> 3], miu[N] = {0, 1}; bitset<N> isprime;
void getPrimeMiu() {
  isprime.set(); isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) { prime[++prime[0]] = i; miu[i] = -1; }
    for (int j = 1, k; j <= prime[0] && prime[j] * i < N; j++) {
      isprime[k = prime[j] * i] = false;
      if (i % prime[j] == 0) { miu[k] = 0; break; }
      miu[k] = -miu[i];
    }
  }
}
//素数 + 欧拉函数 + 莫比乌斯函数筛 O(n)
const int N = 10000000; //~230ms
int prime[N >> 3], phi[N] = {0, 1}, miu[N] = {0, 1}; bitset<N> isnprime;
void getPrimePhiMiu() {
  for (int i = 2; i < N; i++) {
    if (!isnprime[i]) { prime[++prime[0]] = i; phi[i] = i - 1; miu[i] = -1; }
    for (int j = 1, k; j <= prime[0] && prime[j] * i < N; j++) {
      isnprime[k = prime[j] * i] = true;
      if (i % prime[j] == 0) { phi[k] = phi[i] * prime[j]; miu[k] = 0; break; }
      phi[k] = phi[i] * (prime[j] - 1); miu[k] = -miu[i];
    }
  }
}
//素数 + 约数个数筛 O(n)
const int N = 10000000; //~200ms
bitset<N> isprime;
int prime[N >> 3], faccnt[N] = {0, 1}, d[N]; //d[i]表示i的最小质因子的幂次
void getPrimeFaccnt() {
  isprime.set(); isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) { prime[++prime[0]] = i; faccnt[i] = 2; d[i] = 1; }
    for (int j = 1, k; j <= prime[0] && prime[j] * i < N; j++) {
      isprime[k = prime[j] * i] = false;
      if (i % prime[j] == 0) {
        faccnt[k] = faccnt[i] / (d[i] + 1) * (d[i] + 2); d[k] = d[i] + 1; break;
      }
      faccnt[k] = faccnt[i] << 1; d[k] = 1;
    }
  }
}
//A^B的约数之和为:
//sum = [1+p1+p1^2+...+p1^(a1*B)]*...*[1+pn+pn^2+...+pn^(an*B)].
//等比数列求和 1+a+a^2+...+a^b
ll sumPow(ll a, ll b, ll m) {
  ll r = 1; a %= m;
  for (ll t = 1; b; b >>= 1) {
    if (b & 1) { r = (r * a + t) % m; }
    t = t * (a + 1) % m;
    a = a * a % m;
  }
  return r;
}
//求逆元(ax = 1(mod m)的x值)
//扩展欧几里得(求ax + by = gcd(a, b)的解), 求出的x为a对b的模逆元
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) { x = 1; y = 0; return a; }
  ll d = exgcd(b, a % b, y, x); y -= a / b * x; return d;
}
//解不定方程ax + by = c 求得的只是其中一组解
//对于不定整数方程ax + by = c, 若c mod gcd(a, b) = 0, 则该方程存在整数解, 否则不存在整数解
//在找到ax + by = gcd(a, b)的一组解x0, y0后，可得到ax + by = c的一组解x1 = x0 * (c / gcd(a, b)), y1 = y0 * (c / gcd(a,b))
//ax + by = c的其他整数解满足：
//x = x1 + b / gcd(a, b) * t, y = y1 - a / gcd(a, b) * t(其中t为任意整数)
//求ax + by = c的一组解
bool linear_equation(int a, int b, int c, int &x, int &y) {
  int d = exgcd(a, b, x, y);
  if (c % d) { return false; }
  int k = c / d; x *= k; y *= k; return true;
}
//求ax = b (mod p)循环节内的所有解
ll ans[N], cnt;
bool linear_equation(ll a, ll b, ll p) {
  ll x, y, d = exgcd(a, p, x, y); cnt = 0;
  if (b % d) { return false; }
  x = (x % p + p) % p;
  ans[++cnt] = x * (b / d) % (p / d);
  for (int i = 1; i < d; i++) { ans[++cnt] = (ans[1] + i * p / d) % n; }
  return true;
}
//线性预处理逆元
ll Inv[N] = {1, 1};
void getInv(int m) {
  for (ll i = 2; i < m; i++) { Inv[i] = (m - m / i) * Inv[m % i] % m; }
}
//扩展欧几里得求逆元
ll modReverse(ll a, ll m) {
  ll x, y, d = exgcd(a, m, x, y);
  if (d == 1) { return (x % m + m) % m; } else { return -1; }
}
//费马小定理, m为素数, a与m互质
ll inv(ll a, ll m) { return powMod(a, m - 2, m); }
//只能求0 < a < m的情况,a和m互质
ll inv(ll a, ll m) {
  if (a == 1) { return 1; }
  return inv(m % a, m) * (m - m / a) % m;
}
//中国剩余定理 求模线性方程组x = a[i] (mod m[i]) m[i]可以不互质
//[1, n]内解的个数为(n - x) / m1 + (x != 0)
bool merge(ll a1, ll m1, ll a2, ll m2, ll &a3, ll &m3) {
  ll d = __gcd(m1, m2), c = a2 - a1;
  if (c % d != 0) { return false; }
  c = (c % m2 + m2) % m2 / d; m1 /= d; m2 /= d;
  c = c * inv(m1, m2) % m2 * m1 * d + a1;
  m3 = m1 * m2 * d; a3 = (c % m3 + m3) % m3;
  return true;
}
ll CRT(ll a[], ll m[], int k) {
  ll a1 = a[0], m1 = m[0];
  for (int i = 1; i < k; i++) {
    ll a2 = a[i], m2 = m[i], m3, a3;
    if (!merge(a1, m1, a2, m2, a3, m3)) { return -1; }
    a1 = a3; m1 = m3;
  }
  return (a1 % m1 + m1) % m1;
}
//模线性方程组 需扩展欧几里得
//求解方程ax ≡ b (mod m) 相当于求解方程ax + my = b (x, y为整数)
int m[10], a[10]; //模数为m, 余数为a, X % m = a
bool solve(int &m0, int &a0, int m, int a) {
  ll y, x, d = exgcd(m0, m, x, y);
  if (abs(a - a0) % d) { return false; }
  x *= (a - a0) / d; x %= m / d;
  a0 = (x * m0 + a0); m0 *= m / d; a0 %= m0;
  if (a0 < 0) { a0 += m0; }
  return true;
}
//无解返回false, 有解返回true
//解的形式最后为a0 + m0 * t (0 <= a0 < m0)
bool MLES(int &m0, int &a0, int n) {  //解为X = a0 + m0 * k
  bool flag = true; m0 = 1; a0 = 0;
  for (int i = 0; i < n; i++) {
    if (!solve(m0, a0, m[i], a[i])) { flag = false; break; }
  }
  return flag;
}
//求原根
ll fac[N];
ll getRoot(ll n) {
  int cnt = 0;
  for (ll i = 2; i * i < n - 1; i++) { if ((n - 1) % i == 0) { fac[cnt++] = i; fac[cnt++] = (n - 1) / i; } }
  for (int i = 2, j;; i++) {
    for (j = 0; j < cnt; j++) { if (powMod(i, fac[j], n) == 1) { break; } }
    if (j == cnt) { return i; }
  }
}
//线性基
//异或线性基
//若要查询第k小子集异或和, 则把k写成二进制, 对于是1的第i位, 把从低位到高位第i个不为0的数异或进答案
//若要判断是否有非空子集的异或和为0, 如果不存在自由基, 那么说明只有空集的异或值为0, 需要高斯消元来判断
struct XORBase {
  int a[64];
  void clear() { memset(a, 0, sizeof(a)); }
  void ins(ll x) {
    for (int i = 62; i >= 0; i--) {
      if (x & (1 << i)) {
        if (a[i]) { x ^= a[i]; }
        else { a[i] = x; }
        break;
      }
    }
  }
  //查询最大子集异或和
  void query() {
    ll ret = 0;
    for (int i = 62; i >= 0; i--) { ret = max(ret, ret ^ a[i]); }
    return ret;
  }
};
//实数线性基
//ins返回要插入的数是否可以被之前的数线性表示出来, 返回true表示不能, false表示可以
int m;
struct Base {
  double a[N][N]; bool v[N];
  void clear() { memset(a, 0, sizeof(a)); memset(v, 0, sizeof(v)); }
  bool ins(double *x) {
    for (int i = 0; i < m; i++)  {
      if (fabs(x[i]) > 1e-6) {
        if (v[i]) {
          double t = x[i] / a[i][i];
          for (int j = 0; j < m; j++) { x[j] -= t * a[i][j]; }
        } else {
          v[i] = 1;
          for (int j = 0; j < m; j++) { a[i][j] = x[j]; }
          return true;
        }
      }
    }
    return false;
  }
};
//离散对数 大步小步算法 Baby-Step Giant-Step
//BSGS(a, b, p): 求ax = b (mod p)的最小非负整数解, 若无解则返回 -1
//rev(a, p): 扩展欧几里得求逆元
//powMod(base, pow, mod): 快速幂
//mulMod(a, b, mod): 快速乘(这里用快速乘是为了避免爆long long int, 实际有时可以不用)
unordered_map<ll, ll> Hash;
ll BSGS(ll a, ll b, ll p) {
  if (b >= p) { return -1; }
  a %= p, b %= p;
  if (!a && !b) { return 1; } //a和b都是p的倍数的话, 就相当于0^x = 0 (mod p)了, 那么最小非负整数解就是1
  if (!a) { return -1; } //如果a是p的倍数但是b不是, 就相当于0^x = t (mod p), t > 0, 无解
  Hash.clear();
  ll m = ceil(sqrt(p)), tmp = 1 % p; //tmp = a^j
  for (ll j = 0; j < m; j++) { //预处理出a^j mod p的值
    Hash[tmp] = j; tmp = mulMod(tmp, a, p);
  }
  tmp = rev(powMod(a, m, p), p); //tmp = a^(-m)
  for (ll i = 0; i < m; i++) {
    if (Hash.find(b) != Hash.end()) { return i * m + Hash[b]; }
    b = mulMod(b, tmp, p);
  }
  return -1;
}
//高斯消元 求线性方程组的解 O(n^3)
//有equ个方程, var个变元, 增广矩阵行数为equ, 列数为var + 1, 下标从0开始
int a[N][N], x[N]; //增广矩阵, 解集
int freex[N], freenum;//自由变元 (多解枚举自由变元可以使用)
//返回值为-1表示无解, 为0是唯一解, 否则返回自由变元个数
int Gauss(int equ, int var) {
  int mxrow, col, k; freenum = 0;
  for (k = 0, col = 0; k < equ && col < var; k++, col++) {
    mxrow = k;
    for (int i = k + 1; i < equ; i++) { if (abs(a[i][col]) > abs(a[mxrow][col])) { mxrow = i; } }
    if (a[mxrow][col] == 0) { k--; freex[freenum++] = col; continue; } //自由变元
    if (mxrow != k) { for (int j = col; j <= var; j++) { swap(a[k][j], a[mxrow][j]); } }
    for (int i = k + 1; i < equ; i++) {
      if (a[i][col]) {
        int x = abs(a[i][col]), y = abs(a[k][col]), lcm = x / __gcd(x, y) * y, tx = lcm / x, ty = lcm / y;
        if (a[i][col] * a[k][col] < 0) { ty = -ty; }
        for (int j = col; j <= var; j++) {
          a[i][j] = a[i][j] * tx - a[k][j] * ty; //a[i][j] = (a[i][j] % M + M) % M;
        }
      }
    }
  }
  for (int i = k; i < equ; i++) { if (a[i][col]) { return -1; } } //无解
  if (k < var) { return var - k; } //自由变元个数
  for (int i = var - 1; i >= 0; i--) { //唯一解，回代
    for (int j = i + 1; j < var; j++) {
      if (a[i][j]) { a[i][var] -= a[i][j] * x[j]; /*a[i][var] = (a[i][var] % M + M) % M;*/ }
    }
    //while (a[i][var] % a[i][i]) { a[i][var] += M; }
    x[i] = a[i][var] / a[i][i]; //x[i] = (a[i][var] * inv(a[i][i], M)) % M;
  }
  return 0;
}
//高斯消元 (浮点数)
const double eps = 1e-9;
const int N = 205;
double a[N][N], x[N]; //方程的左边的矩阵和等式右边的值, 求解之后x存的就是结果
int equ, var; //方程数和未知数个数
//返回0表示无解, 1表示有解
int Gauss() {
  int i, j, k, col, mxrow;
  for (k = 0, col = 0; k < equ && col < var; k++, col++) {
    mxrow = k;
    for (i = k + 1; i < equ; i++) {
      if (fabs(a[i][col]) > fabs(a[mxrow][col])) { mxrow = i; }
    }
    if (fabs(a[mxrow][col]) < eps) { return 0; }
    if (k != mxrow) {
      for (j = col; j < var; j++) { swap(a[k][j], a[mxrow][j]); }
      swap(x[k], x[mxrow]);
    }
    x[k] /= a[k][col];
    for (j = col + 1; j < var; j++) { a[k][j] /= a[k][col]; }
    a[k][col] = 1;
    for (i = 0; i < equ; i++) {
      if (i != k) {
        x[i] -= x[k] * a[i][k];
        for (j = col + 1; j < var; j++) { a[i][j] -= a[k][j] * a[i][col]; }
        a[i][col] = 0;
      }
    }
  }
  return 1;
}
//自适应simpson积分
//给定一个函数f(x), 求[a, b]区间内f(x)到x轴所形成区域的面积
double simpson(double l, double r) {return (f(l) + f(r) + 4 * f((l + r) / 2.0)) * (r - l) / 6.0;}
double rsimpson(double l, double r) {
  double mid = (l + r) / 2.0;
  if (fabs(simpson(l, r) - simpson(l, mid) - simpson(mid, r)) < EPS) {
    return simpson(l, mid) + simpson(mid, r);
  }
  return rsimpson(l, mid) + rsimpson(mid, r);
}
//FFT O(nlogn)
//以下n必须为2的幂, op为1时是求DFT, op为-1时为求IDFT
typedef complex<double> comp;
const double PI = acos(-1.0);
void fft(comp a[], int n, int op) {
  for (int i = 1, j = 0; i < n - 1; i++) {
    for (int s = n; j ^= s >>= 1, ~j & s;);
    if (i < j) { swap(a[i], a[j]); }
  }
  for (int i = 1; i < n; i <<= 1) {
    comp wn(cos(PI / i), op * sin(PI / i));
    for (int j = 0; j < n; j += i << 1) {
      comp w(1, 0);
      for (int k = 0; k < i; k++, w *= wn) {
        comp x = a[j + k], y = w * a[i + j + k];
        a[j + k] = x + y; a[i + j + k] = x - y;
      }
    }
  }
  if (op == -1) { for (int i = 0; i < n; i++) { a[i] = comp(a[i].real() / n, a[i].imag()); } }
}
//求高精度乘法 HDU 1402
comp a[N], b[N];
char str1[N / 2], str2[N / 2];
int sum[N];
int main() {
  while (~scanf("%s%s", str1, str2)) {
    memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
    int n = strlen(str1), m = strlen(str2), len = 1;
    while (len < n * 2 || len < m * 2) { len <<= 1; }
    for (int i = 0; i < n; i++) { a[i] = comp(str1[n - 1 - i] - '0', 0); }
    for (int i = 0; i < m; i++) { b[i] = comp(str2[m - 1 - i] - '0', 0); }
    fft(a, len, 1); fft(b, len, 1);
    for (int i = 0; i < len; i++) { a[i] *= b[i]; }
    fft(a, len, -1);
    for (int i = 0; i < len; i++) { sum[i] = (int)(a[i].real() + 0.5); }
    for (int i = 0; i < len; i++) { sum[i + 1] += sum[i] / 10; sum[i] %= 10; }
    len = n + m - 1;
    while (sum[len] <= 0 && len > 0) { len--; }
    for (int i = len; i >= 0; i--)  { putchar(sum[i] + '0'); } puts("");
  }
}
//NTT O(nlogn)
//998244353 = 119 * 2^23 + 1, 原根为3; 1004535809 = 479 * 2^21 + 1, 原根为3
//786433 = 3 * 2^18 + 1, 原根为10; 880803841 = 105 * 2^23 + 1, 原根为26
//P是素数且N必须是P - 1的因子
//op为1时是求FNT, op为-1时为求IFNT
const int P = 998244353, G = 3, N = 262144, K = 17;
ll g[N + 5], ng[N + 5], Inv[N + 5] = {1, 1};
void initG() {
  g[K] = powMod(G, (P - 1) / N, P); ng[K] = powMod(g[K], P - 2, P);
  for (int i = K - 1; i >= 0; i--) { g[i] = g[i + 1] * g[i + 1] % P; ng[i] = ng[i + 1] * ng[i + 1] % P; }
  for (ll i = 2; i <= N; i++) { Inv[i] = (P - P / i) * Inv[P % i] % P; }
}
void ntt(ll a[], int n, int op) {
  for (int i = 1, j = 0; i < n - 1; i++) {
    for (int s = n; j ^= s >>= 1, ~j & s;);
    if (i < j) { swap(a[i], a[j]); }
  }
  for (int d = 0; (1 << d) < n; d++) {
    int m = 1 << d; ll w0 = op == 1 ? g[d] : ng[d];
    for (int i = 0; i < n; i += m << 1) {
      for (int j = 0, w = 1; j < m; j++, w = w * w0 % P) {
        ll &x = a[i + j + m], &y = a[i + j], t = w * x % P;
        x = y - t; y = y + t;
        if (x < 0) { x += P; } if (y >= P) { y -= P; }
      }
    }
  }
  if (op == -1) { for (int i = 0; i < n; i++) { a[i] = a[i] * Inv[n] % P; } }
}
//多项式求逆元 O(nlogn) 即求B(x)满足A(X) * B(x) = 1 (mod x^n), deg(B) <= deg(A)
void polyInv(ll a[], ll b[], int n) {
  if (n == 1) { b[0] = powMod(a[0], P - 2, P); return; }
  polyInv(a, b, n >> 1);
  int k = 1;
  while (k < n << 1) { k <<= 1; }
  for (int i = 0; i < n; i++) { tmp[i] = a[i]; }
  for (int i = n; i < k; i++) { tmp[i] = b[i] = 0; }
  ntt(tmp, k, 1); ntt(b, k, 1);
  for (int i = 0; i < k; i++) {
    b[i] = b[i] * (2 - tmp[i] * b[i] % P) % P;
    if (b[i] < 0) { b[i] += P; }
  }
  ntt(b, k, -1);
  for (int i = n; i < k; i++) { b[i] = 0; }
}
//多项式除法 O(nlogn) 即求D(x)和R(x)满足A(x) = D(x) * B(x) + R(x), deg(D) <= deg(A) - deg(B), deg(R) < deg(B)
ll a0[N], b0[N];
void polyDiv(ll a[], int n, ll b[], int m, ll d[], ll r[]) {
  int k = 1, t = n - m + 1;
  while (k < t << 1) { k <<= 1; }
  for (int i = 0; i < k; i++) { a0[i] = b0[i] = 0; }
  for (int i = 0; i < m; i++) { a0[i] = b[m - i - 1]; }
  polyInv(a0, b0, t);
  for (int i = t; i < k; i++) { b0[i] = 0; }
  for (int i = 0; i < t; i++) { a0[i] = a[n - i - 1]; }
  for (int i = t; i < k; i++) { a0[i] = 0; }
  ntt(b0, k, 1); ntt(a0, k, 1);
  for (int i = 0; i < k; i++) { a0[i] = a0[i] * b0[i] % P; }
  ntt(a0, k, -1);
  reverse(a0, a0 + t);
  for (int i = 0; i < t; i++) { d[i] = a0[i]; }
  for (k = 1; k < n << 1; k <<= 1);
  for (int i = t; i < k; i++) { a0[i] = 0; }
  for (int i = 0; i < m; i++) { b0[i] = b[i]; }
  for (int i = m; i < k; i++) { b0[i] = 0; }
  ntt(a0, k, 1); ntt(b0, k, 1);
  for (int i = 0; i < k; i++) { a0[i] = a0[i] * b0[i] % P; }
  ntt(a0, k, -1);
  for (int i = 0; i < m; i++) { r[i] = (a[i] - a0[i]) % P; }
  for (int i = m; i < k; i++) { r[i] = 0; }
}
//多项式求对数函数 O(nlogn) a[0] = 1
void polyLn(ll a[], ll b[], int n) {
  polyInv(a, tmp2, n);
  int k = 1;
  while (k < n << 1) { k <<= 1; }
  for (int i = 0; i < n - 1; i++) { b[i] = a[i + 1] * (i + 1) % P; }
  for (int i = n - 1; i < k; i++) { b[i] = 0; }
  ntt(b, k, 1); ntt(tmp2, k, 1);
  for (int i = 0; i < k; i++) { b[i] = b[i] * tmp2[i] % P; }
  ntt(b, k, -1);
  for (int i = n - 1; i >= 0; i--) { b[i] = b[i - 1] * Inv[i] % P; } b[0] = 0;
}
//多项式求指数函数 O(nlogn) a[0] = 0
void polyExp(ll a[], ll b[], int n) {
  if (n == 1) { b[0] = 1; return; }
  polyExp(a, b, n >> 1); polyLn(b, tmp, n);
  int k = 1;
  while (k < n << 1) { k <<= 1; }
  for (int i = 0; i < n; i++) { tmp[i] -= a[i]; if (tmp[i] < 0) { tmp[i] += P; } }
  if (++tmp[0] == P) { tmp[0] = 0; }
  for (int i = n; i < k; i++) { tmp[i] = b[i] = 0; }
  ntt(tmp, k, 1); ntt(b, k, 1);
  for (int i = 0; i < k; i++) { b[i] = b[i] * tmp[i] % P; }
  ntt(b, k, -1);
  for (int i = n; i < k; i++) { b[i] = 0; }
}
//多项式求平方根 O(nlogn) a[0] = 1
void polySqrt(ll a[], ll b[], int n) {
  if (n == 1) { b[0] = 1; return; }
  polySqrt(a, b, n >> 1); polyInv(b, tmp2, n);
  int k = 1;
  while (k < n << 1) { k <<= 1; }
  for (int i = 0; i < n; i++) { tmp[i] = a[i]; }
  for (int i = n; i < k; i++) { tmp[i] = b[i] = 0; }
  ntt(tmp, k, 1); ntt(b, k, 1); ntt(tmp2, k, 1);
  for (int i = 0; i < k; i++) { b[i] = (b[i] * b[i] + tmp[i]) % P * Inv[2] % P * tmp2[i] % P; }
  ntt(b, k, -1);
  for (int i = n; i < k; i++) { b[i] = 0; }
}
//快速沃尔什变换 即求C[i] = sum{j ? k = i}(A[j] * B[k]) ?为任一二元逻辑位运算
void fwt(ll a[], int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int i = 0, m = d << 1; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        ll x = a[i + j], y = a[i + j + d];
        //xor: a[i + j] = x + y; a[i + j + d] = x - y;
        //and: a[i + j] = x + y;
        //or: a[i + j + d] = x + y;
      }
    }
  }
}
void ufwt(ll a[], int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int i = 0, m = d << 1; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        ll x = a[i + j], y = a[i + j + d];
        //xor: a[i + j] = (x + y) >> 1; a[i + j + d] = (x - y) >> 1;
        //and: a[i + j] = x - y;
        //or: a[i + j + d] = y - x;
      }
    }
  }
}
