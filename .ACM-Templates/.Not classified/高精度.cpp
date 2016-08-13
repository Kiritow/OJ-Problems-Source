//高精度整数
const int BASE = 1000000000;
const int BASEDIGITS = 9;
struct bint {
  vector<int> s; char sign;
  bint(): s(), sign(1) {}
  bint(const ll &v): s(), sign(v < 0 ? -1 : 1) {
    for (ll t = v < 0 ? -v : v; t; t /= BASE) { s.push_back(t % BASE); }
  }
  bint(const string &v): s(), sign(1) {
    int beg = 0;
    for (; beg < (int)v.size() && (v[beg] == '-' || v[beg] == '+'); beg++) {
      if (v[beg] == '-') { sign = -1; }
    }
    for (int i = (int)v.size() - 1, x, j; i >= beg; i -= BASEDIGITS) {
      for (x = 0, j = max(beg, i - BASEDIGITS + 1); j <= i; x = x * 10 + v[j++] - '0');
      s.push_back(x);
    }
    trim();
  }
  bint &operator=(const bint &v) { sign = v.sign; s = v.s; return *this; }
  bint &operator+=(const bint &v) {
    if (sign == v.sign) {
      for (int i = 0, is = 0, len = max(s.size(), v.s.size()); i < len || is; i++) {
        if (i == (int)s.size()) { s.push_back(0); }
        s[i] += is + (i < (int)v.s.size() ? v.s[i] : 0);
        if ((is = s[i] >= BASE)) { s[i] -= BASE; }
      }
      return *this;
    } else { return *this -= -v; }
  }
  bint &operator-=(const bint &v) {
    if (sign == v.sign) {
      if (cmp(v, 0) != -1) {
        for (int i = 0, is = 0; i < (int)v.s.size() || is; i++) {
          s[i] -= is + (i < (int)v.s.size() ? v.s[i] : 0);
          if ((is = s[i] < 0)) { s[i] += BASE; }
        }
        trim(); return *this;
      } else { return *this = -(bint(v) -= *this); }
    } else { return *this += -v; }
  }
  bint &operator*=(const bint &v) {
    vector<ll> num(s.size() + v.s.size());
    for (int i = 0; i < (int)s.size(); i++) {
      for (int j = 0; j < (int)v.s.size(); j++) {
        num[i + j] += (ll)s[i] * v.s[j];
        if (num[i + j] >= BASE) { num[i + j + 1] += num[i + j] / BASE; num[i + j] %= BASE; }
      }
    }
    sign *= v.sign; s.resize(num.size());
    for (int i = 0; i < (int)num.size(); i++) { s[i] = num[i]; }
    trim(); return *this;
  }
  bint &operator/=(const bint &v) { return *this = divmod(*this, v).first; }
  bint &operator%=(const bint &v) { return *this = divmod(*this, v).second; }
  bint operator-()const { bint ret(*this); ret.sign = -sign; return ret; }
  bint operator+(const bint &v)const { return bint(*this) += v; }
  bint operator-(const bint &v)const { return bint(*this) -= v; }
  bint operator*(const bint &v)const { return bint(*this) *= v; }
  bint operator/(const bint &v)const { return divmod(*this, v).first; }
  bint operator%(const bint &v)const { return divmod(*this, v).second; }
  bint operator^(const ll &v)const {
    bint ret(1), t(*this);
    for (ll b = v; b; b >>= 1) { if (b & 1) { ret *= t; } t *= t; }
    return ret;
  }
  //乘除法辅助函数
  friend pair<bint, bint> divmod(const bint &a, const bint &b) {
    int norm = BASE / (b.s.back() + 1);
    bint x = a.abs().mul(norm), y = b.abs().mul(norm), q, r; q.s.resize(x.s.size());
    for (int i = (int)x.s.size() - 1; i >= 0; i--) {
      r = r.mul(BASE); r += x.s[i];
      int s1 = r.s.size() <= y.s.size() ? 0 : r.s[y.s.size()];
      int s2 = r.s.size() + 1 <= y.s.size() ? 0 : r.s[y.s.size() - 1];
      int d = ((ll)BASE * s1 + s2) / y.s.back();
      r -= y.mul(d);
      while (r.cmp(0, 1) == -1) { r += y; --d; }
      q.s[i] = d;
    }
    q.sign = a.sign * b.sign; q.trim(); r.sign = a.sign; r.trim();
    return make_pair(q, r.div(norm));
  }
  bint mul(int v)const {
    bint ret(*this);
    if (v < 0) { ret.sign = -ret.sign; v = -v; }
    for (int i = 0, is = 0; i < (int)ret.s.size() || is; i++) {
      if (i == (int)s.size()) { ret.s.push_back(0); }
      ll a = ret.s[i] * (ll)v + is; is = a / BASE; ret.s[i] = a % BASE;
    }
    ret.trim(); return ret;
  }
  bint div(int v)const {
    bint ret(*this);
    if (v < 0) { ret.sign = -ret.sign; v = -v; }
    for (int i = (int)ret.s.size() - 1, rem = 0; i >= 0; i--) {
      ll a = ret.s[i] + rem * (ll)BASE; ret.s[i] = a / v; rem = a % v;
    }
    ret.trim(); return ret;
  }
  int mod(int v)const {
    if (v < 0) { v = -v; }
    int m = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) { m = (s[i] + m * (ll)BASE) % v; }
    return m * sign;
  }
  bool operator<(const bint &v)const { return cmp(v) < 0; }
  bool operator>(const bint &v)const { return cmp(v) > 0; }
  bool operator<=(const bint &v)const { return cmp(v) <= 0; }
  bool operator>=(const bint &v)const { return cmp(v) >= 0; }
  bool operator==(const bint &v)const { return cmp(v) == 0; }
  bool operator!=(const bint &v)const { return cmp(v) != 0; }
  int cmp(const bint &v, bool is = 1)const {
    if (is) { if (sign > v.sign) { return 1; } if (sign < v.sign) { return -1; } }
    int d = sign > 0 || !is ? 1 : -1;
    if (s.size() > v.s.size()) { return d; }
    if (s.size() < v.s.size()) { return -d; }
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      if (s[i] > v.s[i]) { return d; } if (s[i] < v.s[i]) { return -d; }
    }
    return 0;
  }
  bint abs()const { bint ret(*this); ret.sign *= ret.sign; return ret; }
  void trim() {
    while (!s.empty() && !s.back()) { s.pop_back(); }
    if (s.empty()) { sign = 1; }
  }
  void print()const {
    if (sign == -1) { putchar('-'); }
    printf("%d", s.empty() ? 0 : s.back());
    for (int i = (int)s.size() - 2; i >= 0; i--) { printf("%09d", s[i]); }
  }
  friend istream &operator>>(istream &in, bint &v) { string s; in >> s; v = s; return in; }
  friend ostream &operator<<(ostream &out, const bint &v) {
    if (v.sign == -1) { out << '-'; }
    out << setfill('0') << (v.s.empty() ? 0 : v.s.back());
    for (int i = (int)v.s.size() - 2; i >= 0; i--) { out << setw(BASEDIGITS) << v.s[i]; }
    return out << setfill(' ');
  }
  string toString()const {
    if (s.empty()) { return "0"; }
    string ret, x;
    if (sign == -1) { ret += '-'; }
    for (int o = s[s.size() - 1]; o; o /= 10) { x += o % 10 + '0'; }
    for (int i = (int)x.size() - 1; i >= 0; i--) { ret += x[i]; }
    for (int i = (int)s.size() - 2; i >= 0; i--) {
      x.clear();
      for (int j = 0, p = s[i]; j < BASEDIGITS; j++, p /= 10) { x += p % 10 + '0'; }
      for (int j = BASEDIGITS - 1; j >= 0; j--) { ret += x[j]; }
    }
    return ret;
  }
  operator bool()const { return s.size() && !(s.size() == 1 && !s[0]); }
  //高精度开方
  bint sqrt()const {
    bint ret, t(*this); ret.s.resize((t.s.size() + 1) >> 1);
    for (int i = (int)ret.s.size() - 1; i >= 0; i--) {
      int l = 0, r = BASE - 1, mid = ret.s[i] = (l + r + 1) >> 1;
      while (l < r) {
        if (comp(ret, mid, i - 1, t)) { r = mid - 1; }
        else { l = mid; }
        mid = ret.s[i] = (l + r + 1) >> 1;
      }
      sub(t, ret, mid, i - 1); ret.s[i] += mid;
    }
    for (int i = 0; i < (int)ret.s.size(); i++) { ret.s[i] >>= 1; }
    ret.trim(); return ret;
  }
  void sub(bint &a, const bint &b, const int &k, const int &d)const {
    for (int i = d + 1, l = b.s.size() + d; i <= l; i++) {
      ll tmp = a.s[i] - (ll)b.s[i - d - 1] * k;
      if (tmp < 0) { a.s[i + 1] += (tmp - BASE + 1) / BASE; a.s[i] = tmp - (tmp - BASE + 1) / BASE * BASE; }
      else { a.s[i] = tmp; }
    }
    for (int i = b.s.size() + d + 1; i < (int)a.s.size() && a.s[i] < 0; i++) {
      a.s[i + 1] += (a.s[i] - BASE + 1) / BASE; a.s[i] -= (a.s[i] - BASE + 1) / BASE * BASE;
    }
    a.trim();
  }
  bool comp(const bint &a, const int &c, const int &d, const bint &b)const {
    int l = -(BASE << 1); ll t = 0;
    if (b.s.size() < a.s.size() + d && c) { return true; }
    for (int i = (int)b.s.size() - 1; i > d; i--) {
      t = t * BASE + (ll)(i - d - 1 < (int)a.s.size() ? a.s[i - d - 1] : 0) * c - b.s[i];
      if (t > 0) { return true; }
      if (t < l) { return false; }
    }
    for (int i = d - 1; i >= 0; i--) {
      t = t * BASE - b.s[i];
      if (t > 0) { return true; }
      if (t < l) { return false; }
    }
    return t > 0;
  }
};
