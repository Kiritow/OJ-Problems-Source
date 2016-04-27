#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
char s[MAXN][MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n, m; scanf("%d%d", &n, &m);
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; ++i) scanf("%s", s[i + 10] + 10);
    int ret = 0;
    for (int i = 0; i < n + 10; ++i) {
      for (int j = 0; j < m + 10; ++j) {
        ret += s[i][j + 1] == 'O' || s[i + 1][j] == '/' || s[i + 1][j + 1] == '|' ||
          s[i + 1][j + 2] == '\\' || s[i + 2][j] == '(' || s[i + 2][j + 2] == ')';
      }
    }
    cout << ret << endl;
  }
  return 0;
}
