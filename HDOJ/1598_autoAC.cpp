#include <iostream>
#include <algorithm>
using namespace std;
static const int max_speed = 1000000;
int m,n,root[201],ct;
struct speed{
  int b,e,s;
  friend bool operator < (const speed& lf, const speed& rt){
    return lf.s < rt.s;
  }
}speeds[2048];
int find(int t){
  return root[t] == t ? t : root[t] = find(root[t]);
}
inline void merge(int u, int v){
  root[find(u)] = find(v);
}
int foo(int begin, int end){
  int ret = max_speed+1;
  for (int i = 0; i < m; ++i){
    for (int k = 1; k <= n; ++k) root[k] = k;
    for (int j = i; j < m; ++j){
      merge(speeds[j].b, speeds[j].e);
      if (find(begin) != find(end)) continue;
      int delta = speeds[j].s - speeds[i].s;
      if (delta < ret) ret = delta;
    }
  }
  return ret <= max_ ? ret : -1;
}
int main(){
  ios::sync_with_stdio(false);
  while (cin >> n >> m){
    int q,b,e;
    for (int i = 0; i < m; ++i){
      speed& s = speeds[i];
      cin >> s.b >> s.e >> s.s;
    }
    sort(speeds,speeds+m);
    cin >> q;
    while (q--){
      cin >> b >> e;
      cout << foo(b,e) << endl;
    }
  }
  return 0;
}
