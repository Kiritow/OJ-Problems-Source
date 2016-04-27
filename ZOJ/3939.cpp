#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> p;

int day(int y, int m, int d) {
  int tm = m >= 3 ? (m - 2) : (m + 10);
  int ty = m >= 3 ? y : (y - 1);
  return (ty + ty / 4 - ty / 100 + ty / 400 + (int)(2.6 * tm - 0.2) + d) % 7;
}

void run() {
  int y, m, d, n; cin >> y >> m >> d >> n;
  y -= 1753; n += y / 2800 * p.size();
  y %= 2800;
  n += lower_bound(p.begin(), p.end(), make_tuple(y, m, d)) - p.begin() - 1;
  auto res = p[n % p.size()];
  y = get<0>(res);
  m = get<1>(res);
  d = get<2>(res);
  y += n / p.size() * 2800 + 1753;
  cout << y << " " << m << " " << d << endl;
}

int main() {
  cerr << day(1753, 1, 1) << endl;
  for (int y = 0; y < 2800; ++y) {
    for (int m = 1; m <= 12; ++m) {
      if (day(y + 1753, m,  1) == 1) p.push_back(make_tuple(y, m,  1));
      if (day(y + 1753, m, 11) == 1) p.push_back(make_tuple(y, m, 11));
      if (day(y + 1753, m, 21) == 1) p.push_back(make_tuple(y, m, 21));
    }
  }
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) run();
  return 0;
}
