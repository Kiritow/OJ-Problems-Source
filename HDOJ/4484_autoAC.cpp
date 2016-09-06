#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int cal(int n) {
  int Max = n;
  while (n!=1) {
    if ((n&1) == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
    if (n > Max) Max = n;
  }
  return Max;
}
void solve() {
  int n; scanf("%d", &n);
  int i, t, ca;
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &t, &ca);
    int ans = cal(ca);
    printf("%d %d\n", t, ans);
  }
}
int main(void) {
  solve();
  return 0;
}
