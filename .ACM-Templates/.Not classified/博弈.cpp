//威佐夫博弈 Wizov game
//有两堆各若干个物品, 两个人轮流从某一堆或同时从两堆中取同样多的物品, 规定每次至少取一个, 多者不限, 最后取光者得胜
//ak = [k(1 + √ 5) / 2], bk = ak + k (k = 0, 1, 2, ..., n 方括号表示取整函数)
const double gs = (sqrt(5.0) + 1.0) / 2.0;
bool Wizov(ll a, ll b) {
  return min(a, b) == (ll)(abs(a - b) * gs);
}
//威佐夫博弈 1 <= N <= 1e18
const int N = 95; //~95 for 1e18
ll fib[N] = { 0, 1 }; //预处理fibonacci数列
bool s[N];
bool Wizov(ll a, ll b) {
  int w = upper_bound(fib + 1, fib + N, a) - fib - 1, pos = 1; ll ret = 0;
  for (int i = w; i > 0; i--) {
    if (a >= fib[i]) { s[i] = true; a -= fib[i]; }
    else { s[i] = false; }
  }
  while (!s[pos]) { pos++; }
  for (int i = pos & 1 ? w - 2 : w; i >= 0; i--) {
    if (s[i]) { ret += fib[i + 1]; }
  }
  return ret == b;
}
//尼姆博奕 Nimm Game
//有三堆各若干个物品, 两个人轮流从某一堆取任意多的物品, 规定每次至少取一个, 多者不限, 最后取光者得胜
//计算从1 - n范围内的SG值
//Array存储可以走的步数, Array[0]表示可以有多少种走法
//Array[]需要从小到大排序
//HDU1847 博弈SG函数
//1.可选步数为1-m的连续整数，直接取模即可，SG(x) = x % (m + 1); (即巴什博奕 Bash game)
//2.可选步数为任意步，SG(x) = x;
//3.可选步数为一系列不连续的数，用SG(x)计算
int sg[N];
bool Hash[N];
int SG(int Array[], int n) {
  memset(sg, 0, sizeof(sg));
  for (int i = 0; i <= n; ++i) {
    memset(Hash, 0, sizeof(Hash));
    for (int j = 1; j <= Array[0]; j++) {
      if (i < Array[j]) { break; }
      Hash[sg[i - Array[j]]] = true;
    }
    for (int j = 0; j <= n; j++) {
      if (!Hash[j]) { sg[i] = j; break; }
    }
  }
  return sg[n];
}
//带输出方案
int a[N], ans[N][2]; //a[]为各堆石子数量
void printNim(int n) { //石子堆数
  int cnt = 0, ret = 0;
  for (int i = 0; i < n; i++) { ret ^= a[i]; }
  for (int i = 0; i < n; i++) {
    if (a[i] > (ret ^ a[i])) {
      ans[cnt][0] = a[i]; ans[cnt][1] = s ^ a[i];
      cnt++;
    }
  }
  if (cnt) { //判断先手是胜是负
    puts("Yes");
    printf("%d\n", cnt); //输出使先手为胜的方案的数目
    for (int i = 0; i < cnt; i++) {
      printf("%d %d\n", ans[i][0], ans[i][1]);  //输出若先手为胜的走法
    }
  } else { puts("No"); }
}
//树上删边游戏
//给定一棵n个点的有根树, 每次可以删掉一个子树
//则叶子节点的SG值为0, 非叶子节点的SG值为其所有孩子节点(SG值 + 1)的异或和
