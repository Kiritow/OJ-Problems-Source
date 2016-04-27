#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<PII> res;
int b[5][5], a[5];

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int r[5];
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> b[i][j];
      }
    }
    // stage 1
    int *x = b[0], d = x[0];
    if (d <= 2) r[0] = 2;
    else r[0] = d;
    // stage 2
    x = b[1], d = x[0];
    for (int i = 1; i < 5; ++i) a[x[i]] = i;
    if (d == 1) r[1] = a[4];
    else if (d == 3) r[1] = 1;
    else r[1] = r[0];
    // stage 3
    x = b[2], d = x[0];
    for (int i = 1; i < 5; ++i) a[x[i]] = i;
    if (d == 1) r[2] = a[b[1][r[1]]];
    else if (d == 2) r[2] = a[b[0][r[0]]];
    else if (d == 4) r[2] = a[4];
    else r[2] = d;
    // stage 4
    x = b[3], d = x[0];
    if (d == 1) r[3] = r[0];
    else if (d == 2) r[3] = 1;
    else r[3] = r[1];
    // stage 5
    x = b[4], d = x[0];
    for (int i = 1; i < 5; ++i) a[x[i]] = i;
    if (d <= 2) r[4] = a[b[d - 1][r[d - 1]]];
    else r[4] = a[b[6 - d][r[6 - d]]];
    for (int i = 0; i < 5; ++i) {
      cout << r[i] << " " << b[i][r[i]] << endl;
    }
  }
  return 0;
}
