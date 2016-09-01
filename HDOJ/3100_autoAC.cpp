#include<iostream>
#include<string.h> 
#include<vector>
#include<iomanip>
using namespace std;
vector<double> adj[26][26];
int deg[26];
int main() {
  int n;
  while (cin >> n, n) {
    char v, w; double r;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        adj[i][j].clear();
      }
    }
    for (int i = 0; i < n; i++) {
      cin >> v >> w >> r;
      adj[v-'A'][w-'A'].push_back(r);
      adj[w-'A'][v-'A'].push_back(r);
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          if (adj[i][j].size() > 1) {
            double inv_sum = 0;
            for (int s = 0; s < adj[i][j].size(); s++) {
              inv_sum += 1.0/adj[i][j][s];
            }
            adj[i][j].clear(); adj[j][i].clear();
            adj[i][j].push_back(1.0/inv_sum); adj[j][i].push_back(1.0/inv_sum);
          }
        }
      }
      memset(deg, 0, sizeof deg);
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          if (adj[i][j].size()) deg[i]++;
        }
      }
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          for (int l = 0; l < 26; l++) {
            if (i == l || i == j || j == l) continue;
            if (j == 0 || j == 25) continue;
            if (adj[i][j].size() && adj[j][l].size()) {
              if (deg[j] != 2) break;
              double r = adj[i][j][0] + adj[j][l][0];
              adj[i][j].clear(); adj[j][i].clear();
              adj[j][l].clear(); adj[l][j].clear();
              adj[i][l].push_back(r); adj[l][i].push_back(r);
              deg[j] = 0; deg[i]++; deg[l]++;
            }
          }
        }
      }
    }
    bool reduced = true;
    for (int i = 1; i < 25; i++) {
      if (deg[i] != 0) reduced = false;
    }
    double ans = 0;
    if (!reduced || adj[0][25].empty()) ans = -1;
    else ans = adj[0][25][0];
    cout << fixed << setprecision(3) << ans << endl;
  }
    return 0;
}
