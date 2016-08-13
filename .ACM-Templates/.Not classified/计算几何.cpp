//随机化求最小圆覆盖
//圆心为O, 半径为R
double R, EPS = 1e-9;
struct Point { double x, y; } a[N], O;
inline double dis(Point x, Point y) { return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y)); }
Point center(Point x, Point y, Point z) {
  double a1 = y.x - x.x, a2 = z.x - x.x, b1 = y.y - x.y, b2 = z.y - x.y,
         c1 = (a1 * a1 + b1 * b1) / 2, c2 = (a2 * a2 + b2 * b2) / 2,
         d = a1 * b2 - a2 * b1;
  return (Point) {x.x + (c1 * b2 - c2 * b1) / d, x.y + (a1 * c2 - a2 * c1) / d};
}
void cal(int n, Point b[]) {
  O = a[0]; R = 0;
  for (int i = 0; i < n; i++) { a[i] = b[i]; }
  for (int i = 0; i < n; i++) { swap(a[rand() % n], a[i]); }
  for (int i = 1; i < n; i++) {
    if (dis(a[i], O) > R + EPS) {
      O = a[i]; R = 0;
      for (int j = 0; j < i; j++) {
        if (dis(a[j], O) > R + EPS) {
          O = (Point) {(a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2}, R = dis(O, a[i]);
          for (int k = 0; k < j; k++) {
            if (dis(a[k], O) > R + EPS) { O = center(a[k], a[j], a[i]), R = dis(O, a[i]); }
          }
        }
      }
    }
  }
}

//kuangbin
//1、基本函数
//1.1 Point 定义
const double PI = acos(-1.0);
const double EPS = 1e-8;
inline int sgn(double x) {
  return (fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1));
}
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y): x(_x), y(_y) {}
  Point operator-(const Point &b)const {
    return Point(x - b.x, y - b.y);
  }
  //叉积
  double operator^(const Point &b)const {
    return x * b.y - y * b.x;
  }
  //点积
  double operator*(const Point &b)const {
    return x * b.x + y * b.y;
  }
  //绕原点旋转角度B(弧度值), 后x, y的变化
  void transXY(double B) {
    double tx = x, ty = y;
    x = tx * cos(B) - ty * sin(B);
    y = tx * sin(B) + ty * cos(B);
  }
};
//1.2 Line 定义
struct Line {
  Point s, e;
  Line() {}
  Line(Point _s, Point _e): s(_s), e(_e) {}
  //两直线相交求交点
  //第一个值为0表示直线重合, 为1表示平行, 为0表示相交, 为2是相交
  //只有第一个值为2时, 交点才有意义
  pair<int, Point> operator&(const Line &b)const {
    Point res = s;
    if (sgn((s - e) ^ (b.s - b.e)) == 0) {
      if (sgn((s - b.e) ^ (b.s - b.e)) == 0) { return make_pair(0, res); } //重合
      else { return make_pair(1, res); } //平行
    }
    double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return make_pair(2, res);
  }
};
//1.3 两点间距离
//*两点间距离
double dist(const Point &a, const Point &b) {
  return sqrt((a - b) * (a - b));
}
//1.4 判断: 线段相交
//*判断线段相交
bool inter(const Line &l1, const Line &l2) {
  return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x)
         && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x)
         && max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y)
         && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y)
         && sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e-l1.e) ^ (l1.s - l1.e)) <= 0
         && sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e-l2.e) ^ (l2.s - l2.e)) <= 0;
}
//1.5 判断：直线和线段相交
//判断直线和线段相交
bool Seg_inter_line(const Line &l1, const Line &l2) { //判断直线l1和线段l2是否相交
  return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e-l1.e) ^ (l1.s - l1.e)) <= 0;
}
//1.6 点到直线距离
//点到直线距离
//返回为result, 是点到直线最近的点
Point PointToLine(const Point &P, const Line &L) {
  double t = ((P - L.s) * (L.e-L.s)) / ((L.e - L.s) * (L.e - L.s));
  return Point(L.s.x + (L.e.x - L.s.x) * t, L.s.y + (L.e.y - L.s.y) * t);
}
//1.7 点到线段距离
//点到线段的距离
//返回点到线段最近的点
Point NearestPointToLineSeg(const Point &P, const Line &L) {
  double t = ((P - L.s) * (L.e-L.s)) / ((L.e-L.s) * (L.e-L.s));
  Point result;
  if (t >= 0 && t <= 1) {
    result.x = L.s.x + (L.e.x - L.s.x) * t;
    result.y = L.s.y + (L.e.y - L.s.y) * t;
  } else {
    if (dist(P, L.s) < dist(P, L.e)) { result = L.s; }
    else { result = L.e; }
  }
  return result;
}
//1.8 计算多边形面积
//计算多边形面积
//点的编号从0 ~ n - 1
double CalcArea(Point p[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    res += (p[i] ^ p[(i + 1) % n]) * 0.5;
  }
  return fabs(res);
}
//1.9 判断点在线段上
//*判断点在线段上
bool OnSeg(const Point &P, const Line &L) {
  return sgn((L.s - P) ^ (L.e-P)) == 0
         && sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0
         && sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
//1.10 判断点在凸多边形内
//*判断点在凸多边形内
//点形成一个凸包, 而且按逆时针排序(如果是顺时针把里面的<0改为>0)
//点的编号:0 ~ n - 1
//返回值:
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inConvexPoly(const Point &a, Point p[], int n) {
  for (int i = 0; i < n; i++) {
    if (sgn((p[i] - a) ^ (p[(i + 1) % n] - a)) < 0) { return -1; }
    else if (OnSeg(a, Line(p[i], p[(i + 1) % n]))) { return 0; }
  }
  return 1;
}
//1.11 判断点在任意多边形内
//*判断点在任意多边形内
//射线法, poly[]的顶点数要大于等于3,点的编号0~n-1
//返回值
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inPoly(const Point &p, Point poly[], int n) {
  int cnt = 0;
  Line ray(p, Point(-100000000000.0, p.y)), side; //-INF,注意取值防止越界
  for (int i = 0; i < n; i++) {
    side.s = poly[i];
    side.e = poly[(i + 1) % n];
    if (OnSeg(p, side)) { return 0; }
    //如果平行轴则不考虑
    if (sgn(side.s.y - side.e.y) == 0) { continue; }
    if (OnSeg(side.s, ray)) {
      if (sgn(side.s.y - side.e.y) > 0) { cnt++; }
    } else if (OnSeg(side.e, ray)) {
      if (sgn(side.e.y - side.s.y) > 0) { cnt++; }
    } else if (inter(ray, side)) {
      cnt++;
    }
  }
  if (cnt & 1) { return 1; }
  else { return -1; }
}
//1.12 判断凸多边形
//判断凸多边形
//允许共线边
//点可以是顺时针给出也可以是逆时针给出
//点的编号1~n-1
bool isconvex(Point poly[], int n) {
  bool s[3] = {0};
  for (int i = 0; i < n; i++) {
    s[sgn((poly[(i + 1) % n] - poly[i]) ^ (poly[(i + 2) % n] - poly[i])) + 1] = true;
    if (s[0] && s[2]) { return false; }
  }
  return true;
}
//2、凸包
/*
* 求凸包, Graham算法
* 点的编号0 ~ n - 1
* 返回凸包结果Stack[0 ~ top - 1]为凸包的编号
*/
const int N = 1010;
Point lst[N];
int Stack[N], top;
//相对于lst[0]的极角排序
bool _cmp(const Point &p1, const Point &p2) {
  double tmp = (p1 - lst[0]) ^ (p2 - lst[0]);
  if (sgn(tmp) > 0) { return true; }
  else if (sgn(tmp) == 0 && sgn(dist(p1, lst[0]) - dist(p2, lst[0])) <= 0) { return true; }
  else { return false; }
}
void Graham(int n) {
  Point p0 = lst[0];
  int k = 0;
  //找最下边的一个点
  for (int i = 1; i < n; i++) {
    if ((p0.y > lst[i].y) || (p0.y == lst[i].y && p0.x > lst[i].x)) {
      p0 = lst[i]; k = i;
    }
  }
  swap(lst[k], lst[0]);
  sort(lst + 1, lst + n, _cmp);
  if (n == 1) {
    top = 1;
    Stack[0] = 0;
    return;
  }
  if (n == 2) {
    top = 2;
    Stack[0] = 0;
    Stack[1] = 1;
    return ;
  }
  top = 2;
  Stack[0] = 0;
  Stack[1] = 1;
  for (int i = 2; i < n; i++) {
    while (top > 1 && sgn((lst[Stack[top - 1]] - lst[Stack[top - 2]]) ^ (lst[i] - lst[Stack[top - 2]])) <= 0) {
      top--;
    }
    Stack[top++] = i;
  }
}
//3、平面最近点对(HDU 1007)
const double EPS = 1e-6;
const double INF = 1e20;
const int N = 100005;
struct Point {
  double x, y;
} p[N], tmpt[N];
double dist(const Point &a, const Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmpxy(const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpy(Point a, Point b) {
  return a.y < b.y;
}
double Closest_Pair(int left, int right) {
  double d = INF;
  if (left == right) { return d; }
  if (left + 1 == right) { return dist(p[left], p[right]); }
  int mid = (left + right) / 2;
  double d1 = Closest_Pair(left, mid);
  double d2 = Closest_Pair(mid + 1, right);
  d = min(d1, d2);
  int k = 0;
  for (int i = left; i <= right; i++) {
    if (fabs(p[mid].x - p[i].x) <= d) {
      tmpt[k++] = p[i];
    }
  }
  sort(tmpt, tmpt + k, cmpy);
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k && tmpt[j].y - tmpt[i].y < d; j++) {
      d = min(d, dist(tmpt[i], tmpt[j]));
    }
  }
  return d;
}
int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmpxy);
    printf("%.2lf\n", Closest_Pair(0, n - 1) / 2);
  }
}
//4、旋转卡壳
//4.1 求解平面最远点对(POJ 2187 Beauty Contest)
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0): x(_x), y(_y) {}
  Point operator-(const Point &b)const {
    return Point(x - b.x, y - b.y);
  }
  int operator^(const Point &b)const {
    return x * b.y - y * b.x;
  }
  int operator*(const Point &b)const {
    return x * b.x + y * b.y;
  }
  void input() {
    scanf("%d%d", &x, &y);
  }
};
//距离的平方
int dist2(const Point &a, const Point &b) {
  return (a - b) * (a - b);
}
//******二维凸包, int***********
const int N = 50005;
Point lst[N], p[N];
int Stack[N], top;
bool _cmp(const Point &p1, const Point &p2) {
  int tmp = (p1 - lst[0]) ^ (p2 - lst[0]);
  if (tmp > 0) { return true; }
  else if (tmp == 0 && dist2(p1, lst[0]) <= dist2(p2, lst[0])) { return true; }
  else { return false; }
}
void Graham(int n) {
  Point p0 = lst[0];
  int k = 0;
  for (int i = 1; i < n; i++) {
    if (p0.y > lst[i].y || (p0.y == lst[i].y && p0.x > lst[i].x)) {
      p0 = lst[i];
      k = i;
    }
  }
  swap(lst[k], lst[0]);
  sort(lst + 1, lst + n, _cmp);
  if (n == 1) {
    top = 1;
    Stack[0] = 0;
    return;
  }
  if (n == 2) {
    top = 2;
    Stack[0] = 0; Stack[1] = 1;
    return;
  }
  top = 2;
  Stack[0] = 0;
  Stack[1] = 1;
  for (int i = 2; i < n; i++) {
    while (top > 1 && ((lst[Stack[top - 1]] - lst[Stack[top - 2]]) ^ (lst[i] - lst[Stack[top - 2]])) <= 0) {
      top--;
    }
    Stack[top++] = i;
  }
}
//旋转卡壳, 求两点间距离平方的最大值
int rotating_calipers(Point p[], int n) {
  int ans = 0, cur = 1;
  Point v;
  for (int i = 0; i < n; i++) {
    v = p[i] - p[(i + 1) % n];
    while ((v ^ (p[(cur + 1) % n] - p[cur])) < 0) {
      cur = (cur + 1) % n;
    }
    ans = max(ans, max(dist2(p[i], p[cur]), dist2(p[(i + 1) % n], p[(cur + 1) % n])));
  }
  return ans;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) { lst[i].input(); }
    Graham(n);
    for (int i = 0; i < top; i++) { p[i] = lst[Stack[i]]; }
    printf("%d\n", rotating_calipers(p, top));
  }
}
//4.2 求解平面点集最大三角形
//旋转卡壳计算平面点集最大三角形面积
Point lst[N], p[N];
int rotating_calipers(Point p[], int n) {
  int ans = 0;
  Point v;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n, k = (j + 1) % n;
    while (j != i && k != i) {
      ans = max(ans, abs((p[j] - p[i]) ^ (p[k] - p[i])));
      while (((p[i] - p[j]) ^ (p[(k + 1) % n] - p[k])) < 0) {
        k = (k + 1) % n;
      }
      j = (j + 1) % n;
    }
  }
  return ans;
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    if (n == -1) { break; }
    for (int i = 0; i < n; i++) { lst[i].input(); }
    Graham(n);
    for (int i = 0; i < top; i++) { p[i] = lst[Stack[i]]; }
    printf("%.2f\n", rotating_calipers(p, top) / 2.0);
  }
}
//4.3 求解两凸包最小距离(POJ 3608)
const double EPS = 1e-8;
inline int sgn(double x) {
  return (fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1));
}
struct Point {
  double x, y;
  Point() {}
  Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
  Point operator-(const Point &b)const {
    return Point(x - b.x, y - b.y);
  }
  //叉积
  double operator^(const Point &b)const {
    return x * b.y - y * b.x;
  }
  //点积
  double operator*(const Point &b)const {
    return x * b.x + y * b.y;
  }
  void input() {
    scanf("%lf%lf", &x, &y);
  }
};
struct Line {
  Point s, e;
  Line() {}
  Line(Point _s, Point _e): s(_s), e(_e) {}
};
//两点间距离
double dist(const Point &a, const Point &b) {
  return sqrt((a - b) * (a - b));
}
//点到线段的距离, 返回点到线段最近的点
Point NearestPointToLineSeg(const Point &P, const Line &L) {
  double t = ((P - L.s) * (L.e-L.s)) / ((L.e-L.s) * (L.e-L.s));
  Point result;
  if (t >= 0 && t <= 1) {
    result.x = L.s.x + (L.e.x - L.s.x) * t;
    result.y = L.s.y + (L.e.y - L.s.y) * t;
  } else {
    if (dist(P, L.s) < dist(P, L.e)) { result = L.s; }
    else { result = L.e; }
  }
  return result;
}
/*
* 求凸包, Graham算法
* 点的编号0~n-1
* 返回凸包结果Stack[0~top-1]为凸包的编号
*/
const int N = 10005;
Point lst[N];
int Stack[N], top;
//相对于list[0]的极角排序
bool _cmp(const Point &p1, const Point &p2) {
  double tmp = (p1 - lst[0]) ^ (p2 - lst[0]);
  if (sgn(tmp) > 0) { return true; }
  else if (sgn(tmp) == 0 && sgn(dist(p1, lst[0]) - dist(p2, lst[0])) <= 0) { return true; }
  else { return false; }
}
void Graham(int n) {
  Point p0 = lst[0];
  int k = 0;
  //找最下边的一个点
  for (int i = 1; i < n; i++) {
    if ((p0.y > lst[i].y) || (p0.y == lst[i].y && p0.x > lst[i].x)) {
      p0 = lst[i];
      k = i;
    }
  }
  swap(lst[k], lst[0]);
  sort(lst + 1, lst + n, _cmp);
  if (n == 1) {
    top = 1;
    Stack[0] = 0;
    return;
  }
  if (n == 2) {
    top = 2;
    Stack[0] = 0;
    Stack[1] = 1;
    return ;
  }
  top = 2;
  Stack[0] = 0;
  Stack[1] = 1;
  for (int i = 2; i < n; i++) {
    while (top > 1 && sgn((lst[Stack[top - 1]] - lst[Stack[top - 2]]) ^ (lst[i] - lst[Stack[top - 2]])) <= 0) {
      top--;
    }
    Stack[top++] = i;
  }
}
//点p0到线段p1p2的距离
double pointtoseg(const Point &p0, const Point &p1, const Point &p2) {
  return dist(p0, NearestPointToLineSeg(p0, Line(p1, p2)));
}
//平行线段p0p1和p2p3的距离
double dispallseg(const Point &p0, const Point &p1, const Point &p2, const Point &p3) {
  double ans1 = min(pointtoseg(p0, p2, p3), pointtoseg(p1, p2, p3));
  double ans2 = min(pointtoseg(p2, p0, p1), pointtoseg(p3, p0, p1));
  return min(ans1, ans2);
}
//得到向量a1a2和b1b2的位置关系
double Get_angle(const Point &a1, const Point &a2, const Point &b1, const Point &b2) {
  return (a2 - a1) ^ (b1 - b2);
}
double rotating_calipers(Point p[], int np, Point q[], int nq) {
  int sp = 0, sq = 0;
  for (int i = 0; i < np; i++) {
    if (sgn(p[i].y - p[sp].y) < 0) { sp = i; }
  }
  for (int i = 0; i < nq; i++) {
    if (sgn(q[i].y - q[sq].y) > 0) { sq = i; }
  }
  double ans = dist(p[sp], q[sq]), tmp;
  for (int i = 0; i < np; i++) {
    while (sgn(tmp = Get_angle(p[sp], p[(sp + 1) % np], q[sq], q[(sq + 1) % nq])) < 0) {
      sq = (sq + 1) % nq;
    }
    if (sgn(tmp) == 0) {
      ans = min(ans, dispallseg(p[sp], p[(sp + 1) % np], q[sq], q[(sq + 1) % nq]));
    } else { ans = min(ans, pointtoseg(q[sq], p[sp], p[(sp + 1) % np])); }
    sp = (sp + 1) % np;
  }
  return ans;
}
double solve(Point p[], int n, Point q[], int m) {
  return min(rotating_calipers(p, n, q, m), rotating_calipers(q, m, p, n));
}
Point p[N], q[N];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    if (n == 0 && m == 0) { break; }
    for (int i = 0; i < n; i++) { lst[i].input(); }
    Graham(n);
    for (int i = 0; i < top; i++) { p[i] = lst[i]; }
    n = top;
    for (int i = 0; i < m; i++) { lst[i].input(); }
    Graham(m);
    for (int i = 0; i < top; i++) { q[i] = lst[i]; }
    m = top;
    printf("%.4f\n", solve(p, n, q, m));
  }
}
//5、半平面交
//5.1 半平面交模板(from UESTC)
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 105;
inline int sgn(double x) {
  return (fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1));
}
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y): x(_x), y(_y) {}
  Point operator-(const Point &b)const {
    return Point(x - b.x, y - b.y);
  }
  double operator^(const Point &b)const {
    return x * b.y - y * b.x;
  }
  double operator*(const Point &b)const {
    return x * b.x + y * b.y;
  }
};
struct Line {
  Point s, e;
  double k;
  Line() {}
  Line(Point _s, Point _e): s(_s), e(_e), k(atan2(e.y - s.y, e.x - s.x)) {}
  Point operator&(const Line &b)const {
    Point res = s;
    double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return res;
  }
};
//半平面交, 直线的左边代表有效区域
bool HPIcmp(const Line &a, const Line &b) {
  if (fabs(a.k - b.k) > EPS) { return a.k < b.k; }
  return ((a.s - b.s) ^ (b.e - b.s)) < 0;
}
Line Q[N];
void HPI(Line line[], int n, Point res[], int &resn) {
  int tot = 1;
  sort(line, line + n, HPIcmp);
  for (int i = 1; i < n; i++) {
    if (fabs(line[i].k - line[i - 1].k) > EPS) { line[tot++] = line[i]; }
  }
  int head = 0, tail = 1;
  Q[0] = line[0]; Q[1] = line[1];
  resn = 0;
  for (int i = 2; i < tot; i++) {
    if (fabs((Q[tail].e-Q[tail].s) ^ (Q[tail - 1].e-Q[tail - 1].s)) < EPS
        || fabs((Q[head].e-Q[head].s) ^ (Q[head + 1].e-Q[head + 1].s)) < EPS) {
      return;
    }
    while (head < tail
           && (((Q[tail]&Q[tail - 1]) - line[i].s) ^ (line[i].e-line[i].s)) > EPS) {
      tail--;
    }
    while (head < tail
           && (((Q[head]&Q[head + 1]) - line[i].s) ^ (line[i].e-line[i].s)) > EPS) {
      head++;
    }
    Q[++tail] = line[i];
  }
  while (head < tail
         && (((Q[tail]&Q[tail - 1]) - Q[head].s) ^ (Q[head].e-Q[head].s)) > EPS) {
    tail--;
  }
  while (head < tail
         && (((Q[head]&Q[head - 1]) - Q[tail].s) ^ (Q[tail].e-Q[tail].e)) > EPS) {
    head++;
  }
  if (tail <= head + 1) { return; }
  for (int i = head; i < tail; i++) {
    res[resn++] = Q[i] & Q[i + 1];
  }
  if (head < tail - 1) {
    res[resn++] = Q[head] & Q[tail];
  }
}
//5.2 普通半平面交写法
//POJ 1750
const double EPS = 1e-18;
const double INF = 100000000000.0;
const int N = 105;
inline int sgn(double x) {
  return (fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1));
}
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y): x(_x), y(_y) {}
  Point operator-(const Point &b)const {
    return Point(x - b.x, y - b.y);
  }
  double operator^(const Point &b)const {
    return x * b.y - y * b.x;
  }
  double operator*(const Point &b)const {
    return x * b.x + y * b.y;
  }
};
//计算多边形面积
double CalcArea(Point p[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    res += (p[i] ^ p[(i + 1) % n]);
  }
  return fabs(res / 2);
}
//通过两点, 确定直线方程
void Get_equation(const Point &p1, const Point &p2, double &a, double &b, double &c) {
  a = p2.y - p1.y;
  b = p1.x - p2.x;
  c = p2.x * p1.y - p1.x * p2.y;
}
//求交点
Point Intersection(const Point &p1, const Point &p2, double a, double b, double c) {
  double u = fabs(a * p1.x + b * p1.y + c);
  double v = fabs(a * p2.x + b * p2.y + c);
  return Point((p1.x * v + p2.x * u) / (u + v), (p1.y * v + p2.y * u) / (u + v));
}
Point tp[N];
void Cut(double a, double b, double c, Point p[], int &cnt) {
  int tmp = 0;
  for (int i = 1; i <= cnt; i++) {
    //当前点在左侧, 逆时针的点
    if (a * p[i].x + b * p[i].y + c < EPS) { tp[++tmp] = p[i]; }
    else {
      if (a * p[i - 1].x + b * p[i - 1].y + c < -EPS) {
        tp[++tmp] = Intersection(p[i - 1], p[i], a, b, c);
      }
      if (a * p[i + 1].x + b * p[i + 1].y + c < -EPS) {
        tp[++tmp] = Intersection(p[i], p[i + 1], a, b, c);
      }
    }
  }
  for (int i = 1; i <= tmp; i++) { p[i] = tp[i]; }
  p[0] = p[tmp];
  p[tmp + 1] = p[1];
  cnt = tmp;
}
double V[N], U[N], W[N];
int n;
Point p[N];
bool solve(int id) {
  p[1] = Point(0, 0);
  p[2] = Point(INF, 0);
  p[3] = Point(INF, INF);
  p[4] = Point(0, INF);
  p[0] = p[4];
  p[5] = p[1];
  int cnt = 4;
  for (int i = 0; i < n; i++) {
    if (i != id) {
      double a = (V[i] - V[id]) / (V[i] * V[id]);
      double b = (U[i] - U[id]) / (U[i] * U[id]);
      double c = (W[i] - W[id]) / (W[i] * W[id]);
      if (sgn(a) == 0 && sgn(b) == 0) {
        if (sgn(c) >= 0) { return false; }
        else { continue; }
      }
      Cut(a, b, c, p, cnt);
    }
  }
  if (sgn(CalcArea(p, cnt)) == 0) { return false; }
  else { return true; }
}
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf", &V[i], &U[i], &W[i]);
    }
    for (int i = 0; i < n; i++) {
      if (solve(i)) { printf("Yes\n"); }
      else { printf("No\n"); }
    }
  }
}
//6、三点求圆心坐标(三角形外心)
//过三点求圆心坐标
Point waixin(const Point &a, const Point &b, const Point &c) {
  double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
  double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
  double d = a1 * b2 - a2 * b1;
  return Point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
}
//7、求两圆相交的面积
//两个圆的公共部分面积
double Area_of_overlap(const Point &c1, double r1, const Point &c2, double r2) {
  double d = dist(c1, c2);
  if (r1 + r2 < d + EPS) { return 0; }
  if (d < fabs(r1 - r2) + EPS) {
    double r = min(r1, r2);
    return PI * r * r;
  }
  double x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
  double t1 = acos(x / r1);
  double t2 = acos((d - x) / r2);
  return r1 * r1 * t1 + r2 * r2 * t2 - d * r1 * sin(t1);
}
//8、Pick 公式
//顶点坐标均是整点的简单多边形: 面积 = 内部格点数目 + 边上格点数目 / 2 - 1



//http://www.cppblog.com/abilitytao/archive/2009/08/04/92171.html

//常量区
const double M_PI       = acos(-1.0); //PI
const double INF        = 1e10;       //无穷大
const double EPS        = 1e-8;       //计算精度
const int LEFT          = 0;          //点在直线左边
const int RIGHT         = 1;          //点在直线右边
const int ONLINE        = 2;          //点在直线上
const int CROSS         = 0;          //两直线相交
const int COLINE        = 1;          //两直线共线
const int PARALLEL      = 2;          //两直线平行
const int NOTCOPLANAR   = 3;          //两直线不共面
const int INSIDE        = 1;          //点在图形内部
const int OUTSIDE       = 2;          //点在图形外部
const int BORDER        = 3;          //点在图形边界
const int BAOHAN        = 1;          //大圆包含小圆
const int NEIQIE        = 2;          //内切
const int XIANJIAO      = 3;          //相交
const int WAIQIE        = 4;          //外切
const int XIANLI        = 5;          //相离
///////////////////////////////////////////////////////////////////
//类型定义区
struct Point {              //二维点或矢量
  double x, y;
  double angle, dis;
  Point(): x(0), y(0), angle(0), dis(0) {}
  Point(double x0, double y0): x(x0), y(y0), angle(0), dis(0) {}
};
struct Point3D {            //三维点或矢量
  double x, y, z;
  Point3D(): x(0), y(0), z(0) {}
  Point3D(double x0, double y0, double z0): x(x0), y(y0), z(z0) {}
};
struct Line {               //二维的直线或线段
  Point p1, p2;
  Line(): p1(), p2() {}
  Line(Point p10, Point p20): p1(p10), p2(p20) {}
};
struct Line3D {             //三维的直线或线段
  Point3D p1, p2;
  Line3D(): p1(), p2() {}
  Line3D(Point3D p10, Point3D p20): p1(p10), p2(p20) {}
};
struct Rect {              //用长宽表示矩形的方法 w, h分别表示宽度和高度
  double w, h;
  Rect(): w(0), h(0) {}
  Rect(double _w, double _h) : w(_w), h(_h) {}
};
struct Rect_2 {             //表示矩形, 左下角坐标是(xl, yl), 右上角坐标是(xh, yh)
  double xl, yl, xh, yh;
  Rect_2(): xl(0), yl(0), xh(0), yh(0) {}
  Rect_2(double _xl, double _yl, double _xh, double _yh) : xl(_xl), yl(_yl), xh(_xh), yh(_yh) {}
};
struct Circle {            //圆
  Point c;
  double r;
  Circle(): c(), r(0) {}
  Circle(Point _c, double _r) : c(_c), r(_r) {}
};
typedef vector<Point> Polygon;      //二维多边形
typedef vector<Point> Points;       //二维点集
typedef vector<Point3D> Points3D;   //三维点集
///////////////////////////////////////////////////////////////////
//基本函数区
inline bool ZERO(double x) {            //x == 0
  return (fabs(x) < EPS);
}
inline bool ZERO(Point p) {             //p == 0
  return (ZERO(p.x) && ZERO(p.y));
}
inline bool ZERO(Point3D p) {            //p == 0
  return (ZERO(p.x) && ZERO(p.y) && ZERO(p.z));
}
inline bool EQ(double x, double y) {    //eqaul, x == y
  return (fabs(x - y) < EPS);
}
inline bool NEQ(double x, double y) {   //not equal, x != y
  return (fabs(x - y) >= EPS);
}
inline bool LT(double x, double y) {   //less than, x < y
  return (NEQ(x, y) && (x < y));
}
inline bool GT(double x, double y) {   //greater than, x > y
  return (NEQ(x, y) && (x > y));
}
inline bool LEQ(double x, double y) {   //less equal, x <= y
  return (EQ(x, y) || (x < y));
}
inline bool GEQ(double x, double y) {   //greater equal, x >= y
  return (EQ(x, y) || (x > y));
}
//注意！！！
//如果是一个很小的负的浮点数
//保留有效位数输出的时候会出现-0.000这样的形式,
//前面多了一个负号
//这就会导致错误！！！！！！
//因此在输出浮点数之前, 一定要调用次函数进行修正！
inline double FIX(double x) {
  return (fabs(x) < EPS) ? 0 : x;
}
/////////////////////////////////////////////////////////////////////////////////////
//二维矢量运算
bool operator==(Point p1, Point p2) {
  return (EQ(p1.x, p2.x) && EQ(p1.y, p2.y));
}
bool operator!=(Point p1, Point p2) {
  return (NEQ(p1.x, p2.x) || NEQ(p1.y, p2.y));
}
bool operator<(Point p1, Point p2) {
  if (NEQ(p1.x, p2.x)) { return (p1.x < p2.x); }
  else { return (p1.y < p2.y); }
}
Point operator+(Point p1, Point p2) {
  return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(Point p1, Point p2) {
  return Point(p1.x - p2.x, p1.y - p2.y);
}
double operator*(Point p1, Point p2) { //计算叉乘 p1 × p2
  return (p1.x * p2.y - p2.x * p1.y);
}
double operator&(Point p1, Point p2) { //计算点积 p1·p2
  return (p1.x * p2.x + p1.y * p2.y);
}
double Norm(Point p) { //计算矢量p的模
  return sqrt(p.x * p.x + p.y * p.y);
}
//把矢量p旋转角度angle (弧度表示)
//angle > 0表示逆时针旋转
//angle < 0表示顺时针旋转
Point Rotate(Point p, double angle) {
  Point result;
  result.x = p.x * cos(angle) - p.y * sin(angle);
  result.y = p.x * sin(angle) + p.y * cos(angle);
  return result;
}
//////////////////////////////////////////////////////////////////////////////////////
//三维矢量运算
bool operator==(Point3D p1, Point3D p2) {
  return (EQ(p1.x, p2.x) && EQ(p1.y, p2.y) && EQ(p1.z, p2.z));
}
bool operator<(Point3D p1, Point3D p2) {
  if (NEQ(p1.x, p2.x)) { return (p1.x < p2.x); }
  else if (NEQ(p1.y, p2.y)) { return (p1.y < p2.y); }
  else { return (p1.z < p2.z); }
}
Point3D operator+(Point3D p1, Point3D p2) {
  return Point3D(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}
Point3D operator-(Point3D p1, Point3D p2) {
  return Point3D(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}
Point3D operator*(Point3D p1, Point3D p2) { //计算叉乘 p1 x p2
  return Point3D(p1.y * p2.z - p1.z * p2.y, p1.z * p2.x - p1.x * p2.z, p1.x * p2.y - p1.y * p2.x);
}
double operator&(Point3D p1, Point3D p2) { //计算点积 p1·p2
  return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}
double Norm(Point3D p) { //计算矢量p的模
  return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
/////////////////////////////////////////////////////////////////////////////////////
//几何题面积计算
//
//根据三个顶点坐标计算三角形面积
//面积的正负按照右手旋规则确定
double Area(Point A, Point B, Point C) { //三角形面积
  return ((B - A) * (C - A) / 2.0);
}
//根据三条边长计算三角形面积
double Area(double a, double b, double c) { //三角形面积
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
double Area(const Circle &C) {
  return M_PI * C.r * C.r;
}
//计算多边形面积
//面积的正负按照右手旋规则确定
double Area(const Polygon &poly) { //多边形面积
  double res = 0;
  int n = poly.size();
  if (n < 3) { return 0; }
  for (int i = 0; i < n; i++) {
    res += poly[i].x * poly[(i + 1) % n].y;
    res -= poly[i].y * poly[(i + 1) % n].x;
  }
  return (res / 2.0);
}
/////////////////////////////////////////////////////////////////////////////////////
//点.线段.直线问题
//
double Distance(Point p1, Point p2) { //2点间的距离
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double Distance(Point3D p1, Point3D p2) { //2点间的距离,三维
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}
double Distance(Point p, Line L) { //求二维平面上点到直线的距离
  return (fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1));
}
double Distance(Point3D p, Line3D L) { //求三维空间中点到直线的距离
  return (Norm((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1));
}
bool OnLine(Point p, Line L) { //判断二维平面上点p是否在直线L上
  return ZERO((p - L.p1) * (L.p2 - L.p1));
}
bool OnLine(Point3D p, Line3D L) { //判断三维空间中点p是否在直线L上
  return ZERO((p - L.p1) * (L.p2 - L.p1));
}
int Relation(Point p, Line L) { //计算点p与直线L的相对关系 ,返回ONLINE,LEFT,RIGHT
  double res = (L.p2 - L.p1) * (p - L.p1);
  if (EQ(res, 0)) { return ONLINE; }
  else if (res > 0) { return LEFT; }
  else { return RIGHT; }
}
bool SameSide(Point p1, Point p2, Line L) { //判断点p1, p2是否在直线L的同侧
  double m1 = (p1 - L.p1) * (L.p2 - L.p1);
  double m2 = (p2 - L.p1) * (L.p2 - L.p1);
  return GT(m1 * m2, 0);
}
bool OnLineSeg(Point p, Line L) { //判断二维平面上点p是否在线段l上
  return (ZERO((L.p1 - p) * (L.p2 - p)) && LEQ((p.x - L.p1.x) * (p.x - L.p2.x), 0)
          && LEQ((p.y - L.p1.y) * (p.y - L.p2.y), 0));
}
bool OnLineSeg(Point3D p, Line3D L) { //判断三维空间中点p是否在线段l上
  return (ZERO((L.p1 - p) * (L.p2 - p)) && EQ(Norm(p - L.p1) + Norm(p - L.p2), Norm(L.p2 - L.p1)));
}
Point SymPoint(Point p, Line L) { //求二维平面上点p关于直线L的对称点
  Point result;
  double a = L.p2.x - L.p1.x;
  double b = L.p2.y - L.p1.y;
  double t = ((p.x - L.p1.x) * a + (p.y - L.p1.y) * b) / (a * a + b * b);
  result.x = 2 * L.p1.x + 2 * a * t - p.x;
  result.y = 2 * L.p1.y + 2 * b * t - p.y;
  return result;
}
bool Coplanar(Points3D points) { //判断一个点集中的点是否全部共面
  Point3D p;
  if (points.size() < 4) { return true; }
  p = (points[2] - points[0]) * (points[1] - points[0]);
  for (size_t i = 3; i < points.size(); i++) {
    if (!ZERO(p & (points[i] - points[0]))) { return false; }
  }
  return true;
}
bool LineIntersect(Line L1, Line L2) { //判断二维的两直线是否相交
  return (!ZERO((L1.p1 - L1.p2) * (L2.p1 - L2.p2))); //是否平行
}
bool LineIntersect(Line3D L1, Line3D L2) { //判断三维的两直线是否相交
  Point3D p1 = L1.p1 - L1.p2;
  Point3D p2 = L2.p1 - L2.p2;
  Point3D p  = p1 * p2;
  if (ZERO(p)) { return false; }      //是否平行
  p = (L2.p1 - L1.p2) * (L1.p1 - L1.p2);
  return ZERO(p & L2.p2);         //是否共面
}
bool LineSegIntersect(Line L1, Line L2) { //判断二维的两条线段是否相交
  return (GEQ(max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x)) &&
          GEQ(max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x)) &&
          GEQ(max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y)) &&
          GEQ(max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y)) &&
          LEQ(((L2.p1 - L1.p1) * (L1.p2 - L1.p1)) * ((L2.p2 -  L1.p1) * (L1.p2 - L1.p1)), 0) &&
          LEQ(((L1.p1 - L2.p1) * (L2.p2 - L2.p1)) * ((L1.p2 -  L2.p1) * (L2.p2 - L2.p1)), 0));
}
bool LineSegIntersect(Line3D L1, Line3D L2) { //判断三维的两条线段是否相交
  //todo
  return true;
}
//计算两条二维直线的交点, 结果在参数P中返回
//返回值说明了两条直线的位置关系:  COLINE   -- 共线  PARALLEL -- 平行  CROSS    -- 相交
int CalCrossPoint(Line L1, Line L2, Point &P) {
  double A1, B1, C1, A2, B2, C2;
  A1 = L1.p2.y - L1.p1.y;
  B1 = L1.p1.x - L1.p2.x;
  C1 = L1.p2.x * L1.p1.y - L1.p1.x * L1.p2.y;
  A2 = L2.p2.y - L2.p1.y;
  B2 = L2.p1.x - L2.p2.x;
  C2 = L2.p2.x * L2.p1.y - L2.p1.x * L2.p2.y;
  if (EQ(A1 * B2, B1 * A2))    {
    if (EQ((A1 + B1) * C2, (A2 + B2) * C1)) { return COLINE; }
    else { return PARALLEL; }
  } else {
    P.x = (B2 * C1 - B1 * C2) / (A2 * B1 - A1 * B2);
    P.y = (A1 * C2 - A2 * C1) / (A2 * B1 - A1 * B2);
    return CROSS;
  }
}
//计算两条三维直线的交点, 结果在参数P中返回
//返回值说明了两条直线的位置关系 COLINE   -- 共线  PARALLEL -- 平行  CROSS    -- 相交  NONCOPLANAR -- 不公面
int CalCrossPoint(Line3D L1, Line3D L2, Point3D &P) {
  //todo
  return 0;
}
//计算点P到直线L的最近点
Point NearestPointToLine(Point P, Line L) {
  Point result;
  double a, b, t;
  a = L.p2.x - L.p1.x;
  b = L.p2.y - L.p1.y;
  t = ((P.x - L.p1.x) * a + (P.y - L.p1.y) * b) / (a * a + b * b);
  result.x = L.p1.x + a * t;
  result.y = L.p1.y + b * t;
  return result;
}
//计算点P到线段L的最近点
Point NearestPointToLineSeg(Point P, Line L) {
  Point result;
  double a, b, t;
  a = L.p2.x - L.p1.x;
  b = L.p2.y - L.p1.y;
  t = ((P.x - L.p1.x) * a + (P.y - L.p1.y) * b) / (a * a + b * b);
  if (GEQ(t, 0) && LEQ(t, 1)) {
    result.x = L.p1.x + a * t;
    result.y = L.p1.y + b * t;
  } else {
    if (Norm(P - L.p1) < Norm(P - L.p2)) { result = L.p1; }
    else { result = L.p2; }
  }
  return result;
}
//计算险段L1到线段L2的最短距离
double MinDistance(Line L1, Line L2) {
  double d1, d2, d3, d4;
  if (LineSegIntersect(L1, L2)) {
    return 0;
  } else {
    d1 = Norm(NearestPointToLineSeg(L1.p1, L2) - L1.p1);
    d2 = Norm(NearestPointToLineSeg(L1.p2, L2) - L1.p2);
    d3 = Norm(NearestPointToLineSeg(L2.p1, L1) - L2.p1);
    d4 = Norm(NearestPointToLineSeg(L2.p2, L1) - L2.p2);
    return min(min(d1, d2), min(d3, d4));
  }
}
//求二维两直线的夹角,
//返回值是0~Pi之间的弧度
double Inclination(Line L1, Line L2) {
  Point u = L1.p2 - L1.p1;
  Point v = L2.p2 - L2.p1;
  return acos((u & v) / (Norm(u) * Norm(v)));
}
//求三维两直线的夹角,
//返回值是0~Pi之间的弧度
double Inclination(Line3D L1, Line3D L2) {
  Point3D u = L1.p2 - L1.p1;
  Point3D v = L2.p2 - L2.p1;
  return acos((u & v) / (Norm(u) * Norm(v)));
}
/////////////////////////////////////////////////////////////////////////////
//多边行问题:
//判断点p是否在凸多边形poly内
//poly的顶点数目要大于等于3
//返回值为：
//INSIDE  -- 点在poly内
//BORDER  -- 点在poly边界上
//OUTSIDE -- 点在poly外
int InsideConvex(Point p, const Polygon &poly) { //判断点p是否在凸多边形poly内
  Point q(0, 0);
  Line side;
  int i, n = poly.size();
  for (i = 0; i < n; i++) {
    q.x += poly[i].x; q.y += poly[i].y;
  }
  q.x /= n; q.y /= n;
  for (i = 0; i < n; i++) {
    side.p1 = poly[i];
    side.p2 = poly[(i + 1) % n];
    if (OnLineSeg(p, side)) { return BORDER; }
    else if (!SameSide(p, q, side)) { return OUTSIDE; }
  }
  return INSIDE;
}
//判断多边形poly是否是凸的
bool IsConvex(const Polygon &poly) {
  int i, n, rel;
  Line side;
  n = poly.size();
  if (n < 3) { return false; }
  side.p1 = poly[0];
  side.p2 = poly[1];
  rel = Relation(poly[2], side);
  for (i = 1; i < n; i++) {
    side.p1 = poly[i];
    side.p2 = poly[(i + 1) % n];
    if (Relation(poly[(i + 2) % n], side) != rel) { return false; }
  }
  return true;
}
//判断点p是否在简单多边形poly内, 多边形可以是凸的或凹的
//poly的顶点数目要大于等于3
//返回值为：
//INSIDE  -- 点在poly内
//BORDER  -- 点在poly边界上
//OUTSIDE -- 点在poly外
int InsidePolygon(const Polygon &poly, Point p) {
  int i, n, count;
  Line ray, side;
  n = poly.size();
  count = 0;
  ray.p1    = p;
  ray.p2.y  = p.y;
  ray.p2.x  = - INF;
  for (i = 0; i < n; i++) {
    side.p1 = poly[i];
    side.p2 = poly[(i + 1) % n];
    if (OnLineSeg(p, side)) {
      return BORDER;
    }
    //如果side平行x轴则不作考虑
    if (EQ(side.p1.y, side.p2.y)) { continue; }
    if (OnLineSeg(side.p1, ray)) {
      if (GT(side.p1.y, side.p2.y)) { count++; }
    } else if (OnLineSeg(side.p2, ray)) {
      if (GT(side.p2.y, side.p1.y)) { count++; }
    } else if (LineSegIntersect(ray, side)) {
      count++;
    }
  }
  return ((count % 2 == 1) ? INSIDE : OUTSIDE);
}
//判断线段是否在多边形内 (线段的点可能在多边形上)
//多边形可以是任意简单多边形
bool InsidePolygon(const Polygon &poly, Line L) {
  bool result;
  int n;
  Points points;
  Point p;
  Line side;
  result = ((InsidePolygon(poly, L.p1) != OUTSIDE) && (InsidePolygon(poly, L.p2) != OUTSIDE));
  if (!result) { return false; }
  n = poly.size();
  for (int i = 0; i < n; i++) {
    side.p1 = poly[i];
    side.p2 = poly[(i + 1) % n];
    if (OnLineSeg(L.p1, side)) {
      points.push_back(L.p1);
    } else if (OnLineSeg(L.p2, side)) {
      points.push_back(L.p2);
    } else if (OnLineSeg(side.p1, L)) {
      points.push_back(side.p1);
    } else if (OnLineSeg(side.p2, L)) {
      points.push_back(side.p2);
    } else if (LineSegIntersect(side, L)) {
      return false;
    }
  }
  //对交点进行排序
  sort(points.begin(), points.end());
  for (size_t i = 1; i < points.size(); i++) {
    if (points[i - 1] != points[i]) {
      p.x = (points[i - 1].x + points[i].x) / 2.0;
      p.y = (points[i - 1].y + points[i].y) / 2.0;
      if (InsidePolygon(poly, p) == OUTSIDE) {
        return false;
      }
    }
  }
  return true;
}
//寻找凸包 graham 扫描法
//生成的多边形顶点按逆时针方向排列
bool GrahamComp(const Point &left, const Point &right) {
  if (EQ(left.angle, right.angle)) {
    return (left.dis < right.dis);
  } else {
    return (left.angle < right.angle);
  }
}
void GrahamScan(Points &points, Polygon &result) {
  int i, k, n;
  Point p;
  n = points.size();
  result.clear();
  if (n < 3) { return; }
  //选取points中y坐标最小的点points[k],
  //如果这样的点有多个, 则取最左边的一个
  k = 0;
  for (i = 1; i < n; i++) {
    if (EQ(points[i].y, points[k].y)) {
      if (points[i].x <= points[k].x) { k = i; }
    } else if (points[i].y < points[k].y) {
      k = i;
    }
  }
  swap(points[0], points[k]);
  //现在points中y坐标最小的点在points[0]
  //计算每个点相对于points[0]的极角和距离
  for (i = 1; i < n; i++) {
    points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
    points[i].dis   = Norm(points[i] - points[0]);
  }
  //对顶点按照相对points[0]的极角从小到大进行排序
  //对于极角相同的按照距points[0]的距离从小到大排序
  sort(points.begin() + 1, points.end(), GrahamComp);
  //下面计算凸包
  result.push_back(points[0]);
  for (i = 1; i < n; i++) {
    //如果有极角相同的点, 只取相对于points[0]最远的一个
    if ((i + 1 < n) && EQ(points[i].angle, points[i + 1].angle)) { continue; }
    if (result.size() >= 3) {
      p = result[result.size() - 2];
      while (GEQ((points[i] - p) * (result.back() - p), 0)) {
        result.pop_back();
        p = result[result.size() - 2];
      }
    }
    result.push_back(points[i]);
  }
}
//用有向直线line切割凸多边形,
//result[LEFT]和result[RIGHT]分别保存被切割后line的左边和右边部分
//result[ONLINE]没有用到, 只是用来作为辅助空间
//返回值是切割多边形的切口的长度,
//如果返回值是0 则说明未作切割。
//当未作切割时, 如果多边形在该直线的右侧, 则result[RIGHT]等于该多边形, 否则result[LEFT]等于该多边形
//注意：被切割的多边形一定要是凸多边形, 顶点按照逆时针排列
//可利用这个函数来求多边形的核, 初始的核设为一个很大的矩形, 然后依次用多边形的每条边去割
double CutConvex(const Polygon &poly, const Line &line, Polygon result[3]) {
  vector<Point> points;
  Line side;
  Point p;
  int i, n, cur, pre;
  result[LEFT].clear();
  result[RIGHT].clear();
  result[ONLINE].clear();
  n = poly.size();
  if (n == 0) { return 0; }
  pre = cur = Relation(poly[0], line);
  for (i = 0; i < n; i++) {
    cur = Relation(poly[(i + 1) % n], line);
    if (cur == pre) {
      result[cur].push_back(poly[(i + 1) % n]);
    } else {
      side.p1 = poly[i];
      side.p2 = poly[(i + 1) % n];
      CalCrossPoint(side, line, p);
      points.push_back(p);
      result[pre].push_back(p);
      result[cur].push_back(p);
      result[cur].push_back(poly[(i + 1) % n]);
      pre = cur;
    }
  }
  sort(points.begin(), points.end());
  if (points.size() < 2) { return 0; }
  else { return Norm(points.front() - points.back()); }
}
//求多边形的重心, 适用于凸的或凹的简单多边形
//该算法可以一边读入多边性的顶点一边计算重心
Point CenterOfPolygon(const Polygon &poly) {
  Point p, p0, p1, p2, p3;
  double m, m0;
  p1 = poly[0];
  p2 = poly[1];
  p.x = p.y = m = 0;
  for (size_t i = 2; i < poly.size(); i++) {
    p3 = poly[i];
    p0.x = (p1.x + p2.x + p3.x) / 3.0;
    p0.y = (p1.y + p2.y + p3.y) / 3.0;
    m0 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
    if (ZERO(m + m0)) { m0 += EPS; } //为了防止除0溢出, 对m0做一点点修正
    p.x = (m * p.x + m0 * p0.x) / (m + m0);
    p.y = (m * p.y + m0 * p0.y) / (m + m0);
    m = m + m0;
    p2 = p3;
  }
  return p;
}
//判断两个矩形是否相交
//如果相邻不算相交
bool Intersect(Rect_2 r1, Rect_2 r2) {
  return (max(r1.xl, r2.xl) < min(r1.xh, r2.xh) && max(r1.yl, r2.yl) < min(r1.yh, r2.yh));
}
//判断矩形r2是否可以放置在矩形r1内
//r2可以任意地旋转
//发现原来的给出的方法过不了OJ上的无归之室这题,
//所以用了自己的代码
bool IsContain(Rect r1, Rect r2) { //矩形的w > h
  if (r1.w > r2.w && r1.h > r2.h) { return true; }
  else {
    double r = sqrt(r2.w * r2.w + r2.h * r2.h) / 2.0;
    double alpha = atan2(r2.h, r2.w);
    double sita = asin((r1.h / 2.0) / r);
    double x = r * cos(sita - 2 * alpha);
    double y = r * sin(sita - 2 * alpha);
    if (x < r1.w / 2.0 && y < r1.h / 2.0 && x > 0 && y > -r1.h / 2.0) { return true; }
    else { return false; }
  }
}
////////////////////////////////////////////////////////////////////////
//圆
Point Center(const Circle &C) { //圆心
  return C.c;
}
//两个圆的公共面积
double CommonArea(const Circle &A, const Circle &B) {
  double area = 0.0;
  const Circle &M = (A.r > B.r) ? A : B;
  const Circle &N = (A.r > B.r) ? B : A;
  double D = Distance(Center(M), Center(N));
  if ((D < M.r + N.r) && (D > M.r - N.r)) {
    double cosM = (M.r * M.r + D * D - N.r * N.r) / (2.0 * M.r * D);
    double cosN = (N.r * N.r + D * D - M.r * M.r) / (2.0 * N.r * D);
    double alpha = 2.0 * acos(cosM);
    double beta  = 2.0 * acos(cosN);
    double TM = 0.5 * M.r * M.r * sin(alpha);
    double TN = 0.5 * N.r * N.r * sin(beta);
    double FM = (alpha / 360.0) * Area(M);
    double FN = (beta / 360.0) * Area(N);
    area = FM + FN - TM - TN;
  } else if (D <= M.r - N.r) {
    area = Area(N);
  }
  return area;
}
//判断圆是否在矩形内(不允许相切)
bool IsInCircle(const Circle &C, const Rect_2 &rect) {
  return (GT(C.c.x - C.r, rect.xl) &&  LT(C.c.x + C.r, rect.xh) &&  GT(C.c.y - C.r, rect.yl)
          &&  LT(C.c.y + C.r, rect.yh));
}
//判断2圆的位置关系
//返回:
//BAOHAN   = 1;        //大圆包含小圆
//NEIQIE   = 2;        //内切
//XIANJIAO = 3;        //相交
//WAIQIE   = 4;        //外切
//XIANLI   = 5;        //相离
int CirCir(const Circle &c1, const Circle &c2) {
  double dis = Distance(c1.c, c2.c);
  if (LT(dis, fabs(c1.r - c2.r))) { return BAOHAN; }
  if (EQ(dis, fabs(c1.r - c2.r))) { return NEIQIE; }
  if (LT(dis, c1.r + c2.r) && GT(dis, fabs(c1.r - c2.r))) { return XIANJIAO; }
  if (EQ(dis, c1.r + c2.r)) { return WAIQIE; }
  return XIANLI;
}
